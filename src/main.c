/* main.c -- main implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "colors.h"
#include "controls.h"
#include "filesystem.h"
#include "fps.h"
#include "graphics.h"
#include "score.h"
#include "screens.h"

int main() {

  init_interrupts();
  display_init(RESOLUTION_640x480, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
  rdp_init();
  dfs_init(DFS_DEFAULT_LOCATION);
  controller_init();
  timer_init();

  new_timer(TIMER_TICKS(1000000), TF_CONTINUOUS, screen_update_counter);

  display_context_t disp = 0;
  sprite_t *logo = filesystem_load_sprite("/gfx/logo.sprite");
  if (!logo)
    return 1;

  uint8_t screen = SCREEN_TITLE;

  uint8_t fps = 0;
  uint8_t frames_count = 0;

  uint32_t *colors = graphics_make_colors();

  rdp_set_texture_flush(FLUSH_STRATEGY_NONE);

  while(true)
  {

    controller_t controller = controls_get_keys_down();
    while(!(disp = display_lock()));

    switch (screen) {
      case SCREEN_TITLE:
        screen_title(disp, colors, logo);
        if (controller.start) {
          screen = SCREEN_GAME;
        }
        break;
      case SCREEN_GAME:
        if (screen_game(disp, colors,  controller)) {
            screen = SCREEN_GAMEOVER;
        }
        break;
      case SCREEN_GAMEOVER:
        screen_gameover(disp, colors);
        if (controller.start) {
          score_reset();
          screen = SCREEN_GAME;
        }
    }

    frames_count++;
    if (fps_refresh_get()) {
      fps = frames_count;
      frames_count = 0;
      fps_refresh_set(false);
    }
    graphics_draw_textf(disp, 5, 5, "FPS: %d", fps);

    display_show(disp);
  }

  display_close();
  free(logo);

  return 0;

}
