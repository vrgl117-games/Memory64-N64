/* colors.h -- colors helpers header
 *
 * Copyright (C) 2017 Victor Vieux
 *
 * This software may be modified and distributed under the terms
 * of the Apache license.  See the LICENSE file for details.
 */

#ifndef __COLORS_H__

#include <libdragon.h>

#define BLACK    0
#define DGRAY    1
#define LGRAY    2
#define RED      3
#define BRED     4
#define GREEN    5
#define BGREEN   6
#define BLUE     7
#define BBLUE    8
#define YELLOW   9
#define BYELLOW 10
#define WHITE   11

#define NUM_COLORS 12

void colors_init();
uint32_t colors_get(int i);

#endif //__COLORS_H__
