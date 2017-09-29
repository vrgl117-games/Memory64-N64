/* rdp.h -- rdp helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

 #ifndef __RDP_H__

 #include <libdragon.h>

 void rdp_attach(display_context_t disp);
 void rdp_draw_filled_octagon(int x0, int y0, int radius, int sides, uint32_t color);
 void rdp_draw_filled_octagon_with_border(int x0, int y0, int radius, int sides, uint32_t color, uint32_t border_color);
 void rdp_draw_filled_line_color(int x0, int y0, int x1, int y1, uint32_t color);
 void rdp_draw_filled_rectangle_size(int x, int y, int width, int height, uint32_t color);
 void rdp_draw_filled_rectangle_with_border_size(int x, int y, int width, int height, uint32_t color, uint32_t border_color);

 #endif //__RDP_H__