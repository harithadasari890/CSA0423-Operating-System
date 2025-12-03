#include <stdio.h>
#include <pthread.h>

void* myThread(void* arg) {
    printf("Thread is running!\n");
    return NULL;
}

int main() {
    pthread_t t1;

    pthread_create(&t1, NULL, myThread, NULL);
    pthread_join(t1, NULL);

    printf("Main thread finished.\n");
    return 0;
}

