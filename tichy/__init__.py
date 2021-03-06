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

from tichy.object import Object
from tasklet import Tasklet, Wait, WaitFirst
import gui

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

# The mainloop is defined here !
# We can use it to access to the timeout_add method
mainloop = gui.EventsLoop()
