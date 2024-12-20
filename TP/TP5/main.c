#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int nbThreadsPresents = 0;
int X;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int nbPersonnes;
int nbSec = 0;

/* Manque la temporisation alÃ©atoire */

void* travail() {
    // Attendre
    sleep(2);
    printf("Je suis la \n");

    pthread_mutex_lock(&mutex);
    nbThreadsPresents++;
    nbPersonnes = nbThreadsPresents;
    pthread_mutex_unlock(&mutex);

    // Effectuer la tÃ¢che quand tlm est la
    while(1) {
        sleep(1);
        pthread_mutex_lock(&mutex);
        if(nbSec == 10) {
            break;
        }
        pthread_mutex_unlock(&mutex);
        if(nbPersonnes == X) {
            break;
        }

    }

    if(nbSec == 10) {
        printf("je suis ban :/");
        pthread_exit(NULL);
    }
    printf("J'effectue ma tÃ¢che \n");
    pthread_exit(NULL);
}



void* test(){
    printf("Test");
    pthread_exit(NULL);
}

int main(void) {
    // Variables
    clock_t horloge = clock();
    pthread_attr_t attr;

    // Traitements
    // RÃ©cupÃ©rer le nb utilisateurs
    printf("Combien de personnes ? ");
    scanf("%d", &X);

    // CrÃ©ation du tableau de threads
    pthread_t threads[X];

    // CrÃ©er les threads
    pthread_attr_init(&attr);
    for(int i=0; i < X; i++) {
        pthread_create(&threads[i], &attr, travail, NULL);
    }

    // Attendre la terminaison
    for(int i=0; i < X; i++) {
        pthread_join(threads[i] , NULL);
    }

    // Tout le monde a fini

    // Structure
    return 0;
}
