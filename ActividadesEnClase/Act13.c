#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int hijo_id = 1, numProcesos;
    printf("=====================================\n");
    printf("Número de procesos:");
    scanf("%d", &numProcesos);
    printf("Soy el proceso principal: %d\n", getpid());
    printf("=====================================\n");
    for (size_t i = 0; i < numProcesos; i++){
            pid_t pid_hijo = fork();
            if (pid_hijo == 0){
            int res = wait(NULL);
            if (res == -1){
                printf("Esperando a que termine mi hijo: %d \n", getpid());
            }
            if (hijo_id <= numProcesos){
                printf("Soy el hijo %d (pid=%d) y mi padre es (pid=%d)\n", hijo_id, getpid(), getppid());
                int hijo_finish = wait(NULL);
                do{
                    printf("\t el hijo (pid=%d)...DUERMIENDO\n", getpid());
                }while(hijo_finish != -1);
                    printf("\t hijo(pid=%d)...Termine", getpid());
                    printf("\nya terminó mi hijo: %d\n\n", getpid());
                exit(0);
            }
        }
        hijo_id++;
    }
}