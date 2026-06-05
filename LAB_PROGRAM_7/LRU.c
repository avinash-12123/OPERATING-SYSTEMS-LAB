#include <stdio.h>
int main()
{
    int n, f, pages[30], frame[10], time[10];
    int i, j, k, pos, min, faults = 0, counter = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++)
        frame[i] = -1;
    printf("\nLRU PAGE REPLACEMENT\n");
    printf("-----------------------------------------\n");
    printf("Page\tFrames\t\tStatus\n");
    printf("-----------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        int found = 0;
        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                counter++;
                time[j] = counter;
                break;
            }
        }
        if(!found)
        {
            faults++;
            if(i < f)
                pos = i;
            else
            {
                min = 0;
                for(j = 1; j < f; j++)
                    if(time[j] < time[min])
                        min = j;
                pos = min;
            }
            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
        }
        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++)
        {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        if(found)
            printf("\tHit\n");
        else
            printf("\tFault\n");
    }
    printf("-----------------------------------------\n");
    printf("Total Page Faults = %d\n", faults);
    return 0;
}
