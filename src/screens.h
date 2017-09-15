#ifndef __SCREENS_H__

#include <libdragon.h>

#define SCREEN_TITLE 0
#define SCREEN_GAME  1

void screen_game(display_context_t disp, uint8_t key);
void screen_title(display_context_t disp, sprite_t *logo);
void screen_update_counter();

#endif //__SCREENS_H__