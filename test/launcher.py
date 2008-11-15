#!/usr/bin/python -tt
#
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

"""DBus launcher tichy main script

This script will load all the plugins, then start a DBus server
listening that we can use to start any application.

It is still experimental.

To use it, start it (./launcher.py), then use for example dbus-send to
start an application, e.g. :
  dbus-send --session --dest='org.tichy' /Launcher --print-reply \
  org.tichy.Launcher.Launch string:Contacts

Note for neo : We need to remember to set DISPLAY=:0 even when we call
the dbus method !
"""

# This is to make sure that we use the local tichy lib if run from the
# test directory
import sys
sys.path.insert(0, '../')

import dbus
import dbus.service

import logging
logging.basicConfig(
    level=logging.INFO,
    format='%(name)-8s %(levelname)-8s %(message)s')
logger = logging.getLogger('launcher')

# We use the hack described in tichy/gui.py to choose the gui backend
# before importing tichy
tichy_gui_backends = ['etk']

import tichy


class Launcher(dbus.service.Object):
    """Launch applets via DBus call

    example, top launch the Contacts application, using dbus-send :
      dbus-send --session --dest='org.tichy' /Launcher --print-reply \
      org.tichy.Launcher.Launch string:Contacts
    """

    def __init__(self, *args, **kargs):
        super(Launcher, self).__init__(*args, **kargs)
        # The backend painter
        self.painter = tichy.gui.Painter((480, 640))
        # TODO: at least remove the create invocation !
        self.style = tichy.Style.find_by_name("black style").create()

    @dbus.service.method("org.tichy.Launcher", "s")
    def Launch(self, name):
        """Launch a registered tichy application by name"""
        logger.info("launch %s", name)
        for app in tichy.Application.subclasses:
            if app.name == name:
                self._launch(app)
                break

    def _launch(self, app):
        """Actually launch the application"""
        # Since we use one screen per application, we don't need to
        # pass a parent window to the app
        app(None).start()

    @dbus.service.method("org.tichy.Launcher")
    def Quit(self):
        """Quit tichy"""
        logger.info("quit mainloop")
        tichy.mainloop.quit()


if __name__ == '__main__':
    # We import all the modules into the plugin directory
    for plugins_dir in ['plugins', '/usr/share/tichy/plugins',
                        '/usr/tichy/plugins']:
        try:
            logger.info("try to load plugins in %s", plugins_dir)
            tichy.plugins.import_all(plugins_dir)
            break
        except IOError:
            logger.info("failed to load plugins in %s", plugins_dir)

    # We set the default design
    tichy.Service.set_default('Design', 'Default')

    logger.info("start launcher service")
    bus = dbus.SessionBus(mainloop=tichy.mainloop.dbus_loop)
    bus_name = dbus.service.BusName('org.tichy', bus)

    launcher = Launcher(bus, '/Launcher')

    logger.info("starting mainloop")
    tichy.mainloop.run()
    logger.info("quit")