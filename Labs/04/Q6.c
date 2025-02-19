#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_alarm(int sig) {
    printf("Alarm received. Exiting program.\n");
    exit(0);
}

int main() {
    signal(SIGALRM, handle_alarm);
    alarm(5);  // Set alarm for 5 seconds

    for (int i = 1; ; i++) {
        printf("%d second(s) elapsed...\n", i);
        sleep(1);
    }

    return 0;
}
