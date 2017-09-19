#ifndef __SCREENS_H__

#include <libdragon.h>

#define SCREEN_TITLE    0
#define SCREEN_GAME     1
#define SCREEN_GAMEOVER 2


bool screen_game(display_context_t disp, controller_t controller);
void screen_gameover(display_context_t disp);
void screen_title(display_context_t disp, sprite_t *logo);
void screen_update_counter();

#endif //__SCREENS_H__