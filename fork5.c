#include<stdio.h>
#include <unistd.h>
void main()
{
	int i ,n = 4;
	for(i = 1;i <= n;i++)
	fork();
	printf("Gm\n");
}
