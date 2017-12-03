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


import sys
import os
import OpenGL.GL as gl
import OpenGL.GL.shaders as shaders
import numpy as np
import glfw
import pyMatrixStack as ms
import ctypes
import math
import nuklear

if __name__ != '__main__':
    sys.exit(1)

pwd = os.path.dirname(os.path.abspath(__file__))

glfloat_size = 4

floatsPerVertex = 3

class Triangle:
    def __init__(self):
        pass

    def prepareToRender(self):
        vertices = np.array([-0.6,  -0.4,  0.0,
                             0.6,   -0.4,  0.0,
                             0,     0.6,   0.0],
                            dtype=np.float32)

        self.numberOfVertices = np.size(vertices) // floatsPerVertex


        self.vao = gl.glGenVertexArrays(1)
        gl.glBindVertexArray(self.vao)

        #initialize shaders

        with open(os.path.join(pwd, '..', 'shaders', 'triangle.vert'), 'r') as f:
            vs = shaders.compileShader(f.read() , gl.GL_VERTEX_SHADER)

        with open(os.path.join(pwd, '..', 'shaders', 'triangle.frag'), 'r') as f:
            fs = shaders.compileShader(f.read(), gl.GL_FRAGMENT_SHADER)

        self.shader = shaders.compileProgram(vs,fs)

        self.mvpMatrixLoc = gl.glGetUniformLocation(self.shader,"mvpMatrix")

        #send the modelspace data to the GPU
        vbo = gl.glGenBuffers(1)
        gl.glBindBuffer(gl.GL_ARRAY_BUFFER, vbo)

        position = gl.glGetAttribLocation(self.shader, 'position')
        gl.glEnableVertexAttribArray(position)

        gl.glVertexAttribPointer(position,
                                 floatsPerVertex,
                                 gl.GL_FLOAT,
                                 False,
                                 0,
                                 ctypes.c_void_p(0))

        gl.glBufferData(gl.GL_ARRAY_BUFFER,
                        glfloat_size * np.size(vertices),
                        vertices,
                        gl.GL_STATIC_DRAW)

        # reset VAO/VBO to default
        gl.glBindVertexArray(0)
        gl.glBindBuffer(gl.GL_ARRAY_BUFFER,0)


    def render(self):
        with ms.GLStackProtector(ms.MatrixStack.model):
            # rotate the triangle along the positive z axis
            ms.translate(ms.MatrixStack.model,
                         math.sin(glfw.glfwGetTime()),
                         0,
                         0)
            ms.rotateZ(ms.MatrixStack.model,glfw.glfwGetTime())

            gl.glUseProgram(self.shader)
            gl.glBindVertexArray(self.vao)


            gl.glUniformMatrix4fv(self.mvpMatrixLoc,
                                  1,
                                  gl.GL_TRUE,
                                  np.ascontiguousarray(
                                      ms.getCurrentMatrix(ms.MatrixStack.modelviewprojection),
                                      dtype=np.float32))
            gl.glDrawArrays(gl.GL_TRIANGLES,
                            0,
                            self.numberOfVertices)
            gl.glBindVertexArray(0)



# Initialize the library
if not glfw.glfwInit():
    sys.exit()

glfw.glfwWindowHint(glfw.GLFW_CONTEXT_VERSION_MAJOR,3)
glfw.glfwWindowHint(glfw.GLFW_CONTEXT_VERSION_MINOR,3)
glfw.glfwWindowHint(glfw.GLFW_OPENGL_PROFILE,glfw.GLFW_OPENGL_CORE_PROFILE)
#for osx
glfw.glfwWindowHint(glfw.GLFW_OPENGL_FORWARD_COMPAT, gl.GL_TRUE);


# Create a windowed mode window and its OpenGL context
window = glfw.glfwCreateWindow(640, 480, str.encode("Hello World"), None, None)
if not window:
    glfw.glfwTerminate()
    sys.exit()

# Make the window's context current
glfw.glfwMakeContextCurrent(window)

ctx = nuklear.nk_glfw3_init(window, nuklear.NK_GLFW3_DEFAULT)

fontAtlas = nuklear.NKFontAtlas()
nuklear.nk_glfw3_font_stash_begin(ctypes.byref(fontAtlas))
nuklear.nk_glfw3_font_stash_end()

# Install a key handler
def on_key(window, key, scancode, action, mods):
    if key == glfw.GLFW_KEY_ESCAPE and action == glfw.GLFW_PRESS:
        glfw.glfwSetWindowShouldClose(window,1)
glfw.glfwSetKeyCallback(window, on_key)

gl.glClearColor(0.0,0.0,0.0,1.0)
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
    nuklear.nk_glfw3_new_frame()

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


    if(nuklear.nk_begin(ctx,
                        b'Demonstration',
                        nuklear.NKRect(50.0,50.0,230.0,250.0),
                        nuklear.NK_WINDOW_BORDER
                           |nuklear.NK_WINDOW_MOVABLE
                           |nuklear.NK_WINDOW_SCALABLE
                           |nuklear.NK_WINDOW_MINIMIZABLE
                           |nuklear.NK_WINDOW_TITLE)):

        nuklear.nk_layout_row_static(ctx, ctypes.c_float(30.0), 80, 5)
        if nuklear.nk_button_label(ctx, b'button'):
            print('button pressed')

        nuklear.nk_layout_row_dynamic(ctx, ctypes.c_float(30.0), 2)

        # simulate a local static variable
        try:
            op
        except Exception:
            op = 0

        if nuklear.nk_option_label(ctx, b'easy', op == 0): op = 0
        if nuklear.nk_option_label(ctx, b'hard', op == 1): op = 1

        nuklear.nk_layout_row_dynamic(ctx, ctypes.c_float(25.0), 1)

        # simulate a local static variable
        try:
            prop
        except Exception:
            prop = ctypes.c_int(20)


        nuklear.nk_property_int(ctx, b'Compression:', 0, ctypes.byref(prop), 100, 10, 1);

        nuklear.nk_layout_row_dynamic(ctx, ctypes.c_float(20.0), 1)
        nuklear.nk_label(ctx, b'background:', nuklear.NK_TEXT_LEFT)



        # simulate a local static variable
        try:
            background
        except Exception:
            background = nuklear.NKColor(0, 0, 0, 255)



        nuklear.nk_layout_row_dynamic(ctx, ctypes.c_float(25.0), 1)

        if nuklear.nk_combo_begin_color(ctx,
                                        background,
                                        nuklear.NKVec2(nuklear.nk_widget_width(ctx),
                                                       400)):
            nuklear.nk_layout_row_dynamic(ctx, ctypes.c_float(120.0), 1);
            background = nuklear.nk_color_picker(ctx,
                                                 background,
                                                 nuklear.NK_RGBA)

            nuklear.nk_layout_row_dynamic(ctx, ctypes.c_float(25.0), 1);
            background.r = nuklear.nk_propertyi(ctx, b'#R:', 0, background.r, 255, 1, ctypes.c_float(1))
            background.g = nuklear.nk_propertyi(ctx, b'#G:', 0, background.g, 255, 1, ctypes.c_float(1))
            background.b = nuklear.nk_propertyi(ctx, b'#B:', 0, background.b, 255, 1, ctypes.c_float(1))
            background.a = nuklear.nk_propertyi(ctx, b'#A:', 0, background.a, 255, 1, ctypes.c_float(1))


            gl.glClearColor(background.r/255,background.g/255,background.b/255,background.a/255)

            nuklear.nk_combo_end(ctx);

    nuklear.nk_end(ctx)

    nuklear.nk_glfw3_render(nuklear.NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER)

    # done with frame, flush and swap buffers
    # Swap front and back buffers
    glfw.glfwSwapBuffers(window)


glfw.glfwTerminate()
