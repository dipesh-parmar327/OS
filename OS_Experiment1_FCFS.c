#include <stdio.h>

int main()
{
    float p[20], wt[20], avg_wt, tat[20], avg_tat;
    int n;

    wt[0] = 0;
    tat[0] = 0;
    avg_wt = 0;
    avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%f", &p[i]);
    }

    printf("\n\nStep 1: Gantt Chart\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("+-----------");
    }

    printf("+\n");

    for (int i = 0; i < n; i++)
    {
        printf("|     P%d    ", i + 1);
    }

    printf("|\n");

    for (int i = 0; i < n; i++)
    {
        printf("+-----------");
    }

    for (int i = 0; i < n; i++)
    {
        wt[i+1] = wt[i] + p[i];
        avg_wt = avg_wt + wt[i];
    }

    printf("+\n");
    printf("0         ");
    wt[n+1] = wt[n] + p[n];

    for (int i = 0; i < n; i++)
    {
        printf("%.1f         ", wt[i+1]);
    }

    printf("\n\nStep 2: Waiting Time\n\n");    

    for (int i = 0; i < n; i++)
    {
        printf("P%d = %.2f ms\n", i+1, wt[i]);
    }

    printf("\nStep 3: Average waiting time\n\nAverage waiting time = %.3f ms\n\nStep 4: TurnAround Time\n\n", (avg_wt/n));

    tat[n-1] = wt[n-1] + p[n-1];
    avg_tat = avg_tat + tat[n-1];

    for (int i = 1; i < n; i++)
    {
        tat[i-1] = wt[i];
        avg_tat = avg_tat + tat[i-1];
    }

    for (int i = 0; i < n; i++) 
    {
        printf("P%d = %.2f ms\n", i+1, tat[i]);
    }

    printf("\nStep 5: Average TurnAround Time\n\nAverage TurnAround Time = %.3f ms\n\n", (avg_tat/n));

    return 0;
}








































