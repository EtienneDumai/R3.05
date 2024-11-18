#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void boucleInfini(void){
    while(1){
        printf(".\n");
        sleep(0.5);
    }
}

int main(void){
    boucleInfini();
    return 0;
}