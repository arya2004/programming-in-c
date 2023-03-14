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
void q(void){
    char *e[5000];//pointer is 4 byte. 20k space req
    int number_of_names;
    char temp[100];
    printf("\nhow many names you wanna enter?\n");
    scanf("%d", &number_of_names);
    for (int i = 0; i < number_of_names; i++)
    {
        printf("\nGive name %i\n", i + 1);
        scanf("%s", &temp);
        int l = strlen(temp) + 1;
        e[i] = (char *) malloc(l * sizeof(char));
        strcpy(e[i], temp);
    }
    for (int j = 0; j < number_of_names; j++)
    {
        puts(e[j]);  //base address is passed in puts and printf
        printf("\n");
    }
    char *p;//temp
    for (int i = 0; i <= number_of_names - 1 ; i++){
        for (int letter = i + 1; letter <= number_of_names; letter++){
            if (strcmp(e[i], e[letter]) > 0){
                 p = e[i];
                 e[i] = e[letter];
                 e[letter] = p;
            }
        }
    }
    for (int j = 0; j < number_of_names; j++)
    {
        puts(e[j]);  //base address is passed in puts and printf
        printf("\n");
    }
    
}

int main(){
    //name_sorting();
    //matrix_mul();
    q();
    return 0;
}
