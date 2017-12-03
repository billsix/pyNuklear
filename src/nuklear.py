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

NK_GLFW3_DEFAULT=0
NK_GLFW3_INSTALL_CALLBACKS=1





class NKContext(Structure): pass

nk_glfw3_init             = _nuklear.nk_glfw3_init
nk_glfw3_init.restype     = POINTER(NKContext)
nk_glfw3_init.arglist     = [POINTER(glfw.GLFWwindow), c_int]

class NKFontAtlas(Structure): pass

nk_glfw3_font_stash_begin = _nuklear.nk_glfw3_font_stash_begin
nk_glfw3_font_stash_begin.arglist = [POINTER(POINTER(NKFontAtlas))]

nk_glfw3_font_stash_end = _nuklear.nk_glfw3_font_stash_end

nk_glfw3_new_frame = _nuklear.nk_glfw3_new_frame


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



NK_WINDOW_BORDER            = 1 << 0
NK_WINDOW_MOVABLE           = 1 << 1
NK_WINDOW_SCALABLE          = 1 << 2
NK_WINDOW_CLOSABLE          = 1 << 3
NK_WINDOW_MINIMIZABLE       = 1 << 4
NK_WINDOW_NO_SCROLLBAR      = 1 << 5
NK_WINDOW_TITLE             = 1 << 6
NK_WINDOW_SCROLL_AUTO_HIDE  = 1 << 7
NK_WINDOW_BACKGROUND        = 1 << 8
NK_WINDOW_SCALE_LEFT        = 1 << 9
NK_WINDOW_NO_INPUT          = 1 << 10



nk_begin = _nuklear.nk_begin
nk_begin.arglist = [POINTER(NKContext), c_char_p, NKRect, c_uint]

nk_end            = _nuklear.nk_end
nk_end.arglist    = [POINTER(NKContext)]


NK_ANTI_ALIASING_OFF = 0
NK_ANTI_ALIASING_ON = 1


nk_glfw3_render = _nuklear.nk_glfw3_render
nk_glfw3_render.arglist = [c_int, c_int, c_int]

nk_clear = _nuklear.nk_clear
nk_clear.arglist = [POINTER(NKContext)]

nk_layout_row_static = _nuklear.nk_layout_row_static
nk_layout_row_static.arglist = [POINTER(NKContext), c_float, c_int, c_int]

nk_layout_row_dynamic = _nuklear.nk_layout_row_dynamic
nk_layout_row_dynamic.arglist = [POINTER(NKContext), c_float, c_int]

nk_button_label = _nuklear.nk_button_label
nk_button_label.arglist = [POINTER(NKContext), c_char_p]
nk_button_label.restype     = c_int

nk_option_label = _nuklear.nk_option_label
nk_option_label.arglist = [POINTER(NKContext), c_char_p, c_int]

nk_property_int = _nuklear.nk_property_int
nk_property_int.arglist = [POINTER(NKContext), c_char_p, c_int, c_int, c_int, c_int, c_float]


NK_TEXT_ALIGN_LEFT        = 1
NK_TEXT_ALIGN_CENTERED    = 2
NK_TEXT_ALIGN_RIGHT       = 4
NK_TEXT_ALIGN_TOP         = 8
NK_TEXT_ALIGN_MIDDLE      = 10
NK_TEXT_ALIGN_BOTTOM      = 20

NK_TEXT_LEFT        = NK_TEXT_ALIGN_MIDDLE|NK_TEXT_ALIGN_LEFT
NK_TEXT_CENTERED    = NK_TEXT_ALIGN_MIDDLE|NK_TEXT_ALIGN_CENTERED
NK_TEXT_RIGHT       = NK_TEXT_ALIGN_MIDDLE|NK_TEXT_ALIGN_RIGHT

nk_label = _nuklear.nk_label
nk_label.arglist = [POINTER(NKContext), c_char_p, c_int]

nk_combo_begin_color = _nuklear.nk_combo_begin_color
nk_combo_begin_color.arglist = [POINTER(NKContext), NKColor, NKVec2]
nk_combo_begin_color.restype = c_int

nk_combo_end = _nuklear.nk_combo_end
nk_combo_end.arglist = [POINTER(NKContext)]


NK_RGB = 0
NK_RGBA = 1

nk_color_picker = _nuklear.nk_color_picker
nk_color_picker.arglist = [POINTER(NKContext), NKColor, c_int]
nk_color_picker.restype = NKColor

nk_propertyi = _nuklear.nk_propertyi
nk_propertyi.arglist = [POINTER(NKContext), c_char_p, c_int, c_int, c_int, c_int, c_float]
nk_propertyi.restype = c_int

nk_widget_width = _nuklear.nk_widget_width
nk_widget_width.arglist = [POINTER(NKContext)]
nk_widget_width.restype = c_float

nk_menubar_begin = _nuklear.nk_menubar_begin
nk_menubar_begin.arglist = [POINTER(NKContext)]

nk_menubar_end = _nuklear.nk_menubar_end
nk_menubar_end.arglist = [POINTER(NKContext)]


NK_DYNAMIC = 0
NK_STATIC = 1

nk_layout_row_begin = _nuklear.nk_layout_row_begin
nk_layout_row_begin.arglist = [POINTER(NKContext), c_int, c_float, c_int]

nk_layout_row_push = _nuklear.nk_layout_row_push
nk_layout_row_push.arglist = [POINTER(NKContext), c_float]

nk_menu_begin_label = _nuklear.nk_menu_begin_label
nk_menu_begin_label.arglist = [POINTER(NKContext), c_char_p, c_int, NKVec2]

nk_menu_end = _nuklear.nk_menu_end
nk_menu_end.arglist = [POINTER(NKContext)]

nk_menu_item_label = _nuklear.nk_menu_item_label
nk_menu_item_label.arglist = [POINTER(NKContext), c_char_p, c_int]
nk_menu_item_label.restype = c_int
