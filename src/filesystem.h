/* filesystem.h -- filesystem helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __FILESYSTEM_H__

#include <libdragon.h>
#include <malloc.h>

sprite_t *filesystem_load_sprite(const char * const spritename);

#endif //__FILESYSTEM_H__