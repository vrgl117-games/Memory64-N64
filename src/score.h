/* score.h -- score helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __SCORE_H__

#include <stdint.h>

uint16_t score_get();
void score_increment();
void score_reset();

#endif // __SCORE_H__
