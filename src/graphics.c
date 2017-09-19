#include <stdarg.h>

#include "graphics.h"

void graphics_draw_circle(display_context_t disp, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color, bool fill) {
  int x = radius;
  int y = 0;
  int dx = 1;
  int dy = 1;
  int err = dx - (radius << 1);

  while (x >= y)
  {
    if (fill) {
      graphics_draw_line(disp, x0 - x, y0 + y, x0 + x, y0 + y, color);
      graphics_draw_line(disp, x0 - y, y0 + x, x0 + y, y0 + x, color);
      graphics_draw_line(disp, x0 - x, y0 - y, x0 + x, y0 - y, color);
      graphics_draw_line(disp, x0 - y, y0 - x, x0 + y, y0 - x, color);
    } else {
      graphics_draw_pixel(disp, x0 + x, y0 + y, color);
			graphics_draw_pixel(disp, x0 + y, y0 + x, color);
			graphics_draw_pixel(disp, x0 - y, y0 + x, color);
			graphics_draw_pixel(disp, x0 - x, y0 + y, color);
			graphics_draw_pixel(disp, x0 - x, y0 - y, color);
			graphics_draw_pixel(disp, x0 - y, y0 - x, color);
			graphics_draw_pixel(disp, x0 + y, y0 - x, color);
			graphics_draw_pixel(disp, x0 + x, y0 - y, color);

    }

    if (err <= 0)
    {
        y++;
        err += dy;
        dy += 2;
    }
    if (err > 0)
    {
        x--;
        dx += 2;
        err += (-radius << 1) + dx;
    }
  }
}

void graphics_draw_circle_with_border(display_context_t disp, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color, uint16_t border_color) {
  graphics_draw_circle(disp, x0, y0, radius, border_color, true);
  graphics_draw_circle(disp, x0, y0, radius-2, color, true);
}


void graphics_draw_textf(display_context_t disp, int x, int y, const char * const format, ...) {
  char buffer[256];
  va_list args;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end (args);

  graphics_draw_text(disp, x, y, buffer);
}