#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process executes 'ls' command
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp failed");
        return 1;
    } else {
        // Parent process waits for child to complete
        wait(NULL);
        printf("Child process completed. Parent exiting.\n");
    }

    return 0;
}
