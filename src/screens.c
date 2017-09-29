/* screens.c -- screens helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "colors.h"
#include "controls.h"
#include "fps.h"
#include "graphics.h"
#include "rdp.h"
#include "score.h"
#include "screens.h"

static volatile uint8_t seconds = 0;

void screen_update_counter() {
    seconds++;
    fps_refresh_set(true);
}

bool screen_game(display_context_t disp, uint32_t *colors, controller_t controller) {
    static uint16_t best = 0;

    rdp_attach(disp);

    // background
    rdp_draw_filled_rectangle_size(0,0,640,480, colors[LGRAY]);

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


    if (controller.start) {
        rdp_draw_filled_octagon_with_border(320, 220, 20, 24, colors[RED], colors[BLACK]);
        return true;
    }

    if (controller.B) {
        rdp_draw_filled_octagon_with_border(400, 220, 24, 24, colors[GREEN], colors[BLACK]);
    }

    if (controller.A) {
        score_increment();
        rdp_draw_filled_octagon_with_border(444, 264, 24, 24, colors[BLUE], colors[BLACK]);
    }

    if (controller.C_up || controller.C_down || controller.C_left || controller.C_right) {
        rdp_draw_filled_octagon_with_border(460, 180, 12, 12, colors[YELLOW], colors[BLACK]);
        rdp_draw_filled_octagon_with_border(520, 180, 12, 12, colors[YELLOW], colors[BLACK]);
        rdp_draw_filled_octagon_with_border(490, 150, 12, 12, colors[YELLOW], colors[BLACK]);
        rdp_draw_filled_octagon_with_border(490, 210, 12, 12, colors[YELLOW], colors[BLACK]);
    }

    // score
    rdp_draw_filled_rectangle_size(20, 20, 600, 20, colors[DGRAY]);

    rdp_detach_display();

    uint16_t current_score = score_get();
    if (current_score > best)
        best = current_score;
    graphics_draw_textf(disp, 25, 26, "SCORE: %04d", current_score);
    graphics_draw_textf(disp, 535, 26, "BEST: %04d", best);

    return false;
}

void screen_gameover(display_context_t disp, uint32_t *colors) {
    rdp_attach(disp);

    // background
    rdp_draw_filled_rectangle_size(0,0,640,480, colors[DGRAY]);

    rdp_detach_display();

    graphics_draw_text_center(disp, 320, 240, "GAME OVER");
}

void screen_title(display_context_t disp, uint32_t *colors, sprite_t *logo) {
    rdp_attach(disp);

    // background
    rdp_draw_filled_rectangle_size(0,0,640,480, colors[LGRAY]);


    // logo
    rdp_enable_texture_copy();
    rdp_sync( SYNC_PIPE );
    rdp_load_texture( 0, 0, MIRROR_DISABLED, logo );
    rdp_draw_sprite(0,30, 30);
    rdp_sync( SYNC_PIPE );

    // joystick
    rdp_draw_filled_octagon_with_border(320, 340, 60, 32, colors[DGRAY], colors[BLACK]);
    rdp_draw_filled_octagon_with_border(320, 340, 26, 32, colors[WHITE], colors[BLACK]);
    rdp_draw_filled_octagon_with_border(320, 340, 18, 24, colors[WHITE], colors[DGRAY]);
    rdp_draw_filled_octagon_with_border(320, 340, 10, 24, colors[WHITE], colors[DGRAY]);
    rdp_draw_filled_octagon_with_border(320, 340, 02, 24, colors[WHITE], colors[DGRAY]);

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

    // D-pad
    rdp_draw_filled_rectangle_with_border_size(96, 168, 84, 24, colors[DGRAY], colors[BLACK]);
    rdp_draw_filled_rectangle_with_border_size(126, 138, 24, 84, colors[DGRAY], colors[BLACK]);
    rdp_draw_filled_rectangle_size(126, 170, 24, 20, colors[DGRAY]);

    // press start
    if (seconds%2 == 0) {
        rdp_draw_filled_rectangle_size(270, 430, 100, 20, colors[DGRAY]);
        graphics_draw_text(disp, 277, 436, "PRESS START");
    }

    rdp_detach_display();
}