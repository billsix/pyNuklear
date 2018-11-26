# Copyright (c) 2017-2018 William Emerison Six
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import os
import sys
import ctypes

if __name__ == '__main__':
    print("overview.py is a library, not a program.  Look at README.md for use of pyNuklear")
    sys.exit(1)

import pynuklear.nuklear as nk
import math


def overview(nuklear):
    # show overview
    window_flags = 0

    nuklear.set_style_window_header_align(nk.StyleHeaderAlign.RIGHT)

    global border
    try:
        border
    except Exception:
        border = True

    if(border):
        window_flags |= nk.PanelFlags.WINDOW_BORDER.value

    global resize
    try:
        resize
    except Exception:
        resize = True

    if(resize):
        window_flags |= nk.PanelFlags.WINDOW_SCALABLE.value

    global movable
    try:
        movable
    except Exception:
        movable = True

    if(movable):
        window_flags |= nk.PanelFlags.WINDOW_MOVABLE.value

    global no_scrollbar
    try:
        no_scrollbar
    except Exception:
        no_scrollbar = False

    if(no_scrollbar):
        window_flags |= nk.PanelFlags.WINDOW_NO_SCROLLBAR.value

    global scale_left
    try:
        scale_left
    except Exception:
        scale_left = False

    if(scale_left):
        window_flags |= nk.PanelFlags.WINDOW_SCALE_LEFT.value

    global minimizable
    try:
        minimizable
    except Exception:
        minimizable = True

    if(minimizable):
        window_flags |= nk.PanelFlags.WINDOW_MINIMIZABLE.value

    if nuklear.begin(title="Overview",
                     bounds=nk.Rect(10, 300, 400, 600),
                     flags=window_flags):
        global show_menu
        try:
            show_menu
        except Exception:
            show_menu = True

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
            nuklear.layout_row_begin(format=nk.LayoutFormat.STATIC,
                                     row_height=25.0,
                                     columns=5)
            nuklear.layout_row_push(ratio_or_width=45.0)
            if nuklear.menu_begin_label(text="MENU",
                                        align=nk.TextAlign.TEXT_LEFT,
                                        size=nk.Vec2(120.0, 200.0)):
                nuklear.layout_row_dynamic(height=25.0,
                                           columns=1)
                if nuklear.menu_item_label(label="Hide",
                                           align=nk.TextAlign.TEXT_LEFT):
                    show_menu = False
                if nuklear.menu_item_label(label="About",
                                           align=nk.TextAlign.TEXT_LEFT):
                    show_app_about = True
                (modified, mprog) = nuklear.progress(cur=mprog,
                                                     max=100,
                                                     is_modifyable=nk.Modify.MODIFIABLE)
                (modified, mslider) = nuklear.slider_int(minV=0,
                                                         value=mslider,
                                                         maxV=16,
                                                         step=1)
                (modified, mcheck) = nuklear.checkbox_label(text="check",
                                                            active=mcheck)

                nuklear.menu_end()
            nuklear.layout_row_push(ratio_or_width=60.0)
            if nuklear.menu_begin_label(text="Advanced",
                                        align=nk.TextAlign.TEXT_LEFT,
                                        size=nk.Vec2(200, 600)):
                MENU_NONE, MENU_FILE, MENU_EDIT, MENU_VIEW, MENU_CHART = (
                    0, 1, 2, 3, 4)

                global menu_state
                try:
                    menu_state
                except Exception:
                    menu_state = MENU_NONE

                state = nk.CollapseStates.MAXIMIZED if menu_state == MENU_FILE else nk.CollapseStates.MINIMIZED
                (fileSelected, state) = nuklear.tree_state_push(
                    nk.TreeType.TREE_TAB, "FILE", state)
                if fileSelected:
                    menu_state = MENU_FILE
                    nuklear.menu_item_label(label="New",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.menu_item_label(label="Open",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.menu_item_label(label="Save",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.menu_item_label(label="Close",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.menu_item_label(label="Exit",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.tree_pop()

                state = nk.CollapseStates.MAXIMIZED if menu_state == MENU_EDIT else nk.CollapseStates.MINIMIZED
                (editSelected, state) = nuklear.tree_state_push(
                    nk.TreeType.TREE_TAB, "EDIT", state)
                if editSelected:
                    menu_state = MENU_EDIT
                    nuklear.menu_item_label(label="Copy",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.menu_item_label(label="Delete",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.menu_item_label(label="Cut",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.menu_item_label(label="Paste",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.tree_pop()

                state = nk.CollapseStates.MAXIMIZED if menu_state == MENU_VIEW else nk.CollapseStates.MINIMIZED
                (viewSelected, state) = nuklear.tree_state_push(
                    nk.TreeType.TREE_TAB, "VIEW", state)
                if viewSelected:
                    menu_state = MENU_VIEW
                    nuklear.menu_item_label(label="About",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.menu_item_label(label="Options",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.menu_item_label(label="Customize",
                                            align=nk.TextAlign.TEXT_LEFT)
                    nuklear.tree_pop()

                state = nk.CollapseStates.MAXIMIZED if menu_state == MENU_CHART else nk.CollapseStates.MINIMIZED
                (chartSelected, state) = nuklear.tree_state_push(
                    nk.TreeType.TREE_TAB, "CHART", state)
                if chartSelected:
                    menu_state = MENU_CHART
                    values = [26.0, 13.0, 30.0, 15.0, 25.0,
                              10.0, 20.0, 40.0, 12.0, 8.0, 22.0, 28.0]
                    nuklear.layout_row_dynamic(height=150.0,
                                               columns=1)
                    nuklear.chart_begin(chart_type=nk.ChartType.CHART_COLUMN,
                                        count=len(values),
                                        minV=0.0,
                                        maxV=50.0)
                    for x in range(len(values)):
                        nuklear.chart_push(values[x])
                    nuklear.chart_end()
                    nuklear.tree_pop()
                nuklear.menu_end()

            nuklear.layout_row_push(70.0)
            (modified, mprog) = nuklear.progress(cur=mprog,
                                                 max=100,
                                                 is_modifyable=nk.Modify.MODIFIABLE)
            (modified, mslider) = nuklear.slider_int(minV=0,
                                                     value=mslider,
                                                     maxV=16,
                                                     step=1)
            (modified, mcheck) = nuklear.checkbox_label(text="check",
                                                        active=mcheck)

            nuklear.menubar_end()

            if show_app_about:
                if nuklear.popup_begin(theType=nk.PopupType.POPUP_STATIC,
                                       title="About",
                                       flags=nk.PanelFlags.WINDOW_CLOSABLE,
                                       rect=nk.Rect(20, 100, 400, 200)):
                    nuklear.layout_row_dynamic(height=20.0,
                                               columns=1)
                    nuklear.label(text="pyNuklear",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    nuklear.label(text="By William Emerison Six",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    nuklear.label(text="pyNuklear is MIT-licensed.",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    nuklear.label(text="based on Nuklear",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    nuklear.label(text="By Micha Mettke",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    nuklear.label(text="nuklear is licensed under the public domain License.",
                                  alignment=nk.TextAlign.TEXT_LEFT)

                    nuklear.popup_end()
                else:
                    show_app_about = False

# Uncomment out the lines below to learn about how nuklear uniquely identifies graphical objects.
# By default, nuklear will identify an object by a hash of the file name and the line number of the caller.
# This technique works well enough, but not if the elements are created in a loop.
# The following few lines if uncommented, will all be expanded or closed if any of them are clicked.
#             theList = ['a','b','c']
#             for x in range(len(theList)):
#                 if nuklear.tree_push(theType=nk.TREE_TAB,
#                                      title=theList[x],
#                                      state=nk.MINIMIZED) :
#                     nuklear.tree_pop()

# To uniquely identify the objects in a loop ourselves, call the tree push id method, whereby the user
# can add an id per object to help nuklear uniquely identify objects.

#             theList = ['a','b','c']
#             for x in range(len(theList)):
#                 if nuklear.tree_push_id(theType=nk.TREE_TAB,
#                                         title=theList[x],
#                                         state=nk.MINIMIZED,
#                                         id=x) :
#                     nuklear.tree_pop()

        if nuklear.tree_push(theType=nk.TreeType.TREE_TAB,
                             title="Window",
                             state=nk.CollapseStates.MINIMIZED):
            nuklear.layout_row_dynamic(height=30.0,
                                       columns=2)
            global titlebar
            try:
                titlebar
            except Exception:
                titlebar = True

            (modified, titlebar) = nuklear.checkbox_label(text="Titlebar",
                                                          active=titlebar)
            (modified, show_menu) = nuklear.checkbox_label(text="Menu",
                                                           active=show_menu)
            (modified, border) = nuklear.checkbox_label(text="Border",
                                                        active=border)
            (modified, resize) = nuklear.checkbox_label(text="Resizable",
                                                        active=resize)
            (modified, movable) = nuklear.checkbox_label(text="Movable",
                                                         active=movable)
            (modified, no_scrollbar) = nuklear.checkbox_label(text="No Scrollbar",
                                                              active=no_scrollbar)
            (modified, minimizable) = nuklear.checkbox_label(text="Minimizable",
                                                             active=minimizable)
            (modified, scale_left) = nuklear.checkbox_label(text="Scale Left",
                                                            active=scale_left)
            nuklear.tree_pop()
        if nuklear.tree_push(theType=nk.TreeType.TREE_TAB,
                             title="Widgets",
                             state=nk.CollapseStates.MINIMIZED):
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Text",
                                 state=nk.CollapseStates.MINIMIZED):
                nuklear.layout_row_dynamic(height=20.0,
                                           columns=1)
                nuklear.label(text="Label aligned left",
                              alignment=nk.TextAlign.TEXT_LEFT)
                nuklear.label(text="Label aligned centered",
                              alignment=nk.TextAlign.TEXT_CENTERED)
                nuklear.label(text="Label aligned right",
                              alignment=nk.TextAlign.TEXT_RIGHT)
                nuklear.label_colored(text="Blue text",
                                      align=nk.TextAlign.TEXT_LEFT,
                                      color=nk.Color(0, 0, 255, 255))
                nuklear.label_colored(text="Yellow text",
                                      align=nk.TextAlign.TEXT_LEFT,
                                      color=nk.Color(255, 255, 0, 255))
                nuklear.text(text="Text without /0",
                             length=15,
                             alignment=nk.TextAlign.RIGHT)
                nuklear.layout_row_static(height=100.0,
                                          item_width=200,
                                          columns=1)
                nuklear.label_wrap(
                    text="This is a very long line to hopefully get this text to be wrapped into multiple lines to show line wrapping")
                nuklear.layout_row_dynamic(height=100.0,
                                           columns=1)
                nuklear.label_wrap(
                    text="This is another long text to show dynamic window changes on multiline text")

                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Button",
                                 state=nk.CollapseStates.MINIMIZED):
                nuklear.layout_row_static(height=30,
                                          item_width=100,
                                          columns=3)
                if nuklear.button_label(title="Button"):
                    print("Button pressed!")
                nuklear.button_set_behavior(nk.ButtonBehavior.BUTTON_REPEATER)
                if nuklear.button_label(title="Repeater"):
                    print("Repeater is being pressed!")
                nuklear.button_set_behavior(nk.ButtonBehavior.BUTTON_DEFAULT)
                if nuklear.button_color(nk.Color(0, 0, 255, 255)):
                    pass
                nuklear.layout_row_static(height=25.0,
                                          item_width=25,
                                          columns=8)
                nuklear.button_symbol(nk.SymbolType.SYMBOL_CIRCLE_SOLID)
                nuklear.button_symbol(nk.SymbolType.SYMBOL_CIRCLE_OUTLINE)
                nuklear.button_symbol(nk.SymbolType.SYMBOL_RECT_SOLID)
                nuklear.button_symbol(nk.SymbolType.SYMBOL_RECT_OUTLINE)
                nuklear.button_symbol(nk.SymbolType.SYMBOL_TRIANGLE_UP)
                nuklear.button_symbol(nk.SymbolType.SYMBOL_TRIANGLE_DOWN)
                nuklear.button_symbol(nk.SymbolType.SYMBOL_TRIANGLE_LEFT)
                nuklear.button_symbol(nk.SymbolType.SYMBOL_TRIANGLE_RIGHT)

                nuklear.layout_row_static(height=30.0,
                                          item_width=100,
                                          columns=2)
                nuklear.button_symbol_label(symbol=nk.SymbolType.SYMBOL_TRIANGLE_LEFT,
                                            label="prev",
                                            align=nk.TextAlign.TEXT_RIGHT)
                nuklear.button_symbol_label(symbol=nk.SymbolType.SYMBOL_TRIANGLE_RIGHT,
                                            label="next",
                                            align=nk.TextAlign.TEXT_LEFT)
                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Basic",
                                 state=nk.CollapseStates.MINIMIZED):
                nuklear.layout_row_static(height=30.0,
                                          item_width=100,
                                          columns=1)
                global basicCheckBox
                try:
                    basicCheckBox
                except Exception:
                    basicCheckBox = False
                (modified, basicCheckBox) = nuklear.checkbox_label(text="CheckBox",
                                                                   active=basicCheckBox)

                nuklear.layout_row_static(height=30.0,
                                          item_width=80,
                                          columns=3)

                A = 1
                B = 2
                C = 3
                global basicOption
                try:
                    basicOption
                except Exception:
                    basicOption = A

                if nuklear.option_label(label="optionA",
                                        active=basicOption == A):
                                            basicOption = A
                if nuklear.option_label(label="optionB",
                                        active=basicOption == B):
                                            basicOption = B
                if nuklear.option_label(label="optionC",
                                        active=basicOption == C):
                                            basicOption = C

                # this class is necessary to prevent garbage collection of the array
                with nk.LayoutRow(ctx=nuklear.ctx,
                                  layout_format=nk.LayoutFormat.STATIC,
                                  height=30.0,
                                  ratio=[120.0, 150.0]) as lr:
                    global basicSlider
                    try:
                        basicSlider
                    except Exception:
                        basicSlider = 5
                    nuklear.label(text=str.format("Slider Int: {}", basicSlider),
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    (modified, basicSlider) = nuklear.slider_int(minV=0,
                                                                 value=basicSlider,
                                                                 maxV=10,
                                                                 step=1)
                    global floatSlider
                    try:
                        floatSlider
                    except Exception:
                        floatSlider = 2.5
                    nuklear.label(text=str.format("Slider Float: {}", floatSlider),
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    (modified, floatSlider) = nuklear.slider_float(minV=0.0,
                                                                   value=floatSlider,
                                                                   maxV=5.0,
                                                                   step=0.5)

                    global progFloat
                    try:
                        progFloat
                    except Exception:
                        progFloat = 40

                    nuklear.label(text="Progressbar: ",
                                  alignment=nk.TextAlign.TEXT_LEFT);
                    (modified, progFloat) = nuklear.progress(cur=progFloat,
                                                             max=100,
                                                             is_modifyable=nk.Modify.MODIFIABLE)

                with nk.LayoutRow(ctx=nuklear.ctx,
                                  layout_format=nk.LayoutFormat.STATIC,
                                  height=25.0,
                                  ratio=[120.0, 150.0]) as lr:
                    global basicFloat
                    try:
                        basicFloat
                    except Exception:
                        basicFloat = 2.0

                    nuklear.label(text="Property float:",
                                  alignment=nk.TextAlign.TEXT_LEFT);
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
                                  alignment=nk.TextAlign.TEXT_LEFT);
                    basicInt = nuklear.property_int(name="Int:",
                                                    minV=0,
                                                    val=basicInt,
                                                    maxV=100,
                                                    step=1,
                                                    inc_per_pixel=1);
                # TODO -- I don't think I need to port this
                # nuklear.label(text="Property neg:",
                #               alignment= nk.TextAlign.TEXT_LEFT);
                # nuklear.property_int("Neg:", -10, &property_neg, 10, 1, 1);

                # TODO - do this later
                # nk_layout_row_dynamic(height=ctx, 25, 1);
                # nk_label(ctx, "Range:", NK_TextAlign.TEXT_LEFT);
                # nk_layout_row_dynamic(ctx, 25, 3);
                # nk_property_float(ctx, "#min:", 0, &range_float_min, range_float_max, 1.0f, 0.2f);
                # nk_property_float(ctx, "#float:", range_float_min, &range_float_value, range_float_max, 1.0f, 0.2f);
                # nk_property_float(ctx, "#max:", range_float_min, &range_float_max, 100, 1.0f, 0.2f);

                # nk_property_int(ctx, "#min:", INT_MIN, &range_int_min, range_int_max, 1, 10);
                # nk_property_int(ctx, "#neg:", range_int_min, &range_int_value, range_int_max, 1, 10);
                # nk_property_int(ctx, "#max:", range_int_min, &range_int_max, INT_MAX, 1, 10);

                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Selectable",
                                 state=nk.CollapseStates.MINIMIZED):
                if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                     title="List",
                                     state=nk.CollapseStates.MINIMIZED):
                    nuklear.layout_row_static(height=18.0,
                                              item_width=100,
                                              columns=1)

                    global selected
                    try:
                        selected
                    except Exception:
                        selected = [False, False, False, False]

                    (wasModified, selected[0]) = nuklear.selectable_label(label="Selectable",
                                                                          align=nk.TextAlign.TEXT_LEFT,
                                                                          value=selected[0])
                    (wasModified, selected[1]) = nuklear.selectable_label(label="Selectable",
                                                                          align=nk.TextAlign.TEXT_LEFT,
                                                                          value=selected[1])
                    nuklear.label(text="Not Selectable",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    (wasModified, selected[2]) = nuklear.selectable_label(label="Selectable",
                                                                          align=nk.TextAlign.TEXT_LEFT,
                                                                          value=selected[2])
                    (wasModified, selected[3]) = nuklear.selectable_label(label="Selectable",
                                                                          align=nk.TextAlign.TEXT_LEFT,
                                                                          value=selected[3])
                    nuklear.tree_pop()

                if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                     title="Grid",
                                     state=nk.CollapseStates.MINIMIZED):

                    global gridSelected
                    try:
                        gridSelected
                    except Exception:
                        gridSelected = [True, False, False, False,
                                        False, True, False, False,
                                        False, False, True, False,
                                        False, False, False, True]
                    nuklear.layout_row_static(height=50,
                                              item_width=50,
                                              columns=4)
                    for i in range(16):
                        (wasModified, gridSelected[i]) = nuklear.selectable_label(label="Z",
                                                                                  align=nk.TextAlign.TEXT_LEFT,
                                                                                  value=gridSelected[i])
                        if wasModified:
                            (y, x) = divmod(i, 4)
                            if x > 0:
                                gridSelected[i - 1] = not gridSelected[i - 1]
                            if x < 3:
                                gridSelected[i + 1] = not gridSelected[i + 1]
                            if y > 0:
                                gridSelected[i - 4] = not gridSelected[i - 4]
                            if y < 3:
                                gridSelected[i + 4] = not gridSelected[i + 4]
                    nuklear.tree_pop()

                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Combo",
                                 state=nk.CollapseStates.MINIMIZED):
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
                                          columns=1)
                current_weapon = nuklear.combo(items=weapons,
                                               selected=current_weapon,
                                               item_height=25,
                                               size=nk.Vec2(200, 200))

                nuklear.layout_row_static(height=25.0,
                                          item_width=200,
                                          columns=1)
                global comboColor
                try:
                    comboColor
                except Exception:
                    comboColor = nk.Color(130, 50, 50, 255)

                if nuklear.combo_begin_color(comboColor,
                                             nk.Vec2(200, 200)):
                    nuklear.layout_row_dynamic(height=30.0,
                                               columns=2)
                    nuklear.label(text="R:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    comboColor.r = nuklear.slide_int(0, comboColor.r, 255, 5)
                    nuklear.label(text="G:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    comboColor.g = nuklear.slide_int(0, comboColor.g, 255, 5)
                    nuklear.label(text="B:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    comboColor.b = nuklear.slide_int(0, comboColor.b, 255, 5)
                    nuklear.label(text="A:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    comboColor.a = nuklear.slide_int(0, comboColor.a, 255, 5)

                    nuklear.combo_end()
                # TODO
                #                /* complex color combobox */
                # TODO
                #                /* progressbar combobox */
                # TODO
                #                /* checkbox combobox */
                # TODO
                #                /* complex text combobox */
                # TODO
                #                /* chart combobox */
                # TODO
                #                /* time combobox */
                # TODO
                #                /* date combobox */
                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Input",
                                 state=nk.CollapseStates.MINIMIZED):
                with nk.LayoutRow(ctx=nuklear.ctx,
                                  layout_format=nk.LayoutFormat.STATIC,
                                  height=25.0,
                                  ratio=[120.0, 150.0]) as lr:

                    # create a c string
                    global text
                    global textL
                    try:
                        text
                        textL
                    except Exception:
                        text = []
                        textL = []
                        for x in range(9):
                            text.append((ctypes.c_char * 64)())
                            textL.append(0)

                    nuklear.label(text="Default:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    (eSFlags, textL[0]) = nuklear.edit_string(flags=nk.EditTypes.SIMPLE,
                                                              memory=text[0],
                                                              length=textL[0],
                                                              maxV=64,
                                                              filterF=nk.filter_default)
                    nuklear.label(text="Int:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    (eSFlags, textL[1]) = nuklear.edit_string(flags=nk.EditTypes.SIMPLE,
                                                              memory=text[1],
                                                              length=textL[1],
                                                              maxV=64,
                                                              filterF=nk.filter_decimal)
                    nuklear.label(text="Float:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    (eSFlags, textL[2]) = nuklear.edit_string(flags=nk.EditTypes.SIMPLE,
                                                              memory=text[2],
                                                              length=textL[2],
                                                              maxV=64,
                                                              filterF=nk.filter_float)
                    nuklear.label(text="Hex:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    (eSFlags, textL[4]) = nuklear.edit_string(flags=nk.EditTypes.SIMPLE,
                                                              memory=text[4],
                                                              length=textL[4],
                                                              maxV=64,
                                                              filterF=nk.filter_hex)
                    nuklear.label(text="Octal:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    (eSFlags, textL[5]) = nuklear.edit_string(flags=nk.EditTypes.SIMPLE,
                                                              memory=text[5],
                                                              length=textL[5],
                                                              maxV=64,
                                                              filterF=nk.filter_oct)
                    nuklear.label(text="Binary:",
                                  alignment=nk.TextAlign.TEXT_LEFT)
                    (eSFlags, textL[6]) = nuklear.edit_string(flags=nk.EditTypes.SIMPLE,
                                                              memory=text[6],
                                                              length=textL[6],
                                                              maxV=64,
                                                              filterF=nk.filter_binary)
                # TODO
                nuklear.tree_pop()

            nuklear.tree_pop()
        if nuklear.tree_push(theType=nk.TreeType.TREE_TAB,
                             title="Chart",
                             state=nk.CollapseStates.MINIMIZED):
            nuklear.layout_row_dynamic(height=100.0,
                                       columns=1)
            bounds = nuklear.widget_bounds()
            if nuklear.chart_begin(chart_type=nk.ChartType.CHART_LINES,
                                   count=32,
                                   minV=-1.0,
                                   maxV=1.0):
                numberOfPoints = 32
                hoveredIndex = -1
                for x in range(32):
                    res = nuklear.chart_push(
                        math.cos(x * (2 * 3.141592654) / numberOfPoints))
                    if res & nk.ChartEvent.CHART_HOVERING.value:
                        hoveredIndex = x

                nuklear.chart_end()

                if hoveredIndex != -1:
                    nuklear.tooltip("%f, %f" % (hoveredIndex / numberOfPoints,
                                                math.cos(hoveredIndex * (2 * 3.141592654) / numberOfPoints)))

            # column demo
            nuklear.layout_row_dynamic(height=100.0,
                                       columns=1)
            bounds = nuklear.widget_bounds()
            if nuklear.chart_begin(chart_type=nk.ChartType.CHART_COLUMN,
                                   count=32,
                                   minV=0.0,
                                   maxV=1.0):
                numberOfPoints = 32
                hoveredIndex = -1
                for x in range(32):
                    res = nuklear.chart_push(
                        math.fabs(math.sin(x * (2 * 3.141592654) / numberOfPoints)))
                    if res & nk.ChartEvent.CHART_HOVERING.value:
                        hoveredIndex = x

                nuklear.chart_end()

                if hoveredIndex != -1:
                    nuklear.tooltip("%f, %f" % (hoveredIndex / numberOfPoints,
                                                math.cos(hoveredIndex * (2 * 3.141592654) / numberOfPoints)))

            # mixed chart
            nuklear.layout_row_dynamic(height=100.0,
                                       columns=1)
            bounds = nuklear.widget_bounds()
            numberOfPoints = 32
            if nuklear.chart_begin(chart_type=nk.ChartType.CHART_COLUMN,
                                   count=32,
                                   minV=0.0,
                                   maxV=1.0):
                nuklear.chart_add_slot(chart_type=nk.ChartType.CHART_LINES,
                                       count=32,
                                       minV=-1.0,
                                       maxV=1.0)
                nuklear.chart_add_slot(chart_type=nk.ChartType.CHART_LINES,
                                       count=32,
                                       minV=-1.0,
                                       maxV=1.0)
                for x in range(32):
                    nuklear.chart_push_slot(
                        math.fabs(math.sin(x * (2 * 3.141592654) / numberOfPoints)), 0)
                    nuklear.chart_push_slot(
                        math.cos(x * (2 * 3.141592654) / numberOfPoints), 1)
                    nuklear.chart_push_slot(
                        math.sin(x * (2 * 3.141592654) / numberOfPoints), 2)
            nuklear.chart_end()

            # TODO - mixed colored chart

            nuklear.tree_pop()
        if nuklear.tree_push(theType=nk.TreeType.TREE_TAB,
                             title="Popup",
                             state=nk.CollapseStates.MINIMIZED):
            # TODO
            nuklear.layout_row_static(height=30.0,
                                      item_width=160,
                                      columns=1)
            bounds = nuklear.widget_bounds()
            nuklear.label(text="Right click me for menu",
                          alignment=nk.TextAlign.TEXT_LEFT)

            if nuklear.contextual_begin(flags=0,
                                        size=nk.Vec2(100, 300),
                                        triggerBounds=bounds):
                nuklear.layout_row_dynamic(height=25.0,
                                           columns=1)
                (modified, show_menu) = nuklear.checkbox_label(text="Menu",
                                                               active=show_menu)
                (modified, mprog) = nuklear.progress(cur=mprog,
                                                     max=100,
                                                     is_modifyable=nk.Modify.MODIFIABLE)
                (modified, mslider) = nuklear.slider_int(minV=0,
                                                         value=mslider,
                                                         maxV=16,
                                                         step=1)
                if nuklear.contextual_item_label(text="About",
                                                 align=nk.TextAlign.TEXT_CENTERED):
                    show_app_about = True
                nuklear.contextual_end()
            nuklear.tree_pop()
        if nuklear.tree_push(theType=nk.TreeType.TREE_TAB,
                             title="Layout",
                             state=nk.CollapseStates.MINIMIZED):
            # TODO
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Widget",
                                 state=nk.CollapseStates.MINIMIZED):

                nuklear.layout_row_dynamic(height=30.0,
                                           columns=1)
                nuklear.label(text="Dynamic fixed column layout with generated position and size:",
                              alignment=nk.TextAlign.TEXT_LEFT)
                nuklear.layout_row_dynamic(height=30.0,
                                           columns=3)
                nuklear.button_label(title="button")
                nuklear.button_label(title="button")
                nuklear.button_label(title="button")

                nuklear.layout_row_dynamic(height=30.0,
                                           columns=1)
                nuklear.label(text="static fixed column layout with generated position and size:",
                              alignment=nk.TextAlign.TEXT_LEFT)
                nuklear.layout_row_static(height=30.0,
                                          item_width=100,
                                          columns=3)
                nuklear.button_label(title="button")
                nuklear.button_label(title="button")
                nuklear.button_label(title="button")

                nuklear.layout_row_dynamic(height=30.0,
                                           columns=1)
                nuklear.label(text="Dynamic array-based custom column layout with generated position and custom size:",
                              alignment=nk.TextAlign.TEXT_LEFT)
                # this class is necessary to prevent garbage collection of the array
                with nk.LayoutRow(ctx=nuklear.ctx,
                                  layout_format=nk.LayoutFormat.DYNAMIC,
                                  height=30.0,
                                  ratio=[0.2, 0.6, 0.2]) as lr:

                    nuklear.button_label(title="button")
                    nuklear.button_label(title="button")
                    nuklear.button_label(title="button")

                nuklear.layout_row_dynamic(height=30.0,
                                           columns=1)
                nuklear.label(text="Static array-based custom column layout with generated position and custom size:",
                              alignment=nk.TextAlign.TEXT_LEFT)
                # this class is necessary to prevent garbage collection of the array
                with nk.LayoutRow(ctx=nuklear.ctx,
                                  layout_format=nk.LayoutFormat.STATIC,
                                  height=30.0,
                                  ratio=[100.0, 200.0, 50.0]) as lr:

                    nuklear.button_label(title="button")
                    nuklear.button_label(title="button")
                    nuklear.button_label(title="button")

                nuklear.layout_row_dynamic(height=30.0,
                                           columns=1)
                nuklear.label(text="Dynamic immediate mode custom column layout with generated position and custom size:",
                              alignment=nk.TextAlign.TEXT_LEFT)
                nuklear.layout_row_begin(format=nk.LayoutFormat.DYNAMIC,
                                         row_height=30.0,
                                         columns=3)
                nuklear.layout_row_push(ratio_or_width=0.2)
                nuklear.button_label(title="button")
                nuklear.layout_row_push(ratio_or_width=0.6)
                nuklear.button_label(title="button")
                nuklear.layout_row_push(ratio_or_width=0.2)
                nuklear.button_label(title="button")

                nuklear.layout_row_dynamic(height=30.0,
                                           columns=1)
                nuklear.label(text="Static immediate mode custom column layout with generated position and custom size:",
                              alignment=nk.TextAlign.TEXT_LEFT)
                nuklear.layout_row_begin(format=nk.LayoutFormat.STATIC,
                                         row_height=30.0,
                                         columns=3)
                nuklear.layout_row_push(ratio_or_width=100.0)
                nuklear.button_label(title="button")
                nuklear.layout_row_push(ratio_or_width=200.0)
                nuklear.button_label(title="button")
                nuklear.layout_row_push(ratio_or_width=50.0)
                nuklear.button_label(title="button")

                # TODO - two more layouts

                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Group",
                                 state=nk.CollapseStates.MINIMIZED):
                # TODO
                nuklear.tree_pop()

            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Notebook",
                                 state=nk.CollapseStates.MINIMIZED):
                nuklear.style_push_window_spacing(vec2=nk.Vec2(x=0.0,
                                                               y=0.0))
                nuklear.style_push_button_rounding(f=0.0)

                names = ["Lines", "Columns", "Mixed"]
                nuklear.layout_row_begin(format=nk.LayoutFormat.STATIC,
                                         row_height=20.0,
                                         columns=3)
                global currentTab
                try:
                    currentTab
                except Exception:
                    currentTab = 0

                for i in range(len(names)):
                    nuklear.layout_row_push(
                        ratio_or_width=nuklear.get_text_width(names[i]))
                    if nuklear.button_label(title=names[i],
                                            active=currentTab != i):
                        currentTab = i

                nuklear.style_pop_float()

                nuklear.layout_row_dynamic(height=140.0,
                                           columns=1)
                if(nuklear.group_begin("Notebook", nk.PanelFlags.WINDOW_BORDER)):
                    nuklear.style_pop_vec2()
                    nuklear.layout_row_dynamic(height=100.0,
                                               columns=1)
                    bounds = nuklear.widget_bounds()
                    if currentTab == 0:
                        numberOfPoints = 32
                        hoveredIndex = -1
                        if nuklear.chart_begin(chart_type=nk.ChartType.CHART_LINES,
                                               count=32,
                                               minV=-1.0,
                                               maxV=1.0):
                            for x in range(32):
                                res = nuklear.chart_push(
                                    math.cos(x * (2 * 3.141592654) / numberOfPoints))
                                if res & nk.ChartEvent.CHART_HOVERING.value:
                                    hoveredIndex = x

                        nuklear.chart_end()

                        if hoveredIndex != -1:
                            nuklear.tooltip("%f, %f" % (
                                hoveredIndex / numberOfPoints, math.cos(hoveredIndex * (2 * 3.141592654) / numberOfPoints)))

                    elif currentTab == 1:
                        numberOfPoints = 32
                        hoveredIndex = -1
                        if nuklear.chart_begin(chart_type=nk.ChartType.CHART_COLUMN,
                                               count=32,
                                               minV=0.0,
                                               maxV=1.0):
                            for x in range(32):
                                res = nuklear.chart_push(
                                    math.fabs(math.sin(x * (2 * 3.141592654) / numberOfPoints)))
                                if res & nk.ChartEvent.CHART_HOVERING.value:
                                    hoveredIndex = x

                        nuklear.chart_end()

                        if hoveredIndex != -1:
                            nuklear.tooltip("%f, %f" % (
                                hoveredIndex / numberOfPoints, math.cos(hoveredIndex * (2 * 3.141592654) / numberOfPoints)))

                    elif currentTab == 2:
                        numberOfPoints = 32
                        if nuklear.chart_begin(chart_type=nk.ChartType.CHART_COLUMN,
                                               count=32,
                                               minV=0.0,
                                               maxV=1.0):
                            nuklear.chart_add_slot(chart_type=nk.ChartType.CHART_LINES,
                                                   count=32,
                                                   minV=-1.0,
                                                   maxV=1.0)
                            nuklear.chart_add_slot(chart_type=nk.ChartType.CHART_LINES,
                                                   count=32,
                                                   minV=-1.0,
                                                   maxV=1.0)
                            for x in range(32):
                                nuklear.chart_push_slot(
                                    math.fabs(math.sin(x * (2 * 3.141592654) / numberOfPoints)), 0)
                                nuklear.chart_push_slot(
                                    math.cos(x * (2 * 3.141592654) / numberOfPoints), 1)
                                nuklear.chart_push_slot(
                                    math.sin(x * (2 * 3.141592654) / numberOfPoints), 2)
                        nuklear.chart_end()

                    nuklear.group_end()
                else:
                    nuklear.style_pop_vec2()
                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Simple",
                                 state=nk.CollapseStates.MINIMIZED):
                # TODO
                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Complex",
                                 state=nk.CollapseStates.MINIMIZED):
                # TODO
                nuklear.tree_pop()
            if nuklear.tree_push(theType=nk.TreeType.TREE_NODE,
                                 title="Splitter",
                                 state=nk.CollapseStates.MINIMIZED):
                # TODO
                nuklear.tree_pop()

            nuklear.tree_pop()

    nuklear.end()
