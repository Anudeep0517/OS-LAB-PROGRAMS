#include<stdio.h>
int main()
{ 
	int bt[10], wt[10], tat[10], twt, ttat, n, i;
	char p[20][20];
	float awt, atat;
	printf("\n Enter the no of processes to be executed");
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		printf("\n Enter the process name");
		scanf("%s",p[i]);
		printf("\n Enter the burst time");
		scanf("%d", &bt[i]);
	}
	wt[0]=0,twt = 0;
	tat[0] = bt [0];
	ttat = bt[0];
	for(i = 1;i < n;i++)
	{
		wt[i] = wt[i - 1]+bt[i - 1];
		tat[i] = wt[i]+wt[i];
		twt = twt+wt[i];
		ttat = ttat+tat[i];
 	}
 	awt = (float)twt/n;
 	atat = (float)ttat/n;
 	printf("\n process names, burst time, waiting time, turn around time");
 	for(int i = 0;i < n;i++)
 	{
 		printf("\n %s \t %d \t %d \t %d \t", p[i], bt[i], wt[i], tat[i]);
 	}
 	printf("\n Average waiting time : %f",awt);
 	printf("\n Average trun around time : %f",atat);
 	
 	return 0;
}










