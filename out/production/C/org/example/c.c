//file shit here
#include <stdio.h>
#include<stdlib.h>
#include <math.h>

void a(void){
    int a = 05312; /*base 8 %o*/
    int b = 0xA;/*base 16 %x */
    float z = 3.4e4; /*exponent %g */
    int c = 0b1011; // binary
    printf("%i",c);

}
void b(float a, float b, int operation){
     //int op value: 1.Addition 2.Subtraction 3.Multiplication 4.Division 5.square, 6 squareroot

    switch(operation)
    {
    case 1	:
        printf(" %f",a+b);
        break;
    case 2	:
        printf(" %f",a-b);
        break;
    case 3	:
        printf(" %f",a*b);
        break;
    case 4	:
        printf("%f ",a/b);
        break;
    case 5	:
        printf(" %f, %f",a*a, b*b);
        break;
    case 6	:
        printf("%f, %f ",sqrtf(a), sqrtf(b));
        break;

    }
}


void aa(int a){
    if (a%2 == 0)
    {
        printf("even");
    }
      else if (a%2 == 1)
    {
        printf("odd");
    }
    
}

void k(int a){
    int multiple = a;
    for ( int i = 1; i <= 10; i++)
    {printf("%i ,",multiple );
        multiple= multiple + a;
    }
    
}

void p(int a){
    for ( int i = 1; i <= a; i++) //does the opposite of below
    {
        for ( int z = 1; z <=i; z++)
        {
            printf("*");
        }
        
        printf("\n");
    }
    
}

void pp(int a){
    for ( int i = 1; i <= a; i++) //does the opposite of above
    {
        for ( int z = i; z <= a; z++)
        {
            printf("*");
        }
        
        printf("\n");
    }
    
}

void j(int a, double b, char c, float d){
    printf("%i\n", sizeof(a));
    printf("%f\n", sizeof(a));
    printf("%i\n", sizeof(a));
    printf("%i\n", sizeof(b));
    printf("%i\n", sizeof(a + b));
    printf("%f\n", sizeof(d));
    printf("%g\n", sizeof(c));

}

void kkk(int a){
    (a >= 0?(a == 0?printf("zero"):printf("positive")) :printf("negative"));//(condition? then execute this:else execute this)
}
void lp(int a){
    (a %4 == 0?(a % 400 ==0?printf("leap"):printf("also not leap")) :printf("not leap"));
}

void ary(int nos[5]){
    for ( int i = 0; i <=4; i++)
    {
        printf("%i", nos[i]);
        printf("\n");
    }
}

void arypos(int nos[5]){
    for ( int i = 0; i <=4; i = i + 2)
    {   printf("even");
        printf("%i,", nos[i]);
        printf("\n");
    }
        for ( int i = 1; i <=4; i = i + 2)
    {   printf("odd");
        printf("%i,", nos[i]);
        printf("\n");
    }
}

void arysum(int nos[5]){
    int a = 0;
    for ( int i = 0; i <=4; i++)
    {   a = a + nos[i];

    }
    printf("%i", a);

}

void twoarysum(int nos1[5], int nos2[5]){
    int a[5];
    for ( int i = 0; i <=4; i++)
    {   a[i] = nos1[i] + nos2[i];
        printf("%i", a[i]);
        printf("\n");
    }
    

}

void aaaa(int a, int b){
    a, b = b, a;
    printf("%i", a);
} 

struct kiddo{
    int prn;
    char name[30];
    float cgpa;
    char div;

};

void aaaaa(void){
    struct kiddo vit[3], vit_rd[3];
    FILE *j, *o;
    j = fopen("feil.txt", "w");
    for (int i = 0; i < 2; i++){ 
        printf("name of %i\n", i + 1);
        scanf("%s ", &vit[i].name);  
        printf("prn of %i\n", i + 1);
        scanf("%i ", &vit[i].prn);
        printf("cgpa of %i\n", i + 1);
        scanf("%f ", &vit[i].cgpa);
        printf("div of %i\n", i + 1);
        scanf("%c", &vit[i].div);
        fwrite(&vit[i],sizeof(struct  kiddo),1,j );
    }
    fclose(j);
    o = fopen("feil.txt", "r");
    for (int i = 0; i < 2; i++){ 
        fread(&vit_rd[i],sizeof(struct  kiddo),1,o );
        printf("name of %s\n", &vit_rd[i].name);
        printf("prn of %i\n",  &vit_rd[i].prn);
        printf("cgpa of %f\n", &vit_rd[i].cgpa);
        printf("div of %c\n", &vit_rd[i].div);
        
    }
}

int main(){
    //int z[5] = {1,2,3,4,5};
    //int zz[5] = {5,4,10,2,1};
    //twoarysum(z,zz);
    //aaaa(5,2);
    //lp(2020);
    aaaaa();
    return 0;
}