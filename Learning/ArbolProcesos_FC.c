#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int hijo_id = 1, numProcesos; // Inicializamos el identificador de los hijos
    // Solicita al usuario el número de procesos a crear
    printf("Ingrese el número de procesos: ");
    scanf("%d", &numProcesos);
    printf("=====================================\n");
    printf("Número de procesos: %d\n", numProcesos);
    printf("Proceso principal: %d\n", getpid());//obtiene el ID del proceso actual
    printf("=====================================\n");

    for (size_t i = 0; i < numProcesos; i++) // Bucle para crear 4 procesos hijos
    {
        pid_t pid_hijo = fork(); // Se crea el hijo
        if (pid_hijo == 0) // Si fork() es 0, estamos en el proceso hijo
        {
            printf("Padre (pid=%d) ---> hijo %d (PID=%d)\n", getppid(), hijo_id, getpid()); // El hijo imprime su identificador, su PID y el PID de su padre
            if (hijo_id <= numProcesos) // Solo el primer y segundo hijo crean nietos
            {
                for (int nieto_id = 1; nieto_id <= 2; nieto_id++) // Bucle para crear 2 procesos nietos
                {
                    pid_t pid_nieto = fork(); // Se crea el nieto
                    if (pid_nieto == 0) // Si fork() es 0, estamos en el proceso nieto
                    {
                        printf("\t Hijo (pid=%d) ---> Nieto %d (PID=%d)\n", getppid(), nieto_id, getpid()); // El nieto imprime su identificador, su PID y el PID de su padre
                        exit(0); // Termina el proceso nieto para evitar que siga ejecutando código
                    }
                    wait(NULL); // El hijo espera que su proceso nieto termine antes de crear el siguiente
                }
            }
            exit(0); // Termina el proceso hijo para evitar que siga creando más procesos
        }
        int res = wait(NULL); // El padre espera que el hijo termine antes de continuar con el siguiente hijo
        hijo_id++; // Incrementamos el identificador de los hijos en el proceso padre
        if (res == -1)
        {
            printf("No children is waiting for...");
        }else{
            printf("%d children finished execution\n\n", res);
        }
    }
}