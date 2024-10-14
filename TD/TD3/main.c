#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAILLE 1000000
int tab[TAILLE];
int somme = 0;
int tube[2];

int main(void)
{
    int x = pipe(tube);
    pid_t pid = fork();
    if (x == 1)
    {
        if (pid < 0)
        {
            printf("Erreur dans la creation du fork");
        }
        if (pid == 0)
        {
            printf("Je suis le processus fils\n");
            for (int i = 0; i < TAILLE / 2; i++)
            {
                somme += tab[i];
            }
        }
        else
        {
            printf("Je suis le processus pere\n");
            for (int i = TAILLE / 2; i < TAILLE; i++)
            {
                somme += tab[i];
            }
        }
    }

    return 0;
}