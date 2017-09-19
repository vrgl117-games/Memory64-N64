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
    graphics_draw_circle_with_border(disp, 320, 340, 60, DGRAY, BLACK);
    graphics_draw_circle_with_border(disp, 320, 340, 26, WHITE, BLACK);
    graphics_draw_circle(disp, 320, 340, 18, DGRAY, false);
    graphics_draw_circle(disp, 320, 340, 10, DGRAY, false);
    graphics_draw_circle(disp, 320, 340, 2, DGRAY, false);

    switch (key) {
    case BUTTON_START:
        graphics_draw_circle_with_border(disp, 320, 220, 20, RED, BLACK);
        break;
    case BUTTON_B:
        graphics_draw_circle_with_border(disp, 400, 220, 24, GREEN, BLACK);
        break;
    case BUTTON_A:
        score++;
        graphics_draw_circle_with_border(disp, 444, 264, 24, BLUE, BLACK);
        break;
    case BUTTON_C:
        graphics_draw_circle_with_border(disp, 460, 180, 12, YELLOW, BLACK);
        graphics_draw_circle_with_border(disp, 520, 180, 12, YELLOW, BLACK);
        graphics_draw_circle_with_border(disp, 490, 150, 12, YELLOW, BLACK);
        graphics_draw_circle_with_border(disp, 490, 210, 12, YELLOW, BLACK);
        break;
    }

    // score
    graphics_draw_box(disp, 20, 20, 600, 20, DGRAY);

    if (score > best)
        best = score;
    graphics_draw_textf(disp, 25, 26, "SCORE: %04d", score);
    graphics_draw_textf(disp, 535, 26, "BEST: %04d", best);
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