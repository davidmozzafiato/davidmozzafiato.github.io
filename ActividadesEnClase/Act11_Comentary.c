#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void realizarMultiplicacion(int base, int inicio, int fin) {
    for (int i = inicio; i <= fin; i++) {
        printf("\tMultiplicación del %d x %d = %d (PID=%d)\n", base, i, base * i, getpid());
    }
}

int main()
{
    int hijo_id = 1, numProcesos; // Inicializamos el identificador de los hijos
    // Solicita al usuario el número de procesos a crear
    printf("Ingrese el número de procesos: ");
    scanf("%d", &numProcesos);

    printf("\nNúmero de procesos: %d\n", numProcesos);
    printf("Soy el proceso principal: %d\n", getpid()); // Obtiene el ID del proceso actual
    printf("=====================================\n");

    for (size_t i = 0; i < numProcesos; i++) // Bucle para crear los procesos hijos
    {
        pid_t pid_hijo = fork(); // Se crea el hijo
        if (pid_hijo == 0) // Si fork() es 0, estamos en el proceso hijo
        {
            printf("Padre(pid=%d) ---> hijo%d(PID=%d)\n", getppid(), hijo_id, getpid()); // El hijo imprime su identificador, su PID y el PID de su padre

            for (int nieto_id = 1; nieto_id <= 2; nieto_id++) // Bucle para crear 2 procesos nietos
            {
                pid_t pid_nieto = fork(); // Se crea el nieto
                if (pid_nieto == 0) // Si fork() es 0, estamos en el proceso nieto
                {
                    if (nieto_id == 1)
                        realizarMultiplicacion(hijo_id, 1, 5); // Nieto 1 realiza multiplicaciones del n x 1 al n x 5
                    else
                        realizarMultiplicacion(hijo_id, 6, 10); // Nieto 2 realiza multiplicaciones del n x 6 al n x 10
                    exit(0); // Termina el proceso nieto
                }
                wait(NULL); // El hijo espera a que sus procesos nietos terminen antes de crear el siguiente
            }

            exit(0); // Termina el proceso hijo
        }
        wait(NULL); // El padre espera que el hijo termine antes de continuar con el siguiente hijo
        hijo_id++; // Incrementamos el identificador de los hijos en el proceso padre
    }
}
