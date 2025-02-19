#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_user_id() {
    printf("User ID (UID): %d\n", getuid());
}

int main() {
    pid_t child1, child2;

    child1 = fork();

    if (child1 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (child1 == 0) {
        printf("Child process 1 PID: %d\n", getpid());
        exit(0);
    } else {
        child2 = fork();

        if (child2 < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (child2 == 0) {
            printf("Child process 2 Parent PID: %d\n", getppid());
            exit(0);
        } else {
            wait(NULL);
            wait(NULL);
            printf("Parent process exiting.\n");
        }
    }

    return 0;
}
