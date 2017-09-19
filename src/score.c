#include "score.h"

static uint16_t score = 0;

uint16_t score_get() {
    return score;
}

void score_increment() {
    score++;
}

void score_reset() {
    score = 0;
}