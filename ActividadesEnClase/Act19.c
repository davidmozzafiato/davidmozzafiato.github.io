#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int numHijos;
    printf("=====================================\n");
    printf("Número de procesos:");
    scanf("%d", &numHijos);
    printf("Soy el proceso principal: %d\n", getpid());
    printf("=====================================\n");
}