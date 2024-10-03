#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    pid_t pid;
    printf("Proceso principal (main:) %i \n", getpid());
    switch (pid=fork()){
    case -1: printf("Error al crear el proceso\n");
        exit(0);
        break;
    case 0:
        printf("\t Soy el proceso hijo con (PID= %i) y mi padre es (PID=%i) \n", getpid(), getppid());
        break;
    default:
        printf("\t Soy el proceso padre con (PID= %i) y mi hijo es (PID= %i) \n", getppid(), pid);
        break;
    }
    printf("Terminó el proceso: %i \n", getppid());
    return 0;
}
