#include <stdio.h>
#include <pthread.h>
#include "../lib/game.h"

void* foo(void* arg) {
    printf("Hello from thread!\n");
    printf("arg: %s\n", (char*)arg);
    return NULL;
}

int main() {
    pthread_t thread1;
    pthread_create(&thread1, NULL, foo, "Thread Argument");

    say_hello();

    pthread_join(thread1, NULL);

    say_hello();
    return 0;
}
