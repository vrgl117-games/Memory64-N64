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
#include "dfs.h"
#include "sound.h"
#include "fps.h"
#include "game.h"
#include "graphics.h"
#include "screens.h"

int main()
{
    init_interrupts();
    display_init(RESOLUTION_640x480, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE);
    audio_init(44100, 4);


    rdp_init();
    dfs_init(DFS_DEFAULT_LOCATION);
    sound_init();
    controller_init();
    colors_init();
    timer_init();

    new_timer(TIMER_TICKS(1000000), TF_CONTINUOUS, fps_timer);

    srand(timer_ticks() & 0x7FFFFFFF);

    timer_link_t *timer_press_start =  new_timer(TIMER_TICKS(500000), TF_CONTINUOUS, screen_timer_title);


    display_context_t disp = 0;

    screen_t screen = title;
    sprite_t *logo = dfs_load("/gfx/logo.sprite");

    bool show_fps = false;

    rdp_set_texture_flush(FLUSH_STRATEGY_NONE);

    while (true) {

        if (!(get_controllers_present() & CONTROLLER_1_INSERTED)) {
            screen_no_controller(disp);
        } else {
            control_t keys = controls_get_keys();
            if (IS_DOWN(keys.Z)) {
                show_fps = !show_fps;
                sound_play(SOUND_A);
            }

            while (!(disp = display_lock()));

            switch (screen) {
                case title:
                    screen_title(disp, logo);
                    if (IS_DOWN(keys.start)) {
                        delete_timer(timer_press_start);
                        free(logo);
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
        sound_frame();
    }

    timer_close();
    rdp_close();
    audio_close();
    display_close();
    return 0;

}
