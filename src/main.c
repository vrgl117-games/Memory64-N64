#include "controls.h"
#include "filesystem.h"
#include "screens.h"

int main() {

  init_interrupts();
  display_init(RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
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
    uint8_t key = controls_get_pressed_key();
    while(!(disp = display_lock()));

    if (screen == SCREEN_TITLE) {
      if (key == BUTTON_START) {
        screen = SCREEN_GAME;
      }
      screen_title(disp, logo);
    } else if (screen == SCREEN_GAME) {
      screen_game(disp, key);
    }

    display_show(disp);
  }

  display_close();

  return 0;

}
