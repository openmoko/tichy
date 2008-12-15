#    Tichy
#    copyright 2008 Guillaume Chereau (charlie@openmoko.org)
#
#    This file is part of Tichy.
#
#    Tichy is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    Tichy is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with Tichy.  If not, see <http://www.gnu.org/licenses/>.

__docformat__ = 'reStructuredText'

"""tichy package"""

import sys

from tichy.object import Object
from tasklet import Tasklet, Wait, WaitFirst

from application import Application, Gadget
from service import Service, ServiceUnusable
import plugins

from list import List, ActorList
from text import Text
from tel_number import TelNumber
from item import Item
from actor import Actor
from style import Style
from image import Image
from message import Message
from contact import Contact
from time import Time
from persistance import Persistance

from dialog import Dialog

# All the service we want to use
import phone
import prefs
import notifications
import sound

# XXX: use the same trick than with gui
mainloop = None

def init_gui(backends=None):
    """Initialize tichy gui

    This method will manually set tichy.gui module as the proper gui
    backend.

    This has to be called once before we can import tichy.gui

    :Parameters:
    
    backends : list | str
        backend name or list of backends names that we want to try
    """
    global mainloop
    
    import logging
    logger = logging.getLogger('')

    backends = backends or ['paroli', 'csdl', 'sdl']  # default backends
    if isinstance(backends, str):
        backends = [backends]

    for backend in backends:
        try:
            if backend == 'csdl':
                import guic as gui
            elif backend == 'sdl':
                import guip as gui
            elif backend == 'gtk':
                import guig as gui
            elif backend == 'etk':
                import guie as gui
            elif backend == 'paroli':
                import gui_paroli as gui
            elif backend == 'edje':
                import gui_edje as gui
            logger.info("using backend %s", backend)
        except Exception, e:
            logger.warning("can't use backend %s : %s", backend, e)
            if backend == backends[-1]:
                raise
        else:
            break

    sys.modules['tichy.gui'] = gui
    mainloop = gui.EventsLoop()
