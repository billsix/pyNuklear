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


import numpy as np
from enum import Enum
import math

class MatrixStack(Enum):
    model = 1
    view = 2
    projection = 3
    modelview = 4
    modelviewprojection = 5

__modelStack__ = [np.matrix([[1.0,0.0,0.0,0.0],
                             [0.0,1.0,0.0,0.0],
                             [0.0,0.0,1.0,0.0],
                             [0.0,0.0,0.0,1.0]],
                            dtype=np.float32)]

__viewStack__ =  [np.matrix([[1.0,0.0,0.0,0.0],
                             [0.0,1.0,0.0,0.0],
                             [0.0,0.0,1.0,0.0],
                             [0.0,0.0,0.0,1.0]],
                            dtype=np.float32)]

__projectionStack__ =  [np.matrix([[1.0,0.0,0.0,0.0],
                                   [0.0,1.0,0.0,0.0],
                                   [0.0,0.0,1.0,0.0],
                                   [0.0,0.0,0.0,1.0]],
                                  dtype=np.float32)]

# TODO - define push and pop matrix

def getCurrentMatrix(matrixStack):
    if matrixStack == MatrixStack.model :
        return __modelStack__[len(__modelStack__)-1]
    if matrixStack == MatrixStack.view :
        return __viewStack__[len(__viewStack__)-1]
    if matrixStack == MatrixStack.projection :
        return __projectionStack__[len(__projectionStack__)-1]
    if matrixStack == MatrixStack.modelview :
        return np.matmul(__viewStack__[len(__viewStack__) - 1],
                         __modelStack__[len(__modelStack__) -1])
    if matrixStack == MatrixStack.modelviewprojection :
        return np.matmul(__projectionStack__[len(__projectionStack__) - 1],
                         np.matmul(__viewStack__[len(__viewStack__) - 1],
                                   __modelStack__[len(__modelStack__) -1]))

def setCurrentMatrix(matrixStack,m):
    if matrixStack == MatrixStack.model :
        __modelStack__[len(__modelStack__)-1] = m
    if matrixStack == MatrixStack.view :
        __viewStack__[len(__viewStack__)-1] = m
    if matrixStack == MatrixStack.projection :
        __projectionStack__[len(__projectionStack__)-1] = m
    # TODO, figure out how to throw exception, or whatever
    if matrixStack == MatrixStack.modelview :
        pass
    if matrixStack == MatrixStack.modelviewprojection :
        pass


def __pushMatrix__(matrixStack):
    if matrixStack == MatrixStack.model :
        __modelStack__.append(getCurrentMatrix(matrixStack))
    if matrixStack == MatrixStack.view :
        __viewStack__.append(getCurrentMatrix(matrixStack))
    if matrixStack == MatrixStack.projection :
        __projectionStack__.append(getCurrentMatrix(matrixStack))
    if matrixStack == MatrixStack.modelview :
        pass
    if matrixStack == MatrixStack.modelviewprojection :
        pass

def __popMatrix__(matrixStack):
    if matrixStack == MatrixStack.model :
        __modelStack__.pop()
    if matrixStack == MatrixStack.view :
        __viewStack__.pop()
    if matrixStack == MatrixStack.projection :
        __projectionStack__.pop()
    if matrixStack == MatrixStack.modelview :
        pass
    if matrixStack == MatrixStack.modelviewprojection :
        pass


class GLStackProtector():
    def __init__(self, matrixStack):
        self.matrixStack = matrixStack

    def __enter__(self):
        __pushMatrix__(MatrixStack.model)

    def __exit__(self, type, value, traceback):
        __popMatrix__(MatrixStack.model)


def setToIdentityMatrix(m):
    setCurrentMatrix(m, np.matrix([[1.0,0.0,0.0,0.0],
                                   [0.0,1.0,0.0,0.0],
                                   [0.0,0.0,1.0,0.0],
                                   [0.0,0.0,0.0,1.0]],
                                  dtype=np.float32))

def rotateX(matrixStack, rads):
    # Using a normal linear algebra notation, which
    # is row-major, 1-based indexes, the following
    # matrix multiplication shows how to add a rotation
    # to a matrix, along the position X axis.
    #
    # M(1,1) M(1,2) M(1,3) M(1,4)     1   0    0    0
    # M(2,1) M(2,2) M(2,3) M(2,4) *   0   cos  -sin 0
    # M(3,1) M(3,2) M(3,3) M(3,4)     0   sin  cos  0
    # M(4,1) M(4,2) M(4,3) M(4,4)     0   0    0    1

    #   =

    # Rather than keeping both matricies, we can reduce
    # them to one by matrix multiplication
    #
    # M(1,1)  M(1,2)*cos+M(1,3)*sin  M(1,2)*-sin+M(1,3)*cos  M(1,4)
    # M(2,1)  M(2,2)*cos+M(2,3)*sin  M(2,2)*-sin+M(2,3)*cos  M(2,4)
    # M(3,1)  M(3,2)*cos+M(3,3)*sin  M(3,2)*-sin+M(3,3)*cos  M(3,4)
    # M(4,1)  M(4,2)*cos+M(4,3)*sin  M(4,2)*-sin+M(4,3)*cos  M(4,4)

    m = getCurrentMatrix(matrixStack)
    copyOfM = np.copy(m)

    c = math.cos(rads)
    s = math.sin(rads)

    m[0,1] = copyOfM[0,1]*c + copyOfM[0,2]*s
    m[1,1] = copyOfM[1,1]*c + copyOfM[1,2]*s
    m[2,1] = copyOfM[2,1]*c + copyOfM[2,2]*s
    m[3,1] = copyOfM[3,1]*c + copyOfM[3,2]*s

    m[0,2] = copyOfM[0,1]*-s + copyOfM[0,2]*c
    m[1,2] = copyOfM[1,1]*-s + copyOfM[1,2]*c
    m[2,2] = copyOfM[2,1]*-s + copyOfM[2,2]*c
    m[3,2] = copyOfM[3,1]*-s + copyOfM[3,2]*c

def rotateY(matrixStack, rads):
    # Using a normal linear algebra notation, which
    # is row-major, 1-based indexes, the following
    # matrix multiplication shows how to add a rotation
    # to a matrix, along the position Y axis.

    # M(1,1) M(1,2) M(1,3) M(1,4)     cos  0    sin  0
    # M(2,1) M(2,2) M(2,3) M(2,4) *   0    1    0    0
    # M(3,1) M(3,2) M(3,3) M(3,4)     -sin 0    cos  0
    # M(4,1) M(4,2) M(4,3) M(4,4)     0    0    0    1

    # =

    # Rather than keeping both matricies, we can reduce
    # them to one by matrix multiplication
    #
    # M(1,1)*cos+M(1,3)*-sin    M(1,2)     M(1,1)*sin+M(1,3)*cos     M(1,4)
    # M(2,1)*cos+M(2,3)*-sin    M(2,2)     M(2,1)*sin+M(2,3)*cos     M(2,4)
    # M(3,1)*cos+M(3,3)*-sin    M(3,2)     M(3,1)*sin+M(3,3)*cos     M(3,4)
    # M(4,1)*cos+M(4,3)*-sin    M(4,2)     M(4,1)*sin+M(4,3)*cos     M(4,4)

    m = getCurrentMatrix(matrixStack)
    copyOfM = np.copy(m)

    c = math.cos(rads)
    s = math.sin(rads)

    m[0,0] = copyOfM[0,0]*c + copyOfM[0,2]*-s
    m[1,0] = copyOfM[1,0]*c + copyOfM[1,2]*-s
    m[2,0] = copyOfM[2,0]*c + copyOfM[2,2]*-s
    m[3,0] = copyOfM[3,0]*c + copyOfM[3,2]*-s

    m[0,2] = copyOfM[0,0]*s + copyOfM[0,2]*c
    m[1,2] = copyOfM[1,0]*s + copyOfM[1,2]*c
    m[2,2] = copyOfM[2,0]*s + copyOfM[2,2]*c
    m[3,2] = copyOfM[3,0]*s + copyOfM[3,2]*c

def rotateZ(matrixStack, rads):
    # Using a normal linear algebra notation, which
    # is row-major, 1-based indexes, the following
    # matrix multiplication shows how to add a rotation
    # to a matrix, along the position Z axis.
    #
    # M(1,1) M(1,2) M(1,3) M(1,4)     cos -sin 0    0
    # M(2,1) M(2,2) M(2,3) M(2,4) *   sin cos  0    0
    # M(3,1) M(3,2) M(3,3) M(3,4)     0   0    1    0
    # M(4,1) M(4,2) M(4,3) M(4,4)     0   0    0    1

    #   =

    # Rather than keeping both matricies, we can reduce
    # them to one by matrix multiplication
    #
    # M(1,1)*cos+M(1,2)*sin    M(1,1)*-sin+M(1,2)*cos M(1,3) M(1,4)
    # M(2,1)*cos+M(2,2)*sin    M(2,1)*-sin+M(2,2)*cos M(2,3) M(2,4)
    # M(3,1)*cos+M(3,2)*sin    M(3,1)*-sin+M(3,2)*cos M(3,3) M(3,4)
    # M(4,1)*cos+M(4,2)*sin    M(4,1)*-sin+M(4,2)*cos M(4,3) M(4,4)

    m = getCurrentMatrix(matrixStack)
    copyOfM = np.copy(m)

    c = math.cos(rads)
    s = math.sin(rads)

    m[0,0] = copyOfM[0,0]*c + copyOfM[0,1]*s
    m[1,0] = copyOfM[1,0]*c + copyOfM[1,1]*s
    m[2,0] = copyOfM[2,0]*c + copyOfM[2,1]*s
    m[3,0] = copyOfM[3,0]*c + copyOfM[3,1]*s

    m[0,1] = copyOfM[0,0]*-s + copyOfM[0,1]*c
    m[1,1] = copyOfM[1,0]*-s + copyOfM[1,1]*c
    m[2,1] = copyOfM[2,0]*-s + copyOfM[2,1]*c
    m[3,1] = copyOfM[3,0]*-s + copyOfM[3,1]*c


def translate(matrixStack, x, y, z):
    # Using a normal linear algebra notation, which
    # is row-major, 1-based indexes, the following
    # matrix multiplication shows how to add a translation
    # to a matrix.
    #
    # M(1,1) M(1,2) M(1,3) M(1,4)     1 0 0 x
    # M(2,1) M(2,2) M(2,3) M(2,4) *   0 1 0 y
    # M(3,1) M(3,2) M(3,3) M(3,4)     0 0 1 z
    # M(4,1) M(4,2) M(4,3) M(4,4)     0 0 0 1

    #   =

    # Rather than keeping both matricies, we can reduce
    # them to one by matrix multiplication
    #
    # M(1,1) M(1,2) M(1,3) (M(1,1)*x + M(1,2)*y + M(1,3)*z + M(1,4)*w)
    # M(2,1) M(2,2) M(2,3) (M(2,1)*x + M(2,2)*y + M(2,3)*z + M(2,4)*w)
    # M(3,1) M(3,2) M(3,3) (M(3,1)*x + M(3,2)*y + M(3,3)*z + M(3,4)*w)
    # M(4,1) M(4,2) M(4,3) (M(4,1)*x + M(4,2)*y + M(4,3)*z + M(4,4)*w)

    m = getCurrentMatrix(matrixStack)

    m[0,3] = m[0,0]*x + m[0,1]*y + m[0,2]*z + m[0,3]
    m[1,3] = m[1,0]*x + m[1,1]*y + m[1,2]*z + m[1,3]
    m[2,3] = m[2,0]*x + m[2,1]*y + m[2,2]*z + m[2,3]
    m[3,3] = m[3,0]*x + m[3,1]*y + m[3,2]*z + m[3,3]


def scale(matrixStack, x, y, z):
    # Using a normal linear algebra notation, which
    # is row-major, 1-based indexes, the following
    # matrix multiplication shows how to add a translation
    # to a matrix.
    #
    # M(1,1) M(1,2) M(1,3) M(1,4)     x 0 0 0
    # M(2,1) M(2,2) M(2,3) M(2,4) *   0 y 0 0
    # M(3,1) M(3,2) M(3,3) M(3,4)     0 0 z 0
    # M(4,1) M(4,2) M(4,3) M(4,4)     0 0 0 1

    #   =

    # Rather than keeping both matricies, we can reduce
    # them to one by matrix multiplication
    #
    # M(1,1)*x  M(1,2)*y  M(1,3)*z  M(1,4)
    # M(2,1)*x  M(2,2)*y  M(2,3)*z  M(2,4)
    # M(3,1)*x  M(3,2)*y  M(3,3)*z  M(3,4)
    # M(4,1)*x  M(4,2)*y  M(4,3)*z  M(4,4)

    m = getCurrentMatrix(matrixStack)

    m[0,0] = m[0,0]*x
    m[1,0] = m[1,0]*x
    m[2,0] = m[2,0]*x
    m[3,0] = m[3,0]*x

    m[0,1] = m[0,1]*y
    m[1,1] = m[1,1]*y
    m[2,1] = m[2,1]*y
    m[3,1] = m[3,1]*y

    m[0,2] = m[0,2]*z
    m[1,2] = m[1,2]*z
    m[2,2] = m[2,2]*z
    m[3,2] = m[3,2]*z

# ortho projection, like a blueprint diagram for a house.
# depth down the z axis does not affect x and y position
# in screen space.
#
#http://www.songho.ca/opengl/gl_projectionmatrix.html
def ortho(l,r,b,t,n,f):
    dx = r - l
    dy = t - b
    dz = f - n

    rx = -(r + l) / (r - l)
    ry = -(t +b) / (t - b)
    rz = -(f + n) / (f - n)

    __projectionStack__[len(__projectionStack__) - 1] = np.matrix(
        [[2.0/dx,  0.0,     0.0,       rx],
         [0.0,      2.0/dy, 0.0,       ry],
         [0.0,      0.0,    -2.0/dz,   rz],
         [0.0,      0.0,    0.0,       1.0]],
        dtype=np.float32)


# perspective projection, where things further away look smaller
# by shrinking their x and y coordinates.
#
# Camera is at 0,0,0, facing down the negative z axis.
#
# nearZ and farZ are expressed in positive numbers, which is odd,
# because the camera space coordinates will be from -nearZ to -farZ
# on the z axis.

#http://www.songho.ca/opengl/gl_projectionmatrix.html
def perspective(fov, aspectRatio,nearZ, farZ):
    top = nearZ * math.tan(fovy * 3.14159265358979323846 / 360.0)
    right = top * aspectRatio

    __projectionStack__[len(__projectionStack__) - 1] = np.matrix(
        [[nearZ/right, 0.0,         0.0,                         0.0],
         [0.0,         nearZ/top,   0.0,                         0.0],
         [0.0,         0.0,         -(farZ+nearZ)/(farZ-nearZ),  -2*(farZ*nearZ)/(farZ-nearZ)],
         [0.0,         0.0,         -1.0,                        0.0]],
        dtype=np.float32)
