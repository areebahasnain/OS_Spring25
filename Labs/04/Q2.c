#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t process = fork();

    if (process == -1) {
        printf("Failed to fork process\n");
        return 1;
    }

    for (int i = 0; i < 100; ++i)
        printf("I am a %s process\n", process ? "parent" : "child");

    return 0;
}
