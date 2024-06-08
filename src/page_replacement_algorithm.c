#include <stdio.h>
#include <stdlib.h>

// Function to simulate page replacement algorithm
void simulatePageReplacement() {
    int z; // Number of pages
    printf("Enter the number of pages: ");
    scanf("%i", &z);

    int incomingStream[z]; // Array to store incoming page numbers

    for (int i = 0; i < z; i++) {
        printf("Enter page %i: ", i);
        scanf("%i", &incomingStream[i]);
    }

    int pageFaults = 0; // Count of page faults

    int frames; // Number of frames
    printf("Enter the number of frames: ");
    scanf("%i", &frames);

    int m, n, s, pages;
    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    printf("Incoming\tFrame 1\tFrame 2\tFrame 3\tFrame 4\n");
    int temp[frames];
    for (m = 0; m < frames; m++) {
        temp[m] = -1;
    }
    for (m = 0; m < pages; m++) {
        s = 0;
        for (n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if ((pageFaults <= frames) && (s == 0)) {
            temp[m] = incomingStream[m];
        } else if (s == 0) {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
        printf("\n");
        printf("%d\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf(" %d\t\t", temp[n]);
            else
                printf(" - \t\t");
        }
    }
    printf("\nTotal Page Faults:\t%d\n", pageFaults);
}

int main() {
    simulatePageReplacement(); // Run page replacement algorithm simulation
    return 0;
}
