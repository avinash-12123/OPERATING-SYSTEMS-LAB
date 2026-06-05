#include <stdio.h>
int main()
{
    int pages[30], frames[10], temp[10];
    int n, f, i, j, k, pos, max, faults = 0, found;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++)
        frames[i] = -1;
    printf("\nOPTIMAL PAGE REPLACEMENT\n");
    printf("-----------------------------------------\n");
    printf("Page\tFrames\t\tStatus\n");
    printf("-----------------------------------------\n");
    for(i = 0; i < n; i++)
    {
        found = 0;
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            faults++;
            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    found = -1;
                                 break;
                }
            }
            if(found != -1)
            {
                for(j = 0; j < f; j++)
                {
                    temp[j] = -1;
                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            temp[j] = k;
                            break;
                        }
                    }
                }
                max = -1;
                pos = 0;
                for(j = 0; j < f; j++)
                {
                    if(temp[j] == -1)
                    {
                        pos = j;
                        break;
                    }
                    if(temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
        }
        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
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
