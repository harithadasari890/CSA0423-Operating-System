 #include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5
int buffer[SIZE], in = 0, out = 0;

sem_t full, empty;
pthread_mutex_t lock;

void* producer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&lock);

        buffer[in] = i;
        printf("Produced: %d\n", i);
        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&lock);
        sem_post(&full);
    }
}
void* consumer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&lock);

        printf("Consumed: %d\n", buffer[out]);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&lock);
        sem_post(&empty);
    }
}
int main() {
    pthread_t p, c;

    sem_init(&full, 0, 0);
    sem_init(&empty, 0, SIZE);
    pthread_mutex_init(&lock, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}

