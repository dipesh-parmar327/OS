#include <stdio.h>
#include <stdlib.h>

void SSTF()
{
    int a[10], head, sum = 0, n, temp, diff1, diff2, first, pos;

    printf("\n----------SSTF----------\nEnter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the no. of request sequences: ");
    scanf("%d", &n);

    printf("\nEnter the request sequences: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    diff1 = abs(a[0] - head);
    pos = 0;

    for (int i = 1; i < n; i++)
    {

        if (abs(head - a[i]) < diff1)
        {
            diff1 = abs(head - a[i]);
            pos = i;
        }
    }

    printf("\nSeek sequences: ");

    printf("%d", head);
    for (int i = pos; i >= 0; i--)
    {
        printf(" --> %d ", a[i]);
    }

    for (int i = pos + 1; i < n; i++)
    {
        printf(" --> %d ", a[i]);
    }

    sum = abs(head - a[0]) + abs(a[n - 1] - a[0]);
    printf("\n\nTotal no of seek operation: %d\n", sum);
}

void FCFS()
{
    int a[10], head, sum = 0, n;

    printf("\n----------FCFS----------\nEnter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the no. of request sequences: ");
    scanf("%d", &n);

    printf("Enter the request sequences: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nSeek sequences: ");
    printf("%d", head);

    for (int i = 0; i < n; i++)
    {
        printf(" --> %d ", a[i]);
    }

    sum = sum + abs(head - a[0]);
    for (int i = 1; i < n; i++)
    {
        sum = sum + abs(a[i] - a[i - 1]);
    }
    printf("\nTotal no of seek operation: %d", sum);
}

int main()
{
    int x;
    printf("----------Program to implement FCFS and SSTF----------\n\nPress,\n1 = For SSTF\n2 = For FCFS\n3 = For Exit\n\nEnter your decision: ");
    scanf("%d", &x);

    if (x == 1)
    {
        SSTF();
    }

    if (x == 2)
    {
        FCFS();
    }

    if (x == 3)
    {
        goto end;
    }

end:
    return 0;
}














