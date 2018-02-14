#!/usr/bin/env python3
#Copyright (c) 2017-2018 William Emerison Six
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


import sys
import os
import OpenGL.GL as gl
import OpenGL.GL.shaders as shaders
import numpy as np
import glfw.glfw as glfw
import pyMatrixStack as ms
import ctypes
import math

import builtins
pwd = os.path.dirname(os.path.abspath(__file__))
builtins.NUKLEAR_PATH = ctypes.CDLL(os.path.join(pwd, '..', '..', 'contrib', 'nuklear', 'nuklearGLFWOpenGL3.so'))

import nuklear as nk
import nuklearGLFW3 as nkGLFW3
from demoTriangle import *
from demo.overview import *



if __name__ != '__main__':
    sys.exit(1)

# For Development purposes, always run the tests before running the program
RUN_TESTS=True

if RUN_TESTS:
    import doctest
    modules = [ms]
    for m in modules:
        try:
            doctest.testmod(m, raise_on_error=True)
        except Exception:
            print(doctest.testmod(m))
            sys.exit(1)




# Initialize the library
if not glfw.glfwInit():
    sys.exit()

glfw.glfwWindowHint(glfw.GLFW_CONTEXT_VERSION_MAJOR,3)
glfw.glfwWindowHint(glfw.GLFW_CONTEXT_VERSION_MINOR,3)
glfw.glfwWindowHint(glfw.GLFW_OPENGL_PROFILE,glfw.GLFW_OPENGL_CORE_PROFILE)
#for osx
glfw.glfwWindowHint(glfw.GLFW_OPENGL_FORWARD_COMPAT, gl.GL_TRUE)


# Create a windowed mode window and its OpenGL context
window = glfw.glfwCreateWindow(1000, 1000, str.encode("pyNuklear demo - GLFW OpenGL3"), None, None)
if not window:
    glfw.glfwTerminate()
    sys.exit()

# Make the window's context current
glfw.glfwMakeContextCurrent(window)

ctx = nkGLFW3.glfw3_init(window, nkGLFW3.GLFW3_INSTALL_CALLBACKS)
nuklear = nk.NuklearContext(ctx)

fontAtlas = nkGLFW3.FontAtlas()
nkGLFW3.glfw3_font_stash_begin(ctypes.byref(fontAtlas))
nkGLFW3.glfw3_font_stash_end()

# Install a key handler
def on_key(window, key, scancode, action, mods):
    if key == glfw.GLFW_KEY_ESCAPE and action == glfw.GLFW_PRESS:
        glfw.glfwSetWindowShouldClose(window,1)
glfw.glfwSetKeyCallback(window, on_key)


gl.glClearColor(0.1,0.18,0.24,1.0)
gl.glEnable(gl.GL_DEPTH_TEST)
gl.glClearDepth(1.0)
gl.glDepthFunc(gl.GL_LEQUAL)



class Camera:
    def __init__(self):
        self.x = 0.0
        self.y = 0.0
        self.z = 10.0

        self.rotationX = 0.0
        self.rotationY = 0.0

camera = Camera()

triangle = Triangle()
triangle.prepareToRender()

# does python have static local variables?  this declaration is way too far away from use
#property = ctypes.c_int(20)


# Loop until the user closes the window
while not glfw.glfwWindowShouldClose(window):
    # Render here

    # Poll for and process events
    glfw.glfwPollEvents()
    nkGLFW3.glfw3_new_frame()

    width, height = glfw.glfwGetFramebufferSize(window)
    gl.glViewport(0, 0, width, height)
    gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT)

    ms.setToIdentityMatrix(ms.MatrixStack.model)
    ms.setToIdentityMatrix(ms.MatrixStack.view)
    ms.setToIdentityMatrix(ms.MatrixStack.projection)

    # set the projection matrix to be perspective
    ms.perspective(fov= 45.0,
                   aspectRatio= width / height,
                   nearZ= 0.1,
                   farZ= 10000.0)

    # get input from keyboard for camera movement
    if not nuklear.item_is_any_active():
        # set up Camera
        if glfw.glfwGetKey(window, glfw.GLFW_KEY_RIGHT) == glfw.GLFW_PRESS:
            camera.rotationY -= 0.03

        if glfw.glfwGetKey(window, glfw.GLFW_KEY_LEFT) == glfw.GLFW_PRESS:
            camera.rotationY += 0.03

        if glfw.glfwGetKey(window, glfw.GLFW_KEY_UP) == glfw.GLFW_PRESS:
            camera.x -= math.sin(camera.rotationY)
            camera.z -= math.cos(camera.rotationY)

        if glfw.glfwGetKey(window, glfw.GLFW_KEY_DOWN) == glfw.GLFW_PRESS:
            camera.x += math.sin(camera.rotationY)
            camera.z += math.cos(camera.rotationY)

    # move the camera to the correct position, which means
    # updating the view stack
    ms.rotateX(ms.MatrixStack.view,
               camera.rotationX)
    ms.rotateY(ms.MatrixStack.view,
               -camera.rotationY)
    ms.translate(ms.MatrixStack.view,
                 -camera.x,
                 -camera.y,
                 -camera.z)

    # render the models

    triangle.render()

    MAX_VERTEX_BUFFER = 512 * 1024
    MAX_ELEMENT_BUFFER = 128 * 1024


    if(nuklear.begin(title="Demonstration",
                     bounds=nk.Rect(10.0,10.0,230.0,250.0),
                     flags=nk.WINDOW_BORDER
                       |nk.WINDOW_MOVABLE
                       |nk.WINDOW_SCALABLE
                       |nk.WINDOW_MINIMIZABLE
                       |nk.WINDOW_TITLE)):

        nuklear.layout_row_static(height=30.0,
                                  item_width=80,
                                  columns=5)
        if nuklear.button_label(title="button"):
            print('button pressed')

        nuklear.layout_row_dynamic(height=30.0,
                                   columns=2)

        try:
            op
        except Exception:
            op = 0

        if nuklear.option_label(label="easy",
                                active= op == 0): op = 0
        if nuklear.option_label(label="hard",
                                active= op == 1): op = 1

        nuklear.layout_row_dynamic(height=25.0,
                                   columns=1)

        try:
            prop
        except Exception:
            prop = 20

        prop = nuklear.property_int(name="Compression:",
                                    minV=0,
                                    val=prop,
                                    maxV=100,
                                    step=10,
                                    inc_per_pixel=1)

        nuklear.layout_row_dynamic(height=20.0,
                                   columns=1)
        nuklear.label(text="background:",
                      alignment=nk.TEXT_LEFT)

        try:
            background
        except Exception:
            background = nk.ColorF(r=0.10,
                                   g=0.18,
                                   b=0.24,
                                   a=1.0)

        nuklear.layout_row_dynamic(height=25.0,
                                   columns=1)
        if nuklear.combo_begin_color(color=nuklear.rgb_cf(background),
                                     size=nk.Vec2(nuklear.widget_width(),
                                                  400)):
            nuklear.layout_row_dynamic(height=120.0,
                                       columns=1)
            background = nuklear.color_picker(color=background,
                                              format=nk.ColorFormat.RGBA)

            nuklear.layout_row_dynamic(height=25.0,
                                       columns=1)
            background.r = nuklear.propertyf(name="#R:",
                                             minVal=0.0,
                                             val=background.r,
                                             maxVal=1.0,
                                             step=0.01,
                                             inc_per_pixel=0.005)
            background.g = nuklear.propertyf(name="#G:",
                                             minVal=0.0,
                                             val=background.g,
                                             maxVal=1.0,
                                             step=0.01,
                                             inc_per_pixel=0.005)
            background.b = nuklear.propertyf(name="#B:",
                                             minVal=0.0,
                                             val=background.b,
                                             maxVal=1.0,
                                             step=0.01,
                                             inc_per_pixel=0.005)
            background.a = nuklear.propertyf(name="#A:",
                                             minVal=0.0,
                                             val=background.a,
                                             maxVal=1.0,
                                             step=0.01,
                                             inc_per_pixel=0.005)


            gl.glClearColor(background.r,background.g,background.b,background.a)

            nuklear.combo_end()

    nuklear.end()


    overview(nuklear)

    nkGLFW3.glfw3_render(nk.ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER)

    # done with frame, flush and swap buffers
    # Swap front and back buffers
    glfw.glfwSwapBuffers(window)


glfw.glfwTerminate()
