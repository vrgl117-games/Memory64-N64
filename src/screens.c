#include "colors.h"
#include "controls.h"
#include "graphics.h"
#include "screens.h"

static volatile uint8_t seconds = 0;

void screen_update_counter() {
    seconds++;
}

void screen_game(display_context_t disp, uint8_t key) {
    static uint16_t score = 0;
    static uint16_t best = 0;

    // background
    graphics_fill_screen(disp, LGRAY);

    // joystick
    graphics_draw_circle(disp, 160, 180, 30, DGRAY, true);
    graphics_draw_circle(disp, 160, 180, 10, WHITE, true);

    switch (key) {
    case BUTTON_START:
        graphics_draw_circle_with_border(disp, 160, 120, 10, RED, DGRAY);
        break;
    case BUTTON_B:
        graphics_draw_circle_with_border(disp, 200, 120, 11, GREEN, DGRAY);
        break;
    case BUTTON_A:
        score++;
        graphics_draw_circle_with_border(disp, 222, 142, 11, BLUE, DGRAY);
        break;
    case BUTTON_C:
        graphics_draw_circle_with_border(disp, 230, 100, 6, YELLOW, DGRAY);
        graphics_draw_circle_with_border(disp, 260, 100, 6, YELLOW, DGRAY);
        graphics_draw_circle_with_border(disp, 245,  85, 6, YELLOW, DGRAY);
        graphics_draw_circle_with_border(disp, 245, 115, 6, YELLOW, DGRAY);
        break;
    }

    // score
    graphics_draw_box(disp, 20, 20, 280, 20, DGRAY);

    if (score > best)
    best = score;
    graphics_draw_textf(disp, 25, 26, "SCORE: %04d            BEST: %04d", score, best);
}

void screen_title(display_context_t disp, sprite_t *logo) {
    // background
    graphics_fill_screen(disp, LGRAY);

    // logo

    graphics_draw_sprite_trans(disp, 76, 20, logo);

    // joystick
    graphics_draw_circle(disp, 160, 170, 30, DGRAY, true);
    graphics_draw_circle(disp, 160, 170, 10, WHITE, true);

    // start
    graphics_draw_circle_with_border(disp, 160, 110, 10, RED, DGRAY);

    // B
    graphics_draw_circle_with_border(disp, 200, 110, 11, GREEN, DGRAY);

    // A
    graphics_draw_circle_with_border(disp, 222, 132, 11, BLUE, DGRAY);

    // C
    graphics_draw_circle_with_border(disp, 230,  90, 6, YELLOW, DGRAY);
    graphics_draw_circle_with_border(disp, 260,  90, 6, YELLOW, DGRAY);
    graphics_draw_circle_with_border(disp, 245,  75, 6, YELLOW, DGRAY);
    graphics_draw_circle_with_border(disp, 245, 105, 6, YELLOW, DGRAY);

    // press start
    if (seconds%2 == 0) {
        graphics_draw_box(disp, 110, 210, 100, 20, DGRAY);
        graphics_draw_text(disp, 115, 216, "PRESS START");
    }
}