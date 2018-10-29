# Copyright (c) 2017-2018 William Emerison Six
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.


import os
import ctypes.util
from ctypes import (Structure, POINTER, CFUNCTYPE, byref, c_char_p, c_int, c_short,
                    c_uint, c_double, c_float, c_ushort, c_byte, c_ubyte)
import inspect
import builtins
import OpenGL.GL as gl
import glfw
import pynuklear as nk


GLFW3_DEFAULT = 0
GLFW3_INSTALL_CALLBACKS = 1

print(nk._nuklear)

glfw3_init = nk._nuklear.nk_glfw3_init
glfw3_init.restype = POINTER(nk.Context)
glfw3_init.arglist = [POINTER(glfw._GLFWwindow), c_int]


class FontAtlas(Structure):
    pass


glfw3_font_stash_begin = nk._nuklear.nk_glfw3_font_stash_begin
glfw3_font_stash_begin.arglist = [POINTER(POINTER(FontAtlas))]

glfw3_font_stash_end = nk._nuklear.nk_glfw3_font_stash_end

glfw3_new_frame = nk._nuklear.nk_glfw3_new_frame


glfw3_render_prime = nk._nuklear.nk_glfw3_render
glfw3_render_prime.arglist = [c_int, c_int, c_int]


# wrapper around nukear's render, as it doesn't protect the opengl state
def glfw3_render(antialiasing, vertex_buffer_size=512 * 1024, element_buffer=128 * 1024):
    # save the opengl state
    last_blend_src = gl.glGetIntegerv(gl.GL_BLEND_SRC)
    last_blend_dst = gl.glGetIntegerv(gl.GL_BLEND_DST)
    last_blend_equation_rgb = gl.glGetIntegerv(gl.GL_BLEND_EQUATION_RGB)
    last_blend_equation_alpha = gl.glGetIntegerv(gl.GL_BLEND_EQUATION_ALPHA)
    last_viewport = gl.glGetIntegerv(gl.GL_VIEWPORT)
    last_scissor_box = gl.glGetIntegerv(gl.GL_SCISSOR_BOX)

    last_enable_blend = gl.glIsEnabled(gl.GL_BLEND)
    last_enable_cull_face = gl.glIsEnabled(gl.GL_CULL_FACE)
    last_enable_depth_test = gl.glIsEnabled(gl.GL_DEPTH_TEST)
    last_enable_scissor_test = gl.glIsEnabled(gl.GL_SCISSOR_TEST)

    # render nuklear
    glfw3_render_prime(antialiasing, vertex_buffer_size, element_buffer)

    # restore the opengl state
    gl.glBlendEquationSeparate(last_blend_equation_rgb,
                               last_blend_equation_alpha)
    gl.glBlendFunc(last_blend_src,
                   last_blend_dst)
    if last_enable_blend:
        gl.glEnable(gl.GL_BLEND)
    else:
        gl.glDisable(gl.GL_BLEND)
    if last_enable_cull_face:
        gl.glEnable(gl.GL_CULL_FACE)
    else:
        gl.glDisable(gl.GL_CULL_FACE)
    if last_enable_depth_test:
        gl.glEnable(gl.GL_DEPTH_TEST)
    else:
        gl.glDisable(gl.GL_DEPTH_TEST)
    if last_enable_scissor_test:
        gl.glEnable(gl.GL_SCISSOR_TEST)
    else:
        gl.glDisable(gl.GL_SCISSOR_TEST)
    gl.glViewport(last_viewport[0],
                  last_viewport[1],
                  last_viewport[2],
                  last_viewport[3])
    gl.glScissor(last_scissor_box[0],
                 last_scissor_box[1],
                 last_scissor_box[2],
                 last_scissor_box[3])


# wrapper around nukear's render, as it doesn't protect the opengl state
def glfw3_render_gl2(antialiasing, vertex_buffer_size=512 * 1024, element_buffer=128 * 1024):
    # save the opengl state
    last_program = gl.glGetIntegerv(gl.GL_CURRENT_PROGRAM)
    last_texture = gl.glGetIntegerv(gl.GL_TEXTURE_BINDING_2D)
    last_active_texture = gl.glGetIntegerv(gl.GL_ACTIVE_TEXTURE)
    last_array_buffer = gl.glGetIntegerv(gl.GL_ARRAY_BUFFER_BINDING)
    last_element_array_buffer = gl.glGetIntegerv(
        gl.GL_ELEMENT_ARRAY_BUFFER_BINDING)
    last_vertex_array = gl.glGetIntegerv(gl.GL_VERTEX_ARRAY_BINDING)
    last_blend_src = gl.glGetIntegerv(gl.GL_BLEND_SRC)
    last_blend_dst = gl.glGetIntegerv(gl.GL_BLEND_DST)
    last_blend_equation_rgb = gl.glGetIntegerv(gl.GL_BLEND_EQUATION_RGB)
    last_blend_equation_alpha = gl.glGetIntegerv(gl.GL_BLEND_EQUATION_ALPHA)
    last_viewport = gl.glGetIntegerv(gl.GL_VIEWPORT)
    last_scissor_box = gl.glGetIntegerv(gl.GL_SCISSOR_BOX)

    last_enable_blend = gl.glIsEnabled(gl.GL_BLEND)
    last_enable_cull_face = gl.glIsEnabled(gl.GL_CULL_FACE)
    last_enable_depth_test = gl.glIsEnabled(gl.GL_DEPTH_TEST)
    last_enable_scissor_test = gl.glIsEnabled(gl.GL_SCISSOR_TEST)

    # render nuklear
    glfw3_render_prime(antialiasing, vertex_buffer_size, element_buffer)

    # restore the opengl state
    gl.glUseProgram(last_program)
    gl.glActiveTexture(last_active_texture)
    gl.glBindTexture(gl.GL_TEXTURE_2D,
                     last_texture)
    gl.glBindVertexArray(last_vertex_array)
    gl.glBindBuffer(gl.GL_ARRAY_BUFFER,
                    last_array_buffer)
    gl.glBindBuffer(gl.GL_ELEMENT_ARRAY_BUFFER,
                    last_element_array_buffer)
    gl.glBlendEquationSeparate(last_blend_equation_rgb,
                               last_blend_equation_alpha)
    gl.glBlendFunc(last_blend_src,
                   last_blend_dst)
    if last_enable_blend:
        gl.glEnable(gl.GL_BLEND)
    else:
        gl.glDisable(gl.GL_BLEND)
    if last_enable_cull_face:
        gl.glEnable(gl.GL_CULL_FACE)
    else:
        gl.glDisable(gl.GL_CULL_FACE)
    if last_enable_depth_test:
        gl.glEnable(gl.GL_DEPTH_TEST)
    else:
        gl.glDisable(gl.GL_DEPTH_TEST)
    if last_enable_scissor_test:
        gl.glEnable(gl.GL_SCISSOR_TEST)
    else:
        gl.glDisable(gl.GL_SCISSOR_TEST)
    gl.glViewport(last_viewport[0],
                  last_viewport[1],
                  last_viewport[2],
                  last_viewport[3])
    gl.glScissor(last_scissor_box[0],
                 last_scissor_box[1],
                 last_scissor_box[2],
                 last_scissor_box[3])
