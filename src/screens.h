/* screens.h -- screens helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __SCREENS_H__

#include <libdragon.h>

typedef enum screens {title, game, gameover} screen_t;

bool screen_game(display_context_t disp, controller_t controller);
void screen_gameover(display_context_t disp);
void screen_title(display_context_t disp);
void screen_timer_press_start();

#endif //__SCREENS_H__