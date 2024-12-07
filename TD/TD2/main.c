#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

const int n = 10;
int tab[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int max = 0;
void parcoursTableau(int *debut);

int main(void)
{
    int debthread1, debthread2;
    pthread_attr_t attr;
    pthread_t id1, id2;
    pthread_attr_init(&attr);
    pthread_create(&id1, &attr, (void*)parcoursTableau, &debthread1);
    pthread_create(&id2, &attr, (void*)parcoursTableau, &debthread2);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    printf("Le maximum est %d\n", max);
    pthread_mutex_destroy(&mutex);
    exit(EXIT_SUCCESS);
}
void parcoursTableau(int *debut)
{
    int i, depart, fin;
    depart = *debut;
    fin = depart + n / 2;
    for (i = depart; i<fin ; i++)
    {
        pthread_mutex_lock(&mutex);
        if (tab[i] > max)
        {
            max = tab[i];
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}