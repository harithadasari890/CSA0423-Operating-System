#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full, mutex;

void* producer(void* arg) {
    int item;
    for (int i = 1; i <= 5; i++) {
        item = rand() % 100;

        sem_wait(&empty);  // wait for empty slot
        sem_wait(&mutex);  // enter critical section

        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);  // exit critical section
        sem_post(&full);   // increase full count

        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    int item;
    for (int i = 1; i <= 5; i++) {

        sem_wait(&full);   // wait for full slot
        sem_wait(&mutex);  // enter critical section

        item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);  // exit critical section
        sem_post(&empty);  // increase empty count

        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, BUFFER_SIZE);  // buffer empty initially
    sem_init(&full, 0, 0);             // no items initially
    sem_init(&mutex, 0, 1);            // binary semaphore

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}

