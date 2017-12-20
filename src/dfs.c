/* dfs.c -- dfs helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "dfs.h"
#include <malloc.h>

void *dfs_load(const char *const path)
{
    int fp = dfs_open(path);

    if (fp) {
        int size = dfs_size(fp);
        void *data = malloc(size);
        dfs_read(data, 1, size, fp);
        dfs_close(fp);
        return data;
    }

    return NULL;
}
