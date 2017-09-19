#ifndef __CONTROLS_H__

#include <libdragon.h>

#define BUTTON_A        1
#define BUTTON_B        2
#define BUTTON_START    3
#define BUTTON_C        4

typedef struct SI_condat controller_t;

controller_t controls_get_keys_down();

#endif //__CONTROLS_H__