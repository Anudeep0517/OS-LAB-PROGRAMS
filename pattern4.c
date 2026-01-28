#include<stdio.h>
int main()
{
int n,s,i,j;
printf("enter the number of rows");
scanf("%d",&n);
	for(int i=1;i<=n;++i)
{
	for(int s=i;s<=n-1;++s)
{
	printf(" ");	 
}
	for(int j=1;j<=i;++j)
	{
	printf("%d",i,j);
	}
	printf("\n");
	
}
return 0;
}





































































