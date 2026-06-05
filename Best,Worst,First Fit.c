#include <stdio.h>
#define MAX 20
void firstFit(int blocks[], int nb, int process[], int np);
void bestFit(int blocks[], int nb, int process[], int np);
void worstFit(int blocks[], int nb, int process[], int np);
void printAllocation(int alloc[], int process[], int np, int choice);
int main()
{
    int nb, np;
    int blocks[MAX], process[MAX];
    int choice;
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter sizes of memory blocks:\n");
    for(int i = 0; i < nb; i++)
        scanf("%d", &blocks[i]);
    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter sizes of processes:\n");
    for(int i = 0; i < np; i++)
        scanf("%d", &process[i]);
    printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            firstFit(blocks, nb, process, np);
            break;
        case 2:
            bestFit(blocks, nb, process, np);
            break;
        case 3:
            worstFit(blocks, nb, process, np);
            break;
        default:
            printf("Invalid Choice!\n");
    }
    return 0;
}
void firstFit(int blocks[], int nb, int process[], int np)
{
    int alloc[MAX];
    int b[MAX];
    for(int i = 0; i < nb; i++)
        b[i] = blocks[i];
    for(int i = 0; i < np; i++)
        alloc[i] = -1;
    for(int i = 0; i < np; i++)
    {
        for(int j = 0; j < nb; j++)
        {
            if(b[j] >= process[i])
            {
                alloc[i] = j;
                b[j] -= process[i];
                break;
            }
        }
    }
    printAllocation(alloc, process, np, 1);
}

void bestFit(int blocks[], int nb, int process[], int np)
{
    int alloc[MAX];
    int b[MAX];
    for(int i = 0; i < nb; i++)
        b[i] = blocks[i];
    for(int i = 0; i < np; i++)
        alloc[i] = -1;
    for(int i = 0; i < np; i++)
    {
        int best = -1;
        for(int j = 0; j < nb; j++)
        {
            if(b[j] >= process[i])
            {
                if(best == -1 || b[j] < b[best])
                    best = j;
            }
        }
        if(best != -1)
        {
            alloc[i] = best;
            b[best] -= process[i];
        }
    }
    printAllocation(alloc, process, np, 2);
}
void worstFit(int blocks[], int nb, int process[], int np)
{
    int alloc[MAX];
    int b[MAX];
    for(int i = 0; i < nb; i++)
        b[i] = blocks[i];
    for(int i = 0; i < np; i++)
        alloc[i] = -1;
    for(int i = 0; i < np; i++)
    {
        int worst = -1;
        for(int j = 0; j < nb; j++)
        {
            if(b[j] >= process[i])
            {
                if(worst == -1 || b[j] > b[worst])
                    worst = j;
            }
        }

        if(worst != -1)
        {
            alloc[i] = worst;
            b[worst] -= process[i];
        }
    }
    printAllocation(alloc, process, np, 3);
}
void printAllocation(int alloc[], int process[], int np, int choice)
{
    if(choice == 1)
        printf("\nFIRST FIT ALLOCATION\n\n");
    else if(choice == 2)
        printf("\nBEST FIT ALLOCATION\n\n");
    else
        printf("\nWORST FIT ALLOCATION\n\n");

    printf("Process No.\tProcess Size\tBlock No.\n");

    for(int i = 0; i < np; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if(alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
