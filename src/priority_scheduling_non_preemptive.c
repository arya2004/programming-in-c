#include <stdio.h>

// Define a constant for maximum priority value
#define MAX_PRIORITY 9999

// Structure to represent a process
struct Process {
    int no, AT, BT, CT, WT, TAT, Priority, Status;
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
    printf("Enter Priority: ");
    scanf("%d", &p.Priority);
    p.Status = 0;
    return p;
}

int main() {
    int n, s, CT = 0, remaining;
    struct Process p[10], temp;
    float avgTAT = 0, avgWT = 0;

    printf("<--Priority Scheduling Algorithm Non-Preemptive-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i] = Input(i + 1);
    }

    // Sort processes based on arrival time using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].AT > p[j + 1].AT) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Set maximum priority for the last process
    p[n - 1].Priority = MAX_PRIORITY;
    remaining = n;

    printf("\nProcess No\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    // Schedule processes
    for (CT = p[0].AT; remaining != 0;) {
        s = 9; // Initialize with an index greater than the number of processes

        // Find the process with the highest priority and is ready to execute
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= CT && p[i].Status != 1 && p[i].Priority < p[s].Priority) {
                s = i;
            }
        }

        // Execute the selected process
        p[s].CT = CT = CT + p[s].BT;
        p[s].TAT = p[s].CT - p[s].AT;
        avgTAT += p[s].TAT;
        p[s].WT = p[s].TAT - p[s].BT;
        avgWT += p[s].WT;
        p[s].Status = 1;
        remaining--;

        // Print process details
        printf("P%d\t\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[s].no, p[s].AT, p[s].BT, p[s].Priority, p[s].CT, p[s].TAT, p[s].WT);
    }

    // Calculate and print average turnaround time and average waiting time
    avgTAT /= n;
    avgWT /= n;
    printf("\nAverage Turnaround Time = %f\nAverage Waiting Time = %f", avgTAT, avgWT);

    return 0;
}
