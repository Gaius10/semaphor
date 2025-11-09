#ifndef LIST_H
#define LIST_H

#include "car.h"

#define LIST_MAX_SIZE 100

typedef struct List {
    Car* items[LIST_MAX_SIZE];
    int size;
} List;

List* create_list();
void list_append(List* list, Car* car);
void list_remove(List* list, int index);
void list_destroy(List* list);

Car* list_get(List* list, int index);

#endif
