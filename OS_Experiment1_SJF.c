#include <stdio.h>

int main()
{
    float p[20], sp[20], q[20], temp = 0;
    int n;

    sp[0] = 0;
    q[0] = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%f", &p[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sp[i + 1] = p[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (p[i] >= p[i + 1])
        {
            temp = sp[i + 2];
            sp[i + 2] = sp[i + 1];
            sp[i + 1] = temp;
        }
    }

    temp = 0;

    for (int i = n; i > 0; i--)
    {
        if (sp[n - 1] <= sp[n - 2])
        {
            temp = sp[n - 1];
            sp[n - 1] = sp[n - 2];
            sp[n - 2] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        q[i] = q[i] + sp[i+1];
    }

    // printf("\n\nStep 1: Gantt Chart\n\n");

    // for (int i = 0; i < n; i++)
    // {
    //     printf("+-----------");
    // }

    // printf("+\n");

    // for (int i = 0; i < n; i++)
    // {
    //     printf("|     P%d    ", i + 1);
    // }

    // printf("|\n");

    // for (int i = 0; i < n; i++)
    // {
    //     printf("+-----------");
    // }

    // printf("+\n");
    // printf("0         ");

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%.1f         ", sp[i+1]);
    // }

    printf("\n\nWaiting time: \n\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d = %.2f ms\n", i+1, q[n-1-i]);
    }
    




}