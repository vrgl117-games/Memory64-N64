/* filesystem.c -- filesystem helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "filesystem.h"

sprite_t *filesystem_load_sprite(const char * const spritename) {
    int fp = dfs_open(spritename);

    if(fp) {
        sprite_t *sp = malloc(dfs_size(fp));
        dfs_read(sp, 1, dfs_size(fp), fp);
        dfs_close(fp);
        return sp;
    }
    return 0;
}