#include <stdio.h>
#include <unistd.h>
int main(){
    pid_t pid, child1, child2;
    printf("\n Prueba de procesos:\n");

    child1 = fork();
    child2 = fork();
    printf("\t Se ha creado un proceso: padre= %d, yo= %d\n", getppid(), getpid());
    pid = waitpid(pid, NULL, 0);
    return 1;
}
