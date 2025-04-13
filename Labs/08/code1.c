#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg) {
    pthread_exit((void *)42);  
}

int main() {
    pthread_t thread;
    void *exit_status;    
    pthread_create(&thread, NULL, thread_function, NULL);
    pthread_join(thread, &exit_status);
    printf("Thread exited with status: %ld\n", (long)exit_status);
    return 0;
}
