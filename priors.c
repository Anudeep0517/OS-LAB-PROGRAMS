#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int bt[10], wt[10], tat[10], pr[10];
    int twt = 0, ttat = 0, n;
    char p[10][20];
    float awt, atat;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter process name: ");
        scanf("%s", p[i]);

        printf("Enter burst time: ");
        scanf("%d", &bt[i]);

        printf("Enter priority: ");
        scanf("%d", &pr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {              
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
 
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
               
                char tempName[20];
                strcpy(tempName, p[i]);
                strcpy(p[i], p[j]);
                strcpy(p[j], tempName);
            }
        }
    }
   
    wt[0] = 0;
    tat[0] = bt[0];
    ttat = tat[0];

    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];

        twt += wt[i];
        ttat += tat[i];
    }

    awt = (float)twt / n;
    atat = (float)ttat / n;

    printf("\nProcess\tBT\tPriority\tWT\tTAT");
    for (int i = 0; i < n; i++)
    {
        printf("\n%s\t%d\t%d\t\t%d\t%d", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f\n", atat);

    return 0;
}

