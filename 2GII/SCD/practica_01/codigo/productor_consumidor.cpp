#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

using namespace std;

const unsigned int NUM_ITEMS = 50;
const unsigned int TAM_BUFFER = 10;

struct Buffer {
    int uso_buffer;
    int datos[TAM_BUFFER];

    Buffer() : uso_buffer(0) {
    }
};

sem_t puede_producir;
sem_t puede_consumir;
sem_t mutex;

int dato;
int contador = 0;

int producir_dato() {
    contador++;
    cout << "Dato producido: " << contador << endl << flush;

    return contador;
}

void consumir_dato() {
    cout << "Dato consumido: " << dato << endl << flush;
}

void * productor(void *aux) {
    Buffer *vector = (Buffer*) aux;

    for (unsigned int i = 0; i < NUM_ITEMS; i++) {

        if (vector->uso_buffer < TAM_BUFFER) {
            sem_wait(&puede_producir);

            dato = producir_dato();

            sem_wait(&mutex);

            vector->datos[vector->uso_buffer] = dato;
            vector->uso_buffer++;

            sem_post(&mutex);
            sem_post(&puede_consumir);

            sleep(rand() % 3);
        } else {
            i--;
        }
    }

    return NULL;
}

void * consumidor(void *aux) {
    Buffer *vector = (Buffer*) aux;

    for (unsigned int i = 0; i < NUM_ITEMS; i++) {

        if (vector->uso_buffer > 0) {
            sem_wait(&puede_consumir);
            sem_wait(&mutex);

            dato = vector->datos[vector->uso_buffer - 1];
            consumir_dato();
            vector->uso_buffer--;

            sem_post(&mutex);
            sem_post(&puede_producir);

            sleep(rand() % 3);
        } else {
            i--;
        }

    }

    return NULL;
}

int main() {
    Buffer *vector = new Buffer;

    srand(time(NULL));

    pthread_t hebra_productora;
    pthread_t hebra_consumidora;

    sem_init(&mutex, 0, 1);
    sem_init(&puede_producir, 0, 10);
    sem_init(&puede_consumir, 0, 0);

    pthread_create(&hebra_productora, NULL, productor, vector);
    pthread_create(&hebra_consumidora, NULL, consumidor, vector);

    pthread_join(hebra_productora, NULL);
    pthread_join(hebra_consumidora, NULL);

    sem_destroy(&puede_producir);
    sem_destroy(&puede_consumir);
    sem_destroy(&mutex);

    cout << "\nFin" << endl << flush;

    return (0);
}
