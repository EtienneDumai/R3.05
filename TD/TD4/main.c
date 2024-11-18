#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void afficher (int sig) {
    printf("ALors ca vient ?\n");
}

int main(void){
    struct sigaction sig_relance, ancien;
    char c;
    sig_relance.sa_handler = afficher;
    sig_relance.sa_flags = SA_RESTART;
    sigemptyset(&sig_relance.sa_mask);
    sigaction(SIGALRM, &sig_relance, &ancien);
    alarm(3);
    c=getchar();
    alarm(0);
    sigaction(SIGALRM, &ancien, NULL);
    sleep(50);
    exit(EXIT_SUCCESS);
    return 0;
}