#include<stdio.h>
#include<signal.h>
#include <stdlib.h>
  

int main()
{
    pid_t pid;
    int signal;
    printf("Mi a folyamat PID-je?\n");
    scanf("%d", &pid);

    while(1) {
        printf("Milyen jelet küldjünk? 1 - SIGUSR1 2 - SIGUSR2 0 - kilépés\n");
        scanf("%d", &signal);

        if (signal == 0) {
            printf("Program befejezése.\n");
            break;
        } else if (signal == 1) {
            kill(pid, SIGUSR1);
        } else if (signal == 2) {
            kill(pid, SIGUSR2);
        }

        printf("Signal elküldve.\n");
    }
    

    return 0;
}
