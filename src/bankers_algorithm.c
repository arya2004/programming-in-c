#include <stdio.h>

/**
 * Function to implement the Banker's Algorithm to find a safe sequence.
 * 
 * @return Exit status of the program.
 */
int main() {
    // Prompt user for number of processes
    printf("Enter number of processes: \n");
    int n = 0;
    scanf("%i", &n);

    // Prompt user for number of resources
    printf("Enter number of resources: \n");
    int m = 0;
    scanf("%i", &m);

    // Allocation Matrix
    int alloc[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter allocated resources for process %i, resource %i: ", i, j);
            int temp = 0;
            scanf("%i", &temp);
            alloc[i][j] = temp;
        }
    }

    // Maximum Matrix
    int max[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter maximum resources for process %i, resource %i: ", i, j);
            int temp = 0;
            scanf("%i", &temp);
            max[i][j] = temp;
        }
    }

    // Available Resources
    int avail[m];
    for (int i = 0; i < m; i++) {
        printf("Enter available resources for resource %i: ", i);
        int temp = 0;
        scanf("%i", &temp);
        avail[i] = temp;
    }

    int i, j, k;
    int f[n], ans[n], ind = 0;

    // Initialize finish array
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    // Calculate Need Matrix
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    // Banker's Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) { // If process is not finished
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) { // If resources can be allocated
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    // Check if all processes are finished
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The following system is not safe.\n");
            break;
        }
    }

    if (flag == 1) {
        printf("Following is the SAFE Sequence:\n");
        for (i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d\n", ans[n - 1]);
    }

    return 0;
}
