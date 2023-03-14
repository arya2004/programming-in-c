//Matrix multiplication on line 58
//find substring on line 117
//atleast works on my PC :) main function is at 187. Uncomment the function to call and comment the rest

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
   
char name[50][39],  temp[39];//initialized to zero after declaring global. most efficient way to remove garbage values
    
void name_sorting(){
    int number_of_names;
    printf("\nhow many names you wanna enter?(max 50, min 1)\n");
    scanf("%d", &number_of_names);
    printf("\nEnter %i names\n", number_of_names);
    for (int l = 0; l <= number_of_names; l++) {
        gets(name[l]);
        
    }
// above gets all names
    for (int row = 0; row <= 50; row++){
        for (int column = 0; column < 39; column++){
            if (name[row][column] >= 'A' && name[row][column] <= 'Z'){
            name[row][column] = name[row][column] + ('a' - 'A');
        }
    }
        for (int letter = 0; letter < 39; letter++){
            if ((letter == 0 || name[row][letter - 1] == ' ') && (name[row][letter] >= 'a' && name[row][letter] <= 'z' )){
                name[row][letter] =  name[row][letter] - ('a' - 'A');
            }
        
        }
    }
 // above first lower cases all letter then uppercase first letter of each word       
    for (int i = 0; i <= number_of_names - 1 ; i++){
        for (int letter = i + 1; letter <= number_of_names; letter++){
            if (strcmp(name[i], name[letter]) > 0){
                    for (int letter_first_switch = 0; letter_first_switch < 39; letter_first_switch++){
                        temp[letter_first_switch] = name[i][letter_first_switch];
                    }
                    for (int letter_second_switch = 0; letter_second_switch < 39; letter_second_switch++){
                        name[i][letter_second_switch] = name[letter][letter_second_switch];
                    }
                    for (int letter_third_switch = 0; letter_third_switch < 39; letter_third_switch++){
                        name[letter][letter_third_switch] = temp[letter_third_switch];
                    }                   
            }
        }
    }
// above sorts them    
    for (int k = 0; k <= number_of_names; k++) {
            printf("%s\n", name[k]);
    }
//above prints
} 

void matrix_mul(void){
  int brow;
  int bcol; 
  int arow;
  int  acol; 
  float sum = 0;
  float a[10][10], b[10][10], c[10][10];

    printf("\nno of rows for first matrix\n");
    scanf("%i", &arow);
    printf("\nno of columns for first matrix\n");
    scanf("%i", &acol);
    printf("\nno of rows for second matrix\n");
    scanf("%i", &brow);
    printf("\nno of column for second matrix\n");
    scanf("%i", &bcol);


  if (acol != brow){
    printf(" get better at maths, human. This programme now breaks ");
    }
while (acol == brow)
{
  

  printf("elements for a\n");
  for (int c = 0; c < arow; c++)
    for (int d = 0; d < acol; d++)
      scanf("%f", &a[c][d]);
 


    printf("elements for b\n");
 
    for (int cc = 0; cc < brow; cc++)
      for (int dd = 0; dd < bcol; dd++)
        scanf("%f", &b[cc][dd] );

    for (int ccc = 0; ccc < arow; ccc++) {
      for (int ddd = 0; ddd < bcol; ddd++) {
        for (int k = 0; k < brow; k++) {
          sum = sum + a[ccc][k] * b[k][ddd];
        }
        c[ccc][ddd] = sum;
        sum = 0;
      }
    }
 
     
    for (int ee = 0; ee < arow; ee++) {
      for (int ww = 0; ww < bcol; ww++){
        printf("%.2f\t", c[ee][ww] ); //prints 2 digit after decimal
      
    }
    printf("\n");}
    break;
}
}

void exist(void){
    
   char x[300];
char y[100];
    printf("\nmain string\n");
    gets(x);
    printf("\nSubstring\n");
    gets(y);
    printf("search order 0 : for left to right, 1: for right to left\n");
    int search_order;
    scanf("%i", &search_order);
    printf("i want Nth occurence.Enter value of N\n");
    int req;
    scanf("%i", &req);

    int output = -1;
    int occurence = 0;
    int flag = 0;
    int xx = strlen(x);
    int yy = strlen(y);
    if(search_order == 0){
        for(int i = 0; i < xx; i = i + 1){
            if (x[i] == y[0]){
                for (int j = 1; j < yy; j = j + 1){
                    if (x[i + j] != y[j]){
                      flag = 0;
                      continue;
                    }
                flag = 1;
                }
            }
        if (flag == 1){
            occurence = occurence + 1;
            flag = 0;
          }
        if (req == occurence){
            output = i;
            break;
        }
        }      
    }
    if (search_order == 1){
        for (int i = xx; i >= 0; i = i - 1){
            if (x[i] == y[0]){
                for (int j = 1; j < yy; j = j + 1){
                    if (x[i + j] != y[j]){
                        flag = 0;
                        continue;
                    }
                    flag = 1;
                }
            }
        if(flag == 1){
            occurence = occurence + 1;
            flag = 0;
        }
        if (req == occurence){
            output = i;
            break;
        }
        }      
    }
    if (flag == 1){
        printf("\n%i", output);
    }
    else{
        printf("\n%i", output);
    }  
}

int main(){
    //name_sorting();
    //matrix_mul();
    exist();
    return 0;
}

