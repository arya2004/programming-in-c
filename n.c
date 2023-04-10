#include <stdio.h>

void diamond(int height){
    //above
    for ( int row = 1; row <= height ; row++){
        for (int  blank = 1; blank <= height - row; blank++)
        {
            printf(" ");
        }
        
        for (int star = 1 ; star <= (2*row)- 1; star++)
        {
            printf("*");
        }
        printf("\n");
        }
    //bottom
    for ( int row = height; row >= 1 ; row--){
        for (int  blank = height - row; blank >= 1; blank--)
        {
            printf(" ");
        }
        
        for (int star = (2*row)- 1 ; star >= 1 ; star--)
        {
            printf("*");
        }
        printf("\n");
        }
    
}

void abc(int height){
    //left
     for ( int row = 1; row <= height ; row++){
        for (int  left = 65; left <= (height - row) + 65; left++)
        {
            printf("%c", left  );
        }
     // blanks   
        for (int blank = 1 ; blank < (2*row)- 1; blank++)
        {
            printf(" ");
        }
    // right    
        for (int  right = (height - row) + 65; right >= 65; right--)
        {
            printf("%c", right  );
        }
        printf("\n");
    
    }
    // BOTTOM
    for ( int row = height; row >= 1 ; row = row - 1){
        for (int  left = (height - row) + 65; left >=65; left = left - 1)
        {
            printf("%c", left  );
        }
     // blanks   
        for (int blank = (2*row)- 1 ; blank > 1; blank = blank - 1)
        {
            printf(" ");
        }
    // right    
        for (int  right = 65; right <= (height - row) + 65; right--)
        {
            printf("%c", right  );
        }
        printf("\n");
    
    }
}

void a(void){
    int z[10] = {0,0,0,0,0,0,0,0,0,0};
    char s[1000];
    scanf("%s", &s);
    for (int i = 0; s[1000]; i++)
    {
        if (s[i] == '0')
        {
            z[0] = z[0] + 1;
        }
        else if (s[i] == '1')
        {
            z[1] = z[1] + 1;
        }
                else if (s[i] == '2')
        {
            z[2] = z[2] + 1;
        }
                else if (s[i] == '3')
        {
            z[3] = z[3] + 1;
        }
                else if (s[i] == '4')
        {
            z[4] = z[4] + 1;
        }
                else if (s[i] == '5')
        {
            z[5] = z[5] + 1;
        }
                else if (s[i] == '6')
        {
            z[6] = z[6] + 1;
        }
                else if (s[i] == '7')
        {
            z[7] = z[7] + 1;
        }
                else if (s[i] == '8')
        {
            z[8] = z[8] + 1;
        }
        else if (s[i] == '9')
        {
            z[9] = z[9] + 1;
        }
        
        
        
    }
    for (int l = 0; l < 10; l++)
    {
        printf("%i ",z[l]);
    }
    

    
}

void bb(int n){
    int lenght = (2*n) - 1;
    int b = n;
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0 ; j <= i; j++)
        {
            printf("%i", n-j);
        }
        for (int k = lenght ; k >= 0; k = k + 2)
        {
            printf("%i", b);
            
        }
        b = b - 1;
        for (int l = i ; l >= 0; l = l - 1)
        {
            printf("%i", -(l-n));
        }
        printf("\n");
    }
    
}



int main() {
    bb(5);
    return 0;
}