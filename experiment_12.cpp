#include <stdio.h>
#include <pthread.h>

pthread_mutex_t chopstick[5];

void* philosopher(void* num) {
    int id = *(int*)num;

    pthread_mutex_lock(&chopstick[id]);
    pthread_mutex_lock(&chopstick[(id+1)%5]);

    printf("Philosopher %d is eating\n", id);

    pthread_mutex_unlock(&chopstick[id]);
    pthread_mutex_unlock(&chopstick[(id+1)%5]); 
    return NULL;
}

int main() {
    pthread_t p[5];
    int i, id[5];

    for(i=0;i<5;i++) pthread_mutex_init(&chopstick[i], NULL);

    for(i=0;i<5;i++) {
        id[i] = i;
        pthread_create(&p[i], NULL, philosopher, &id[i]);
    }

    for(i=0;i<5;i++) pthread_join(p[i], NULL);

    return 0;
}

