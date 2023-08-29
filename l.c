#include <stdio.h>
#include<stdlib.h>


void ary(void){
    int a[6] = {33,55,3,2,1,10};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                  for (int k = 0; k < 6; k++){
        printf("%i ", a[k]);
    }  
            }
            printf("\n");
        }
        
    }

    
}
int main(){

    /*char c[] = "Hello";
for (int i = 0; i < 5; i++)
{
    

    
    switch (c[i])
    {
    case 'A':
        printf("00110\n");
        continue;
    case 'H':
        printf("111")  && printf("Hello\n");
        continue;
    case 'o':
        printf("000\n");
        continue;
    case 'l':
        printf("11001\n");
        continue;
    case 'e':
        printf("F\n");
        continue;
    case 'O':
        printf("0001");
        continue;
    case 'g':
        printf("F");
        continue;
    case 'h':
        printf("F");
        continue;
    case 'i':
        printf("F");
        continue;
    case 'j':
        printf("F");
        continue;
    case 'k':
        printf("F");
        continue;
    case 'L':
        printf("Best div Eva!\n");
        continue;


    }
        return 0;
}*/
}