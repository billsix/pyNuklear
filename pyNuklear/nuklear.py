#Copyright (c) 2017 William Emerison Six
#
#Permission is hereby granted, free of charge, to any person obtaining a copy
#of this software and associated documentation files (the "Software"), to deal
#in the Software without restriction, including without limitation the rights
#to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#copies of the Software, and to permit persons to whom the Software is
#furnished to do so, subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all
#copies or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#SOFTWARE.

import os
import ctypes.util
from ctypes import (Structure, POINTER, CFUNCTYPE, byref, c_char_p, c_int,
                    c_uint, c_double, c_float, c_ushort, c_byte, c_ubyte)
import glfw

pwd = os.path.dirname(os.path.abspath(__file__))


# Load it
_nuklear = ctypes.CDLL(os.path.join(pwd, '..', 'contrib', 'nuklear', 'nuklear.so'))

GLFW3_DEFAULT=0
GLFW3_INSTALL_CALLBACKS=1





class NKContext(Structure): pass

glfw3_init             = _nuklear.nk_glfw3_init
glfw3_init.restype     = POINTER(NKContext)
glfw3_init.arglist     = [POINTER(glfw.GLFWwindow), c_int]

class NKFontAtlas(Structure): pass

glfw3_font_stash_begin = _nuklear.nk_glfw3_font_stash_begin
glfw3_font_stash_begin.arglist = [POINTER(POINTER(NKFontAtlas))]

glfw3_font_stash_end = _nuklear.nk_glfw3_font_stash_end

glfw3_new_frame = _nuklear.nk_glfw3_new_frame


class NKColor(Structure):
    _fields_ = [ ('r',  c_ubyte),
                 ('g',  c_ubyte),
                 ('b',  c_ubyte),
                 ('a',  c_ubyte)]

    def __init__(self,r,g,b,a):
        self.r = r
        self.g = g
        self.b = b
        self.a = a

class NKVec2(Structure):
    _fields_ = [ ('x',  c_float),
                 ('y',  c_float)]

    def __init__(self,x,y):
        self.x = x
        self.y = y


class NKRect(Structure):
    _fields_ = [ ('x',  c_float),
                 ('y',  c_float),
                 ('w',  c_float),
                 ('h',  c_float)]

    def __init__(self,x,y,w,h):
        self.x = x
        self.y = y
        self.w = w
        self.h = h



WINDOW_BORDER            = 1 << 0
WINDOW_MOVABLE           = 1 << 1
WINDOW_SCALABLE          = 1 << 2
WINDOW_CLOSABLE          = 1 << 3
WINDOW_MINIMIZABLE       = 1 << 4
WINDOW_NO_SCROLLBAR      = 1 << 5
WINDOW_TITLE             = 1 << 6
WINDOW_SCROLL_AUTO_HIDE  = 1 << 7
WINDOW_BACKGROUND        = 1 << 8
WINDOW_SCALE_LEFT        = 1 << 9
WINDOW_NO_INPUT          = 1 << 10



begin = _nuklear.nk_begin
begin.arglist = [POINTER(NKContext), c_char_p, NKRect, c_uint]

end            = _nuklear.nk_end
end.arglist    = [POINTER(NKContext)]


ANTI_ALIASING_OFF = 0
ANTI_ALIASING_ON = 1


glfw3_render = _nuklear.nk_glfw3_render
glfw3_render.arglist = [c_int, c_int, c_int]

clear = _nuklear.nk_clear
clear.arglist = [POINTER(NKContext)]

layout_row_static = _nuklear.nk_layout_row_static
layout_row_static.arglist = [POINTER(NKContext), c_float, c_int, c_int]

layout_row_dynamic = _nuklear.nk_layout_row_dynamic
layout_row_dynamic.arglist = [POINTER(NKContext), c_float, c_int]

button_label = _nuklear.nk_button_label
button_label.arglist = [POINTER(NKContext), c_char_p]
button_label.restype     = c_int

option_label = _nuklear.nk_option_label
option_label.arglist = [POINTER(NKContext), c_char_p, c_int]

property_int = _nuklear.nk_property_int
property_int.arglist = [POINTER(NKContext), c_char_p, c_int, c_int, c_int, c_int, c_float]


TEXT_ALIGN_LEFT        = 1
TEXT_ALIGN_CENTERED    = 2
TEXT_ALIGN_RIGHT       = 4
TEXT_ALIGN_TOP         = 8
TEXT_ALIGN_MIDDLE      = 10
TEXT_ALIGN_BOTTOM      = 20

TEXT_LEFT        = TEXT_ALIGN_MIDDLE|TEXT_ALIGN_LEFT
TEXT_CENTERED    = TEXT_ALIGN_MIDDLE|TEXT_ALIGN_CENTERED
TEXT_RIGHT       = TEXT_ALIGN_MIDDLE|TEXT_ALIGN_RIGHT

label = _nuklear.nk_label
label.arglist = [POINTER(NKContext), c_char_p, c_int]

combo_begin_color = _nuklear.nk_combo_begin_color
combo_begin_color.arglist = [POINTER(NKContext), NKColor, NKVec2]
combo_begin_color.restype = c_int

combo_end = _nuklear.nk_combo_end
combo_end.arglist = [POINTER(NKContext)]


RGB = 0
RGBA = 1

color_picker = _nuklear.nk_color_picker
color_picker.arglist = [POINTER(NKContext), NKColor, c_int]
color_picker.restype = NKColor

propertyi = _nuklear.nk_propertyi
propertyi.arglist = [POINTER(NKContext), c_char_p, c_int, c_int, c_int, c_int, c_float]
propertyi.restype = c_int

widget_width = _nuklear.nk_widget_width
widget_width.arglist = [POINTER(NKContext)]
widget_width.restype = c_float

menubar_begin = _nuklear.nk_menubar_begin
menubar_begin.arglist = [POINTER(NKContext)]

menubar_end = _nuklear.nk_menubar_end
menubar_end.arglist = [POINTER(NKContext)]


DYNAMIC = 0
STATIC = 1

layout_row_begin = _nuklear.nk_layout_row_begin
layout_row_begin.arglist = [POINTER(NKContext), c_int, c_float, c_int]

layout_row_push = _nuklear.nk_layout_row_push
layout_row_push.arglist = [POINTER(NKContext), c_float]

menu_begin_label = _nuklear.nk_menu_begin_label
menu_begin_label.arglist = [POINTER(NKContext), c_char_p, c_int, NKVec2]

menu_end = _nuklear.nk_menu_end
menu_end.arglist = [POINTER(NKContext)]

menu_item_label = _nuklear.nk_menu_item_label
menu_item_label.arglist = [POINTER(NKContext), c_char_p, c_int]
menu_item_label.restype = c_int

item_is_any_active = _nuklear.nk_item_is_any_active
item_is_any_active.arglist = [POINTER(NKContext)]
item_is_any_active.restype = c_int
