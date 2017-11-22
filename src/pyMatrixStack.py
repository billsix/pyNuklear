#  Copyright (c) 2017 William Emerison Six
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

def getMatrix(matrixStack):
    if matrixStack == MatrixStack.model :
        return modelStack
    if matrixStack == MatrixStack.view :
        return  viewStack
    if matrixStack == MatrixStack.projection :
        return projectionStack
    if matrixStack == MatrixStack.modelview :
        return np.matmul(viewStack[len(viewStack) - 1],
                         modelStack[len(modelStack) -1])
    if matrixStack == MatrixStack.modelviewprojection :
        return np.matmul(projectionStack[len(projectionStack) - 1],
                         np.matmul(viewStack[len(viewStack) - 1],
                                   modelStack[len(modelStack) -1]))


def identity(ms):
    ms = getMatrix(ms)
    ms[len(ms)-1] = np.matrix([[1.0,0.0,0.0,0.0],
                               [0.0,1.0,0.0,0.0],
                               [0.0,0.0,1.0,0.0],
                               [0.0,0.0,0.0,1.0]],
                              dtype=np.float32)

def rotateZ(matrixStack, rads):
    ms = getMatrix(matrixStack)
    topOfStack = ms[len(ms)-1]
    topOfStackCopy = np.copy(topOfStack)

    c = math.cos(rads)
    s = math.sin(rads)

    topOfStack[0,0] = topOfStackCopy[0,0]*c + topOfStackCopy[0,1]*s
    topOfStack[1,0] = topOfStackCopy[1,0]*c + topOfStackCopy[1,1]*s
    topOfStack[2,0] = topOfStackCopy[2,0]*c + topOfStackCopy[2,1]*s
    topOfStack[3,0] = topOfStackCopy[3,0]*c + topOfStackCopy[3,1]*s

    topOfStack[0,1] = topOfStackCopy[0,0]*-s + topOfStackCopy[0,1]*c
    topOfStack[1,1] = topOfStackCopy[1,0]*-s + topOfStackCopy[1,1]*c
    topOfStack[2,1] = topOfStackCopy[2,0]*-s + topOfStackCopy[2,1]*c
    topOfStack[3,1] = topOfStackCopy[3,0]*-s + topOfStackCopy[3,1]*c


#matrix operations
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
