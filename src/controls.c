/* controls.c -- controls helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "controls.h"
#include <string.h>

control_t controls_get_keys()
{
    controller_scan();
    struct SI_condat held = get_keys_held().c[0];
    struct SI_condat up = get_keys_up().c[0];
    struct SI_condat down = get_keys_down().c[0];


    control_t keys;
    memset(&keys, 0, sizeof(control_t));

    if (held.Z) {
        keys.Z = HELD;
    } else if (down.Z) {
        keys.Z = DOWN;
    } else if (up.Z) {
        keys.Z = UP;
    }

    if (held.A) {
        keys.A = HELD;
    } else if (down.A) {
        keys.A = DOWN;
    } else if (up.A) {
        keys.A = UP;
    }

    if (held.B) {
        keys.B = HELD;
    } else if (down.B) {
        keys.B = DOWN;
    } else if (up.B) {
        keys.B = UP;
    }

    if (held.C_up || held.C_down || held.C_left || held.C_right) {
        keys.C = HELD;
    } else if (down.C_up || down.C_down || down.C_left || down.C_right) {
        keys.C = DOWN;
    } else if (up.C_up || up.C_down || up.C_left || up.C_right) {
        keys.C = UP;
    }

    if (held.start) {
        keys.start = HELD;
    } else if (down.start) {
        keys.start = DOWN;
    } else if (up.start) {
        keys.start = UP;
    }

    return keys;
}