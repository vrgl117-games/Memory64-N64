/* colors.h -- colors helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "colors.h"

uint32_t colors[NUM_COLORS];

void colors_init()
{
    colors[BLACK] = graphics_make_color(0x00, 0x00, 0x00, 0xff);
    colors[LGRAY] =  graphics_make_color(0xbd, 0xbd, 0xbd, 0xff);
    colors[DGRAY] =  graphics_make_color(0x3a, 0x3a, 0x3a, 0xff);
    colors[RED] = graphics_make_color(0x88, 0x00, 0x00, 0xff);
    colors[BRED] = graphics_make_color(0xff, 0x00, 0x00, 0xff);
    colors[GREEN] = graphics_make_color(0x00, 0x88, 0x00, 0xff);
    colors[BGREEN] = graphics_make_color(0x00, 0xff, 0x00, 0xff);
    colors[BLUE] = graphics_make_color(0x00, 0x00, 0x88, 0xff);
    colors[BBLUE] = graphics_make_color(0x00, 0x00, 0xff, 0xff);
    colors[YELLOW] = graphics_make_color(0x88, 0x88, 0x00, 0xff);
    colors[BYELLOW] = graphics_make_color(0xff, 0xff, 0x00, 0xff);
    colors[WHITE] = graphics_make_color(0xff, 0xff, 0xff, 0xff);
}

uint32_t colors_get(int i)
{
    return colors[i];
}