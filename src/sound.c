/* filesystem.c -- filesystem helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "sound.h"
#include <malloc.h>

static sound_t *sounds[NUM_SOUNDS];
static short *audio_buffer;


sound_t *load_sound(const char *const soundname)
{
    int fp = dfs_open(soundname);

    if (fp) {
        int size = dfs_size(fp);
        short *data = malloc(size);
        dfs_read(data, 1, size, fp);
        dfs_close(fp);
        sound_t *sound = malloc(sizeof(sound_t));
        sound->frames = size / sizeof(signed short);
        sound->data = data;
        sound->cursor = -1;
        return sound;
    }

    return NULL;
}

void sound_init()
{
    sounds[SOUND_A] = load_sound("/sfx/A.raw");
    sounds[SOUND_B] = load_sound("/sfx/B.raw");
    sounds[SOUND_C] = load_sound("/sfx/C.raw");
    sounds[SOUND_START] = load_sound("/sfx/start.raw");
    audio_buffer = malloc(audio_get_buffer_length() * 2 * sizeof(short));
}

void sound_play(int sound) {
    sounds[sound]->cursor = 0;
}

void sound_frame()
{
    if (audio_can_write()){
        for (uint16_t frame = 0; frame < audio_get_buffer_length() << 1;) {
            if (sounds[SOUND_A]->cursor >= 0) {
                audio_buffer[frame++] = sounds[SOUND_A]->data[sounds[SOUND_A]->cursor];
                audio_buffer[frame++] = sounds[SOUND_A]->data[sounds[SOUND_A]->cursor];
                sounds[SOUND_A]->cursor++;
                if (sounds[SOUND_A]->cursor > sounds[SOUND_A]->frames) {
                    sounds[SOUND_A]->cursor = -1;
                }
            } else {
                audio_buffer[frame++] = 0;
                audio_buffer[frame++] = 0;
            }
        }
        audio_write(audio_buffer);
    }
}
