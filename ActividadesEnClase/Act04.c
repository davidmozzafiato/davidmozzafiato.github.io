#include <stdio.h>
#include <unistd.h>
int main(){
    int pid;
    printf("\n Prueba de procesos:\n");

    fork();
    fork();
    fork();
    printf("\t Se ha creado un proceso: padre= %d, yo= %d\n", getppid(), getpid());
    // sleep(2); nunca usar
    return 0;
}
