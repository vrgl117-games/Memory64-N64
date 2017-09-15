#include "controls.h"

uint8_t get_pressed_key() {
    
    controller_scan();
    struct controller_data keys = get_keys_pressed();	

    if (keys.c[0].A)
        return BUTTON_A;

    if (keys.c[0].B)
        return BUTTON_B;

    if (keys.c[0].C_left)
        return BUTTON_C;

    if (keys.c[0].start)
        return BUTTON_START;

    return 0;
}