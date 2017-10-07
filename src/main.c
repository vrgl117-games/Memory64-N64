/* main.c -- main implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include <stdlib.h>

#include "colors.h"
#include "controls.h"
#include "filesystem.h"
#include "fps.h"
#include "game.h"
#include "graphics.h"
#include "screens.h"

int main()
{
    init_interrupts();
    display_init(RESOLUTION_640x480, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
    rdp_init();
    filesystem_init();
    controller_init();
    colors_init();
    timer_init();

    new_timer(TIMER_TICKS(1000000), TF_CONTINUOUS, fps_timer);

    srand(timer_ticks() & 0x7FFFFFFF);

    timer_link_t *timer_press_start =  new_timer(TIMER_TICKS(500000), TF_CONTINUOUS, screen_timer_title);


    display_context_t disp = 0;

    screen_t screen = title;

    bool show_fps = false;

    rdp_set_texture_flush(FLUSH_STRATEGY_NONE);

    while (true) {

        if (!(get_controllers_present() & CONTROLLER_1_INSERTED)) {
            screen_no_controller(disp);
        } else {
            control_t keys = controls_get_keys();
            if (IS_DOWN(keys.Z)) {
                show_fps = !show_fps;
            }

            while (!(disp = display_lock()));

            switch (screen) {
                case title:
                    screen_title(disp);
                    if (IS_DOWN(keys.start)) {
                        delete_timer(timer_press_start);
                        game_set_level(1);
                        screen = game;
                    }
                    break;
                case game:
                    if (screen_game(disp, keys)) {
                        screen = gameover;
                    }
                    break;
                case gameover:
                    screen_gameover(disp);
                    if (IS_DOWN(keys.start)) {
                        game_set_level(1);
                        screen = game;
                    }
            }

            fps_frame();
            if (show_fps) {
                graphics_draw_textf(disp, 5, 5, "FPS: %d", fps_get());
            }
        }
        display_show(disp);
    }

    display_close();
    filesystem_sprites_free();

    return 0;

}
