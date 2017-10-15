/* game.c -- game header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __GAME_H__

#include <libdragon.h>

typedef struct game {
    uint8_t notes[256];
    uint8_t current;
    uint8_t size;

    uint16_t score;
    uint16_t best;

    bool pause;
    timer_link_t *timer_IA;

} game_t;

#define BUTTON_START 0
#define BUTTON_A     1
#define BUTTON_B     2
#define BUTTON_C     3

game_t game_get();
bool game_play_player(uint8_t button);
void game_timer_IA();
void game_set_level(uint8_t size);

#endif //__GAME_H__