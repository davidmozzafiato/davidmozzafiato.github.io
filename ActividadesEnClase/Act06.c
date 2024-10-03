#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int a = 8;
    pid_t pid;
    printf("\n Proceso principal (main:) %i \n", getpid());
    printf("\n Número de hijos: %i", a);
    switch (pid=fork()){
    case -1: printf("Error al crear el proceso\n");
        exit(0);
        break;
    case 0:
        for (size_t i = 0; i < a; i++)
        {
            printf("\n Soy el proceso hijo con (PID= %i) y mi padre es (PID=%i) \n", getpid(), getppid());
        }
        break;
    default:
        break;
    }
    return 0;
}
