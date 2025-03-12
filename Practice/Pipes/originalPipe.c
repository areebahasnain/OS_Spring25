#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

#define BUFFER_SIZE 100
#define READ_END 0
#define WRITE_END 1

int main() {
  char write_msg[BUFFER_SIZE];
  char read_msg[BUFFER_SIZE];
  int fd[2];
  pid_t pid;
    
  if(pipe(fd) == -1) { // creating pipe
    perror("Pipe failed");
    exit(1);
  }
  
  printf("Enter a message to send:\n");
  fgets(write_msg, BUFFER_SIZE, stdin);
  
  pid = fork();
  
  if(pid > 0) { // parent
    close(fd[READ_END]);
    write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
    close(fd[WRITE_END]);
    printf("Parent Process ID: %d\n", getpid());
  }
  
  else { // child
    close(fd[WRITE_END]);
    read(fd[READ_END], read_msg, BUFFER_SIZE);
    printf("Received msg: %s", read_msg);
    close(fd[READ_END]);
    printf("Child Process ID: %d\n", getpid());
  }
  

  return 0;
}
