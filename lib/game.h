
#ifndef GAME_H
#define GAME_H

#include "stack.h"

typedef GameArgs {
    Stack *road1;
    Stack *road2;
} GameArgs;

void *car_factory(void* arg);

#endif

