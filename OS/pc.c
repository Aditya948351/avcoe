#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5
int buffer[SIZE], in = 0, out = 0;

sem_t empty;      // count empty slots
sem_t full;       // count full slots
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutual exclusion

void* producer(void* arg) {
    int item = 1;
    while(item <= 10) {        // produce 10 items
        sem_wait(&empty);      // wait for empty slot
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Producer produced %d\n", item);
        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);       // signal full slot

        item++;
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    int item;
    for(int i=0; i<10; i++) {  // consume 10 items
        sem_wait(&full);       // wait for full slot
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        printf("Consumer consumed %d\n", item);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);      // signal empty slot

        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;
    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}