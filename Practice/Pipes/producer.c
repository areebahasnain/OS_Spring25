#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

#define FIFO_FILE "/tmp/myfifo"
#define BUFFER_SIZE 100

int main() {
  int fd;
  char buffer[BUFFER_SIZE];
  ssize_t num_bytes;
  
  mkfifo(FIFO_FILE, 0666);
  
  fd = open(FIFO_FILE, O_WRONLY);
  
  if(fd == -1) {
    perror("Error reading pipe");
    exit(1);
  }
  
  while(1) {
    printf("Producer: Enter a message (or 'exit' to quit: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    
    num_bytes = write(fd, buffer, strlen(buffer));
    if(num_bytes == -1) {
      perror("Error writing to file");
      exit(1);
    }
    
    if(strncmp(buffer, "exit", 4) == 0) {
      break;
    }
  }
  
  close(fd);
  unlink(FIFO_FILE);
  
  return 0;
}

