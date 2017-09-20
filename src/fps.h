/* fps.h -- fps helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __FPS_H__

#include <libdragon.h>

bool fps_refresh_get();
void fps_refresh_set(bool b);

#endif // __FPS_H__
