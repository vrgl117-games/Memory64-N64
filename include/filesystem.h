/* filesystem.h -- filesystem helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __FILESYSTEM_H__

#include <libdragon.h>

#define SPRITE_LOGO 0
#define NUM_SPRITES 1

#define SOUND_A 0
#define SOUND_B 1
#define SOUND_C 2
#define SOUND_START 3
#define NUM_SOUNDS 4

void filesystem_init();
sprite_t *filesystem_get_sprite(int i);

#endif //__FILESYSTEM_H__