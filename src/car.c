#include "../lib/car.h"

Car* create_car(int x, int y) {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car == NULL) {
        printf("Memory allocation failed to car.\n");
        printf("Exiting...\n");
        exit(1);
    }

    car->position_x = x;
    car->position_y = y;

    return car;
}

void move_left(Car* car, int distance) {
    if (car == NULL) {
        return;
    }

    car->position_x -= distance;
}

void move_right(Car* car, int distance) {
    if (car == NULL) {
        return;
    }

    car->position_x += distance;
}

void move_up(Car* car, int distance) {
    if (car == NULL) {
        return;
    }

    car->position_y += distance;
}

void move_down(Car* car, int distance) {
    if (car == NULL) {
        return;
    }

    car->position_y -= distance;
}

void move_car(Car* car, int delta_x, int delta_y) {
    if (car == NULL) {
        return;
    }

    car->position_x += delta_x;
    car->position_y += delta_y;
}

void destroy_car(Car* car) {
    if (car != NULL) {
        free(car);
    }
}
