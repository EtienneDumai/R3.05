#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
unsigned long int cpt = 0;
void *compteur(void *arg)
{
    unsigned long int tmp = 0;
    for (int i = 0; i < 1000000; i++)
    {
        tmp = cpt;
        tmp += 1;
        cpt = tmp;
    }
}
int main(void)
{
    clock_t start, end;
    start = clock();
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_t thread1, thread2;
    pthread_create(&thread1, &attr, compteur, NULL);
    pthread_create(&thread2, &attr, compteur, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("cpt = %lu\n", cpt);
    end = clock();
    
    // Calculer le temps écoulé en millisecondes
    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    
    // Afficher le résultat
    printf("Temps d'exécution : %f millisecondes\n", time_taken);

    return 0;
}
// Question 2
