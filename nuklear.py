#Copyright (c) 2017-2018 William Emerison Six
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

import os
import sys
import ctypes.util
from ctypes import (Structure, POINTER, CFUNCTYPE, byref, c_char_p, c_int, c_short,
                    c_uint, c_double, c_float, c_ushort, c_byte, c_ubyte)
import inspect
import builtins
from enum import Enum

if __name__ == '__main__':
    print("nuklear.py is a library, not a program.  Look at README.md for use of pyNuklear")
    sys.exit(1)


# Load the nuklear shared library

if hasattr(builtins, "NUKLEAR_PATH"):
    NUKLEAR_PATH = builtins.NUKLEAR_PATH
else:
    print("Nuklear shared library not found")
    sys.exit(1)
_nuklear = NUKLEAR_PATH




# nuklear needs to uniquely identify widgets, and one
# way to do so is to inspect the function caller's frame info
# such as filename and line number.
#
# since callerFrameInfo is a procedure called from an method called
# from a c-wrapper procedure, we need the frame info
# from the caller which is three back.
def callerFrameInfo():
    previous_frame = inspect.currentframe().f_back.f_back.f_back
    return inspect.getframeinfo(previous_frame)



class Context(Structure): pass

class Command(Structure): pass

class DrawCommand(Structure): pass


class Color(Structure):
    _fields_ = [ ('r',  c_ubyte),
                 ('g',  c_ubyte),
                 ('b',  c_ubyte),
                 ('a',  c_ubyte)]

    def __init__(self,r,g,b,a):
        self.r = r
        self.g = g
        self.b = b
        self.a = a

class ColorF(Structure):
    _fields_ = [ ('r',  c_float),
                 ('g',  c_float),
                 ('b',  c_float),
                 ('a',  c_float)]

    def __init__(self,r,g,b,a):
        self.r = r
        self.g = g
        self.b = b
        self.a = a


class Vec2(Structure):
    _fields_ = [ ('x',  c_float),
                 ('y',  c_float)]

    def __init__(self,x,y):
        self.x = ctypes.c_float(x)
        self.y = ctypes.c_float(y)


class Vec2i(Structure):
    _fields_ = [ ('x',  c_short),
                 ('y',  c_short)]

    def __init__(self,x,y):
        self.x = x
        self.y = y



class Rect(Structure):
    _fields_ = [ ('x',  c_float),
                 ('y',  c_float),
                 ('w',  c_float),
                 ('h',  c_float)]

    def __init__(self,x,y,w,h):
        self.x = x
        self.y = y
        self.w = w
        self.h = h

class Recti(Structure):
    _fields_ = [ ('x',  c_short),
                 ('y',  c_short),
                 ('w',  c_short),
                 ('h',  c_short)]

    def __init__(self,x,y,w,h):
        self.x = x
        self.y = y
        self.w = w
        self.h = h


Handle = POINTER(ctypes.c_void_p)

class Image(Structure):
    _fields_ = [ ('handle', Handle),
                 ('w',  c_short),
                 ('h',  c_short),
                 ('region',  c_int)]

    def __init__(self,handle,w,h,region):
        self.handle = handle
        self.w = w
        self.h = h
        self.region = region

class Cursor(Structure):
    _fields_ = [ ('img', Image),
                 ('size',  Vec2),
                 ('offset', Vec2)]

    def __init__(self,image,size,offset):
        self.image = image
        self.size = size
        self.offset = offset

class Scroll(Structure):
    _fields_ = [ ('x', c_int),
                 ('y',  c_int)]

    def __init__(self,x,y):
        self.x = x
        self.y = y

class Heading(Enum):
    UP=0
    RIGHT=1
    DOWN=2
    LEFT=3

class ButtonBehavior(Enum):
    BUTTON_DEFAULT=0
    BUTTON_REPEATER=1

class Modify(Enum):
    FIXED=0
    MODIFIABLE=1

class Orientation(Enum):
    VERTICAL=0
    HORIZONTAL=1

class CollapseStates(Enum):
    MINIMIZED=0
    MAXIMIZED=1

class ShowStates(Enum):
    HIDDEN=0
    SHOWN=1

class ChartType(Enum):
    CHART_LINES=0
    CHART_COLUMN=1
    CHART_MAX=2

class ChartEvent(Enum):
    CHART_HOVERING=1
    CHART_CLICKED=2

class ColorFormat(Enum):
    RGB = 0
    RGBA = 1

class PopupType(Enum):
    POPUP_STATIC=0
    POPUP_DYNAMIC=1

class LayoutFormat(Enum):
    DYNAMIC=0
    STATIC=1

class TreeType(Enum):
    TREE_NODE=0
    TREE_TAB=1


class SymbolType(Enum):
    SYMBOL_NONE=0
    SYMBOL_X=1
    SYMBOL_UNDERSCORE=2
    SYMBOL_CIRCLE_SOLID=3
    SYMBOL_CIRCLE_OUTLINE=4
    SYMBOL_RECT_SOLID=5
    SYMBOL_RECT_OUTLINE=6
    SYMBOL_TRIANGLE_UP=7
    SYMBOL_TRIANGLE_DOWN=8
    SYMBOL_TRIANGLE_LEFT=9
    SYMBOL_TRIANGLE_RIGHT=10
    SYMBOL_PLUS=11
    SYMBOL_MINUS=12
    SYMBOL_MAX=13


# Context
# int nk_init_default(struct nk_context*, const struct nk_user_font*);
# int nk_init_fixed(struct nk_context*, void *memory, nk_size size, const struct nk_user_font*);
# int nk_init(struct nk_context*, struct nk_allocator*, const struct nk_user_font*);
# int nk_init_custom(struct nk_context*, struct nk_buffer *cmds, struct nk_buffer *pool, const struct nk_user_font*);
clear = _nuklear.nk_clear
clear.arglist = [POINTER(Context)]
# void nk_free(struct nk_context*);
# void nk_set_user_data(struct nk_context*, nk_handle handle);

# Input

## Keys
class Keys(Enum):
    NONE=0
    SHIFT=1
    CTRL=2
    DEL=3
    ENTER=4
    TAB=5
    BACKSPACE=6
    COPY=7
    CUT=8
    PASTE=9
    UP=10
    DOWN=11
    LEFT=12
    RIGHT=13
    TEXT_INSERT_MODE=14
    TEXT_REPLACE_MODE=15
    TEXT_RESET_MODE=16
    TEXT_LINE_START=17
    TEXT_LINE_END=18
    TEXT_START=19
    TEXT_END=20
    TEXT_UNDO=21
    TEXT_REDO=22
    TEXT_SELECT_ALL=23
    TEXT_WORD_LEFT=24
    TEXT_WORD_RIGHT=25
    SCROLL_START=26
    SCROLL_END=27
    SCROLL_DOWN=28
    SCROLL_UP=29
    MAX=30

## Buttons
class Buttons(Enum):
    LEFT=0
    MIDDLE=1
    RIGHT=2
    DOUBLE=3
    MAX=4

input_begin = _nuklear.nk_input_begin
input_begin.arglist = [POINTER(Context)]

input_motion = _nuklear.nk_input_motion
input_motion.arglist = [POINTER(Context), c_int, c_int]

input_key = _nuklear.nk_input_key
input_key.arglist = [POINTER(Context), c_int, c_int]

input_button = _nuklear.nk_input_button
input_button.arglist = [POINTER(Context), c_int, c_int, c_int, c_int]

input_scroll = _nuklear.nk_input_scroll
input_scroll.arglist = [POINTER(Context), Vec2]

# input_char = _nuklear.nk_input_char
# input_char.arglist = [POINTER(Context), c_char]


# input_glyph = _nuklear.nk_input_glyph
# input_glyph.arglist = [POINTER(Context), Glyph]

# input_unicode = _nuklear.nk_input_unicode
# input_unicode.arglist = [POINTER(Context, Rune)]

input_end = _nuklear.nk_input_end
input_end.arglist = [POINTER(Context)]

# Drawing
class AntiAliasing(Enum):
    OFF=0
    ON=1

class ConvertResult(Enum):
    SUCCESS = 0
    INVALID_PARAM = 1
    COMMAND_BUFFER_FULL = 1 << 0
    VERTEX_BUFFER_FULL = 1 << 1
    ELEMENT_BUFFER_FULL = 1 << 2


# const struct nk_command* nk__begin(struct nk_context*);
# const struct nk_command* nk__next(struct nk_context*, const struct nk_command*);
# nk_flags nk_convert(struct nk_context*, struct nk_buffer *cmds, struct nk_buffer *vertices, struct nk_buffer *elements, const struct nk_convert_config*);
# const struct nk_draw_command* nk__draw_begin(const struct nk_context*, const struct nk_buffer*);
# const struct nk_draw_command* nk__draw_end(const struct nk_context*, const struct nk_buffer*);
# const struct nk_draw_command* nk__draw_next(const struct nk_draw_command*, const struct nk_buffer*, const struct nk_context*);


# Window

class PanelFlags(Enum):
    WINDOW_BORDER            = 1 << 0
    WINDOW_MOVABLE           = 1 << 1
    WINDOW_SCALABLE          = 1 << 2
    WINDOW_CLOSABLE          = 1 << 3
    WINDOW_MINIMIZABLE       = 1 << 4
    WINDOW_NO_SCROLLBAR      = 1 << 5
    WINDOW_TITLE             = 1 << 6
    WINDOW_SCROLL_AUTO_HIDE  = 1 << 7
    WINDOW_BACKGROUND        = 1 << 8
    WINDOW_SCALE_LEFT        = 1 << 9
    WINDOW_NO_INPUT          = 1 << 10

__begin__ = _nuklear.nk_begin
__begin__.arglist = [POINTER(Context), c_char_p, Rect, c_uint]
__begin__.restype = c_int


__begin_titled__ = _nuklear.nk_begin_titled
__begin_titled__.arglist = [POINTER(Context), c_char_p, c_char_p, Rect, c_int]
__begin_titled__.restype = c_int

__end__            = _nuklear.nk_end
__end__.arglist    = [POINTER(Context)]
# struct nk_window *nk_window_find(POINTER(Context), c_char_p name);
__window_get_bounds__ = _nuklear.nk_window_get_bounds
__window_get_bounds__.arglist = [POINTER(Context)]
__window_get_bounds__.restype = Rect

__window_get_position__ = _nuklear.nk_window_get_position
__window_get_position__.arglist = [POINTER(Context)]
__window_get_position__.restype = Vec2

__window_get_size__ = _nuklear.nk_window_get_size
__window_get_size__.arglist = [POINTER(Context)]
__window_get_size__.restype = Vec2

__window_get_width__ = _nuklear.nk_window_get_width
__window_get_width__.arglist = [POINTER(Context)]
__window_get_width__.restype = c_float

__window_get_height__ = _nuklear.nk_window_get_height
__window_get_height__.arglist = [POINTER(Context)]
__window_get_height__.restype = c_float

# struct nk_panel* nk_window_get_panel(POINTER(Context));

__nk_window_get_content_region__ = _nuklear.nk_window_get_content_region
__nk_window_get_content_region__.arglist = [POINTER(Context)]
__nk_window_get_content_region__.restype = Rect

__nk_window_get_content_region_min__ = _nuklear.nk_window_get_content_region_min
__nk_window_get_content_region_min__.arglist = [POINTER(Context)]
__nk_window_get_content_region_min__.restype = Vec2

__nk_window_get_content_region_max__ = _nuklear.nk_window_get_content_region_max
__nk_window_get_content_region_max__.arglist = [POINTER(Context)]
__nk_window_get_content_region_max__.restype = Vec2

# Vec2 nk_window_get_content_region_size(POINTER(Context));
# struct nk_command_buffer* nk_window_get_canvas(POINTER(Context));

__window_has_focus__ = _nuklear.nk_window_has_focus
__window_has_focus__.arglist = [POINTER(Context)]
__window_has_focus__.restype = c_int

__window_is_collapsed__ = _nuklear.nk_window_is_collapsed
__window_is_collapsed__.arglist = [POINTER(Context), c_char_p]
__window_is_collapsed__.restype = c_int

__window_is_closed__ = _nuklear.nk_window_is_closed
__window_is_closed__.arglist = [POINTER(Context), c_char_p]
__window_is_closed__.restype = c_int

__window_is_hidden__ = _nuklear.nk_window_is_hidden
__window_is_hidden__.arglist = [POINTER(Context), c_char_p]
__window_is_hidden__.restype = c_int

__window_is_active__ = _nuklear.nk_window_is_active
__window_is_active__.arglist = [POINTER(Context), c_char_p]
__window_is_active__.restype = c_int

__window_is_hovered__ = _nuklear.nk_window_is_hovered
__window_is_hovered__.arglist = [POINTER(Context)]
__window_is_hovered__.restype = c_int

__window_is_any_hovered__ = _nuklear.nk_window_is_any_hovered
__window_is_any_hovered__.arglist = [POINTER(Context)]
__window_is_any_hovered__.restype = c_int


__item_is_any_active__ = _nuklear.nk_item_is_any_active
__item_is_any_active__.arglist = [POINTER(Context)]
__item_is_any_active__.restype = c_int

__window_set_bounds__ = _nuklear.nk_window_set_bounds
__window_set_bounds__.arglist = [POINTER(Context), c_char_p, Rect]

__window_set_position__ = _nuklear.nk_window_set_position
__window_set_position__.arglist = [POINTER(Context), c_char_p, Vec2]

__window_set_size__ = _nuklear.nk_window_set_size
__window_set_size__.arglist = [POINTER(Context), c_char_p, Vec2]

__window_set_focus__ = _nuklear.nk_window_set_focus
__window_set_focus__.arglist = [POINTER(Context), c_char_p]

__window_close__ = _nuklear.nk_window_close
__window_close__.arglist = [POINTER(Context), c_char_p]

__window_collapse__ = _nuklear.nk_window_collapse
__window_collapse__.arglist = [POINTER(Context), c_char_p, c_int]

__window_collapse_if__ = _nuklear.nk_window_collapse_if
__window_collapse_if__.arglist = [POINTER(Context), c_char_p, c_int, c_int]

__window_show__ = _nuklear.nk_window_show
__window_show__.arglist = [POINTER(Context), c_char_p, c_int]

__window_show_if__ = _nuklear.nk_window_show_if
__window_show_if__.arglist = [POINTER(Context), c_char_p, c_int, c_int]

# Layout
__layout_set_min_row_height__ = _nuklear.nk_layout_set_min_row_height
__layout_set_min_row_height__.arglist = [POINTER(Context), c_float]

__layout_reset_min_row_height__ = _nuklear.nk_layout_reset_min_row_height
__layout_reset_min_row_height__.arglist = [POINTER(Context)]

__layout_widget_bounds__ = _nuklear.nk_layout_widget_bounds
__layout_widget_bounds__.arglist = [POINTER(Context)]
__layout_widget_bounds__.restype = Rect

__layout_ratio_from_pixel__ = _nuklear.nk_layout_ratio_from_pixel
__layout_ratio_from_pixel__.arglist = [POINTER(Context), c_float]
__layout_ratio_from_pixel__.restype = c_float

__layout_row_dynamic__ = _nuklear.nk_layout_row_dynamic
__layout_row_dynamic__.arglist = [POINTER(Context), c_float, c_int]

__layout_row_static__ = _nuklear.nk_layout_row_static
__layout_row_static__.arglist = [POINTER(Context), c_float, c_int, c_int]

__layout_row_begin__ = _nuklear.nk_layout_row_begin
__layout_row_begin__.arglist = [POINTER(Context), c_int, c_float, c_int]

__layout_row_push__ = _nuklear.nk_layout_row_push
__layout_row_push__.arglist = [POINTER(Context), c_float]

__layout_row_end__ = _nuklear.nk_layout_row_end
__layout_row_end__.arglist = [POINTER(Context)]

__layout_row__ = _nuklear.nk_layout_row
__layout_row__.arglist = [POINTER(Context), c_int, c_float, c_int, POINTER(c_float)]

__layout_row_template_begin__ = _nuklear.nk_layout_row_template_begin
__layout_row_template_begin__.arglist = [POINTER(Context), c_float]

__layout_row_template_push_dynamic__ = _nuklear.nk_layout_row_template_push_dynamic
__layout_row_template_push_dynamic__.arglist = [POINTER(Context)]

__layout_row_template_push_variable__ = _nuklear.nk_layout_row_template_push_variable
__layout_row_template_push_variable__.arglist = [POINTER(Context), c_float ]

__layout_row_template_push_static__ = _nuklear.nk_layout_row_template_push_static
__layout_row_template_push_static__.arglist = [POINTER(Context), c_float]

__layout_row_template_end__ = _nuklear.nk_layout_row_template_end
__layout_row_template_end__.arglist = [POINTER(Context)]

__layout_space_begin__ = _nuklear.nk_layout_space_begin
__layout_space_begin__.arglist = [POINTER(Context), c_int, c_float, c_int]

__layout_space_push__ = _nuklear.nk_layout_space_push
__layout_space_push__.arglist = [POINTER(Context), Rect]

__layout_space_end__ = _nuklear.nk_layout_space_end
__layout_space_end__.arglist = [POINTER(Context)]

__layout_space_bounds__ = _nuklear.nk_layout_space_bounds
__layout_space_bounds__.arglist = [POINTER(Context)]
__layout_space_bounds__.restype = Rect

__layout_space_to_screen__ = _nuklear.nk_layout_space_to_screen
__layout_space_to_screen__.arglist = [POINTER(Context), Vec2]
__layout_space_to_screen__.restype = Vec2

__layout_space_to_local__ = _nuklear.nk_layout_space_to_local
__layout_space_to_local__.arglist = [POINTER(Context), Vec2]
__layout_space_to_local__.restype = Vec2

__layout_space_rect_to_screen__ = _nuklear.nk_layout_space_rect_to_screen
__layout_space_rect_to_screen__.arglist = [POINTER(Context), Rect]
__layout_space_rect_to_screen__.restype = Rect

__layout_space_rect_to_local__ = _nuklear.nk_layout_space_rect_to_local
__layout_space_rect_to_local__.arglist = [POINTER(Context), Rect]
__layout_space_rect_to_local__.restype = Rect



# Group

__group_begin__ = _nuklear.nk_group_begin
__group_begin__.arglist = [POINTER(Context), c_char_p, c_int]
__group_begin__.restype = c_int

# int nk_group_scrolled_offset_begin(struct nk_context*, nk_uint *x_offset, nk_uint *y_offset, const char*, nk_flags);
# int nk_group_scrolled_begin(struct nk_context*, struct nk_scroll*, const char *title, nk_flags);
# void nk_group_scrolled_end(struct nk_context*);

__group_end__ = _nuklear.nk_group_end
__group_end__.arglist = [POINTER(Context)]



# List View

# int nk_list_view_begin(struct nk_context*, struct nk_list_view *out, const char *id, nk_flags, int row_height, int row_count);
# void nk_list_view_end(struct nk_list_view*);

# Tree
__tree_push_hashed__ = _nuklear.nk_tree_push_hashed
__tree_push_hashed__.arglist = [POINTER(Context), c_int, c_char_p, c_int, c_char_p,c_int,c_int]
__tree_push_hashed__.restype = c_int

def __tree_push__(ctx, theType, title, state):
    (filename, line_number,
     function_name, lines, index) = callerFrameInfo()
    return __tree_push_hashed__(ctx, theType, str.encode(title), state, filename, len(filename),line_number)

def __tree_push_id__(ctx, theType, title, state, id):
    (filename, line_number,
     function_name, lines, index) = callerFrameInfo()
    return __tree_push_hashed__(ctx, theType, str.encode(title), state, filename, len(filename),id)


# int nk_tree_image_push_hashed(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states initial_state, const char *hash, int len,int seed);

__tree_pop__ = _nuklear.nk_tree_pop
__tree_pop__.arglist = [POINTER(Context)]

__tree_state_push__ = _nuklear.nk_tree_state_push
__tree_state_push__.arglist = [POINTER(Context), c_int, c_char_p, POINTER(c_int)]
__tree_state_push__.restype = c_int


# int nk_tree_state_image_push(struct nk_context*, enum nk_tree_type, struct nk_image, const char *title, enum nk_collapse_states *state);
# void nk_tree_state_pop(struct nk_context*);

# Widget

class WidgetLayoutStates(Enum):
    INVALID=0
    VALID=1
    ROM=2


class WidgetStates(Enum):
    MODIFIED    = 1 << 0
    INACTIVE    = 1 << 1
    ENTERED     = 1 << 2
    HOVER       = 1 << 3
    ACTIVED     = 1 << 4
    LEFT        = 1 << 5
    HOVERED     = HOVER|MODIFIED
    ACTIVE      = ACTIVED|MODIFIED


# enum nk_widget_layout_states nk_widget(struct nk_rect*, const struct nk_context*);
# enum nk_widget_layout_states nk_widget_fitting(struct nk_rect*, struct nk_context*, struct nk_vec2);
__widget_bounds__ = _nuklear.nk_widget_bounds
__widget_bounds__.arglist = [POINTER(Context)]
__widget_bounds__.restype = Rect
# struct nk_vec2 nk_widget_position(struct nk_context*);
# struct nk_vec2 nk_widget_size(struct nk_context*);
__widget_width__ = _nuklear.nk_widget_width
__widget_width__.arglist = [POINTER(Context)]
__widget_width__.restype = c_float

__widget_height__ = _nuklear.nk_widget_height
__widget_height__.arglist = [POINTER(Context)]
__widget_height__.restype = c_float
# int nk_widget_is_hovered(struct nk_context*);
# int nk_widget_is_mouse_clicked(struct nk_context*, enum nk_buttons);
# int nk_widget_has_mouse_click_down(struct nk_context*, enum nk_buttons, int down);
# void nk_spacing(struct nk_context*, int columns);


# Text

class TextAlign(Enum):
    LEFT        = 0x01
    CENTERED    = 0x02
    RIGHT       = 0x04
    TOP         = 0x08
    MIDDLE      = 0x10
    BOTTOM      = 0x20

    TEXT_LEFT        = MIDDLE|LEFT
    TEXT_CENTERED    = MIDDLE|CENTERED
    TEXT_RIGHT       = MIDDLE|RIGHT


__text__ = _nuklear.nk_text
__text__.arglist = [POINTER(Context), c_char_p, c_int, c_int]

# void nk_text_colored(struct nk_context*, const char*, int, nk_flags, struct nk_color);
# void nk_text_wrap(struct nk_context*, const char*, int);
# void nk_text_wrap_colored(struct nk_context*, const char*, int, struct nk_color);

__label__ = _nuklear.nk_label
__label__.arglist = [POINTER(Context), c_char_p, c_uint]

__label_colored__ = _nuklear.nk_label_colored
__label_colored__.arglist = [POINTER(Context), c_char_p, c_int, Color]

__label_wrap__ = _nuklear.nk_label_wrap
__label_wrap__.arglist = [POINTER(Context), c_char_p]


# void nk_label_colored_wrap(struct nk_context*, const char*, struct nk_color);
# void nk_image(struct nk_context*, struct nk_image);

# NO NEED TO BIND LABELF, python already has formatting abilities
#__labelf__ = _nuklear.nk_labelf
#__labelf__.arglist = [POINTER(Context), c_int, c_char_p]

# void nk_labelf_colored(struct nk_context*, nk_flags align, struct nk_color, const char*,...);
# void nk_labelf_wrap(struct nk_context*, const char*,...);
# void nk_labelf_colored_wrap(struct nk_context*, struct nk_color, const char*,...);
# void nk_value_bool(struct nk_context*, const char *prefix, int);
# void nk_value_int(struct nk_context*, const char *prefix, int);
# void nk_value_uint(struct nk_context*, const char *prefix, unsigned int);
# void nk_value_float(struct nk_context*, const char *prefix, float);
# void nk_value_color_byte(struct nk_context*, const char *prefix, struct nk_color);
# void nk_value_color_float(struct nk_context*, const char *prefix, struct nk_color);
# void nk_value_color_hex(struct nk_context*, const char *prefix, struct nk_color);


# Button

# int nk_button_text(struct nk_context*, const char *title, int len);
__button_label__ = _nuklear.nk_button_label
__button_label__.arglist = [POINTER(Context), c_char_p]
__button_label__.restype     = c_int


__button_color__ = _nuklear.nk_button_color
__button_color__.arglist = [POINTER(Context), Color]
__button_color__.restype = c_int

__button_symbol__ = _nuklear.nk_button_symbol
__button_symbol__.arglist = [POINTER(Context), c_int]
__button_symbol__.restype = c_int

# int nk_button_image(struct nk_context*, struct nk_image img);

__button_symbol_label__ = _nuklear.nk_button_symbol_label
__button_symbol_label__.arglist = [POINTER(Context), c_int, c_char_p, c_int]
__button_symbol_label__.restype = c_int

# int nk_button_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
# int nk_button_image_label(struct nk_context*, struct nk_image img, const char*, nk_flags text_alignment);
# int nk_button_image_text(struct nk_context*, struct nk_image img, const char*, int, nk_flags alignment);
# int nk_button_text_styled(struct nk_context*, const struct nk_style_button*, const char *title, int len);
# int nk_button_label_styled(struct nk_context*, const struct nk_style_button*, const char *title);
# int nk_button_symbol_styled(struct nk_context*, const struct nk_style_button*, enum nk_symbol_type);
# int nk_button_image_styled(struct nk_context*, const struct nk_style_button*, struct nk_image img);
# int nk_button_symbol_text_styled(struct nk_context*,const struct nk_style_button*, enum nk_symbol_type, const char*, int, nk_flags alignment);
# int nk_button_symbol_label_styled(struct nk_context *ctx, const struct nk_style_button *style, enum nk_symbol_type symbol, const char *title, nk_flags align);
# int nk_button_image_label_styled(struct nk_context*,const struct nk_style_button*, struct nk_image img, const char*, nk_flags text_alignment);
# int nk_button_image_text_styled(struct nk_context*,const struct nk_style_button*, struct nk_image img, const char*, int, nk_flags alignment);


__button_set_behavior__ = _nuklear.nk_button_set_behavior
__button_set_behavior__.arglist = [POINTER(Context), c_int]

# int nk_button_push_behavior(struct nk_context*, enum nk_button_behavior);
# int nk_button_pop_behavior(struct nk_context*);


# Checkbox
# int nk_check_label(struct nk_context*, const char*, int active);
# int nk_check_text(struct nk_context*, const char*, int,int active);
# unsigned nk_check_flags_label(struct nk_context*, const char*, unsigned int flags, unsigned int value);
# unsigned nk_check_flags_text(struct nk_context*, const char*, int, unsigned int flags, unsigned int value);

__checkbox_label__ = _nuklear.nk_checkbox_label
__checkbox_label__.arglist = [POINTER(Context), c_char_p, POINTER(c_int)]
__checkbox_label__.restype = c_int



# int nk_checkbox_text(struct nk_context*, const char*, int, int *active);
# int nk_checkbox_flags_label(struct nk_context*, const char*, unsigned int *flags, unsigned int value);
# int nk_checkbox_flags_text(struct nk_context*, const char*, int, unsigned int *flags, unsigned int value);


# Radio Button

# int nk_radio_label(struct nk_context*, const char*, int *active);
# int nk_radio_text(struct nk_context*, const char*, int, int *active);

__option_label__ = _nuklear.nk_option_label
__option_label__.arglist = [POINTER(Context), c_char_p, c_int]
__option_label__.restype = c_int


# int nk_option_text(struct nk_context*, const char*, int, int active);

__selectable_label__ = _nuklear.nk_selectable_label
__selectable_label__.arglist = [POINTER(Context), c_char_p, c_int, POINTER(c_int)]
__selectable_label__.restype = c_int


# Selectable
# int nk_selectable_label(struct nk_context*, const char*, nk_flags align, int *value);
# int nk_selectable_text(struct nk_context*, const char*, int, nk_flags align, int *value);
# int nk_selectable_image_label(struct nk_context*,struct nk_image,  const char*, nk_flags align, int *value);
# int nk_selectable_image_text(struct nk_context*,struct nk_image, const char*, int, nk_flags align, int *value);
# int nk_select_label(struct nk_context*, const char*, nk_flags align, int value);
# int nk_select_text(struct nk_context*, const char*, int, nk_flags align, int value);
# int nk_select_image_label(struct nk_context*, struct nk_image,const char*, nk_flags align, int value);
# int nk_select_image_text(struct nk_context*, struct nk_image,const char*, int, nk_flags align, int value);


# Slider
# float nk_slide_float(struct nk_context*, float min, float val, float max, float step);


__slide_int__ = _nuklear.nk_slide_int
__slide_int__.arglist = [POINTER(Context), c_int, c_int, c_int, c_int]
__slide_int__.restype = c_int



__slider_float__ = _nuklear.nk_slider_float
__slider_float__.arglist = [POINTER(Context), c_float, POINTER(c_float), c_float, c_float]
__slider_float__.restype = c_int


__slider_int__ = _nuklear.nk_slider_int
__slider_int__.arglist = [POINTER(Context), c_int, POINTER(c_int), c_int, c_int]
__slider_int__.restype = c_int



__progress__ = _nuklear.nk_progress
__progress__.arglist = [POINTER(Context), POINTER(c_int), c_int, c_int]
__progress__.restype = c_int


# ProgressBar
# int nk_progress(struct nk_context*, nk_size *cur, nk_size max, int modifyable);
# nk_size nk_prog(struct nk_context*, nk_size cur, nk_size max, int modifyable);

# ColorPicker#
__color_picker__ = _nuklear.nk_color_picker
__color_picker__.arglist = [POINTER(Context), ColorF, c_int]
__color_picker__.restype = ColorF
# int nk_color_pick(struct nk_context*, struct nk_colorf*, enum nk_color_format);


# Properties

__property_int__ = _nuklear.nk_property_int
__property_int__.arglist = [POINTER(Context), c_char_p, c_int, c_int, c_int, c_int, c_float]


__property_float__ = _nuklear.nk_property_float
__property_float__.arglist = [POINTER(Context), c_char_p, c_float, POINTER(c_float), c_float, c_float, c_float]
# void nk_property_double(struct nk_context*, const char *name, double min, double *val, double max, double step, float inc_per_pixel);

__propertyi__ = _nuklear.nk_propertyi
__propertyi__.arglist = [POINTER(Context), c_char_p, c_int, c_int, c_int, c_int, c_float]
__propertyi__.restype = c_int


__propertyf__ = _nuklear.nk_propertyf
__propertyf__.arglist = [POINTER(Context), c_char_p, c_float, c_float, c_float, c_float, c_float]
__propertyf__.restype = c_float
# double nk_propertyd(struct nk_context*, const char *name, double min, double val, double max, double step, float inc_per_pixel);


# TextEdit
class EditFlags(Enum):
    DEFAULT                 = 0,
    READ_ONLY               = 1 << 0
    AUTO_SELECT             = 1 << 1
    SIG_ENTER               = 1 << 2
    ALLOW_TAB               = 1 << 3
    NO_CURSOR               = 1 << 4
    SELECTABLE              = 1 << 5
    CLIPBOARD               = 1 << 6
    CTRL_ENTER_NEWLINE      = 1 << 7
    NO_HORIZONTAL_SCROLL    = 1 << 8
    ALWAYS_INSERT_MODE      = 1 << 9
    MULTILINE               = 1 << 10
    GOTO_END_ON_ACTIVATE    = 1 << 11


class EditTypes(Enum):
    SIMPLE  = EditFlags.ALWAYS_INSERT_MODE
    FIELD   = SIMPLE.value|EditFlags.SELECTABLE.value|EditFlags.CLIPBOARD.value
    BOX     = EditFlags.ALWAYS_INSERT_MODE.value| EditFlags.SELECTABLE.value| EditFlags.MULTILINE.value|EditFlags.ALLOW_TAB.value|EditFlags.CLIPBOARD.value
    EDITOR  = EditFlags.SELECTABLE.value|EditFlags.MULTILINE.value|EditFlags.ALLOW_TAB.value| EditFlags.CLIPBOARD.value


class EditEvents(Enum):
    ACTIVE      = 1 << 0
    INACTIVE    = 1 << 1
    ACTIVATED   = 1 << 2
    DEACTIVATED = 1 << 3
    COMMITED    = 1 << 4


filter_default = _nuklear.nk_filter_default
filter_ascii = _nuklear.nk_filter_ascii
filter_float = _nuklear.nk_filter_float
filter_decimal = _nuklear.nk_filter_decimal
filter_hex = _nuklear.nk_filter_hex
filter_oct = _nuklear.nk_filter_oct
filter_binary = _nuklear.nk_filter_binary


__edit_string__ = _nuklear.nk_edit_string
__edit_string__.arglist = [POINTER(Context), c_int, c_char_p, POINTER(c_int), c_int, ctypes.c_void_p]
__edit_string__.restype = c_int

# nk_flags nk_edit_string_zero_terminated(struct nk_context*, nk_flags, char *buffer, int max, nk_plugin_filter);
# nk_flags nk_edit_buffer(struct nk_context*, nk_flags, struct nk_text_edit*, nk_plugin_filter);
# void nk_edit_focus(struct nk_context*, nk_flags flags);
# void nk_edit_unfocus(struct nk_context*);

# Chart
__chart_begin__ = _nuklear.nk_chart_begin
__chart_begin__.arglist = [POINTER(Context), c_int, c_int, c_float, c_float]
__chart_begin__.restype = c_int

# int nk_chart_begin_colored(struct nk_context*, enum nk_chart_type, struct nk_color, struct nk_color active, int num, float min, float max);

__chart_add_slot__ = _nuklear.nk_chart_add_slot
__chart_add_slot__.arglist = [POINTER(Context), c_int, c_int, c_float, c_float]

# void nk_chart_add_slot_colored(struct nk_context *ctx, const enum nk_chart_type, struct nk_color, struct nk_color active, int count, float min_value, float max_value);

__chart_push__ = _nuklear.nk_chart_push
__chart_push__.arglist = [POINTER(Context), float]
__chart_push__.restype = c_int

__chart_push_slot__ = _nuklear.nk_chart_push_slot
__chart_push_slot__.arglist = [POINTER(Context), c_float, c_int]
__chart_push_slot__.restype = c_int


__chart_end__ = _nuklear.nk_chart_end
__chart_end__.arglist = [POINTER(Context)]

# void nk_plot(struct nk_context*, enum nk_chart_type, const float *values, int count, int offset);
# void nk_plot_function(struct nk_context*, enum nk_chart_type, void *userdata, float(*value_getter)(void* user, int index), int count, int offset);


# Popup

__popup_begin__ = _nuklear.nk_popup_begin
__popup_begin__.arglist= [POINTER(Context), c_int, c_char_p, c_int,Rect]
__popup_begin__.restype = c_int


# void nk_popup_close(struct nk_context*);

__popup_end__ = _nuklear.nk_popup_end
__popup_end__.arglist= [POINTER(Context)]


# void nk_popup_end(struct nk_context*);


# ComboBox
__combo__ = _nuklear.nk_combo
__combo__.arglist = [POINTER(Context), POINTER(POINTER(c_char_p)), c_int, c_int, c_int, Vec2]
__combo__.restype = c_int

# int nk_combo_separator(struct nk_context*, const char *items_separated_by_separator, int separator, int selected, int count, int item_height, struct nk_vec2 size);
# int nk_combo_string(struct nk_context*, const char *items_separated_by_zeros, int selected, int count, int item_height, struct nk_vec2 size);
# int nk_combo_callback(struct nk_context*, void(*item_getter)(void*, int, const char**), void *userdata, int selected, int count, int item_height, struct nk_vec2 size);
# void nk_combobox(struct nk_context*, const char **items, int count, int *selected, int item_height, struct nk_vec2 size);
# void nk_combobox_string(struct nk_context*, const char *items_separated_by_zeros, int *selected, int count, int item_height, struct nk_vec2 size);
# void nk_combobox_separator(struct nk_context*, const char *items_separated_by_separator, int separator,int *selected, int count, int item_height, struct nk_vec2 size);
# void nk_combobox_callback(struct nk_context*, void(*item_getter)(void*, int, const char**), void*, int *selected, int count, int item_height, struct nk_vec2 size);


# Abstract Combobox
# int nk_combo_begin_text(struct nk_context*, const char *selected, int, struct nk_vec2 size);
# int nk_combo_begin_label(struct nk_context*, const char *selected, struct nk_vec2 size);
__combo_begin_color__ = _nuklear.nk_combo_begin_color
__combo_begin_color__.arglist = [POINTER(Context), Color, Vec2]
__combo_begin_color__.restype = c_int
# int nk_combo_begin_symbol(struct nk_context*,  enum nk_symbol_type,  struct nk_vec2 size);
# int nk_combo_begin_symbol_label(struct nk_context*, const char *selected, enum nk_symbol_type, struct nk_vec2 size);
# int nk_combo_begin_symbol_text(struct nk_context*, const char *selected, int, enum nk_symbol_type, struct nk_vec2 size);
# int nk_combo_begin_image(struct nk_context*, struct nk_image img,  struct nk_vec2 size);
# int nk_combo_begin_image_label(struct nk_context*, const char *selected, struct nk_image, struct nk_vec2 size);
# int nk_combo_begin_image_text(struct nk_context*,  const char *selected, int, struct nk_image, struct nk_vec2 size);
# int nk_combo_item_label(struct nk_context*, const char*, nk_flags alignment);
# int nk_combo_item_text(struct nk_context*, const char*,int, nk_flags alignment);
# int nk_combo_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);
# int nk_combo_item_image_text(struct nk_context*, struct nk_image, const char*, int,nk_flags alignment);
# int nk_combo_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);
# int nk_combo_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
# void nk_combo_close(struct nk_context*);
__combo_end__ = _nuklear.nk_combo_end
__combo_end__.arglist = [POINTER(Context)]

# Contextual
__contextual_begin__  = _nuklear.nk_contextual_begin
__contextual_begin__.arglist = [POINTER(Context), c_int, Vec2, Rect]
__contextual_begin__.restype = c_int
# int nk_contextual_item_text(struct nk_context*, const char*, int,nk_flags align);
__contextual_item_label__ = _nuklear.nk_contextual_item_label
__contextual_item_label__.arglist = [POINTER(Context), c_char_p, c_int]
__contextual_item_label__.restype = c_int
# int nk_contextual_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);
# int nk_contextual_item_image_text(struct nk_context*, struct nk_image, const char*, int len, nk_flags alignment);
# int nk_contextual_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);
# int nk_contextual_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
# void nk_contextual_close(struct nk_context*);
__contextual_end__ = _nuklear.nk_contextual_end
__contextual_end__.arglist = [POINTER(Context)]

# Tooltip
__tooltip__ = _nuklear.nk_tooltip
__tooltip__.arglist = [POINTER(Context), c_char_p]

# void nk_tooltipf(struct nk_context*, const char*, ...);
# int nk_tooltip_begin(struct nk_context*, float width);
# void nk_tooltip_end(struct nk_context*);


# Menu
__menubar_begin__ = _nuklear.nk_menubar_begin
__menubar_begin__.arglist = [POINTER(Context)]

__menubar_end__ = _nuklear.nk_menubar_end
__menubar_end__.arglist = [POINTER(Context)]

# int nk_menu_begin_text(struct nk_context*, const char* title, int title_len, nk_flags align, struct nk_vec2 size);

__menu_begin_label__ = _nuklear.nk_menu_begin_label
__menu_begin_label__.arglist = [POINTER(Context), c_char_p, c_int, Vec2]
__menu_begin_label__.restype = c_int


# int nk_menu_begin_image(struct nk_context*, const char*, struct nk_image, struct nk_vec2 size);
# int nk_menu_begin_image_text(struct nk_context*, const char*, int,nk_flags align,struct nk_image, struct nk_vec2 size);
# int nk_menu_begin_image_label(struct nk_context*, const char*, nk_flags align,struct nk_image, struct nk_vec2 size);
# int nk_menu_begin_symbol(struct nk_context*, const char*, enum nk_symbol_type, struct nk_vec2 size);
# int nk_menu_begin_symbol_text(struct nk_context*, const char*, int,nk_flags align,enum nk_symbol_type, struct nk_vec2 size);
# int nk_menu_begin_symbol_label(struct nk_context*, const char*, nk_flags align,enum nk_symbol_type, struct nk_vec2 size);
# int nk_menu_item_text(struct nk_context*, const char*, int,nk_flags align);

__menu_item_label__ = _nuklear.nk_menu_item_label
__menu_item_label__.arglist = [POINTER(Context), c_char_p, c_int]
__menu_item_label__.restype = c_int

# int nk_menu_item_image_label(struct nk_context*, struct nk_image, const char*, nk_flags alignment);
# int nk_menu_item_image_text(struct nk_context*, struct nk_image, const char*, int len, nk_flags alignment);
# int nk_menu_item_symbol_text(struct nk_context*, enum nk_symbol_type, const char*, int, nk_flags alignment);
# int nk_menu_item_symbol_label(struct nk_context*, enum nk_symbol_type, const char*, nk_flags alignment);
# void nk_menu_close(struct nk_context*);

__menu_end__ = _nuklear.nk_menu_end
__menu_end__.arglist = [POINTER(Context)]


# Style

class StyleColors(Enum):
    TEXT=0
    WINDOW=1
    HEADER=2
    BORDER=3
    BUTTON=4
    BUTTON_HOVER=5
    BUTTON_ACTIVE=6
    TOGGLE=7
    TOGGLE_HOVER=8
    TOGGLE_CURSOR=9
    SELECT=10
    SELECT_ACTIVE=11
    SLIDER=12
    SLIDER_CURSOR=13
    SLIDER_CURSOR_HOVER=14
    SLIDER_CURSOR_ACTIVE=15
    PROPERTY=16
    EDIT=17
    EDIT_CURSOR=18
    COMBO=19
    CHART=20
    CHART_COLOR=21
    CHART_COLOR_HIGHLIGHT=22
    SCROLLBAR=23
    SCROLLBAR_CURSOR=24
    SCROLLBAR_CURSOR_HOVER=25
    SCROLLBAR_CURSOR_ACTIVE=26
    TAB_HEADER=27
    COUNT=28


class StyleCursor(Enum):
    ARROW=0
    TEXT=1
    MOVE=2
    RESIZE_VERTICAL=3
    RESIZE_HORIZONTAL=4
    RESIZE_TOP_LEFT_DOWN_RIGHT=5
    RESIZE_TOP_RIGHT_DOWN_LEFT=6
    COUN=7


# void nk_style_default(struct nk_context*);
# void nk_style_from_table(struct nk_context*, const struct nk_color*);
# void nk_style_load_cursor(struct nk_context*, enum nk_style_cursor, const struct nk_cursor*);
# void nk_style_load_all_cursors(struct nk_context*, struct nk_cursor*);
# const char* nk_style_get_color_by_name(enum nk_style_colors);
# void nk_style_set_font(struct nk_context*, const struct nk_user_font*);
# int nk_style_set_cursor(struct nk_context*, enum nk_style_cursor);
# void nk_style_show_cursor(struct nk_context*);
# void nk_style_hide_cursor(struct nk_context*);
# int nk_style_push_font(struct nk_context*, const struct nk_user_font*);
# int nk_style_push_float(struct nk_context*, float*, float);
# int nk_style_push_vec2(struct nk_context*, struct nk_vec2*, struct nk_vec2);
# int nk_style_push_style_item(struct nk_context*, struct nk_style_item*, struct nk_style_item);
# int nk_style_push_flags(struct nk_context*, nk_flags*, nk_flags);
# int nk_style_push_color(struct nk_context*, struct nk_color*, struct nk_color);

__style_pop_font__ = _nuklear.nk_style_pop_font
__style_pop_font__.arglist = [POINTER(Context)]
__style_pop_font__.restype = c_int

__style_pop_float__ = _nuklear.nk_style_pop_float
__style_pop_float__.arglist = [POINTER(Context)]
__style_pop_float__.restype = c_int

__style_pop_vec2__ = _nuklear.nk_style_pop_vec2
__style_pop_vec2__.arglist = [POINTER(Context)]
__style_pop_vec2__.restype = c_int

__style_pop_style_item__ = _nuklear.nk_style_pop_style_item
__style_pop_style_item__.arglist = [POINTER(Context)]
__style_pop_style_item__.restype = c_int

__style_pop_flags__ = _nuklear.nk_style_pop_flags
__style_pop_flags__.arglist = [POINTER(Context)]
__style_pop_flags__.restype = c_int

__style_pop_color__ = _nuklear.nk_style_pop_color
__style_pop_color__.arglist = [POINTER(Context)]
__style_pop_color__.restype = c_int



# struct nk_color nk_rgb(int r, int g, int b);


# Color
# struct nk_color nk_rgb(int r, int g, int b);
# struct nk_color nk_rgb_iv(const int *rgb);
# struct nk_color nk_rgb_bv(const nk_byte* rgb);
# struct nk_color nk_rgb_f(float r, float g, float b);
# struct nk_color nk_rgb_fv(const float *rgb);
__rgb_cf__ = _nuklear.nk_rgb_cf
__rgb_cf__.arglist = [ColorF]
__rgb_cf__.restype = Color
# struct nk_color nk_rgb_hex(const char *rgb);
# struct nk_color nk_rgba(int r, int g, int b, int a);
# struct nk_color nk_rgba_u32(nk_uint);
# struct nk_color nk_rgba_iv(const int *rgba);
# struct nk_color nk_rgba_bv(const nk_byte *rgba);
# struct nk_color nk_rgba_f(float r, float g, float b, float a);
# struct nk_color nk_rgba_fv(const float *rgba);
# struct nk_color nk_rgba_cf(struct nk_colorf c);
# struct nk_color nk_rgba_hex(const char *rgb);

# struct nk_colorf nk_hsva_colorf(float h, float s, float v, float a);
# struct nk_colorf nk_hsva_colorfv(float *c);
# void nk_colorf_hsva_f(float *out_h, float *out_s, float *out_v, float *out_a, struct nk_colorf in);
# void nk_colorf_hsva_fv(float *hsva, struct nk_colorf in);

# struct nk_color nk_hsv(int h, int s, int v);
# struct nk_color nk_hsv_iv(const int *hsv);
# struct nk_color nk_hsv_bv(const nk_byte *hsv);
# struct nk_color nk_hsv_f(float h, float s, float v);
# struct nk_color nk_hsv_fv(const float *hsv);
# struct nk_color nk_hsva(int h, int s, int v, int a);
# struct nk_color nk_hsva_iv(const int *hsva);
# struct nk_color nk_hsva_bv(const nk_byte *hsva);
# struct nk_color nk_hsva_f(float h, float s, float v, float a);
# struct nk_color nk_hsva_fv(const float *hsva);
# void nk_color_f(float *r, float *g, float *b, float *a, struct nk_color);
# void nk_color_fv(float *rgba_out, struct nk_color);
# struct nk_colorf nk_color_cf(struct nk_color);
# void nk_color_d(double *r, double *g, double *b, double *a, struct nk_color);
# void nk_color_dv(double *rgba_out, struct nk_color);
# nk_uint nk_color_u32(struct nk_color);
# void nk_color_hex_rgba(char *output, struct nk_color);
# void nk_color_hex_rgb(char *output, struct nk_color);
# void nk_color_hsv_i(int *out_h, int *out_s, int *out_v, struct nk_color);
# void nk_color_hsv_b(nk_byte *out_h, nk_byte *out_s, nk_byte *out_v, struct nk_color);
# void nk_color_hsv_iv(int *hsv_out, struct nk_color);
# void nk_color_hsv_bv(nk_byte *hsv_out, struct nk_color);
# void nk_color_hsv_f(float *out_h, float *out_s, float *out_v, struct nk_color);
# void nk_color_hsv_fv(float *hsv_out, struct nk_color);
# void nk_color_hsva_i(int *h, int *s, int *v, int *a, struct nk_color);
# void nk_color_hsva_b(nk_byte *h, nk_byte *s, nk_byte *v, nk_byte *a, struct nk_color);
# void nk_color_hsva_iv(int *hsva_out, struct nk_color);
# void nk_color_hsva_bv(nk_byte *hsva_out, struct nk_color);
# void nk_color_hsva_f(float *out_h, float *out_s, float *out_v, float *out_a, struct nk_color);
# void nk_color_hsva_fv(float *hsva_out, struct nk_color);


# Image# nk_handle nk_handle_ptr(void*);
# nk_handle nk_handle_id(int);
# struct nk_image nk_image_handle(nk_handle);
# struct nk_image nk_image_ptr(void*);
# struct nk_image nk_image_id(int);
# int nk_image_is_subimage(const struct nk_image* img);
# struct nk_image nk_subimage_ptr(void*, unsigned short w, unsigned short h, struct nk_rect sub_region);
# struct nk_image nk_subimage_id(int, unsigned short w, unsigned short h, struct nk_rect sub_region);
# struct nk_image nk_subimage_handle(nk_handle, unsigned short w, unsigned short h, struct nk_rect sub_region);


# Math# nk_hash nk_murmur_hash(const void *key, int len, nk_hash seed);
# void nk_triangle_from_direction(struct nk_vec2 *result, struct nk_rect r, float pad_x, float pad_y, enum nk_heading);
# struct nk_vec2 nk_vec2(float x, float y);
# struct nk_vec2 nk_vec2i(int x, int y);
# struct nk_vec2 nk_vec2v(const float *xy);
# struct nk_vec2 nk_vec2iv(const int *xy);
# struct nk_rect nk_get_null_rect(void);
# struct nk_rect nk_rect(float x, float y, float w, float h);
# struct nk_rect nk_recti(int x, int y, int w, int h);
# struct nk_rect nk_recta(struct nk_vec2 pos, struct nk_vec2 size);
# struct nk_rect nk_rectv(const float *xywh);
# struct nk_rect nk_rectiv(const int *xywh);
# struct nk_vec2 nk_rect_pos(struct nk_rect);
# struct nk_vec2 nk_rect_size(struct nk_rect);
# int nk_strlen(const char *str);

# String# int nk_strlen(const char *str);
# int nk_stricmp(const char *s1, const char *s2);
# int nk_stricmpn(const char *s1, const char *s2, int n);
# int nk_strtoi(const char *str, const char **endptr);
# float nk_strtof(const char *str, const char **endptr);
# double nk_strtod(const char *str, const char **endptr);
# int nk_strfilter(const char *text, const char *regexp);
# int nk_strmatch_fuzzy_string(char const *str, char const *pattern, int *out_score);
# int nk_strmatch_fuzzy_text(const char *txt, int txt_len, const char *pattern, int *out_score);

# UTF 8
# int nk_utf_decode(const char*, nk_rune*, int);
# int nk_utf_encode(nk_rune, char*, int);
# int nk_utf_len(const char*, int byte_len);
# const char* nk_utf_at(const char *buffer, int length, int index, nk_rune *unicode, int *len);


# Font


class FontCoordType(Enum):
    UV=0
    PIXEL=1



class FontAtlasFormat(Enum):
    ALPHA8=0
    RGBA32=1


# const nk_rune *nk_font_default_glyph_ranges(void);
# const nk_rune *nk_font_chinese_glyph_ranges(void);
# const nk_rune *nk_font_cyrillic_glyph_ranges(void);
# const nk_rune *nk_font_korean_glyph_ranges(void);
# void nk_font_atlas_init_default(struct nk_font_atlas*);
# void nk_font_atlas_init(struct nk_font_atlas*, struct nk_allocator*);
# void nk_font_atlas_init_custom(struct nk_font_atlas*, struct nk_allocator *persistent, struct nk_allocator *transient);
# void nk_font_atlas_begin(struct nk_font_atlas*);
# struct nk_font_config nk_font_config(float pixel_height);
# struct nk_font *nk_font_atlas_add(struct nk_font_atlas*, const struct nk_font_config*);
# struct nk_font* nk_font_atlas_add_default(struct nk_font_atlas*, float height, const struct nk_font_config*);
# struct nk_font* nk_font_atlas_add_from_memory(struct nk_font_atlas *atlas, void *memory, nk_size size, float height, const struct nk_font_config *config);
# struct nk_font* nk_font_atlas_add_from_file(struct nk_font_atlas *atlas, const char *file_path, float height, const struct nk_font_config*);
# struct nk_font *nk_font_atlas_add_compressed(struct nk_font_atlas*, void *memory, nk_size size, float height, const struct nk_font_config*);
# struct nk_font* nk_font_atlas_add_compressed_base85(struct nk_font_atlas*, const char *data, float height, const struct nk_font_config *config);
# const void* nk_font_atlas_bake(struct nk_font_atlas*, int *width, int *height, enum nk_font_atlas_format);
# void nk_font_atlas_end(struct nk_font_atlas*, nk_handle tex, struct nk_draw_null_texture*);
# const struct nk_font_glyph* nk_font_find_glyph(struct nk_font*, nk_rune unicode);
# void nk_font_atlas_cleanup(struct nk_font_atlas *atlas);
# void nk_font_atlas_clear(struct nk_font_atlas*);


# Memory Buffer


class AllocationType(Enum):
    FIXED=0
    DYNAMIC=1

class BufferAllocationType(Enum):
    FRONT=0
    BACK=1
    MAX=2

# void nk_buffer_init_default(struct nk_buffer*);
# void nk_buffer_init(struct nk_buffer*, const struct nk_allocator*, nk_size size);
# void nk_buffer_init_fixed(struct nk_buffer*, void *memory, nk_size size);
# void nk_buffer_info(struct nk_memory_status*, struct nk_buffer*);
# void nk_buffer_push(struct nk_buffer*, enum nk_buffer_allocation_type type, const void *memory, nk_size size, nk_size align);
# void nk_buffer_mark(struct nk_buffer*, enum nk_buffer_allocation_type type);
# void nk_buffer_reset(struct nk_buffer*, enum nk_buffer_allocation_type type);
# void nk_buffer_clear(struct nk_buffer*);
# void nk_buffer_free(struct nk_buffer*);
# void *nk_buffer_memory(struct nk_buffer*);
# const void *nk_buffer_memory_const(const struct nk_buffer*);
# nk_size nk_buffer_total(struct nk_buffer*);


# String
# void nk_str_init_default(struct nk_str*);
# void nk_str_init(struct nk_str*, const struct nk_allocator*, nk_size size);
# void nk_str_init_fixed(struct nk_str*, void *memory, nk_size size);
# void nk_str_clear(struct nk_str*);
# void nk_str_free(struct nk_str*);
# int nk_str_append_text_char(struct nk_str*, const char*, int);
# int nk_str_append_str_char(struct nk_str*, const char*);
# int nk_str_append_text_utf8(struct nk_str*, const char*, int);
# int nk_str_append_str_utf8(struct nk_str*, const char*);
# int nk_str_append_text_runes(struct nk_str*, const nk_rune*, int);
# int nk_str_append_str_runes(struct nk_str*, const nk_rune*);
# int nk_str_insert_at_char(struct nk_str*, int pos, const char*, int);
# int nk_str_insert_at_rune(struct nk_str*, int pos, const char*, int);
# int nk_str_insert_text_char(struct nk_str*, int pos, const char*, int);
# int nk_str_insert_str_char(struct nk_str*, int pos, const char*);
# int nk_str_insert_text_utf8(struct nk_str*, int pos, const char*, int);
# int nk_str_insert_str_utf8(struct nk_str*, int pos, const char*);
# int nk_str_insert_text_runes(struct nk_str*, int pos, const nk_rune*, int);
# int nk_str_insert_str_runes(struct nk_str*, int pos, const nk_rune*);
# void nk_str_remove_chars(struct nk_str*, int len);
# void nk_str_remove_runes(struct nk_str *str, int len);
# void nk_str_delete_chars(struct nk_str*, int pos, int len);
# void nk_str_delete_runes(struct nk_str*, int pos, int len);
# char *nk_str_at_char(struct nk_str*, int pos);
# char *nk_str_at_rune(struct nk_str*, int pos, nk_rune *unicode, int *len);
# nk_rune nk_str_rune_at(const struct nk_str*, int pos);
# const char *nk_str_at_char_const(const struct nk_str*, int pos);
# const char *nk_str_at_const(const struct nk_str*, int pos, nk_rune *unicode, int *len);
# char *nk_str_get(struct nk_str*);
# const char *nk_str_get_const(const struct nk_str*);
# int nk_str_len(struct nk_str*);
# int nk_str_len_char(struct nk_str*);

# Text Editor


class TextEditType(Enum):
    SINGLE_LINE=0
    MULTI_LINE=1

class TextEditMode(Enum):
    VIEW=0
    INSERT=1
    REPLACE=2


# int nk_filter_default(const struct nk_text_edit*, nk_rune unicode);
# int nk_filter_ascii(const struct nk_text_edit*, nk_rune unicode);
# int nk_filter_float(const struct nk_text_edit*, nk_rune unicode);
# int nk_filter_decimal(const struct nk_text_edit*, nk_rune unicode);
# int nk_filter_hex(const struct nk_text_edit*, nk_rune unicode);
# int nk_filter_oct(const struct nk_text_edit*, nk_rune unicode);
# int nk_filter_binary(const struct nk_text_edit*, nk_rune unicode);
# void nk_textedit_init_default(struct nk_text_edit*);
# void nk_textedit_init(struct nk_text_edit*, struct nk_allocator*, nk_size size);
# void nk_textedit_init_fixed(struct nk_text_edit*, void *memory, nk_size size);
# void nk_textedit_free(struct nk_text_edit*);
# void nk_textedit_text(struct nk_text_edit*, const char*, int total_len);
# void nk_textedit_delete(struct nk_text_edit*, int where, int len);
# void nk_textedit_delete_selection(struct nk_text_edit*);
# void nk_textedit_select_all(struct nk_text_edit*);
# int nk_textedit_cut(struct nk_text_edit*);
# int nk_textedit_paste(struct nk_text_edit*, char const*, int len);
# void nk_textedit_undo(struct nk_text_edit*);
# void nk_textedit_redo(struct nk_text_edit*);

# Drawing
class CommandType(Enum):
    NOP=0
    SCISSOR=1
    LINE=2
    CURVE=3
    RECT=4
    RECT_FILLED=5
    RECT_MULTI_COLOR=6
    CIRCLE=7
    CIRCLE_FILLED=8
    ARC=9
    ARC_FILLED=10
    TRIANGLE=11
    TRIANGLE_FILLED=12
    POLYGON=13
    POLYGON_FILLED=14
    POLYLINE=15
    TEXT=16
    IMAGE=17
    CUSTOM=18

class CommandScissor(Enum):
    OFF = 0
    ON = 1



# void nk_stroke_line(struct nk_command_buffer *b, float x0, float y0, float x1, float y1, float line_thickness, struct nk_color);
# void nk_stroke_curve(struct nk_command_buffer*, float, float, float, float, float, float, float, float, float line_thickness, struct nk_color);
# void nk_stroke_rect(struct nk_command_buffer*, struct nk_rect, float rounding, float line_thickness, struct nk_color);
# void nk_stroke_circle(struct nk_command_buffer*, struct nk_rect, float line_thickness, struct nk_color);
# void nk_stroke_arc(struct nk_command_buffer*, float cx, float cy, float radius, float a_min, float a_max, float line_thickness, struct nk_color);
# void nk_stroke_triangle(struct nk_command_buffer*, float, float, float, float, float, float, float line_thichness, struct nk_color);
# void nk_stroke_polyline(struct nk_command_buffer*, float *points, int point_count, float line_thickness, struct nk_color col);
# void nk_stroke_polygon(struct nk_command_buffer*, float*, int point_count, float line_thickness, struct nk_color);
# void nk_fill_rect(struct nk_command_buffer*, struct nk_rect, float rounding, struct nk_color);
# void nk_fill_rect_multi_color(struct nk_command_buffer*, struct nk_rect, struct nk_color left, struct nk_color top, struct nk_color right, struct nk_color bottom);
# void nk_fill_circle(struct nk_command_buffer*, struct nk_rect, struct nk_color);
# void nk_fill_arc(struct nk_command_buffer*, float cx, float cy, float radius, float a_min, float a_max, struct nk_color);
# void nk_fill_triangle(struct nk_command_buffer*, float x0, float y0, float x1, float y1, float x2, float y2, struct nk_color);
# void nk_fill_polygon(struct nk_command_buffer*, float*, int point_count, struct nk_color);
# void nk_draw_image(struct nk_command_buffer*, struct nk_rect, const struct nk_image*, struct nk_color);
# void nk_draw_text(struct nk_command_buffer*, struct nk_rect, const char *text, int len, const struct nk_user_font*, struct nk_color, struct nk_color);
# void nk_push_scissor(struct nk_command_buffer*, struct nk_rect);
# void nk_push_custom(struct nk_command_buffer*, struct nk_rect, nk_command_custom_callback, nk_handle usr);


# Input
# struct nk_mouse_button {
#     int down;
#     unsigned int clicked;
#     struct nk_vec2 clicked_pos;
# };
# struct nk_mouse {
#     struct nk_mouse_button buttons[NK_BUTTON_MAX];
#     struct nk_vec2 pos;
#     struct nk_vec2 prev;
#     struct nk_vec2 delta;
#     struct nk_vec2 scroll_delta;
#     unsigned char grab;
#     unsigned char grabbed;
#     unsigned char ungrab;
# };

# struct nk_key {
#     int down;
#     unsigned int clicked;
# };
# struct nk_keyboard {
#     struct nk_key keys[NK_KEY_MAX];
#     char text[NK_INPUT_MAX];
#     int text_len;
# };

# struct nk_input {
#     struct nk_keyboard keyboard;
#     struct nk_mouse mouse;
# };
# int nk_input_has_mouse_click(const struct nk_input*, enum nk_buttons);
# int nk_input_has_mouse_click_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);
# int nk_input_has_mouse_click_down_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect, int down);
# int nk_input_is_mouse_click_in_rect(const struct nk_input*, enum nk_buttons, struct nk_rect);
# int nk_input_is_mouse_click_down_in_rect(const struct nk_input *i, enum nk_buttons id, struct nk_rect b, int down);
# int nk_input_any_mouse_click_in_rect(const struct nk_input*, struct nk_rect);
# int nk_input_is_mouse_prev_hovering_rect(const struct nk_input*, struct nk_rect);
# int nk_input_is_mouse_hovering_rect(const struct nk_input*, struct nk_rect);
# int nk_input_mouse_clicked(const struct nk_input*, enum nk_buttons, struct nk_rect);
# int nk_input_is_mouse_down(const struct nk_input*, enum nk_buttons);
# int nk_input_is_mouse_pressed(const struct nk_input*, enum nk_buttons);
# int nk_input_is_mouse_released(const struct nk_input*, enum nk_buttons);
# int nk_input_is_key_pressed(const struct nk_input*, enum nk_keys);
# int nk_input_is_key_released(const struct nk_input*, enum nk_keys);
# int nk_input_is_key_down(const struct nk_input*, enum nk_keys);


# Draw List

# typedef nk_ushort nk_draw_index;
class DrawListStroke(Enum):
    STROKE_OPEN=0
    STROKE_CLOSED=1


class DrawVertexLayoutAttribute(Enum):
    POSITION=0
    COLOR=1
    TEXCOORD=2
    ATTRIBUTE_COUNT=3



# void nk_draw_list_init(struct nk_draw_list*);
# void nk_draw_list_setup(struct nk_draw_list*, const struct nk_convert_config*, struct nk_buffer *cmds, struct nk_buffer *vertices, struct nk_buffer *elements, enum nk_anti_aliasing line_aa,enum nk_anti_aliasing shape_aa);
# void nk_draw_list_clear(struct nk_draw_list*);
# const struct nk_draw_command* nk__draw_list_begin(const struct nk_draw_list*, const struct nk_buffer*);
# const struct nk_draw_command* nk__draw_list_next(const struct nk_draw_command*, const struct nk_buffer*, const struct nk_draw_list*);
# const struct nk_draw_command* nk__draw_list_end(const struct nk_draw_list*, const struct nk_buffer*);
# void nk_draw_list_path_clear(struct nk_draw_list*);
# void nk_draw_list_path_line_to(struct nk_draw_list*, struct nk_vec2 pos);
# void nk_draw_list_path_arc_to_fast(struct nk_draw_list*, struct nk_vec2 center, float radius, int a_min, int a_max);
# void nk_draw_list_path_arc_to(struct nk_draw_list*, struct nk_vec2 center, float radius, float a_min, float a_max, unsigned int segments);
# void nk_draw_list_path_rect_to(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, float rounding);
# void nk_draw_list_path_curve_to(struct nk_draw_list*, struct nk_vec2 p2, struct nk_vec2 p3, struct nk_vec2 p4, unsigned int num_segments);
# void nk_draw_list_path_fill(struct nk_draw_list*, struct nk_color);
# void nk_draw_list_path_stroke(struct nk_draw_list*, struct nk_color, enum nk_draw_list_stroke closed, float thickness);
# void nk_draw_list_stroke_line(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_color, float thickness);
# void nk_draw_list_stroke_rect(struct nk_draw_list*, struct nk_rect rect, struct nk_color, float rounding, float thickness);
# void nk_draw_list_stroke_triangle(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_vec2 c, struct nk_color, float thickness);
# void nk_draw_list_stroke_circle(struct nk_draw_list*, struct nk_vec2 center, float radius, struct nk_color, unsigned int segs, float thickness);
# void nk_draw_list_stroke_curve(struct nk_draw_list*, struct nk_vec2 p0, struct nk_vec2 cp0, struct nk_vec2 cp1, struct nk_vec2 p1, struct nk_color, unsigned int segments, float thickness);
# void nk_draw_list_stroke_poly_line(struct nk_draw_list*, const struct nk_vec2 *pnts, const unsigned int cnt, struct nk_color, enum nk_draw_list_stroke, float thickness, enum nk_anti_aliasing);
# void nk_draw_list_fill_rect(struct nk_draw_list*, struct nk_rect rect, struct nk_color, float rounding);
# void nk_draw_list_fill_rect_multi_color(struct nk_draw_list*, struct nk_rect rect, struct nk_color left, struct nk_color top, struct nk_color right, struct nk_color bottom);
# void nk_draw_list_fill_triangle(struct nk_draw_list*, struct nk_vec2 a, struct nk_vec2 b, struct nk_vec2 c, struct nk_color);
# void nk_draw_list_fill_circle(struct nk_draw_list*, struct nk_vec2 center, float radius, struct nk_color col, unsigned int segs);
# void nk_draw_list_fill_poly_convex(struct nk_draw_list*, const struct nk_vec2 *points, const unsigned int count, struct nk_color, enum nk_anti_aliasing);
# void nk_draw_list_add_image(struct nk_draw_list*, struct nk_image texture, struct nk_rect rect, struct nk_color);
# void nk_draw_list_add_text(struct nk_draw_list*, const struct nk_user_font*, struct nk_rect, const char *text, int len, float font_height, struct nk_color);
# void nk_draw_list_push_userdata(struct nk_draw_list*, nk_handle userdata);


# GUI

class StyleItemType(Enum):
    COLOR=0
    IMAGE=1

# union nk_style_item_data {
#     struct nk_image image;
#     struct nk_color color;
# };


class StyleHeaderAlign(Enum):
    LEFT=0
    RIGHT=1


class PanelType(Enum):
    WINDOW     = 1 << 0
    GROUP      = 1 << 1
    POPUP      = 1 << 2
    CONTEXTUAL = 1 << 4
    COMBO      = 1 << 5
    MENU       = 1 << 6
    TOOLTIP    = 1 << 7

class PanelSet(Enum):
    NONBLOCK = PanelType.CONTEXTUAL.value|PanelType.COMBO.value|PanelType.MENU.value|PanelType.TOOLTIP.value
    POPUP = NONBLOCK|PanelType.POPUP.value
    SUB = POPUP|PanelType.GROUP.value


class PanelRowLayoutType(Enum):
    DYNAMIC_FIXED = 0
    DYNAMIC_ROW=1
    DYNAMIC_FREE=2
    DYNAMIC=3
    STATIC_FIXED=4
    STATIC_ROW=5
    STATIC_FREE=6
    STATIC=7
    TEMPLATE=8
    COUNT=9



#==============================================================
#                          WINDOW
# =============================================================

WINDOW_PRIVATE       = 1 << 11
WINDOW_DYNAMIC       = WINDOW_PRIVATE
WINDOW_ROM           = 1 << 12
WINDOW_NOT_INTERACTIVE = WINDOW_ROM|PanelFlags.WINDOW_NO_INPUT.value
WINDOW_HIDDEN        = 1 << 13
WINDOW_CLOSED        = 1 << 14
WINDOW_MINIMIZED     = 1 << 15
WINDOW_REMOVE_ROM    = 1 << 16


# /*==============================================================
#  *                          CONTEXT
#  * =============================================================*/

# union nk_page_data {
#     struct nk_table tbl;
#     struct nk_panel pan;
#     struct nk_window win;
# };



# because I don't want to recreate all of the nuklear data structures,
# I have made some wrapper procedures
__set_style_window_header_align__ = _nuklear.nkWrapper_context_set_style_window_header_align
__set_style_window_header_align__.arglist = [POINTER(Context), c_int]
__set_style_window_header_align__.restype = c_int


__input_is_mouse_hovering_rect__ = _nuklear.nkWrapper_input_is_mouse_hovering_rect
__input_is_mouse_hovering_rect__.arglist = [POINTER(Context), Rect]
__input_is_mouse_hovering_rect__.restype = c_int

__style_push_window_spacing__ = _nuklear.nkWrapper_style_push_window_spacing
__style_push_window_spacing__.arglist = [POINTER(Context), Vec2]
__style_push_window_spacing__.restype = c_int

__style_push_button_rounding__ = _nuklear.nkWrapper_style_push_button_rounding
__style_push_button_rounding__.arglist = [POINTER(Context), c_float]
__style_push_button_rounding__.restype = c_int


__get_text_width__ = _nuklear.nkWrapper_get_text_width
__get_text_width__.arglist = [POINTER(Context), c_char_p]
__get_text_width__.restype = c_float


__button_label_active__ = _nuklear.nkWrapper_button_label_active
__button_label_active__.arglist = [POINTER(Context), c_char_p]
__button_label_active__.restype     = c_int



# because average programmers who are English speakers like Subject-Verb-Object
# word ordering, create an object that holds the nuklear context.
class NuklearContext:
    def __init__(self,ctx):
        self.ctx = ctx

    def begin(self, title, bounds, flags):
        return __begin__(self.ctx, str.encode(title), bounds, flags)

    # if two windows are going to have the same title, you need to provide
    # a unique string "name" so that nuklear can identify it
    def begin_titled(self, name, title, bounds, flags):
        return __begin_titled__(self.ctx,
                                str.encode(name),
                                str.encode(title),
                                bounds,
                                flags)

    def layout_widget_bounds(self):
        return __layout_widget_bounds__(self.ctx)

    def layout_row_dynamic(self,height,columns):
        __layout_row_dynamic__(self.ctx,ctypes.c_float(height), columns)

    def layout_row_static(self,height,item_width,columns):
        __layout_row_static__(self.ctx,ctypes.c_float(height), item_width,columns)

    def group_begin(self, title, flags):
        return __group_begin__(self.ctx, str.encode(title), flags.value)

    def group_end(self):
        return __group_end__(self.ctx)

    def text(self, text, length, alignment):
        __text__(self.ctx,str.encode(text),length, alignment.value)

    def label(self, text, alignment):
        __label__(self.ctx, str.encode(text), alignment.value)

    def label_colored(self, text, align, color):
        __label_colored__(self.ctx,str.encode(text),align.value,color)

    def label_wrap(self, text):
        __label_wrap__(self.ctx,str.encode(text))

    def button_label(self, title, active=False):
        if active:
            return __button_label__(self.ctx, str.encode(title))
        else:
            return __button_label_active__(self.ctx, str.encode(title))

    def checkbox_label(self, text, active):
        a = ctypes.c_int(active)
        wasModified = __checkbox_label__(self.ctx,str.encode(text),ctypes.byref(a))
        return (wasModified, a.value)

    def option_label(self, label, active):
        return __option_label__(self.ctx, str.encode(label), active)

    def selectable_label(self, label, align, value):
        a = ctypes.c_int(value)
        wasModified = __selectable_label__(self.ctx, str.encode(label), align.value, ctypes.byref(a))
        return (wasModified, a.value)

    def slide_int(self, minV, val, maxV, step):
        return __slide_int__(self.ctx, c_int(minV), c_int(val), c_int(maxV), c_int(step))

    def slider_float(self, minV, value, maxV, step):
        v = ctypes.c_float(value)
        wasModified = __slider_float__(self.ctx, c_float(minV), ctypes.byref(v), c_float(maxV), c_float(step))
        return (wasModified,v.value)

    def slider_int(self, minV, value, maxV, step):
        v = ctypes.c_int(value)
        wasModified = __slider_int__(self.ctx, minV, ctypes.byref(v), maxV, step)
        return (wasModified,v.value)

    def progress(self, cur, max, is_modifyable):
        v = ctypes.c_int(cur)
        wasModified = __progress__(self.ctx, ctypes.byref(v), max, is_modifyable.value)
        return (wasModified, v.value)

    def property_int(self, name, minV, val, maxV, step, inc_per_pixel):
        v = ctypes.c_int(val)
        __property_int__(self.ctx,
                         str.encode(name),
                         minV,
                         ctypes.byref(v),
                         maxV,
                         step,
                         c_float(inc_per_pixel))
        return v.value

    def edit_string(self, flags, memory, length, maxV, filterF):
        l = ctypes.c_int(length)
        return (__edit_string__(self.ctx,
                                c_int(flags.value.value),
                                memory,
                                ctypes.byref(l),
                                c_int(maxV),
                                filterF),
                l.value)

    def chart_begin(self,chart_type,count,minV,maxV):
        return __chart_begin__(self.ctx,chart_type.value,count,c_float(minV),c_float(maxV))

    def chart_add_slot(self, chart_type, count, minV, maxV):
        __chart_add_slot__(self.ctx, c_int(chart_type.value), c_int(count), c_float(minV), c_float(maxV))

    def chart_push(self,value):
        return __chart_push__(self.ctx,c_float(value))

    def chart_push_slot(self, val, slot):
        return __chart_push_slot__(self.ctx, c_float(val), c_int(slot))

    def chart_end(self):
        __chart_end__(self.ctx)

    def property_float(self, name, minV, val, maxV, step, inc_per_pixel):
        v = ctypes.c_float(val)
        __property_float__(self.ctx,
                           str.encode(name),
                           c_float(minV),
                           ctypes.byref(v),
                           c_float(maxV),
                           c_float(step),
                           c_float(inc_per_pixel))
        return v.value

    def propertyi(self, name, minVal, val, maxVal, step, inc_per_pixel):
        return __propertyi__(self.ctx,
                             str.encode(name),
                             minVal,
                             val,
                             maxVal,
                             step,
                             ctypes.c_float(inc_per_pixel))

    def propertyf(self, name, minVal, val, maxVal, step, inc_per_pixel):
        return __propertyf__(self.ctx,
                             str.encode(name),
                             c_float(minVal),
                             c_float(val),
                             c_float(maxVal),
                             c_float(step),
                             c_float(inc_per_pixel))

    def popup_begin(self, theType, title, flags, rect):
        return __popup_begin__(self.ctx, theType.value, str.encode(title), flags.value, rect)

    def menu_begin_label(self,text,align,size):
        return __menu_begin_label__(self.ctx,str.encode(text),align.value,size)

    def menu_item_label(self, label, align):
        return __menu_item_label__(self.ctx,str.encode(label), align.value)


    def item_is_any_active(self):
        '''returns if any window or widgets is currently hovered or active'''
        return __item_is_any_active__(self.ctx)

    def combo_begin_color(self, color, size):
        return __combo_begin_color__(self.ctx, color, size)

    def color_picker(self, color, format):
        return __color_picker__(self.ctx, color, format.value)

    def combo_end(self):
        __combo_end__(self.ctx)

    def contextual_begin(self,flags, size, triggerBounds):
        return __contextual_begin__(self.ctx,flags, size, triggerBounds)

    def contextual_item_label(self, text, align):
        return __contextual_item_label__(self.ctx, str.encode(text), align.value)

    def contextual_end(self):
        __contextual_end__(self.ctx)

    def end(self):
        __end__(self.ctx)

    def tooltip(self, text):
        __tooltip__(self.ctx, str.encode(text))

    def menubar_begin(self):
        __menubar_begin__(self.ctx)

    def layout_row_begin(self, format, row_height, columns):
        __layout_row_begin__(self.ctx,ctypes.c_int(format.value), ctypes.c_float(row_height), ctypes.c_int(columns))

    def layout_row_push(self, ratio_or_width):
        __layout_row_push__(self.ctx, ctypes.c_float(ratio_or_width))

    def menu_end(self):
        __menu_end__(self.ctx)

    def style_pop_font(self):
        return __style_pop_font__(self.ctx)

    def style_pop_float(self):
        return __style_pop_float__(self.ctx)

    def style_pop_vec2(self):
        return __style_pop_vec2__(self.ctx)

    def style_pop_style_item(self):
        return __style_pop_style_item__(self.ctx)

    def style_pop_flags(self):
        return __style_pop_flags__(self.ctx)

    def style_pop_color(self):
        return __style_pop_color__(self.ctx)


    def rgb_cf(self,colorf):
        return __rgb_cf__(self.ctx, colorf)

    def menubar_end(self):
        __menubar_end__(self.ctx)

    def popup_end(self):
        __popup_end__(self.ctx)

    def combo(self, items, selected, item_height, size):
        count = len(items)

        ctypesList = []
        for x in range(count):
            ctypesList.append(str.encode(items[x]))
        arr = (ctypes.c_char_p * len(ctypesList)) (*ctypesList)

        return __combo__(self.ctx, arr, count, selected, item_height, size)

    def tree_push(self, theType, title, state):
        return __tree_push__(self.ctx, theType.value, title, state.value)

    def tree_push_id(self, theType, title, state, id):
        return __tree_push_id__(self.ctx, theType, title, state, id)

    def tree_state_push(self, tree_type, title, state):
        v = ctypes.c_int(state.value)

        return (__tree_state_push__(self.ctx,
                                    tree_type.value,
                                    str.encode(title),
                                    ctypes.byref(v)),
                v.value)


    def tree_pop(self):
        __tree_pop__(self.ctx)

    def widget_width(self):
        return __widget_width__(self.ctx)

    def widget_bounds(self):
        return __widget_bounds__(self.ctx)

    def button_set_behavior(self, behavior):
        __button_set_behavior__(self.ctx, behavior.value)

    def button_color(self,color):
        return __button_color__(self.ctx,color)

    def button_symbol(self, symbol):
        return __button_symbol__(self.ctx, symbol.value)

    def button_symbol_label(self,symbol,label,align):
        return __button_symbol_label__(self.ctx, symbol.value, str.encode(label), align.value)

    def set_style_window_header_align(self, header_align):
        __set_style_window_header_align__(self.ctx, header_align.value)

    def input_is_mouse_hovering_rect(self, bounds):
        return __input_is_mouse_hovering_rect__(self.ctx, bounds)

    def style_push_window_spacing(self, vec2):
        return __style_push_window_spacing__(self.ctx, vec2)

    def style_push_button_rounding(self, f):
        return __style_push_button_rounding__(self.ctx,ctypes.c_float(f))

    def get_text_width(self, s):
        return __get_text_width__(self.ctx, str.encode(s))


# class to protect the ratio array from garbage collection
class LayoutRow():
    def __init__(self, ctx, layout_format, height, ratio):
        self.ctx = ctx
        self.ctypesList = []
        for x in range(len(ratio)):
            self.ctypesList.append(ctypes.c_float(ratio[x]))
        # protect self.arr from garbage collection until exit
        self.arr = (ctypes.c_float * len(ratio))(*self.ctypesList)
        __layout_row__(self.ctx, c_int(layout_format.value), ctypes.c_float(height), c_int(len(self.ctypesList)), self.arr)

    def __enter__(self):
        pass

    def __exit__(self, type, value, traceback):
        # now self.arr can be garbage collected
        pass
