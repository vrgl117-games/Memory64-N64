/* filesystem.h -- filesystem helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __FILESYSTEM_H__

#include <libdragon.h>

#define LOGO 0

#define NUM_SPRITES 1

void filesystem_init();
sprite_t *filesystem_get_sprite(int i);
void filesystem_sprites_free();

#endif //__FILESYSTEM_H__