#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void numerosNaturales(int hijoId, int nietoId, int numN) {
    printf("\t (PID=%d): %d\n", getpid(), numN);
}

int main()
{
    int hijoId = 1, numProcesos, num = 1, inicio = 0, fin = 5;
    printf("Ingrese el número de procesos: ");
    scanf("%d", &numProcesos);
    printf("\nNúmero de procesos: %d\n", numProcesos);
    printf("Soy el proceso principal: %d\n", getpid());
    printf("=====================================\n");
    for (size_t i = 0; i < numProcesos; i++)
    {
        pid_t pidHijo = fork();
        if (pidHijo == 0)
        {
            printf("Padre(pid=%d) ---> hijo%d(PID=%d)\n", getppid(), hijoId, getpid());
            for (int nietoId = 1; nietoId <= 2; nietoId++)
            {
                pid_t pidNieto = fork();
                if (pidNieto == 0)
                {
                    for (int i = inicio; i < fin; i++){
                        if (nietoId == 1){
                            numerosNaturales(hijoId, nietoId, num);
                            sleep(1);
                        }
                        else{
                            numerosNaturales(hijoId, nietoId, num);
                            sleep(2);
                        }
                        num++;
                    }
                    exit(0);
                }
                wait(NULL);
            }
            exit(0);
        }
        wait(NULL);
        hijoId++;
    }
}
