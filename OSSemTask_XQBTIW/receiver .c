#include<stdio.h>
#include<signal.h>
#include <stdlib.h>
  
int counter = 0;
void handle_signals(int sig) {
    if (sig == SIGUSR1) {
        counter += 1;
        printf("SIGUSR1 jel elkapva, valtozo novelve.\n");
    } else if (sig == SIGUSR2) {
        printf("SIGUSR2 jel elkapva, valtozo erteke: %d\n", counter);
    }
}

int main()
{
    signal(SIGUSR1, handle_signals);
    signal(SIGUSR2, handle_signals);
    
    while (1) ;
    return 0;
}
