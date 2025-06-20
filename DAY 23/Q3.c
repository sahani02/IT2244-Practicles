/*Q3)Write a program that creates a thread which prints numbers from 1 to 10 with a 1-second delay 
     between each number.the main thread should wait for this thread to finish.*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* count_to_ten(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread;

    pthread_create(&thread, NULL, count_to_ten, NULL);
    pthread_join(thread, NULL);

    printf("Counting thread finished.\n");
    return 0;
}
