#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int hijo_id = 1, numProcesos;
    printf("=====================================\n");
    printf("Número de procesos:");
    scanf("%d", &numProcesos);
    printf("Soy el proceso principal: %d\n", getpid());
    printf("=====================================\n");

    for (size_t i = 0; i < numProcesos; i++)
    {
        pid_t pid_hijo = fork();
        if (pid_hijo == 0)
        {
            printf("Soy el proceso hijo(pid=%d) y mi padre es (pid=%d)",getpid(), getppid());
            //printf("Padre (pid=%d) ---> hijo %d (PID=%d)\n", getppid(), hijo_id, getpid());
            if (hijo_id <= numProcesos)
            {
                printf("\n\t hijo (pid=%d)", getppid());
                exit(0);
            }
            exit(0);
        }
        int res = wait(NULL);
        hijo_id++;
        if (res == -1)
        {
            printf("No hay procesos por terminar.");
        }else{
            printf("...Terminé \n");
        }
    }
    printf("TERMINÓ EL PROCESO PRINCIPAL (pid=%d)  \n\n", getpid());
}