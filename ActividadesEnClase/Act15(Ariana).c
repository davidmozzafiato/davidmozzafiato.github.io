#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int num_hijos;

    // Solicitar el número de hijos al usuario
    printf("Ingrese el número de hijos a crear: ");
    scanf("%d", &num_hijos);

    if (num_hijos <= 0) {
        printf("El número de hijos debe ser un entero positivo.\n");
        return 1;
    }

    printf("Soy el proceso principal: %d\n", getpid());
    printf("============================\n");

    pid_t hijos[num_hijos];

    // Crear hijos
    for (int i = 0; i < num_hijos; i++) {
        pid = fork();
        if (pid == -1) {
            perror("Error al crear el proceso hijo");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Código del proceso hijo
            printf("Soy el hijo %d (pid=%d) y mi padre es (pid=%d)\n", i + 1, getpid(), getppid());
            sleep(1);  // Simular trabajo
            printf("Soy el hijo %d (pid=%d)... Terminé\n", i + 1, getpid());
            exit(0);
        } else {
            hijos[i] = pid; // Guardar el PID del hijo creado
        }
    }

    // Esperar a que todos los hijos terminen en orden específico
    for (int i = num_hijos - 1; i >= 0; i--) {
        pid_t hijo_terminado = waitpid(hijos[i], NULL, 0);
        if (hijo_terminado > 0) {
            printf("Padre: Esperando.... %d hijos\n", i);
            printf("hijo %d (pid=%d)...Termine\n", i + 1, hijos[i]);
        }
    }

    printf("TERMINÓ EL PROCESO PRINCIPAL (PID=%d)\n", getpid());
    return 0;
}