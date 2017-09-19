#ifndef __GRAPHICS_H__

#include <stdio.h>
#include <libdragon.h>

void graphics_draw_circle(display_context_t disp, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color, bool fill);
void graphics_draw_circle_with_border(display_context_t disp, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color, uint16_t border_color);
void graphics_draw_text_center(display_context_t disp, int x, int y, const char * const msg);
void graphics_draw_textf(display_context_t disp, int x, int y, const char * const msg, ...);

#endif //__GRAPHICS_H__