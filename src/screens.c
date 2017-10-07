/* screens.c -- screens helpers implementation
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
#include "game.h"
#include "graphics.h"
#include "rdp.h"
#include "screens.h"

extern uint32_t colors[NUM_COLORS];
static volatile uint8_t tick = 0;

void screen_timer_title()
{
    tick++;
}

void print_controller()
{
    // background
    rdp_draw_filled_rectangle_size(0, 0, 640, 480, colors[LGRAY]);

    // joystick
    rdp_draw_filled_octagon_with_border(320, 340, 60, 32, colors[DGRAY], colors[BLACK]);
    rdp_draw_filled_octagon_with_border(320, 340, 26, 32, colors[WHITE], colors[BLACK]);
    rdp_draw_filled_octagon_with_border(320, 340, 18, 24, colors[WHITE], colors[DGRAY]);
    rdp_draw_filled_octagon_with_border(320, 340, 10, 24, colors[WHITE], colors[DGRAY]);
    rdp_draw_filled_octagon_with_border(320, 340, 02, 24, colors[WHITE], colors[DGRAY]);

    // D-pad
    rdp_draw_filled_rectangle_with_border_size(96, 168, 84, 24, colors[DGRAY], colors[BLACK]);
    rdp_draw_filled_rectangle_with_border_size(126, 138, 24, 84, colors[DGRAY], colors[BLACK]);
    rdp_draw_filled_rectangle_size(126, 170, 24, 20, colors[DGRAY]);

    // start
    rdp_draw_filled_octagon_with_border(320, 220, 20, 24, colors[RED], colors[BLACK]);

    // B
    rdp_draw_filled_octagon_with_border(400, 220, 24, 24, colors[GREEN], colors[BLACK]);

    // A
    rdp_draw_filled_octagon_with_border(444, 264, 24, 24, colors[BLUE], colors[BLACK]);

    // C
    rdp_draw_filled_octagon_with_border(460, 180, 12, 12, colors[YELLOW], colors[BLACK]);
    rdp_draw_filled_octagon_with_border(520, 180, 12, 12, colors[YELLOW], colors[BLACK]);
    rdp_draw_filled_octagon_with_border(490, 150, 12, 12, colors[YELLOW], colors[BLACK]);
    rdp_draw_filled_octagon_with_border(490, 210, 12, 12, colors[YELLOW], colors[BLACK]);
}

bool screen_game(display_context_t disp, control_t keys)
{
    game_t game = game_get();

    rdp_attach(disp);

    print_controller();

    bool gameover = false;

    if (game.timer_IA != NULL && !game.pause) {
        switch (game.notes[game.current]) {
            case BUTTON_START:
                rdp_draw_filled_octagon_with_border(320, 220, 20, 24, colors[BRED], colors[BLACK]);
                break;
            case BUTTON_A:
                rdp_draw_filled_octagon_with_border(400, 220, 24, 24, colors[BGREEN], colors[BLACK]);
                break;
            case BUTTON_B:
                rdp_draw_filled_octagon_with_border(444, 264, 24, 24, colors[BBLUE], colors[BLACK]);
                break;
            case BUTTON_C:
                rdp_draw_filled_octagon_with_border(460, 180, 12, 12, colors[BYELLOW], colors[BLACK]);
                rdp_draw_filled_octagon_with_border(520, 180, 12, 12, colors[BYELLOW], colors[BLACK]);
                rdp_draw_filled_octagon_with_border(490, 150, 12, 12, colors[BYELLOW], colors[BLACK]);
                rdp_draw_filled_octagon_with_border(490, 210, 12, 12, colors[BYELLOW], colors[BLACK]);
                break;
        }
    } else if (game.timer_IA == NULL) {
        if (IS_PRESSED(keys.start)) {
            rdp_draw_filled_octagon_with_border(320, 220, 20, 24, colors[BRED], colors[BLACK]);
        } else if (IS_UP(keys.start)) {
            gameover = game_play_player(BUTTON_START);
        }

        if (IS_PRESSED(keys.A)) {
            rdp_draw_filled_octagon_with_border(400, 220, 24, 24, colors[BGREEN], colors[BLACK]);
        } else if (IS_UP(keys.A)) {
            gameover = game_play_player(BUTTON_A);
        }

        if (IS_PRESSED(keys.B)) {
            rdp_draw_filled_octagon_with_border(444, 264, 24, 24, colors[BBLUE], colors[BLACK]);
        } else if (IS_UP(keys.B)) {
            gameover = game_play_player(BUTTON_B);
        }

        if (IS_PRESSED(keys.C)) {
            rdp_draw_filled_octagon_with_border(460, 180, 12, 12, colors[BYELLOW], colors[BLACK]);
            rdp_draw_filled_octagon_with_border(520, 180, 12, 12, colors[BYELLOW], colors[BLACK]);
            rdp_draw_filled_octagon_with_border(490, 150, 12, 12, colors[BYELLOW], colors[BLACK]);
            rdp_draw_filled_octagon_with_border(490, 210, 12, 12, colors[BYELLOW], colors[BLACK]);
        } else if (IS_UP(keys.C)) {
            gameover = game_play_player(BUTTON_C);
        }
    }


    // score
    rdp_draw_filled_rectangle_size(20, 20, 600, 18, colors[DGRAY]);

    rdp_detach_display();

    graphics_draw_textf(disp, 25, 26, "SCORE: %04d", game.score);
    graphics_draw_textf(disp, 536, 26, "BEST: %04d", game.best);

    return gameover;
}

void screen_gameover(display_context_t disp)
{
    rdp_attach(disp);

    // background
    rdp_draw_filled_rectangle_size(0, 0, 640, 480, colors[DGRAY]);

    rdp_detach_display();

    graphics_draw_text_center(disp, 320, 230, "GAME OVER");
}

void screen_title(display_context_t disp)
{
    rdp_attach(disp);

    print_controller();

    // logo
    graphics_draw_sprite_trans_stride(disp, 320 - filesystem_get_sprite(LOGO)->width / 2, 30, filesystem_get_sprite(LOGO), tick % 9);

    // press start
    if (tick % 2) {
        rdp_draw_filled_rectangle_size(270, 430, 100, 20, graphics_make_color(0x3a, 0x3a, 0x3a, 0x00));
        graphics_draw_text(disp, 277, 436, "PRESS START");
    }

    rdp_detach_display();
}
