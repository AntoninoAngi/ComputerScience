/*
Create this graph using forks

         P1
        /  \
       /    \
     P2      P3
     /\      /\
    /  \    /  \
  P4   P5  |   P6
    \  /    \  /
     \/      \/
     P7      P8
       \    /
        \  /
         P9

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    fprintf(stdout, "P1, PID = %d\n", getpid());
    pid_t pid23, pid36, pid45;
    pid23 = fork();

    if (pid23 == 0){ //child P3
        fprintf(stdout, "P3, PID = %d\n", getpid());
        pid36 = fork();
        if (pid36 == 0){ //child P6
            fprintf(stdout, "P6, PID = %d\n", getpid());
            exit (0);
        }else{ //padre P3
            wait((int *) 0);
            fprintf(stdout, "P8, PID = %d\n", getpid());
            exit (0);
        }
    }else{ //padre P2
        fprintf(stdout, "P2, PID = %d\n", getpid());
        pid45 = fork();
        if (pid45 == 0){ //child P5
            fprintf(stdout, "P5, PID = %d\n", getpid());
            exit(0);
        }else{ //padre P4
            fprintf(stdout, "P4, PID = %d\n", getpid());
            while (wait((int *) 0) != pid45);
            fprintf(stdout, "P7, PID = %d\n", getpid());
            wait((int *) 0);
            fprintf(stdout, "P9, PID = %d\n", getpid());
        }
    }

    return 0;
}
