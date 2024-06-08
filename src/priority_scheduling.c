#include <stdio.h>

#define MAX 9999

// Structure to represent a process
struct Process {
    int no, AT, BT, RT, CT, WT, TAT, Priority, temp;
};

// Function to input process details
struct Process Input(int i) {
    struct Process p;
    printf("\nProcess No: %d\n", i);
    p.no = i;
    printf("Enter Arrival Time: ");
    scanf("%d", &p.AT);
    printf("Enter Burst Time: ");
    scanf("%d", &p.BT);
    p.RT = p.BT;
    printf("Enter Priority: ");
    scanf("%d", &p.Priority);
    p.temp = p.Priority;
    return p;
}

int main() {
    int i, n, c, remaining, min_val, min_index;
    struct Process p[10], temp;
    float avgTAT = 0, avgWT = 0;

    printf("<-- Priority First Scheduling Algorithm (Preemptive) -->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Input process details
    for (int i = 0; i < n; i++)
        p[i] = Input(i + 1);

    // Sort processes by arrival time using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].AT > p[j + 1].AT) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    remaining = n;
    min_val = p[0].temp, min_index = 0;
    c = p[0].CT = p[0].AT + 1;
    p[0].RT--;

    // Execute processes in preemptive priority scheduling
    while (remaining > 0) {
        min_val = p[0].temp, min_index = 0;
        for (int j = 0; j < n && p[j].AT <= c; j++) {
            if (p[j].temp < min_val) {
                min_val = p[j].temp;
                min_index = j;
            }
        }
        i = min_index;
        p[i].CT = c = c + 1;
        p[i].RT--;
        if (p[i].RT == 0) {
            p[i].temp = MAX;
            remaining--;
        }
    }

    printf("\nProcess No\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        p[i].TAT = p[i].CT - p[i].AT;
        avgTAT += p[i].TAT;
        p[i].WT = p[i].TAT - p[i].BT;
        avgWT += p[i].WT;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].no, p[i].AT, p[i].BT, p[i].Priority, p[i].CT, p[i].TAT, p[i].WT);
    }
    avgTAT /= n, avgWT /= n;
    printf("\nAverage TurnAroundTime = %f\nAverage WaitingTime = %f\n", avgTAT, avgWT);

    return 0;
}
