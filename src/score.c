/* score.c -- score helpers implementation
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#include "score.h"

static uint16_t score = 0;

uint16_t score_get()
{
    return score;
}

void score_increment()
{
    score++;
}

void score_reset()
{
    score = 0;
}