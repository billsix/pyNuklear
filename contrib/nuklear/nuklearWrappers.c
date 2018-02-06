/*
Copyright (c) 2017 William Emerison Six

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

void
nkWrapper_context_set_style_window_header_align(struct nk_context *ctx,
                                                enum nk_style_header_align header_align)
{
  ctx->style.window.header.align = header_align;
}

int
nkWrapper_input_is_mouse_hovering_rect(struct nk_context *ctx,
                                       struct nk_rect bounds)
{
  return nk_input_is_mouse_hovering_rect(&ctx->input, bounds);
}

int
nkWrapper_style_push_window_spacing(struct nk_context *ctx,
                                    struct nk_vec2 vec2)
{
  return nk_style_push_vec2(ctx, &ctx->style.window.spacing, vec2);

}

int
nkWrapper_style_push_button_rounding(struct nk_context *ctx,
                                     float f)
{
  return nk_style_push_float(ctx, &ctx->style.button.rounding, f);

}

float
nkWrapper_get_text_width(struct nk_context *ctx,
                         char *str)
{
  const struct nk_user_font *f = ctx->style.font;
  float text_width = f->width(f->userdata, f->height, str, nk_strlen(str));
  return text_width + 3 * ctx->style.button.padding.x;
}
