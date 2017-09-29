/* controls.c -- controls helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "controls.h"

controller_t controls_get_keys_down()
{
    controller_scan();
    return get_keys_down().c[0];
}