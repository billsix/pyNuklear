# -----------------------------------------------------------------------------
#  GLFW - An OpenGL framework
#  API version: 3.0.1
#  WWW:         http://www.glfw.org/
#  ----------------------------------------------------------------------------
#  Copyright (c) 2002-2006 Marcus Geelnard
#  Copyright (c) 2006-2010 Camilla Berglund
#
#  Python bindings - Copyright (c) 2013 Nicolas P. Rougier
#
#  This software is provided 'as-is', without any express or implied
#  warranty. In no event will the authors be held liable for any damages
#  arising from the use of this software.
#
#  Permission is granted to anyone to use this software for any purpose,
#  including commercial applications, and to alter it and redistribute it
#  freely, subject to the following restrictions:
#
#  1. The origin of this software must not be misrepresented; you must not
#     claim that you wrote the original software. If you use this software
#     in a product, an acknowledgment in the product documentation would
#     be appreciated but is not required.
#
#  2. Altered source versions must be plainly marked as such, and must not
#     be misrepresented as being the original software.
#
#  3. This notice may not be removed or altered from any source
#     distribution.
#
# -----------------------------------------------------------------------------
#
# This short example shows how the GLFW API looks and how easy it is to create
# and a window and OpenGL context with it. There are many more functions than
# those used here, but these are all you need to get started.
#
# -----------------------------------------------------------------------------

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
