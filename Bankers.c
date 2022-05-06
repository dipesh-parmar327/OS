// Banker's Algorithm
#include <stdio.h>

int main()
{
    int P_all[10][10], P_max[10][10], Available[10], P_need[10][10], x1, x2;

    printf("Enter the number of processes: ");
    scanf("%d", &x1);

    printf("Enter the number of memory spaces: ");
    scanf("%d", &x2);

    for (int i = 0; i < x1; i++)
    {
        printf("Enter allocation of P%d:\n", i);
        for (int j = 0; j < x2; j++)
        {
            scanf("%d", &P_all[i][j]);
        }
    }

    printf("\n\n");

    for (int i = 0; i < x1; i++)
    {
        printf("Enter maximum memory space of P%d:\n", i);
        for (int j = 0; j < x2; j++)
        {
            scanf("%d", &P_max[i][j]);
        }
    }

    printf("\n\nEnter available memory space of P0:\n");
    for (int j = 0; j < x2; j++)
    {
        scanf("%d", &Available[j]);
    }

    // Calculating Need Matrix

    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < x2; j++)
        {
            P_need[i][j] = P_max[i][j] - P_all[i][j];
        }
    }

    printf("\n\nThe need matrix:\n");

    printf("+---------+");
    for (int i = 0; i < x2; i++)
    {
        printf("--------+");
    }

    printf("\n| Process |");

    for (int i = 1; i <= x2; i++)
    {
        if (i == ((x2 / 2) + 1) || x2 == 1)
        {
            printf("  Need  ");
        }

        else
        {
            printf("         ");
        }
    }

    printf("|\n+---------+");
    for (int i = 0; i < x2; i++)
    {
        printf("--------+");
    }
    printf("\n");

    for (int i = 0; i < x1; i++)
    {
        printf("|   P%d    |", i);
        for (int j = 0; j < x2; j++)
        {
            if (P_need[i][j] < 10 || P_need[i][j] > 0)
            {
                printf("   0%d   ", P_need[i][j]);
            }

            if (P_need[i][j] >= 10 || P_need[i][j] < 0)
            {
                printf("   %d   ", P_need[i][j]);
            }
            printf("|");
        }
        printf("\n");
    }

    printf("+---------+");
    for (int i = 0; i < x2; i++)
    {
        printf("--------+");
    }
    printf("\n");

    // Checking condition
    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < x2; j++)
        {
            if (P_need[i][j] <= Available[j])
            {
                Available[j] = Available[j] + P_all[i][j];
            }
        }
    }

    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < x2; j++)
        {
            if (P_need[i][j] <= Available[j])
            {
                Available[j] = Available[j] + P_all[i][j];
            }

            else
            {
                printf("\nThe System is in The DeadLock!!!\n");
            }
        }
    }

    return 0;
}





















