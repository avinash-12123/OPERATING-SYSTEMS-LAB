#include <stdio.h>

int main()
{
    int n, choice;
    int pid[20], at[20], bt[20], ct[20], tat[20], wt[20];
    int i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Process IDs:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pid[i]);

    printf("Enter Arrival Times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter Burst Times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("\nChoose Scheduling Type\n");
    printf("1. SJF Non-Preemptive\n");
    printf("2. SJF Preemptive (SRTF)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {

    case 1:
    {
        int completed[20] = {0};
        int time = 0, done = 0;
        float avgwt = 0, avgtat = 0;

        while(done < n)
        {
            int idx = -1;
            int min = 9999;

            for(i = 0; i < n; i++)
            {
                if(at[i] <= time && completed[i] == 0 && bt[i] < min)
                {
                    min = bt[i];
                    idx = i;
                }
            }

            if(idx != -1)
            {
                time += bt[idx];
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                completed[idx] = 1;
                done++;
            }
            else
                time++;
        }

        printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
        for(i = 0; i < n; i++)
        {
            avgwt += wt[i];
            avgtat += tat[i];
            printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        }
        printf("\nAverage Waiting Time = %.2f", avgwt/n);
        printf("\nAverage Turnaround Time = %.2f\n", avgtat/n);
        break;
    }
    case 2:
    {
        int rt[20];
        for(i = 0; i < n; i++)
            rt[i] = bt[i];

        int time = 0, done = 0;
        float avgwt = 0, avgtat = 0;

        while(done < n)
        {
            int idx = -1;
            int min = 9999;

            for(i = 0; i < n; i++)
            {
                if(at[i] <= time && rt[i] > 0 && rt[i] < min)
                {
                    min = rt[i];
                    idx = i;
                }
            }

            if(idx != -1)
            {
                rt[idx]--;
                time++;

                if(rt[idx] == 0)
                {
                    ct[idx] = time;
                    tat[idx] = ct[idx] - at[idx];
                    wt[idx] = tat[idx] - bt[idx];
                    done++;
                }
            }
            else
                time++;
        }

        printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
        for(i = 0; i < n; i++)
        {
            avgwt += wt[i];
            avgtat += tat[i];
            printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        }

        printf("\nAverage Waiting Time = %.2f", avgwt/n);
        printf("\nAverage Turnaround Time = %.2f\n", avgtat/n);

        break;
    }

    default:
        printf("Invalid Choice\n");
    }

    return 0;
}
