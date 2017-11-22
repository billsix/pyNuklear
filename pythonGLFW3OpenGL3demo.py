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

if __name__ != '__main__':
    sys.exit(1)

import sys
import glfw
import numpy as np
import pyMatrixStack as ms
import ctypes
import OpenGL.GL as gl
import OpenGL.GL.shaders as shaders


glfloat_size = 4

vertices = np.array([-0.6, -0.4, 0,
                     0.6, -0.4, 0,
                     0, 0.6, 0],
                    dtype=np.float32)


def create_object(shader):
    vao = gl.glGenVertexArrays(1)
    gl.glBindVertexArray(vao)

    vbo = gl.glGenBuffers(1)
    gl.glBindBuffer(gl.GL_ARRAY_BUFFER, vbo)

    position = gl.glGetAttribLocation(shader, 'position')
    gl.glEnableVertexAttribArray(position)


    gl.glVertexAttribPointer(position,
                             3,
                             gl.GL_FLOAT,
                             False,
                             0,
                             ctypes.c_void_p(0))

    gl.glBufferData(gl.GL_ARRAY_BUFFER,
                    glfloat_size * 9,
                    vertices,
                    gl.GL_STATIC_DRAW)

    gl.glBindVertexArray(0)

    gl.glDisableVertexAttribArray(position)
    gl.glBindBuffer(gl.GL_ARRAY_BUFFER,0)

    return vao


def on_key(window, key, scancode, action, mods):
    if key == glfw.GLFW_KEY_ESCAPE and action == glfw.GLFW_PRESS:
        glfw.glfwSetWindowShouldClose(window,1)

# Initialize the library
if not glfw.glfwInit():
    sys.exit()

# Create a windowed mode window and its OpenGL context
window = glfw.glfwCreateWindow(640, 480, str.encode("Hello World"), None, None)
if not window:
    glfw.glfwTerminate()
    sys.exit()


glfw.glfwWindowHint(glfw.GLFW_CONTEXT_VERSION_MAJOR,3)
glfw.glfwWindowHint(glfw.GLFW_CONTEXT_VERSION_MINOR,3)
glfw.glfwWindowHint(glfw.GLFW_OPENGL_PROFILE,glfw.GLFW_OPENGL_CORE_PROFILE)

# Make the window's context current
glfw.glfwMakeContextCurrent(window)

# Install a key handler
glfw.glfwSetKeyCallback(window, on_key)
gl.glClearColor(0.0,0.0,0.0,1.0)

gl.glEnable(gl.GL_DEPTH_TEST)
gl.glClearDepth(1.0)
gl.glDepthFunc(gl.GL_LEQUAL)



vertex_shader = """
#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 mvpMatrix;

void main()
{
   gl_Position = mvpMatrix * vec4(position,1.0);
}
"""

fragment_shader = """
#version 330 core

void main()
{
   gl_FragColor = vec4(1.0f,1.0f,1.0f,1.0f);
}
"""

vs = shaders.compileShader(vertex_shader, gl.GL_VERTEX_SHADER)

fs = shaders.compileShader(fragment_shader, gl.GL_FRAGMENT_SHADER)
shader = shaders.compileProgram(vs,fs)

mvpMatrixLoc = gl.glGetUniformLocation(shader,"mvpMatrix")

shaders.glDeleteShader(vs)
shaders.glDeleteShader(fs)

triangleVAO = create_object(shader)


# Loop until the user closes the window
while not glfw.glfwWindowShouldClose(window):
    # Render here
    width, height = glfw.glfwGetFramebufferSize(window)
    gl.glViewport(0, 0, width, height)
    gl.glClear(gl.GL_COLOR_BUFFER_BIT | gl.GL_DEPTH_BUFFER_BIT)

    ms.identity(ms.MatrixStack.model)
    ms.identity(ms.MatrixStack.view)
    ms.identity(ms.MatrixStack.projection)


    # rotate the triangle along the positive z axis
    ms.rotateZ(ms.MatrixStack.model,glfw.glfwGetTime())

    gl.glUseProgram(shader)
    gl.glBindVertexArray(triangleVAO)

    # set the projection matrix to be ortho
    ms.ortho(-1,1,-1,1,-1,1)

    gl.glUniformMatrix4fv(mvpMatrixLoc,
                          1,
                          gl.GL_TRUE,
                          np.ascontiguousarray(ms.getMatrix(ms.MatrixStack.modelviewprojection),
                                               dtype=np.float32))
    gl.glDrawArrays(gl.GL_TRIANGLES,0,3)
    gl.glBindVertexArray(0)



    # Swap front and back buffers
    glfw.glfwSwapBuffers(window)

    # Poll for and process events
    glfw.glfwPollEvents()

glfw.glfwTerminate()
