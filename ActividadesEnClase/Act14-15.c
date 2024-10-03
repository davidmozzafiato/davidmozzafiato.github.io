#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int num_hijos;
    printf("Ingrese el número de hijos a crear: ");
    scanf("%d", &num_hijos);
    if (num_hijos <= 0) {
        printf("El número de hijos debe ser un entero positivo.\n");
        return 1;
    }
    printf("Soy el proceso principal: %d\n", getpid());
    printf("============================\n");
    int hijo_numero = 1;
    for (int i = 0; i < num_hijos; i++) {
        pid = fork();
        if (pid == -1) {
            perror("Error al crear el proceso hijo");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            printf("Soy el hijo %d (pid=%d) y mi padre es (pid=%d)\n", hijo_numero, getpid(), getppid());
            if ((i + 1) % 2 == 0) {
                pid_t pid_nieto = fork();
                if (pid_nieto == -1) {
                    perror("Error al crear el proceso nieto");
                    exit(EXIT_FAILURE);
                }
                if (pid_nieto == 0) {
                    hijo_numero++;
                    printf("Soy el hijo %d (pid=%d) y mi padre es (pid=%d)\n", hijo_numero, getpid(), getppid());
                    sleep(1);
                    printf("Soy el hijo %d (pid=%d)... Terminé\n", hijo_numero, getpid());
                    exit(0);
                }
                wait(NULL);
            }
            sleep(1);
            printf("Soy el hijo %d (pid=%d)... Terminé\n", hijo_numero, getpid());
            exit(0);
        }
        hijo_numero++;
    }
    for (int i = 0; i < num_hijos; i++) {
        wait(NULL);
        printf("Padre: Esperando.... %d hijos\n", num_hijos - i - 1);
    }
    printf("TERMINÓ EL PROCESO PRINCIPAL (PID=%d)\n", getpid());
    return 0;
}
