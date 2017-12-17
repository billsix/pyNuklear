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
import nuklear as nk

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
window = glfw.glfwCreateWindow(1000, 1000, str.encode("Hello World"), None, None)
if not window:
    glfw.glfwTerminate()
    sys.exit()

# Make the window's context current
glfw.glfwMakeContextCurrent(window)

ctx = nk.glfw3_init(window, nk.GLFW3_INSTALL_CALLBACKS)

fontAtlas = nk.FontAtlas()
nk.glfw3_font_stash_begin(ctypes.byref(fontAtlas))
nk.glfw3_font_stash_end()

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
    nk.glfw3_new_frame()

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
    if not nk.item_is_any_active(ctx):
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


    if(nk.begin(ctx=ctx,
                title="Demonstration",
                bounds=nk.Rect(10.0,10.0,230.0,250.0),
                flags=nk.WINDOW_BORDER
                        |nk.WINDOW_MOVABLE
                        |nk.WINDOW_SCALABLE
                        |nk.WINDOW_MINIMIZABLE
                        |nk.WINDOW_TITLE)):

        nk.layout_row_static(ctx, 30.0, 80, 5)
        if nk.button_label(ctx=ctx,
                           title="button"):
            print('button pressed')

        nk.layout_row_dynamic(ctx, 30.0, 2)

        # simulate a local static variable
        try:
            op
        except Exception:
            op = 0

        if nk.option_label(ctx=ctx,
                           label="easy",
                           active= op == 0): op = 0
        if nk.option_label(ctx=ctx,
                           label="hard",
                           active= op == 1): op = 1

        nk.layout_row_dynamic(ctx, 25.0, 1)

        # simulate a local static variable
        try:
            prop
        except Exception:
            prop = 20


        prop = nk.property_int(ctx=ctx,
                               name="Compression:",
                               minV=0,
                               val=prop,
                               maxV=100,
                               step=10,
                               inc_per_pixel=1);

        nk.layout_row_dynamic(ctx, 20.0, 1)
        nk.label(ctx=ctx,
                 text="background:",
                 alignment=nk.TEXT_LEFT)



        # simulate a local static variable
        try:
            background
        except Exception:
            background = nk.Color(0, 0, 0, 255)



        nk.layout_row_dynamic(ctx, 25.0, 1)

        if nk.combo_begin_color(ctx,
                                        background,
                                        nk.Vec2(nk.widget_width(ctx),
                                                       400)):
            nk.layout_row_dynamic(ctx, 120.0, 1);
            background = nk.color_picker(ctx,
                                                 background,
                                                 nk.RGBA)

            nk.layout_row_dynamic(ctx, 25.0, 1);
            background.r = nk.propertyi(ctx=ctx,
                                        name="#R:",
                                        minVal=0,
                                        val=background.r,
                                        maxVal=255,
                                        step=1,
                                        inc_per_pixel=1.0)
            background.g = nk.propertyi(ctx=ctx,
                                        name="#G:",
                                        minVal=0,
                                        val=background.g,
                                        maxVal=255,
                                        step=1,
                                        inc_per_pixel=1.0)
            background.b = nk.propertyi(ctx=ctx,
                                        name="#B:",
                                        minVal=0,
                                        val=background.b,
                                        maxVal=255,
                                        step=1,
                                        inc_per_pixel=1.0)
            background.a = nk.propertyi(ctx=ctx,
                                        name="#A:",
                                        minVal=0,
                                        val=background.a,
                                        maxVal=255,
                                        step=1,
                                        inc_per_pixel=1.0)


            gl.glClearColor(background.r/255,background.g/255,background.b/255,background.a/255)

            nk.combo_end(ctx);

    nk.end(ctx)



    # show overview

    # simulate a local static variable
    try:
        show_menu
    except Exception:
        show_menu = True
    try:
        titlebar
    except Exception:
        titlebar  = True
    try:
        border
    except Exception:
        border = True
    try:
        resize
    except Exception:
        resize = True
    try:
        movable
    except Exception:
        movable = True
    try:
        no_scrollbar
    except Exception:
        no_scrollbar = False
    try:
        scale_left
    except Exception:
        scale_left = False
    try:
        minimizable
    except Exception:
        minimizable = True



    window_flags = 0
    #TODO -- map the ctx struct

    #ctx->style.window.header.align = header_align;

    if(border) : window_flags |= nk.WINDOW_BORDER
    if(resize) : window_flags |= nk.WINDOW_SCALABLE
    if(movable) : window_flags |= nk.WINDOW_MOVABLE
    if(no_scrollbar) : window_flags |= nk.WINDOW_NO_SCROLLBAR
    if(scale_left) : window_flags |= nk.WINDOW_SCALE_LEFT
    if(minimizable) : window_flags |= nk.WINDOW_MINIMIZABLE


    if nk.begin(ctx=ctx,
                title="Overview",
                bounds=nk.Rect(10,300,400,600),
                flags=window_flags):
        if show_menu:
            try:
                mprog
            except Exception:
                mprog = 60
            try:
                mslider
            except Exception:
                mslider = 10
            try:
                mcheck
            except Exception:
                mcheck = False

            try:
                show_app_about
            except Exception:
                show_app_about = False

            nk.menubar_begin(ctx)
            nk.layout_row_begin(ctx, nk.STATIC, ctypes.c_float(25.0),5)
            nk.layout_row_push(ctx, ctypes.c_float(45.0))
            if nk.menu_begin_label(ctx=ctx,
                                   text="MENU",
                                   align=nk.TEXT_LEFT,
                                   size=nk.Vec2(120,120)):
                nk.layout_row_dynamic(ctx, 25.0, 1)
                if nk.menu_item_label(ctx=ctx,
                                      label="Hide",
                                      align=nk.TEXT_LEFT):
                    show_menu = False
                if nk.menu_item_label(ctx=ctx,
                                      label="About",
                                      align=nk.TEXT_LEFT):
                    show_app_about = True
                (mprog,_) = nk.progress(ctx, mprog, 100, nk.MODIFIABLE)
                (mslider,_) = nk.slider_int(ctx, 0, mslider, 16, 1)
                # TODO, for some reason, this checkbox is not showing.
                # if i move it up 2 lines, it does, and another widget
                # is not showing
                (mcheck,_) = nk.checkbox_label(ctx=ctx,
                                               text="check",
                                               active=mcheck)



                nk.menu_end(ctx)
            nk.layout_row_push(ctx, ctypes.c_float(60.0))
            if nk.menu_begin_label(ctx=ctx,
                                   text="Advanced",
                                   align=nk.TEXT_LEFT,
                                   size=nk.Vec2(200,600)):
                # TODO -- do the advanced menu

                nk.menu_end(ctx)

            nk.layout_row_push(ctx, ctypes.c_float(70.0));
            (mprog, _) = nk.progress(ctx, mprog, 100, nk.MODIFIABLE)
            (mslider,_) = nk.slider_int(ctx, 0, mslider, 16, 1)
            (mcheck,_) = nk.checkbox_label(ctx=ctx,
                                           text="check",
                                           active=mcheck)

            nk.menubar_end(ctx)

            if show_app_about:
                if nk.popup_begin(ctx=ctx,
                                  theType=nk.POPUP_STATIC,
                                  title="About",
                                  flags=nk.WINDOW_CLOSABLE,
                                  rect=nk.Rect(20,100,300,190)):
                    nk.layout_row_dynamic(ctx, 20.0, 1)
                    nk.label(ctx=ctx,
                             text="Nuklear",
                             alignment=nk.TEXT_LEFT)
                    nk.label(ctx=ctx,
                             text="By Micha Mettke",
                             alignment=nk.TEXT_LEFT)
                    nk.label(ctx=ctx,
                             text="nuklear is licensed under the public domain License.",
                             alignment=nk.TEXT_LEFT)

                    nk.popup_end(ctx)
                else:
                    show_app_about = False
            if nk.tree_push(ctx=ctx,
                            theType=nk.TREE_TAB,
                            title="Window",
                            state=nk.MINIMIZED) :
                nk.layout_row_dynamic(ctx, 30.0, 2);
                (titlebar,_) = nk.checkbox_label(ctx=ctx,
                                                 text="Titlebar",
                                                 active=titlebar);
                (show_menu,_) = nk.checkbox_label(ctx=ctx,
                                                  text="Menu",
                                                  active=show_menu);
                (border,_) = nk.checkbox_label(ctx=ctx,
                                               text="Border",
                                               active=border);
                (resize,_) = nk.checkbox_label(ctx=ctx,
                                               text="Resizable",
                                               active=resize);
                (movable,_) = nk.checkbox_label(ctx=ctx,
                                                text="Movable",
                                                active=movable);
                (no_scrollbar,_) = nk.checkbox_label(ctx=ctx,
                                                     text="No Scrollbar",
                                                     active=no_scrollbar);
                (minimizable,_) = nk.checkbox_label(ctx=ctx,
                                                    text="Minimizable",
                                                    active=minimizable);
                (scale_left,_) = nk.checkbox_label(ctx=ctx,
                                                   text="Scale Left",
                                                   active=scale_left);
                nk.tree_pop(ctx);
            if nk.tree_push(ctx=ctx,
                            theType=nk.TREE_TAB,
                            title="Widgets",
                            state=nk.MINIMIZED) :
                if nk.tree_push(ctx=ctx,
                                theType=nk.TREE_NODE,
                                title="Text",
                                state=nk.MINIMIZED) :
                    nk.layout_row_dynamic(ctx, 20.0 ,1)
                    nk.label(ctx=ctx,
                             text="Label aligned left",
                             alignment=nk.TEXT_LEFT)
                    nk.label(ctx=ctx,
                             text="Label aligned centered",
                             alignment=nk.TEXT_CENTERED)
                    # TODO - why doesn't text_right work, but text_align_right does?
                    nk.label(ctx=ctx,
                             text="Label aligned right",
                             alignment=nk.TEXT_ALIGN_RIGHT)
                    nk.label_colored(ctx=ctx,
                                     text="Blue text",
                                     align=nk.TEXT_LEFT,
                                     color=nk.Color(0,0,255,255))
                    nk.label_colored(ctx=ctx,
                                     text="Yellow text",
                                     align=nk.TEXT_LEFT,
                                     color=nk.Color(255,255,0,255))
                    nk.text(ctx=ctx,
                            text="Text without /0",
                            length=15,
                            alignment=nk.TEXT_ALIGN_RIGHT)
                    nk.layout_row_static(ctx, 100.0, 200, 1)
                    nk.label_wrap(ctx=ctx,
                                  text="This is a very long line to hopefully get this text to be wrapped into multiple lines to show line wrapping")
                    nk.layout_row_dynamic(ctx, 100.0, 1);
                    nk.label_wrap(ctx=ctx,
                                  text="This is another long text to show dynamic window changes on multiline text")

                    nk.tree_pop(ctx)
                if nk.tree_push(ctx=ctx,
                                theType=nk.TREE_NODE,
                                title="Button",
                                state=nk.MINIMIZED) :
                    nk.tree_pop(ctx)
                if nk.tree_push(ctx=ctx,
                                theType=nk.TREE_NODE,
                                title="Basic",
                                state=nk.MINIMIZED) :
                    nk.tree_pop(ctx)
                if nk.tree_push(ctx=ctx,
                                theType=nk.TREE_NODE,
                                title="Selectable",
                                state=nk.MINIMIZED) :
                    nk.tree_pop(ctx)
                if nk.tree_push(ctx=ctx,
                                theType=nk.TREE_NODE,
                                title="Combo",
                                state=nk.MINIMIZED) :
                    nk.tree_pop(ctx)
                if nk.tree_push(ctx=ctx,
                                theType=nk.TREE_NODE,
                                title="Input",
                                state=nk.MINIMIZED) :
                    nk.tree_pop(ctx)

                nk.tree_pop(ctx);
            if nk.tree_push(ctx=ctx,
                            theType=nk.TREE_TAB,
                            title="Chart",
                            state=nk.MINIMIZED,) :
                #TODO
                nk.tree_pop(ctx);
            if nk.tree_push(ctx=ctx,
                            theType=nk.TREE_TAB,
                            title="Chart",
                            state=nk.MINIMIZED) :
                #TODO
                nk.tree_pop(ctx);
            if nk.tree_push(ctx=ctx,
                            theType=nk.TREE_TAB,
                            title="Popup",
                            state=nk.MINIMIZED) :
                #TODO
                nk.tree_pop(ctx);
            if nk.tree_push(ctx=ctx,
                            theType=nk.TREE_TAB,
                            title="Layout",
                            state=nk.MINIMIZED) :
                #TODO
                nk.tree_pop(ctx);


    nk.end(ctx)

    nk.glfw3_render(nk.ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER)

    # done with frame, flush and swap buffers
    # Swap front and back buffers
    glfw.glfwSwapBuffers(window)


glfw.glfwTerminate()
