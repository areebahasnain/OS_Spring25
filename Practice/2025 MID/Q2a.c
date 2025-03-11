#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

#define FILE_NAME "data.txt"

void write_numbers_to_file() {
  FILE *file = fopen(FILE_NAME, "w");
  if(file == NULL) {
    perror("Error opening file");
    exit(1);
  }
  fprintf(file, "10 2 7");
  fclose(file);
}

void read_numbers_from_file(int *a, int *b, int *c) {
  FILE *file = fopen(FILE_NAME, "r");
  if(file == NULL) {
    perror("Error opening file");
    exit(1);
  }
  fscanf(file, "%d %d %d", a, b, c);
  fclose(file);
}

int sum(int n) {
  return (n* (n+1)) / 2;
}

int main() {
  int num1, num2, num3;
  
  write_numbers_to_file();
  read_numbers_from_file(&num1, &num2, &num3);
  
  pid_t pid;
  
  // CHILD 1
  pid = fork();
  if(pid == 0) { // child process
    printf("Child 1: Sum of first %d numbers: %d\n", num1, sum(num1));
    exit(0);
  }
  else if(pid > 0) { // parent process
   wait(NULL);
  }
  else {
    perror("Fork Failed");
    exit(1);
  }
  
  // CHILD 2
  pid = fork();
  if(pid == 0) { // child process
    printf("Child 2: Cube of %d: %d\n", num2, num2*num2*num2);
    exit(0);
  }
  else if(pid > 0) { // parent process
    wait(NULL);
  }
  else {
    perror("Fork Failed");
    exit(1);
  }
  
  // CHILD 3
  pid = fork();
  if(pid == 0) { // child process
    printf("Child 3: Square of %d: %d\n", num3, num3*num3);
    exit(0);
  }
  else if(pid > 0) { // parent process
    wait(NULL);
  }
  else {
    perror("Fork Failed");
    exit(1);
  }
      
  printf("All child processes have completed their tasks.\n");
  return 0;
}
