#include <stdio.h>
#define MAX 50
void fifo(int pages[], int n, int frames)
{
    int frame[MAX];
    int front = 0;
    int pageFaults = 0;
    for(int i = 0; i < frames; i++)
        frame[i] = -1;
    printf("\nFIFO PAGE REPLACEMENT\n\n");
    printf("-------------------------------------------------\n");
    printf("Page\t");
    for(int i = 0; i < frames; i++)
        printf("F%d\t", i+1);
    printf("Status\n");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < n; i++)
    {
        int found = 0;
        for(int j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            frame[front] = pages[i];
            front = (front + 1) % frames;
            pageFaults++;
        }
        printf("%d\t", pages[i]);
        for(int j = 0; j < frames; j++)
        {
            if(frame[j] == -1)
                printf("-\t");
            else
                printf("%d\t", frame[j]);
        }
        if(found)
            printf("Hit\n");
        else
            printf("Fault\n");
    }
    printf("-------------------------------------------------\n");
    printf("Total Page Faults = %d\n", pageFaults);
}
int main()
{
    int n, frames;
    int pages[MAX];
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    fifo(pages, n, frames);
    return 0;
}
