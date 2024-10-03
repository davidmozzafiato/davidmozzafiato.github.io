#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void realizarMultiplicacion(int base, int nieto_id, int inicio, int fin) {
    for (int i = inicio; i <= fin; i++) {
        printf("\t Hijo%d, ---> nieto%d(PID=%d): %d x %d = %d\n",base, nieto_id, getpid(), base, i, base * i);
    }
}

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
            printf("Padre(pid=%d) ---> hijo%d(PID=%d)\n", getppid(), hijo_id, getpid());
            for (int nieto_id = 1; nieto_id <= 2; nieto_id++)
            {
                pid_t pid_nieto = fork();
                if (pid_nieto == 0)
                {
                    if (nieto_id == 1)
                        realizarMultiplicacion(hijo_id, nieto_id, 1, 5);
                    else
                        realizarMultiplicacion(hijo_id, nieto_id, 6, 10);
                    exit(0);
                }
                wait(NULL);
            }
            exit(0);
        }
        wait(NULL);
        hijo_id++;
    }
}
