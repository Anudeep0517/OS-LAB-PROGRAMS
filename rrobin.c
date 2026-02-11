#include <stdio.h>
#include <string.h>

int main()
{
    int bt[10], wt[10], tat[10], rt[10];
    int n, tq;
    int total = 0, completed = 0;
    float awt = 0, atat = 0;
    char p[10][20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter process name: ");
        scanf("%s", p[i]);

        printf("Enter burst time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];  
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (rt[i] > 0)
            {
                if (rt[i] > tq)
                {
                    total += tq;
                    rt[i] -= tq;
                }
                else
                {
                    total += rt[i];
                    wt[i] = total - bt[i];
                    rt[i] = 0;
                    completed++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;

    printf("\nProcess\tBT\tWT\tTAT");
    for (int i = 0; i < n; i++)
    {
        printf("\n%s\t%d\t%d\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f\n", atat);

    return 0;
}

