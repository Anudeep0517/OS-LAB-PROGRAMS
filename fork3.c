#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Hi\n");
    fork();
    printf("Hello\n");
    fork();
    printf("Gm\n");
    return 0;
}

