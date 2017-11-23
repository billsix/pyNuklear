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

modelStack = [np.matrix([[1.0,0.0,0.0,0.0],
                         [0.0,1.0,0.0,0.0],
                         [0.0,0.0,1.0,0.0],
                         [0.0,0.0,0.0,1.0]],
                        dtype=np.float32)]

viewStack =  [np.matrix([[1.0,0.0,0.0,0.0],
                         [0.0,1.0,0.0,0.0],
                         [0.0,0.0,1.0,0.0],
                         [0.0,0.0,0.0,1.0]],
                        dtype=np.float32)]

projectionStack =  [np.matrix([[1.0,0.0,0.0,0.0],
                               [0.0,1.0,0.0,0.0],
                               [0.0,0.0,1.0,0.0],
                               [0.0,0.0,0.0,1.0]],
                              dtype=np.float32)]

# TODO - define push and pop matrix

def getCurrentMatrix(matrixStack):
    if matrixStack == MatrixStack.model :
        return modelStack[len(modelStack)-1]
    if matrixStack == MatrixStack.view :
        return  viewStack[len(viewStack)-1]
    if matrixStack == MatrixStack.projection :
        return projectionStack[len(projectionStack)-1]
    if matrixStack == MatrixStack.modelview :
        return np.matmul(viewStack[len(viewStack) - 1],
                         modelStack[len(modelStack) -1])
    if matrixStack == MatrixStack.modelviewprojection :
        return np.matmul(projectionStack[len(projectionStack) - 1],
                         np.matmul(viewStack[len(viewStack) - 1],
                                   modelStack[len(modelStack) -1]))

def setCurrentMatrix(matrixStack,m):
    if matrixStack == MatrixStack.model :
        modelStack[len(modelStack)-1] = m
    if matrixStack == MatrixStack.view :
        viewStack[len(viewStack)-1] = m
    if matrixStack == MatrixStack.projection :
        projectionStack[len(projectionStack)-1] = m
    # TODO, figure out how to throw exception, or whatever
    if matrixStack == MatrixStack.modelview :
        pass
    if matrixStack == MatrixStack.modelviewprojection :
        pass


def setToIdentityMatrix(ms):
    setCurrentMatrix(ms, np.matrix([[1.0,0.0,0.0,0.0],
                                    [0.0,1.0,0.0,0.0],
                                    [0.0,0.0,1.0,0.0],
                                    [0.0,0.0,0.0,1.0]],
                                   dtype=np.float32))

def rotateX(matrixStack, rads):
    # M(1,1) M(1,2) M(1,3) M(1,4)     1   0    0    0
    # M(2,1) M(2,2) M(2,3) M(2,4) *   0   cos  -sin 0
    # M(3,1) M(3,2) M(3,3) M(3,4)     0   sin  cos  0
    # M(4,1) M(4,2) M(4,3) M(4,4)     0   0    0    1

    #   =

    # M(1,1)  M(1,2)*cos+M(1,3)*sin  M(1,2)*-sin+M(1,3)*cos  M(1,4)
    # M(2,1)  M(2,2)*cos+M(2,3)*sin  M(2,2)*-sin+M(2,3)*cos  M(2,4)
    # M(3,1)  M(3,2)*cos+M(3,3)*sin  M(3,2)*-sin+M(3,3)*cos  M(3,4)
    # M(4,1)  M(4,2)*cos+M(4,3)*sin  M(4,2)*-sin+M(4,3)*cos  M(4,4)

    ms = getCurrentMatrix(matrixStack)
    currentMatrixCopy = np.copy(ms)

    c = math.cos(rads)
    s = math.sin(rads)

    ms[0,1] = currentMatrixCopy[0,1]*c + currentMatrixCopy[0,2]*s
    ms[1,1] = currentMatrixCopy[1,1]*c + currentMatrixCopy[1,2]*s
    ms[2,1] = currentMatrixCopy[2,1]*c + currentMatrixCopy[2,2]*s
    ms[3,1] = currentMatrixCopy[3,1]*c + currentMatrixCopy[3,2]*s

    ms[0,2] = currentMatrixCopy[0,1]*-s + currentMatrixCopy[0,2]*c
    ms[1,2] = currentMatrixCopy[1,1]*-s + currentMatrixCopy[1,2]*c
    ms[2,2] = currentMatrixCopy[2,1]*-s + currentMatrixCopy[2,2]*c
    ms[3,2] = currentMatrixCopy[3,1]*-s + currentMatrixCopy[3,2]*c

def rotateY(matrixStack, rads):
    # M(1,1) M(1,2) M(1,3) M(1,4)     cos  0    sin  0
    # M(2,1) M(2,2) M(2,3) M(2,4) *   0    1    0    0
    # M(3,1) M(3,2) M(3,3) M(3,4)     -sin 0    cos  0
    # M(4,1) M(4,2) M(4,3) M(4,4)     0    0    0    1

    # =

    # M(1,1)*cos+M(1,3)*-sin    M(1,2)     M(1,1)*sin+M(1,3)*cos     M(1,4)
    # M(2,1)*cos+M(2,3)*-sin    M(2,2)     M(2,1)*sin+M(2,3)*cos     M(2,4)
    # M(3,1)*cos+M(3,3)*-sin    M(3,2)     M(3,1)*sin+M(3,3)*cos     M(3,4)
    # M(4,1)*cos+M(4,3)*-sin    M(4,2)     M(4,1)*sin+M(4,3)*cos     M(4,4)

    ms = getCurrentMatrix(matrixStack)
    currentMatrixCopy = np.copy(ms)

    c = math.cos(rads)
    s = math.sin(rads)

    ms[0,0] = currentMatrixCopy[0,0]*c + currentMatrixCopy[0,2]*-s
    ms[1,0] = currentMatrixCopy[1,0]*c + currentMatrixCopy[1,2]*-s
    ms[2,0] = currentMatrixCopy[2,0]*c + currentMatrixCopy[2,2]*-s
    ms[3,0] = currentMatrixCopy[3,0]*c + currentMatrixCopy[3,2]*-s

    ms[0,2] = currentMatrixCopy[0,0]*s + currentMatrixCopy[0,2]*c
    ms[1,2] = currentMatrixCopy[1,0]*s + currentMatrixCopy[1,2]*c
    ms[2,2] = currentMatrixCopy[2,0]*s + currentMatrixCopy[2,2]*c
    ms[3,2] = currentMatrixCopy[3,0]*s + currentMatrixCopy[3,2]*c

def rotateZ(matrixStack, rads):
    # M(1,1) M(1,2) M(1,3) M(1,4)     cos -sin 0    0
    # M(2,1) M(2,2) M(2,3) M(2,4) *   sin cos  0    0
    # M(3,1) M(3,2) M(3,3) M(3,4)     0   0    1    0
    # M(4,1) M(4,2) M(4,3) M(4,4)     0   0    0    1

    #   =

    # M(1,1)*cos+M(1,2)*sin    M(1,1)*-sin+M(1,2)*cos M(1,3) M(1,4)
    # M(2,1)*cos+M(2,2)*sin    M(2,1)*-sin+M(2,2)*cos M(2,3) M(2,4)
    # M(3,1)*cos+M(3,2)*sin    M(3,1)*-sin+M(3,2)*cos M(3,3) M(3,4)
    # M(4,1)*cos+M(4,2)*sin    M(4,1)*-sin+M(4,2)*cos M(4,3) M(4,4)

    ms = getCurrentMatrix(matrixStack)
    currentMatrixCopy = np.copy(ms)

    c = math.cos(rads)
    s = math.sin(rads)

    ms[0,0] = currentMatrixCopy[0,0]*c + currentMatrixCopy[0,1]*s
    ms[1,0] = currentMatrixCopy[1,0]*c + currentMatrixCopy[1,1]*s
    ms[2,0] = currentMatrixCopy[2,0]*c + currentMatrixCopy[2,1]*s
    ms[3,0] = currentMatrixCopy[3,0]*c + currentMatrixCopy[3,1]*s

    ms[0,1] = currentMatrixCopy[0,0]*-s + currentMatrixCopy[0,1]*c
    ms[1,1] = currentMatrixCopy[1,0]*-s + currentMatrixCopy[1,1]*c
    ms[2,1] = currentMatrixCopy[2,0]*-s + currentMatrixCopy[2,1]*c
    ms[3,1] = currentMatrixCopy[3,0]*-s + currentMatrixCopy[3,1]*c


def translate(matrixStack, x, y, z):
    # M(1,1) M(1,2) M(1,3) M(1,4)     1 0 0 x
    # M(2,1) M(2,2) M(2,3) M(2,4) *   0 1 0 y
    # M(3,1) M(3,2) M(3,3) M(3,4)     0 0 1 z
    # M(4,1) M(4,2) M(4,3) M(4,4)     0 0 0 1

    #   =

    # M(1,1) M(1,2) M(1,3) (M(1,1)*x + M(1,2)*y + M(1,3)*z + M(1,4)*w)
    # M(2,1) M(2,2) M(2,3) (M(2,1)*x + M(2,2)*y + M(2,3)*z + M(2,4)*w)
    # M(3,1) M(3,2) M(3,3) (M(3,1)*x + M(3,2)*y + M(3,3)*z + M(3,4)*w)
    # M(4,1) M(4,2) M(4,3) (M(4,1)*x + M(4,2)*y + M(4,3)*z + M(4,4)*w)

    ms = getCurrentMatrix(matrixStack)

    ms[0,3] = ms[0,0]*x + ms[0,1]*y + ms[0,2]*z + ms[0,3]
    ms[1,3] = ms[1,0]*x + ms[1,1]*y + ms[1,2]*z + ms[1,3]
    ms[2,3] = ms[2,0]*x + ms[2,1]*y + ms[2,2]*z + ms[2,3]
    ms[3,3] = ms[3,0]*x + ms[3,1]*y + ms[3,2]*z + ms[3,3]


#matrix operations
#http://www.songho.ca/opengl/gl_projectionmatrix.html
def ortho(l,r,b,t,n,f):
    dx = r - l
    dy = t - b
    dz = f - n

    rx = -(r + l) / (r - l)
    ry = -(t +b) / (t - b)
    rz = -(f + n) / (f - n)

    projectionStack[len(projectionStack) - 1] = np.matrix([[2.0/dx,  0.0,     0.0,       rx],
                                                           [0.0,      2.0/dy, 0.0,       ry],
                                                           [0.0,      0.0,    -2.0/dz,   rz],
                                                           [0.0,      0.0,    0.0,       1.0]],
                                                          dtype=np.float32)
