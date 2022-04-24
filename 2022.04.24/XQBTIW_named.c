#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main()
{

    char* fifoname = "./XQBTIW";
    mkfifo(fifoname, 0666);

    int pipe;
    pid_t p;
 
    p = fork();
 
    if (p < 0) {
        fprintf(stderr, "fork hiba");
        return 1;
    } else if (p > 0) {
        char str[80];
 
        printf("Szülő processz vár\n");

        wait(NULL);

        printf("Szülő process olvas.\n");

        pipe = open(fifoname, O_RDONLY);
        read(pipe, str, 80);
        close(pipe);

        printf("A %s nevű piperól olvasva: %s\n", fifoname, str);
        
    }
    else { 
 
        printf("Gyerek process.\n");

        char output_string[80];
        strcpy(output_string, "Dobra Gabor XQBTIW\n");

        pipe = open(fifoname, O_WRONLY);
        write(pipe, output_string, strlen(output_string));
        close(pipe);

        printf("Gyerek process vége.\n");

        exit(0);
    }

    return 0;
}