#    Tichy
#
#    copyright 2008 Guillaume Chereau (charlie@openmoko.org)
#
#    This file is part of Tichy.
#
#    Tichy is free software: you can redistribute it and/or modify it
#    under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Tichy is distributed in the hope that it will be useful, but
#    WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#    General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Tichy.  If not, see <http://www.gnu.org/licenses/>.

import logging
logger = logging.getLogger('xwindow')

from widget import Widget
try:
    import Xlib
    import Xlib.display
    import Xlib.protocol.event
    import Xlib.ext.xtest
    import Xlib.XK
except ImportError, e:
    logger.error("can't import Xlib %s", e)
    Xlib = None

import pygame
import time

# XXX: we have a few busy wait in this class


class XWindow(Widget):
    """Experimental support for XWindow"""

    def __init__(self, parent, expand=True, **kargs):
        super(XWindow, self).__init__(parent, expand=expand, **kargs)
        self.x_window = None
        self.watch = None

    def __get_id(self):
        return self.x_window.id
    id = property(__get_id)

    def create_x_window(self):
        if self.x_window is not None:
            return
        if not Xlib:
            self.x_display = None
            return

        # First we get the xwindow id of the SDL window
        self.x_display = Xlib.display.Display()
        self.x_screen = self.x_display.screen()
        info = pygame.display.get_wm_info()
        x_window_id = info['window']
        x_window = self.x_display.create_resource_object('window',
                                                         x_window_id)
        pos = self.screen_pos()
        # Create a sub window
        self.x_window = x_window.create_window(
            pos.x, pos.y, self.size.x, self.size.y, 0,
            self.x_screen.root_depth,
            Xlib.X.CopyFromParent,
            Xlib.X.CopyFromParent,
            background_pixel=self.x_screen.white_pixel,
            colormap=Xlib.X.CopyFromParent,
            event_mask=Xlib.X.StructureNotifyMask)
        self.x_window.map()

        # Do a busy wait for X reply
        while True:
            event = self.x_display.next_event()
            if event.type == Xlib.X.MapNotify and \
                    event.window == self.x_window:
                break
        self.x_display.sync()

        # We get the Notify Events
        self.emit('exposed')

    def hide(self):
        if self.x_window:
            self.x_window.destroy()
            # Do a busy wait for X reply
            while 1:
                event = self.x_display.next_event()
                if event.type == Xlib.X.DestroyNotify and \
                        event.window == self.x_window:
                    break
        self.x_window = None

    def show(self):
        if not self.x_window:
            self.create_x_window()

    def organize(self):
        self.show()

    def destroy(self):
        self.hide()
        super(XWindow, self).destroy()

    def key_down(self, key):
        # If a key down event arrives, we send it to the x_window (in
        # fact here we just send it to X and assume that the x window
        # has the focus. I am not sure it is the best way...)
        if not key.key:
            return
        # We need to check the modifiers to simulate the proper key
        # press events
        if key.mod == 1:
            modifier = self.x_display.keysym_to_keycode(Xlib.XK.XK_Shift_L)
        else:
            modifier = None
        keycode = self.x_display.keysym_to_keycode(key.key)
        if modifier:
            Xlib.ext.xtest.fake_input(self.x_display, Xlib.X.KeyPress,
                                      modifier)
            self.x_display.sync()
        Xlib.ext.xtest.fake_input(self.x_display, Xlib.X.KeyPress, keycode)
        self.x_display.sync()
        Xlib.ext.xtest.fake_input(self.x_display, Xlib.X.KeyRelease, keycode)

        if modifier:
            self.x_display.sync()
            Xlib.ext.xtest.fake_input(self.x_display, Xlib.X.KeyRelease,
                                      modifier)
        return True

    def start_app(self, *cmd):
        import subprocess

        self.enable_wm()
        process = subprocess.Popen(*cmd)
        return process

    def enable_wm(self):
        """Make the window automatically swallow every new created X window
        that have root as a parent

        This effectively turns the window into a windows manager.
        """
        # XXX: need to put `watch` method into tichy.mainloop
        import gobject

        logger.info("listening to display socket %s",
                    self.x_display.fileno())
        self.watch = gobject.io_add_watch(self.x_display.fileno(),
                                          gobject.IO_IN,
                                          self._on_x_display_socket_ready)
        self.x_screen.root.change_attributes(
            event_mask=Xlib.X.SubstructureNotifyMask)
        self.x_display.sync()

    def disable_wm(self):
        if self.watch:
            # XXX: need to put `watch` method into tichy.mainloop
            import gobject
            gobject.source_remove(self.watch)
            self.watch = None
            self.x_screen.root.change_attributes(event_mask=Xlib.X.NONE)

    def _on_x_display_socket_ready(self, source, cond):
        logger.debug("display socket ready")
        event = self.x_display.next_event()
        logger.debug("got event: %s", event)
        # We only reparent windows that are child of the root window
        # and that didn't set there overide attribute
        if event.type == Xlib.X.CreateNotify and \
                event.parent == self.x_screen.root and \
                not event.override:
            self._reparent(event.window, event.x, event.y)
        return True

    def _reparent(self, window, x, y):
        window.reparent(self.x_window, x, y)
        window.map()
        self.x_display.sync()
        # TODO: We shouldn't give the focus to this XWindow We
        #       should send the event in the key_down method
        self.x_display.set_input_focus(
            window, Xlib.X.RevertToParent, Xlib.X.CurrentTime)
