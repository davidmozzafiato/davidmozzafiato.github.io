#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int i, j; // Declaración de variables para contadores
    printf("Padre(PID=%d))\n", getpid()); // Imprime el proceso padre inicial con su PID
    for (size_t i = 0; i < 4; i++) // Bucle para crear 4 procesos hijos
    {
        if (fork() == 0) // Si fork() es 0, estamos en el proceso hijo
        {
            if (i == 1) // Solo el segundo hijo (i == 1) ejecutará el código dentro de este bloque
            {
                printf("\t Hijo(PID=%d) ---> mi Padre es (PID=%d))\n", getpid(), getppid()); // El hijo imprime su PID y el PID de su padre
                for (size_t i = 0; i < 2; i++) // Bucle para crear 2 procesos nietos
                {
                    if(fork() == 0) // Si fork() es 0, estamos en el proceso nieto
                    {
                        printf("\t \t Nieto(PID=%d) ---> mi Padre es (PID=%d))\n", getpid(), getppid()); // El nieto imprime su PID y el PID de su padre (el hijo)
                        break; // Termina la ejecución del nieto para evitar que siga creando más procesos
                    }
                }
            }
            break; // El hijo sale del bucle para evitar que cree más procesos
        }
    }
}
