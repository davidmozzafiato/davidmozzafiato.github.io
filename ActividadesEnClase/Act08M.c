/* Escribir un programa que cree N procesos según el siguiente árbol de procesos:*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int c;
    pid_t pid;
    printf("\n Proceso principal (main:) %i \n", getpid());
    printf("\n Número de hijos: %i", c);
    while (c >= 0){
    switch (pid=fork()){
    case -1: printf("Error al crear el proceso\n");
        exit(0);
        break;
    case 0:
            printf("\n Padre (PID=%i))", getppid());
            exit(0);
        break;
    default:
        printf("---> hijo (PID=%i) \n", getpid());
        exit(0);
        break;
    }}
    return 0;
}