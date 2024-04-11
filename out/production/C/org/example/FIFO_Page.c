#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

int main()  
{  
    printf("Enter no of pages \n");
    int z = 0;
    scanf("%i", &z);

    int incomingStream[z];  

    for (int i = 0; i < z; i++)
    {
        printf("Enter %ith page: ", i);
        int temp = 0;
        scanf("%i", &temp);
       incomingStream[i] = temp;
    }
    
    
    int pageFaults = 0;  

     printf("Enter no of frames\n");
    const int frames = 0; 
    scanf("%i", &frames);
     

    int m, n, s, pages;   
    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);   
    printf(" Incoming \t Frame 1 \t Frame 2 \t Frame 3 \t Frame 4 ");  
    int temp[frames];  
    for(m = 0; m < frames; m++)  
    {  
        temp[m] = -1;  
    }  
    for(m = 0; m < pages; m++)  
    {  
        s = 0;   
        for(n = 0; n < frames; n++)  
        {  
            if(incomingStream[m] == temp[n])  
            {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults <= frames) && (s == 0))  
        {  
            temp[m] = incomingStream[m];  
        }  
        else if(s == 0)  
        {  
            temp[(pageFaults - 1) % frames] = incomingStream[m];  
        }  
        printf("\n");  
        printf("%d\t\t",incomingStream[m]);  
        for(n = 0; n < frames; n++)  
        {  
            if(temp[n] != -1)  
                printf(" %d\t\t", temp[n]);  
            else  
                printf(" - \t\t");  
        }  
    }  
    printf("\nTotal Page Faults:\t%d\n", pageFaults);  
    return 0;  
}