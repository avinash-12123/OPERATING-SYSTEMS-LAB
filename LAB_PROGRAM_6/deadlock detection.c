#include <stdio.h>
#define MAXP 10
#define MAXR 10
int main() {
    int n, m;
    int Allocation[MAXP][MAXR];
    int Request[MAXP][MAXR];
    int Available[MAXR];
    int Work[MAXR];
    int Finish[MAXP];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);
    printf("\nEnter Allocation Matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &Allocation[i][j]);
    printf("\nEnter Request Matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &Request[i][j]);
    printf("\nEnter Available Vector:\n");
    for(int j = 0; j < m; j++)
        scanf("%d", &Available[j]);
    for(int j = 0; j < m; j++)
        Work[j] = Available[j];
    for(int i = 0; i < n; i++) {
        int allZero = 1;

        for(int j = 0; j < m; j++) {
            if(Allocation[i][j] != 0) {
                allZero = 0;
                break;
            }
        }

        Finish[i] = allZero ? 1 : 0;
    }
    int found;
    do {
        found = 0;
        for(int i = 0; i < n; i++) {
            if(Finish[i] == 0) {
                int possible = 1;
                for(int j = 0; j < m; j++) {
                    if(Request[i][j] > Work[j]) {
                        possible = 0;
                        break;
                    }
                }
                if(possible) {
                    for(int j = 0; j < m; j++)
                        Work[j] += Allocation[i][j];

                    Finish[i] = 1;
                    found = 1;
                }
            }
        }
    } while(found);
    int deadlock = 0;
    printf("\nDeadlocked Processes: ");
    for(int i = 0; i < n; i++) {
        if(Finish[i] == 0) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if(!deadlock)
        printf("None");
    printf("\n");
    return 0;
}
