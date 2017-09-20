/* controls.h -- controls helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __CONTROLS_H__

#include <libdragon.h>

typedef struct SI_condat controller_t;

controller_t controls_get_keys_down();

#endif //__CONTROLS_H__