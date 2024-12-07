/*
Question 1
Il y aura eu 4 processus quand le programme sera terminé.
A : 1 B: 2 C : 4
*/
#include <stdio.h>
#include <unistd.h>
int main(void) {
    pid_t pid = fork();
    printf("Hello World\n");
    if (pid == 0)
    {
        printf("I am the child\n");
    }
    else
    {
        printf("I am the parent\n");
    }
    
}