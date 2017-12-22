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
import glfw.glfw as glfw
import pyMatrixStack as ms
import ctypes
import math
import nuklear as nk


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

        with open(os.path.join(pwd, '..', '..', 'shaders', 'triangle.vert'), 'r') as f:
            vs = shaders.compileShader(f.read() , gl.GL_VERTEX_SHADER)

        with open(os.path.join(pwd, '..', '..', 'shaders', 'triangle.frag'), 'r') as f:
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
