#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t process = fork();

	if (process == -1) {
		printf("Failed to fork\n");
		return 1;
	}

	if (process == 0) {
		execlp("ls", "ls", NULL);
		printf("Failed to list content of dir\n");
		return 1;
	}

	wait(NULL);
	printf("Parent process ending\n");

	return 0;
}
