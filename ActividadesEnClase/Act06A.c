#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int N; // Número de procesos hijos
    pid_t pid;

    // Solicita al usuario el número de procesos hijos
    printf("Ingrese el número de hijos a crear: ");
    scanf("%d", &N);

    printf("\nNúmero de hijos: %d\n", N);
    printf("Soy el proceso principal: %d\n", getpid());
    printf("=====================================\n");

    // Creamos N procesos hijos secuencialmente sin usar ciclos
    while (N > 0) {
        pid = fork(); // Crea un proceso hijo

        if (pid == -1) { // Si ocurre un error en fork()
            printf("Error al crear el proceso\n");
            exit(1);
        }

        if (pid == 0) { // Proceso hijo
            printf("Soy el proceso hijo(pid=%d) y mi padre es(pid=%d)\n", getpid(), getppid());
            exit(0); // El hijo termina aquí
        }

        // Disminuye N, cada vez que se crea un hijo, el padre sigue
        N--;
    }

    return 0; // El padre termina cuando ha creado todos los hijos
}