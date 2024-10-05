#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    //QUESTION 1 :
    /*printf("QUESTION 1 : \n");
    printf("je suis le processus n° : %d\n", getpid() );
    pid_t fork_value = fork();
    printf("fork m'a renvoye la valeur %d\n", fork_value);
    printf("je suis le processus %d et mon père est le processus %d \n", getpid(), getppid());
    sleep(1);*/
    //QUESTION 2 :
    /*printf("QUESTION 2 : \n");
    pid_t pid = fork();
    if(pid <0){
    printf("le fork a echoue\n");
    }
    if(pid == 0)
    {
        printf("Affichage des 10 premiers pair\n");
        for(int i=0; i<10; i++)
        {

            printf("Valeur de i pair : %d\n", i*2 );
        }
    }
    else
    {
        printf("Affichage des 10 premiers impairs\n");
        for(int i = 0; i<10; i++)
        {
            sleep(1);
            printf("Valeur de i impair %d\n", (i*2)+1);
        }
    }*/
    //QUESTION 3 :
    printf("QUESTION 3 : \n");
    pid_t pid = fork();
    int retour;
    if(pid <0)
    {
        printf("le fork a echoue \n");
    }
    if(pid==0)
    {
        sleep(1);
        printf("Resultat de la commande du fils : %d\n", retour);
    }
    else
    {
        retour = execlp("ps", "ps");
    }
    exit(0);
}
