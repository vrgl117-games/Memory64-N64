/* game.c -- game implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include <stdlib.h>
#include "game.h"

static game_t game;



void game_set_level(uint8_t size)
{
    if (size == 1) {
        for (int i = 0; i < 256; i++) {
            game.notes[i] = rand() % 2;
        }
    }
    game.current = 0;
    game.size = size;
    game.timer_IA = new_timer(TIMER_TICKS(500000), TF_CONTINUOUS, game_timer_IA);
    game.pause = true;

}

void game_timer_IA()
{
    if (!game.pause) {
        game.current++;
    } else {
        if (game.current == game.size) {
            game.current = 0;
            delete_timer(game.timer_IA);
            game.timer_IA = NULL;
        }
    }
    game.pause = !game.pause;
}


game_t game_get()
{
    return game;
}

bool game_play_player(uint8_t button)
{
    if (game.notes[game.current] == button) {
        game.current++;
        if (game.current == game.size) {
            game.score++;
            if (game.score > game.best) {
                game.best = game.score;
            }
            game_set_level(game.size + 1);
        }
    } else {
        game.score = 0;
        return true;
    }

    return false;
}