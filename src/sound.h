/* filesystem.h -- sound helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __SOUND_H__

#include <libdragon.h>

#define SOUND_A 0
#define SOUND_B 1
#define SOUND_C 2
#define SOUND_START 3
#define NUM_SOUNDS 4

typedef struct sound {
    int32_t cursor;
    uint32_t frames;
    short *data;
} sound_t;

void sound_init();
void sound_play(int sound);
void sound_frame();

#endif //__SOUND_H__