/* main.c -- main implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "controls.h"
#include "filesystem.h"
#include "score.h"
#include "screens.h"

int main() {

  init_interrupts();
  display_init(RESOLUTION_640x480, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
  dfs_init(DFS_DEFAULT_LOCATION);
  controller_init();
  timer_init();

  new_timer(TIMER_TICKS(1000000), TF_CONTINUOUS, screen_update_counter);

  display_context_t disp = 0;
  sprite_t *logo = filesystem_load_sprite("/gfx/logo.sprite");
  if (!logo)
    return 1;

  uint8_t screen = SCREEN_TITLE;
  while(true)
  {
    controller_t controller = controls_get_keys_down();
    while(!(disp = display_lock()));

    switch (screen) {
      case SCREEN_TITLE:
        screen_title(disp, logo);
        if (controller.start) {
          screen = SCREEN_GAME;
        }
        break;
      case SCREEN_GAME:
        if (screen_game(disp, controller)) {
            screen = SCREEN_GAMEOVER;
        }
        break;
      case SCREEN_GAMEOVER:
        screen_gameover(disp);
        if (controller.start) {
          score_reset();
          screen = SCREEN_GAME;
        }
    }

    display_show(disp);
  }

  display_close();
  free(logo);

  return 0;

}
