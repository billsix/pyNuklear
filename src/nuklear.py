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
                    c_uint, c_double, c_float, c_ushort)
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
