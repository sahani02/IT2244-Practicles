/*Q1)Write a C program that creates two threads.Each thread should print a
   message indicating it is running.the main thread should
   wait for both threads to finish before exiting.*/
   
#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg) {
	int threadNum=*(int*)arg;
    printf("Thread %d is running.\n", threadNum);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, threadFunc, &id1);
    pthread_create(&t2, NULL, threadFunc, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads have completed.\n");
    return 0;
}
