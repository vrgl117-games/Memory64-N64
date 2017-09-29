/* fps.c -- fps helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "fps.h"

static volatile bool fps_refresh = false;

bool fps_refresh_get()
{
    return fps_refresh;
}

void fps_refresh_set(bool b)
{
    fps_refresh = b;
}
