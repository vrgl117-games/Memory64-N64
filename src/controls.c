#include "controls.h"

controller_t controls_get_keys_down() {
    controller_scan();
    return get_keys_down().c[0];
}