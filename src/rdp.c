/* rdp.c -- rpd helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include <stdlib.h>
#include <math.h>

#include "rdp.h"

void rdp_attach(display_context_t disp)
{
    rdp_attach_display(disp);
    rdp_sync(SYNC_PIPE);
    rdp_set_clipping(0, 0, 640, 480);
}

void rdp_draw_filled_octagon(int x0, int y0, int radius, int sides, uint32_t color)
{
    rdp_enable_blend_fill();
    rdp_set_blend_color(color);

    float angle = (3.141592653589793 * 2) / sides;

    for (int n = 0; n < sides; n++) {
        rdp_draw_filled_triangle(x0, y0, sin(angle * n)*radius + x0, cos(angle * n)*radius + y0, sin(angle * (n + 1))*radius + x0, cos(angle * (n + 1))*radius + y0);
    }
}

void rdp_draw_filled_octagon_with_border(int x0, int y0, int radius, int sides, uint32_t color, uint32_t border_color)
{
    rdp_draw_filled_octagon(x0, y0, radius, sides, border_color);
    rdp_draw_filled_octagon(x0, y0, radius - 2, sides, color);
}


void rdp_draw_filled_rectangle_size(int x, int y, int width, int height, uint32_t color)
{
    rdp_enable_primitive_fill();
    rdp_set_primitive_color(color);
    rdp_draw_filled_rectangle(x, y, x + width, y + height);
}

void rdp_draw_filled_rectangle_with_border_size(int x, int y, int width, int height, uint32_t color, uint32_t border_color)
{
    rdp_enable_primitive_fill();
    rdp_set_primitive_color(border_color);
    rdp_draw_filled_rectangle(x, y, x + width, y + height);
    rdp_set_primitive_color(color);
    rdp_draw_filled_rectangle(x + 2, y + 2, x + width - 2, y + height - 2);
}

