/* filesystem.c -- filesystem helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "filesystem.h"
#include <malloc.h>

static sprite_t *sprites[NUM_SPRITES];

sprite_t *filesystem_load_sprite(const char *const spritename)
{
    int fp = dfs_open(spritename);

    if (fp) {
        int size = dfs_size(fp);
        sprite_t *sp = malloc(size);
        dfs_read(sp, 1, size, fp);
        dfs_close(fp);
        return sp;
    }

    return NULL;
}

void filesystem_init()
{
    dfs_init(DFS_DEFAULT_LOCATION);
    sprites[SPRITE_LOGO] = filesystem_load_sprite("/gfx/logo.sprite");
}

sprite_t *filesystem_get_sprite(int i)
{
    return sprites[i];
}
