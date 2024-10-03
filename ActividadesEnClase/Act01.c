#include <stdio.h>
#include <unistd.h>
int main(){
    printf("\n Prueba de procesos: \n");

    fork();
    printf("\t Se ha creado un proceso\n");
}
