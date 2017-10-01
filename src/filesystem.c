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
        sprite_t *sp = malloc(dfs_size(fp));
        dfs_read(sp, 1, dfs_size(fp), fp);
        dfs_close(fp);

        if (sp->bitdepth > 1) {
            data_cache_hit_writeback_invalidate( sp->data, sp->width * sp->height * sp->bitdepth );
        } else if (sp->bitdepth == 1) {
            data_cache_hit_writeback_invalidate( sp->data, sp->width * sp->height );
        } else {
            data_cache_hit_writeback_invalidate( sp->data, (sp->width * sp->height) >> 1 );
        }

        return sp;
    }


    return 0;
}

void filesystem_init()
{
    dfs_init(DFS_DEFAULT_LOCATION);
    sprites[LOGO] = filesystem_load_sprite("/gfx/logo.sprite");
}

sprite_t *filesystem_get_sprite(int i)
{
    return sprites[i];
}


void filesystem_sprites_free()
{
    for (int i = 0 ; i < NUM_SPRITES ; i++) {
        free(sprites[i]);
    }
}
