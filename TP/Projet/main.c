#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int nombreThreads = 0;
int nombresPersonnesTab=0;
int nombrePersonne=0;
int nombreSecondes = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* bosser() {
    int limite = rand()%6; 
    limite = limite + 5;
    sleep(2);
    printf("J'y suis tkt pas \n");

    pthread_mutex_lock(&mutex);
    nombreThreads++;
    nombrePersonne = nombreThreads;
    pthread_mutex_unlock(&mutex);
    time_t fin = time(NULL) + limite;
    while(1) {
        sleep(1);
        pthread_mutex_lock(&mutex);
        if(nombreSecondes == 10) {
            break;
        }
        if (fin < time(NULL)) {
            printf("Je suis en retard dcp je pars.\n");
            nombresPersonnesTab--; 
            nombreThreads--; // On décrémente le nombre de threads présents
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);
        if(nombrePersonne == nombresPersonnesTab) {
            break;
        }
    }
    if(nombreSecondes == 10) {
        printf("Exclusion de cours");
        pthread_exit(NULL);
    }
    printf("Je charbonne comme tout les jours de la semaine\n");
    pthread_exit(NULL);
}



int main(void) {

    pthread_attr_t attr;
    printf("Ca sera pour combien de personne aujourd'hui ?");
    scanf("%d", &nombresPersonnesTab);
    pthread_t threads[nombresPersonnesTab];
    pthread_attr_init(&attr);
    for(int i=0; i < nombresPersonnesTab; i++) {
        pthread_create(&threads[i], &attr, bosser, NULL);
    }
    for(int i=0; i < nombresPersonnesTab; i++) {
        pthread_join(threads[i] , NULL);
    }
    return 0;
}
