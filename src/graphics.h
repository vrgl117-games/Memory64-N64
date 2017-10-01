/* graphics.h -- graphics helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __GRAPHICS_H__

#include <stdio.h>
#include <libdragon.h>

void graphics_draw_box_with_border(display_context_t disp, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color, uint16_t border_color);
void graphics_draw_circle(display_context_t disp, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color, bool fill);
void graphics_draw_circle_with_border(display_context_t disp, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color, uint16_t border_color);
void graphics_draw_text_center(display_context_t disp, int x, int y, const char *const msg);
void graphics_draw_textf(display_context_t disp, int x, int y, const char *const msg, ...);

#endif //__GRAPHICS_H__