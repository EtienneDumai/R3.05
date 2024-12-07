#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *boucleInfini(void *arg)
{
    setbuf(stdout, NULL);
    while (1)
    {
        printf(".\n");
        sleep(1);
    }
    return NULL;
}
void *entreeUser(void *arg)
{
    printf("tapez un caractère\n");
    getchar();
    return NULL;
}
int main(void)
{
    // creation de 2 threads
    pthread_t thread1, thread2;
    
    //initialiser les attributs
    pthread_attr_t attr;
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_attr_init(&attr);
    
    //creation des threads

    pthread_create(&thread1, &attr, boucleInfini, NULL);
    pthread_create(&thread2, &attr, entreeUser, NULL);
    printf("Les 2 threads sont lances\n");
    //attendre la fin des threads
    
    pthread_join(thread2, NULL);
    printf("On va s'arreter la \n");
    return 0;
}
// @brief : Reponse Q3, le premier ne se fini jamais car il execute une boucle infini donc le programme va continuer a tourner