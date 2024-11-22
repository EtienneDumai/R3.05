#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void boucleInfini(void){
    while(1){
        printf(".\n");
        sleep(1.5);
        printf("\n");
    }
}

int main(void){
    boucleInfini();
    return 0;
}