#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = num * num;
    pthread_exit(result);
}

int main() {
    pthread_t thread;
    int number = 5;
    int* result;

    pthread_create(&thread, NULL, square, &number);
    pthread_join(thread, (void**)&result);

    printf("Square of %d is %d\n", number, *result);
    free(result);

    return 0;
}
