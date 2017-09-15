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