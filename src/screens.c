#include "colors.h"
#include "controls.h"
#include "graphics.h"
#include "score.h"
#include "screens.h"

static volatile uint8_t seconds = 0;

void screen_update_counter() {
    seconds++;
}

bool screen_game(display_context_t disp, controller_t controller) {
    static uint16_t best = 0;

    // background
    graphics_fill_screen(disp, LGRAY);

    // joystick
    graphics_draw_circle_with_border(disp, 320, 340, 60, DGRAY, BLACK);
    graphics_draw_circle_with_border(disp, 320, 340, 26, WHITE, BLACK);
    graphics_draw_circle(disp, 320, 340, 18, DGRAY, false);
    graphics_draw_circle(disp, 320, 340, 10, DGRAY, false);
    graphics_draw_circle(disp, 320, 340, 2, DGRAY, false);

    if (controller.start) {
        graphics_draw_circle_with_border(disp, 320, 220, 20, RED, BLACK);
        return true;
    }

    if (controller.B) {
        graphics_draw_circle_with_border(disp, 400, 220, 24, GREEN, BLACK);
    }

    if (controller.A) {
        score_increment();
        graphics_draw_circle_with_border(disp, 444, 264, 24, BLUE, BLACK);
    }

    if (controller.C_up || controller.C_down || controller.C_left || controller.C_right) {
        graphics_draw_circle_with_border(disp, 460, 180, 12, YELLOW, BLACK);
        graphics_draw_circle_with_border(disp, 520, 180, 12, YELLOW, BLACK);
        graphics_draw_circle_with_border(disp, 490, 150, 12, YELLOW, BLACK);
        graphics_draw_circle_with_border(disp, 490, 210, 12, YELLOW, BLACK);
    }

    // score
    graphics_draw_box(disp, 20, 20, 600, 20, DGRAY);

    uint16_t current_score = score_get();
    if (current_score > best)
        best = current_score;
    graphics_draw_textf(disp, 25, 26, "SCORE: %04d", current_score);
    graphics_draw_textf(disp, 535, 26, "BEST: %04d", best);

    return false;
}

void screen_gameover(display_context_t disp) {
     // background
     graphics_fill_screen(disp, DGRAY);

     graphics_draw_text_center(disp, 320, 240, "GAME OVER");
}

void screen_title(display_context_t disp, sprite_t *logo) {
    // background
    graphics_fill_screen(disp, LGRAY);

    // logo
    graphics_draw_sprite_trans(disp, 320-logo->width/2, 30, logo);

    // joystick
    graphics_draw_circle_with_border(disp, 320, 340, 60, DGRAY, BLACK);
    graphics_draw_circle_with_border(disp, 320, 340, 26, WHITE, BLACK);
    graphics_draw_circle(disp, 320, 340, 18, DGRAY, false);
    graphics_draw_circle(disp, 320, 340, 10, DGRAY, false);
    graphics_draw_circle(disp, 320, 340, 2, DGRAY, false);

    // start
    graphics_draw_circle_with_border(disp, 320, 220, 20, RED, BLACK);

    // B
    graphics_draw_circle_with_border(disp, 400, 220, 24, GREEN, BLACK);

    // A
    graphics_draw_circle_with_border(disp, 444, 264, 24, BLUE, BLACK);

    // C
    graphics_draw_circle_with_border(disp, 460, 180, 12, YELLOW, BLACK);
    graphics_draw_circle_with_border(disp, 520, 180, 12, YELLOW, BLACK);
    graphics_draw_circle_with_border(disp, 490, 150, 12, YELLOW, BLACK);
    graphics_draw_circle_with_border(disp, 490, 210, 12, YELLOW, BLACK);

    // press start
    if (seconds%2 == 0) {
        graphics_draw_box(disp, 270, 430, 100, 20, DGRAY);
        graphics_draw_text(disp, 277, 436, "PRESS START");
    }
}