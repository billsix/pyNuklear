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
from ctypes import (Structure, POINTER, CFUNCTYPE, byref, c_char_p, c_int, c_short,
                    c_uint, c_double, c_float, c_ushort, c_byte, c_ubyte)
import inspect
import builtins
import glfw.glfw as glfw
import nuklear as nk




GLFW3_DEFAULT=0
GLFW3_INSTALL_CALLBACKS=1


glfw3_init             = nk._nuklear.nk_glfw3_init
glfw3_init.restype     = POINTER(nk.Context)
glfw3_init.arglist     = [POINTER(glfw.GLFWwindow), c_int]

class FontAtlas(Structure):
    _fields_ = [ ('pixel', ctypes.c_void_p),
                 ('tex_width',  c_int),
                 ('tex_height',  c_int),
                 ('permanent',  nk.Allocator),
                 ('temporary',  nk.Allocator),
                 ('custom',  nk.Recti),
                 ('cunsors',  POINTER(nk.Cursor)),
                 ('glyph_count',  c_int),
                 ('glypts',  ctypes.c_void_p), # TODO  POINTER(nk.FontGlyph)),
                 ('default_font',  nk.Font),
                 ('fonts', ctypes.c_void_p), # TODO  POINTER(nk.Font)),
                 ('config', ctypes.c_void_p), # TODO  POINTER(nk.FontConfig )),
                 ('font_num', c_int )]

glfw3_font_stash_begin = nk._nuklear.nk_glfw3_font_stash_begin
glfw3_font_stash_begin.arglist = [POINTER(POINTER(FontAtlas))]

glfw3_font_stash_end = nk._nuklear.nk_glfw3_font_stash_end

glfw3_new_frame = nk._nuklear.nk_glfw3_new_frame



glfw3_render = nk._nuklear.nk_glfw3_render
glfw3_render.arglist = [c_int, c_int, c_int]
