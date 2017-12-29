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


import nuklear as nk
import math

def overview(nuklear):
    # show overview
    # simulate a local static variable
    global show_menu
    try:
        show_menu
    except Exception:
        show_menu = True
    global titlebar
    try:
        titlebar
    except Exception:
        titlebar  = True
    global border
    try:
        border
    except Exception:
        border = True
    global resize
    try:
        resize
    except Exception:
        resize = True
    global movable
    try:
        movable
    except Exception:
        movable = True
    global no_scrollbar
    try:
        no_scrollbar
    except Exception:
        no_scrollbar = False
    global scale_left
    try:
        scale_left
    except Exception:
        scale_left = False
    global minimizable
    try:
        minimizable
    except Exception:
        minimizable = True



    window_flags = 0
    #TODO -- map the ctx struct

    #ctx->style.window.header.align = header_align

    if(border) : window_flags |= nk.WINDOW_BORDER
    if(resize) : window_flags |= nk.WINDOW_SCALABLE
    if(movable) : window_flags |= nk.WINDOW_MOVABLE
    if(no_scrollbar) : window_flags |= nk.WINDOW_NO_SCROLLBAR
    if(scale_left) : window_flags |= nk.WINDOW_SCALE_LEFT
    if(minimizable) : window_flags |= nk.WINDOW_MINIMIZABLE


    if nuklear.begin(title="Overview",
                     bounds=nk.Rect(10,300,400,600),
                     flags=window_flags):
        if show_menu:
            global mprog
            try:
                mprog
            except Exception:
                mprog = 60
            global mslider
            try:
                mslider
            except Exception:
                mslider = 10
            global mcheck
            try:
                mcheck
            except Exception:
                mcheck = False

            global show_app_about
            try:
                show_app_about
            except Exception:
                show_app_about = False

            nuklear.menubar_begin()
            nuklear.layout_row_begin(fmt=nk.STATIC,
                                     row_height=25.0,
                                     cols=5)
            nuklear.layout_row_push(ratio_or_width=45.0)
            if nuklear.menu_begin_label(text="MENU",
                                        align=nk.TEXT_LEFT,
                                        size=nk.Vec2(120.0,200.0)):
                nuklear.layout_row_dynamic(height=25.0,
                                           cols=1)
                if nuklear.menu_item_label(label="Hide",
                                           align=nk.TEXT_LEFT):
                    show_menu = False
                if nuklear.menu_item_label(label="About",
                                           align=nk.TEXT_LEFT):
                    show_app_about = True
                (modified,mprog) = nuklear.progress(cur=mprog,
                                                    max=100,
                                                    is_modifyable=nk.MODIFIABLE)
                (modified,mslider) = nuklear.slider_int(minV=0,
                                                        value=mslider,
                                                        maxV=16,
                                                        step=1)
                (modified,mcheck) = nuklear.checkbox_label(text="check",
                                                           active=mcheck)

                nuklear.menu_end()
            nuklear.layout_row_push(ratio_or_width=60.0)
            if nuklear.menu_begin_label(text="Advanced",
                                        align=nk.TEXT_LEFT,
                                        size=nk.Vec2(200,600)):
                # TODO -- do the advanced menu

                nuklear.menu_end()

            nuklear.layout_row_push(70.0)
            (modified,mprog) = nuklear.progress(cur=mprog,
                                                 max=100,
                                                 is_modifyable=nk.MODIFIABLE)
            (modified,mslider) = nuklear.slider_int(minV=0,
                                                    value=mslider,
                                                    maxV=16,
                                                    step=1)
            (modified,mcheck) = nuklear.checkbox_label(text="check",
                                                       active=mcheck)

            nuklear.menubar_end()

            if show_app_about:
                if nuklear.popup_begin(theType=nk.POPUP_STATIC,
                                       title="About",
                                       flags=nk.WINDOW_CLOSABLE,
                                       rect=nk.Rect(20,100,400,200)):
                    nuklear.layout_row_dynamic(height=20.0,
                                               cols=1)
                    nuklear.label(text="pyNuklear",
                                  alignment=nk.TEXT_LEFT)
                    nuklear.label(text="By William Emerison Six",
                                  alignment=nk.TEXT_LEFT)
                    nuklear.label(text="pyNuklear is MIT-licensed.",
                             alignment=nk.TEXT_LEFT)
                    nuklear.label(text="based on Nuklear",
                                  alignment=nk.TEXT_LEFT)
                    nuklear.label(text="By Micha Mettke",
                                  alignment=nk.TEXT_LEFT)
                    nuklear.label(text="nuklear is licensed under the public domain License.",
                             alignment=nk.TEXT_LEFT)

                    nuklear.popup_end()
                else:
                    show_app_about = False
            if nuklear.tree_push(theType=nk.TREE_TAB,
                                 title="Window",
                                 state=nk.MINIMIZED) :
                nuklear.layout_row_dynamic(height=30.0,
                                           cols=2)
                (modified,titlebar) = nuklear.checkbox_label(text="Titlebar",
                                                             active=titlebar)
                (modified,show_menu) = nuklear.checkbox_label(text="Menu",
                                                              active=show_menu)
                (modified,border) = nuklear.checkbox_label(text="Border",
                                                           active=border)
                (modified,resize) = nuklear.checkbox_label(text="Resizable",
                                                           active=resize)
                (modified,movable) = nuklear.checkbox_label(text="Movable",
                                                            active=movable)
                (modified,no_scrollbar) = nuklear.checkbox_label(text="No Scrollbar",
                                                                 active=no_scrollbar)
                (modified,minimizable) = nuklear.checkbox_label(text="Minimizable",
                                                                active=minimizable)
                (modified,scale_left) = nuklear.checkbox_label(text="Scale Left",
                                                               active=scale_left)
                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TREE_TAB,
                                 title="Widgets",
                                 state=nk.MINIMIZED) :
                if nuklear.tree_push(theType=nk.TREE_NODE,
                                     title="Text",
                                     state=nk.MINIMIZED) :
                    nuklear.layout_row_dynamic(height=20.0 ,
                                               cols=1)
                    nuklear.label(text="Label aligned left",
                                  alignment=nk.TEXT_LEFT)
                    nuklear.label(text="Label aligned centered",
                                  alignment=nk.TEXT_CENTERED)
                    nuklear.label(text="Label aligned right",
                                  alignment=nk.TEXT_RIGHT)
                    nuklear.label_colored(text="Blue text",
                                          align=nk.TEXT_LEFT,
                                          color=nk.Color(0,0,255,255))
                    nuklear.label_colored(text="Yellow text",
                                          align=nk.TEXT_LEFT,
                                          color=nk.Color(255,255,0,255))
                    nuklear.text(text="Text without /0",
                                 length=15,
                                 alignment=nk.TEXT_ALIGN_RIGHT)
                    nuklear.layout_row_static(height=100.0,
                                              item_width=200,
                                              cols=1)
                    nuklear.label_wrap(text="This is a very long line to hopefully get this text to be wrapped into multiple lines to show line wrapping")
                    nuklear.layout_row_dynamic(height=100.0,
                                               cols=1)
                    nuklear.label_wrap(text="This is another long text to show dynamic window changes on multiline text")

                    nuklear.tree_pop()
                if nuklear.tree_push(theType=nk.TREE_NODE,
                                     title="Button",
                                     state=nk.MINIMIZED) :
                    nuklear.layout_row_static(height=30,
                                              item_width=100,
                                              cols=3)
                    if nuklear.button_label(title="Button"):
                        print("Button pressed!")
                    nuklear.button_set_behavior(nk.BUTTON_REPEATER)
                    if nuklear.button_label(title="Repeater"):
                        print("Repeater is being pressed!")
                    nuklear.button_set_behavior(nk.BUTTON_DEFAULT)
                    if nuklear.button_color(nk.Color(0,0,255,255)):
                        pass
                    nuklear.layout_row_static(height=25.0,
                                              item_width=25,
                                              cols=8)
                    nuklear.button_symbol(nk.SYMBOL_CIRCLE_SOLID)
                    nuklear.button_symbol(nk.SYMBOL_CIRCLE_OUTLINE)
                    nuklear.button_symbol(nk.SYMBOL_RECT_SOLID)
                    nuklear.button_symbol(nk.SYMBOL_RECT_OUTLINE)
                    nuklear.button_symbol(nk.SYMBOL_TRIANGLE_UP)
                    nuklear.button_symbol(nk.SYMBOL_TRIANGLE_DOWN)
                    nuklear.button_symbol(nk.SYMBOL_TRIANGLE_LEFT)
                    nuklear.button_symbol(nk.SYMBOL_TRIANGLE_RIGHT)

                    nuklear.layout_row_static(height=30.0,
                                              item_width=100,
                                              cols=2)
                    nuklear.button_symbol_label(symbol=nk.SYMBOL_TRIANGLE_LEFT,
                                                label="prev",
                                                align=nk.TEXT_RIGHT)
                    nuklear.button_symbol_label(symbol=nk.SYMBOL_TRIANGLE_RIGHT,
                                                label="next",
                                                align=nk.TEXT_LEFT)
                    nuklear.tree_pop()
                if nuklear.tree_push(theType=nk.TREE_NODE,
                                     title="Basic",
                                     state=nk.MINIMIZED) :
                    nuklear.layout_row_static(height=30.0,
                                              item_width=100,
                                              cols=1)
                    global basicCheckBox
                    try:
                        basicCheckBox
                    except Exception:
                        basicCheckBox = False
                    (modified,basicCheckBox) = nuklear.checkbox_label(text="CheckBox",
                                                                      active=basicCheckBox)

                    nuklear.layout_row_static(height=30.0,
                                              item_width=80,
                                              cols=3)

                    A = 1
                    B = 2
                    C = 3
                    global basicOption
                    try:
                        basicOption
                    except Exception:
                        basicOption = A

                    if nuklear.option_label(label="optionA",
                                            active= basicOption == A): basicOption = A
                    if nuklear.option_label(label="optionB",
                                            active= basicOption == B): basicOption = B
                    if nuklear.option_label(label="optionC",
                                            active= basicOption == C): basicOption = C


                    #TODO -- figure out why this code isn't working quite correctly
                    # nuklear.layout_row(layout_format=nk.STATIC,
                    #                    height=30.0,
                    #                    cols=2,
                    #                    ratio=[120.0,150.0])
                    # once I figure that out, delete the subsequent 3 lines
                    nuklear.layout_row_static(height=30.0,
                                              item_width=100,
                                              cols=2)
                    global basicSlider
                    try:
                        basicSlider
                    except Exception:
                        basicSlider = 5
                    nuklear.label(text="Slider Int",
                                  alignment=nk.TEXT_LEFT)
                    (modified,basicSlider) = nuklear.slider_int(minV=0,
                                                                value=basicSlider,
                                                                maxV=10,
                                                                step=1)
                    global floatSlider
                    try:
                        floatSlider
                    except Exception:
                        floatSlider = 2.5
                    nuklear.label(text="Slider Float",
                                  alignment=nk.TEXT_LEFT)
                    (modified,floatSlider) = nuklear.slider_float(minV=0.0,
                                                                  value=floatSlider,
                                                                  maxV=5.0,
                                                                  step=0.5)
                    #TODO -- figure out why this code isn't working quite correctly
                    # nuklear.layout_row(NK_STATIC, 25, 2, ratio);
                    # once I figure that out, delete the subsequent 3 lines
                    nuklear.layout_row_static(height=25.0,
                                              item_width=150,
                                              cols=2)
                    global basicFloat
                    try:
                        basicFloat
                    except Exception:
                        basicFloat = 2.0

                    nuklear.label(text="Property float:",
                                  alignment=nk.TEXT_LEFT);
                    basicFloat = nuklear.property_float(name="Float:",
                                                        minV=0.0,
                                                        val=basicFloat,
                                                        maxV=64.0,
                                                        step=0.1,
                                                        inc_per_pixel=0.2)
                    global basicInt
                    try:
                        basicInt
                    except Exception:
                        basicInt = 10
                    nuklear.label(text="Property int:",
                                  alignment=nk.TEXT_LEFT);
                    basicInt = nuklear.property_int(name="Int:",
                                                    minV=0,
                                                    val=basicInt,
                                                    maxV=100,
                                                    step=1,
                                                    inc_per_pixel=1);
                    # TODO -- I don't think I need to port this
                    # nuklear.label(text="Property neg:",
                    #               alignment= nk.TEXT_LEFT);
                    # nuklear.property_int("Neg:", -10, &property_neg, 10, 1, 1);



                    # TODO - do this later
                    # nk_layout_row_dynamic(height=ctx, 25, 1);
                    # nk_label(ctx, "Range:", NK_TEXT_LEFT);
                    # nk_layout_row_dynamic(ctx, 25, 3);
                    # nk_property_float(ctx, "#min:", 0, &range_float_min, range_float_max, 1.0f, 0.2f);
                    # nk_property_float(ctx, "#float:", range_float_min, &range_float_value, range_float_max, 1.0f, 0.2f);
                    # nk_property_float(ctx, "#max:", range_float_min, &range_float_max, 100, 1.0f, 0.2f);

                    # nk_property_int(ctx, "#min:", INT_MIN, &range_int_min, range_int_max, 1, 10);
                    # nk_property_int(ctx, "#neg:", range_int_min, &range_int_value, range_int_max, 1, 10);
                    # nk_property_int(ctx, "#max:", range_int_min, &range_int_max, INT_MAX, 1, 10);


                    nuklear.tree_pop()
                if nuklear.tree_push(theType=nk.TREE_NODE,
                                     title="Selectable",
                                     state=nk.MINIMIZED) :
                    if nuklear.tree_push(theType=nk.TREE_NODE,
                                         title="List",
                                         state=nk.MINIMIZED) :
                        nuklear.layout_row_static(height=18.0,
                                                  item_width=100,
                                                  cols=1)

                        global selected
                        try:
                            selected
                        except Exception:
                            selected = [0,0,0,0]

                        (wasModified, selected[0]) = nuklear.selectable_label(label="Selectable",
                                                                              align=nk.TEXT_LEFT,
                                                                              value=selected[0])
                        (wasModified, selected[1]) = nuklear.selectable_label(label="Selectable",
                                                                              align=nk.TEXT_LEFT,
                                                                              value=selected[1])
                        nuklear.label(text="Not Selectable",
                                      alignment=nk.TEXT_LEFT)
                        (wasModified, selected[2]) = nuklear.selectable_label(label="Selectable",
                                                                              align=nk.TEXT_LEFT,
                                                                              value=selected[2])
                        (wasModified, selected[3]) = nuklear.selectable_label(label="Selectable",
                                                                              align=nk.TEXT_LEFT,
                                                                              value=selected[3])
                        nuklear.tree_pop()

                    if nuklear.tree_push(theType=nk.TREE_NODE,
                                         title="Grid",
                                         state=nk.MINIMIZED) :
                        # TODO later
                        # int i;
                        # static int selected[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
                        # nk_layout_row_static(ctx, 50, 50, 4);
                        # for (i = 0; i < 16; ++i) {
                        #         if (nk_selectable_label(ctx, "Z", NK_TEXT_CENTERED, &selected[i])) {
                        #                 int x = (i % 4), y = i / 4;
                        #                 if (x > 0) selected[i - 1] ^= 1;
                        #                 if (x < 3) selected[i + 1] ^= 1;
                        #                 if (y > 0) selected[i - 4] ^= 1;
                        #                 if (y < 3) selected[i + 4] ^= 1;
                        #         }
                        # }
                        nuklear.tree_pop()

                    nuklear.tree_pop()
                if nuklear.tree_push(theType=nk.TREE_NODE,
                                     title="Combo",
                                     state=nk.MINIMIZED) :
                    global current_weapon
                    global weapons
                    try:
                        current_weapon
                        weapons
                    except Exception:
                        current_weapon = 0
                        weapons = ['Fist', 'Pistol', 'Shotgun', 'Plasma', 'BFG']

                    nuklear.layout_row_static(height=25,
                                              item_width=200,
                                              cols=1)
                    current_weapon = nuklear.combo(items=weapons,
                                                   selected=current_weapon,
                                                   item_height=25,
                                                   size=nk.Vec2(200,200))

                    # TODO
                    #                 /* slider color combobox */
                    #                /* complex color combobox */
                    # etc



                    nuklear.tree_pop()
                if nuklear.tree_push(theType=nk.TREE_NODE,
                                     title="Input",
                                     state=nk.MINIMIZED) :
                    #TODO
                    nuklear.tree_pop()

                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TREE_TAB,
                                 title="Chart",
                                 state=nk.MINIMIZED) :
                #TODO
                nuklear.layout_row_dynamic(height=100.0,
                                           cols=1)
                # TODO - why is this in the regular nuklear demo?  it is unused
                #bounds = nuklear.widget_bounds()
                if nuklear.chart_begin(chart_type=nk.CHART_LINES,
                                       count=32,
                                       minV=-1.0,
                                       maxV=1.0):
                    numberOfPoints = 32
                    hoveredIndex = -1
                    for x in range(32) :
                        res = nuklear.chart_push(math.cos( x * (2*3.141592654) / numberOfPoints ))
                        if res & nk.CHART_HOVERING:
                            hoveredIndex = x

                    nuklear.chart_end()

                    if hoveredIndex != -1:
                        nuklear.tooltip("%f, %f" % (hoveredIndex / numberOfPoints, math.cos( hoveredIndex  * (2*3.141592654) / numberOfPoints )))

                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TREE_TAB,
                                 title="Popup",
                                 state=nk.MINIMIZED) :
                #TODO
                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TREE_TAB,
                                 title="Layout",
                                 state=nk.MINIMIZED) :
                #TODO
                nuklear.tree_pop()


    nuklear.end()
