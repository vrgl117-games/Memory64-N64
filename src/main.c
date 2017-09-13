
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <libdragon.h>

#include "controller.h"
#include "interrupt.h"
int main() {
  
  init_interrupts();
  controller_init();

}
