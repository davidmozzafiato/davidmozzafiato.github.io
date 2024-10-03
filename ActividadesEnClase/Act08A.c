#include <stdio.h>
#include <unistd.h>

int main() {
    int N; // Número de procesos a crear
    pid_t pid;

    // Solicita al usuario el número de procesos a crear
    printf("Ingrese el número de procesos: ");
    scanf("%d", &N);

    printf("\nNúmero de procesos: %d\n", N);
    printf("Soy el proceso principal: %d\n", getpid());//obtiene el ID del proceso actual
    printf("=====================================\n");

    for (int i = 0; i < N; i++) {
        pid = fork(); // Crea un nuevo proceso

        if (pid < 0) { // Si ocurre un error en fork()
            printf("Error al crear el proceso\n");
            return 1; // Termina el programa en caso de error
        }

        if (pid > 0) { // Proceso padre
            // Imprime el PID del padre y del hijo
            printf("Padre(pid=%d) ---> hijo(pid=%d)\n", getpid(), pid);
            break; // El padre sale del ciclo para que solo el hijo continúe
        }
        // Si pid == 0, es un proceso hijo y sigue el ciclo para crear otro hijo
    }

    return 0;
}