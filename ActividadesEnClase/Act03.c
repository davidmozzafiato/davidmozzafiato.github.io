#include <stdio.h>
#include <unistd.h>
int main(){
    int pid;
    printf("\n Prueba de procesos:\n");

    fork();
    fork();
    printf("\t Se ha creado un proceso: padre= %d, yo= %d\n", getppid(), getpid());
    //waitpid(-1, NULL, 0);
    return 1;
}
