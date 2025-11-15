#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>

#include "../lib/list.h"
#include "../lib/game.h"

void* car_factory(void* arg) {
    // @todo semaphores to control access to roads memmory

    unsigned int random_number;
    srand(time(NULL));

    GameContext* game = (GameContext*)arg;

    List *road1 = &game->road1; // horizontal
    List *road2 = &game->road2; // vertical

    sem_wait(&game->road1_memmory);
    sem_wait(&game->road2_memmory);

    Car* car_buffer = NULL;

    while (1) {
        sleep(1);
        random_number = rand() % 3;

        switch (random_number) {
            case 0:
                // do nothing
                break;
            case 1:
                // push car to stack 1
                car_buffer = create_car(-10, 0);
                list_append(road1, car_buffer);
                break;
            case 2:
                // push car to stack 2
                car_buffer = create_car(0, -10);
                list_append(road2, car_buffer);
                break;
        }
    }

    sem_post(&game->road1_memmory);
    sem_post(&game->road2_memmory);

    return NULL;
}

void* car_mover(void* arg) {
    // @todo
    printf("Car mover is running!\n");
    printf("arg: %s\n", (char*)arg);
    return NULL;
}

void* world_renderer(void* arg) {
    // @todo
    printf("World renderer is running!\n");
    printf("arg: %s\n", (char*)arg);
    return NULL;
}
