#include <stdio.h>
#include <unistd.h>

void print_user_id() {
    printf("User ID (UID): %d\n", getuid());
}

int main() {
    printf("Current Process ID (PID): %d\n", getpid());
    printf("Parent Process ID (PPID): %d\n", getppid());
    
    print_user_id();
    
    return 0;
}
