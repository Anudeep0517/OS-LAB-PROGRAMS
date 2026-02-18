#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int file;
    file = open("test file.txt", O_RDONLY);
    if (file < 0) {
        perror("Error opening file");
        return 1;
    }
    char buffer[20];
    ssize_t bytesRead;

    bytesRead = read(file, buffer, 19);
    if (bytesRead < 0) {
        perror("Error reading file");
        close(file);
        return 1;
    }
    buffer[bytesRead] = '\0';
    printf("First read: %s\n", buffer);

    if (lseek(file, 10, SEEK_SET) < 0) {
        perror("Error with lseek");
        close(file);
        return 1;
    }

    bytesRead = read(file, buffer, 19);
    if (bytesRead < 0) {
        perror("Error reading file");
        close(file);
        return 1;
    }

    buffer[bytesRead] = '\0';
    printf("Second read: %s\n", buffer);

    close(file);
    return 0;
}
