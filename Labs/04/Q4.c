#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    int input_file, output_file;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    input_file = open("input.txt", O_RDONLY);
    if (input_file < 0) {
        perror("Error opening input.txt");
        return 1;
    }

    output_file = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_file < 0) {
        perror("Error opening output.txt");
        close(input_file);
        return 1;
    }

    while ((bytes_read = read(input_file, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(output_file, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to output.txt");
            close(input_file);
            close(output_file);
            return 1;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading from input.txt");
    }

    close(input_file);
    close(output_file);

    printf("File content copied successfully.\n");
    return 0;
}
