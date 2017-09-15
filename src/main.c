
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include <stdlib.h>
#include <math.h>

#include "colors.h"
#include "graphics.h"
#include "controls.h"

int main() {

  init_interrupts();
  display_init(RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
  controller_init();

  display_context_t disp = 0;
  uint16_t score = 0;
  uint16_t best = 0;

  while(true)
  {
      while(!(disp = display_lock()));

      // background
      graphics_fill_screen(disp, LGRAY);

      // joystick
      graphics_draw_circle(disp, 160, 180, 30, DGRAY, true);
      graphics_draw_circle(disp, 160, 180, 10, WHITE, true);

      switch (get_pressed_key()) {
        case BUTTON_START:
          graphics_draw_circle_with_border(disp, 160, 120, 10, RED, DGRAY);
          break;
        case BUTTON_B:
          graphics_draw_circle_with_border(disp, 200, 120, 11, GREEN, DGRAY);
          break;
        case BUTTON_A:
          score++;
          graphics_draw_circle_with_border(disp, 222, 142, 11, BLUE, DGRAY);
          break;
        case BUTTON_C:
          graphics_draw_circle_with_border(disp, 230, 100, 6, YELLOW, DGRAY);
          graphics_draw_circle_with_border(disp, 260, 100, 6, YELLOW, DGRAY);
          graphics_draw_circle_with_border(disp, 245,  85, 6, YELLOW, DGRAY);
          graphics_draw_circle_with_border(disp, 245, 115, 6, YELLOW, DGRAY);
          break;
      }

      // score
      graphics_draw_box(disp, 20, 20, 300, 40, DGRAY);
      graphics_draw_textf(disp, 30, 30, "SCORE: %d", score);

      if (score > best)
        best = score;
      graphics_draw_textf(disp, 30, 36, "BEST:  %d", best);

      display_show(disp);
  }

  display_close();

  return 0;

}
