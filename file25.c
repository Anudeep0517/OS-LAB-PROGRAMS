#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int file = 0;

    if ((file = open("test file.txt", O_RDONLY)) < 0)
        return 1;

    char buffer[20];   
    if (read(file, buffer, 19) != 19)
        return 1;

    buffer[19] = '\0';   
    printf("%s\n", buffer);

    if (lseek(file, 10, SEEK_SET) < 0)
        return 1;

    if (read(file, buffer, 19) != 19)
        return 1;

    buffer[19] = '\0';
    printf("%s\n", buffer);

    close(file);
    return 0;
}

