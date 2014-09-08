#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

sem_t sem_estanquero;
sem_t sem_fumadores[3];

int decide_ingredientes() {
    int ingredientes = rand() % 3;

    sleep(rand() % 5);

    return ingredientes;
}

void* estanquero(void*) {
    int ingredientes;

    while (true) {
        ingredientes = decide_ingredientes();

        if (ingredientes == 0) {
            cout << "El estanquero pone papel y cerillas en el mostrador." << endl << flush;
        } else if (ingredientes == 1) {
            cout << "El estanquero pone tabaco y papel en el mostrador." << endl << flush;
        } else {
            cout << "El estanquero pone cerillas y tabaco en el mostrador." << endl << flush;
        }

        sem_post(&sem_fumadores[ingredientes]);
        sem_wait(&sem_estanquero);
    }

    return NULL;
}

void fumar() {
    sleep(rand() % 5);
}

void* fumador0(void*) {
    while (true) {
        sem_wait(&sem_fumadores[0]);
        sem_post(&sem_estanquero);

        cout << "El primer fumador coge el papel y las cerillas y se va a fumar.\n" << endl << flush;
        fumar();
    }
}

void* fumador1(void*) {
    while (true) {
        sem_wait(&sem_fumadores[1]);
        sem_post(&sem_estanquero);

        cout << "El segundo fumador coge el tabaco y el papel y se va a fumar.\n" << endl << flush;
        fumar();
    }
}

void* fumador2(void*) {
    while (true) {
        sem_wait(&sem_fumadores[2]);
        sem_post(&sem_estanquero);

        cout << "El tercer fumador coge las cerillas y el tabaco y se va a fumar.\n" << endl << flush;
        fumar();
    }
}

int main() {
    srand(time(NULL));

    pthread_t hebra_fumadores[3];
    pthread_t hebra_estanquero;

    sem_init(&sem_estanquero, 0, 0);

    for (int i = 0; i < 3; i++)
        sem_init(&sem_fumadores[i], 0, 0);

    pthread_create(&(hebra_fumadores[0]), NULL, fumador0, NULL);
    pthread_create(&(hebra_fumadores[1]), NULL, fumador1, NULL);
    pthread_create(&(hebra_fumadores[2]), NULL, fumador2, NULL);
    pthread_create(&hebra_estanquero, NULL, estanquero, NULL);

    pthread_join(hebra_fumadores[0], NULL);
    pthread_join(hebra_fumadores[1], NULL);
    pthread_join(hebra_fumadores[2], NULL);
    pthread_join(hebra_estanquero, NULL);

    for (int i = 0; i < 3; i++) {
        sem_destroy(&sem_fumadores[i]);
    }

    sem_destroy(&sem_estanquero);
}
