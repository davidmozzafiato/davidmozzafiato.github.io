#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int hijo_id = 1, numProcesos;
    printf("Ingrese el número de procesos: ");
    scanf("%d", &numProcesos);
    printf("\nNúmero de procesos: %d\n", numProcesos);
    printf("Soy el proceso principal: %d\n", getpid());
    printf("=====================================\n");

    for (size_t i = 0; i < numProcesos; i++)
    {
        pid_t pid_hijo = fork();
        if (pid_hijo == 0)
        {
            printf("Padre(pid=%d) ---> hijo%d:(pidf=%d)\n", getppid(), hijo_id, getpid());
            if (hijo_id <= 1)
            {
                for (int nieto_id = 1; nieto_id <= 2; nieto_id++)
                {
                    pid_t pid_nieto = fork();
                    if (pid_nieto == 0)
                    {
                        printf("\t Hijo (pid=%d) ---> Nieto%d:(pid=%d)\n", getppid(), nieto_id, getpid());
                        exit(0);
                    }
                    wait(NULL);
                }
            }
            exit(0);
        }
        wait(NULL);
        hijo_id++;
    }
}
