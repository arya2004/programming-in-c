//all pointer and struct should be here

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>

 void multiplier(int a, int b){
    int c = a * b;
    printf("%d", c); 
 }


 void area(int lenght, int breadth){
    int z =  lenght * breadth;
    printf("%d", z);
}

void q1(float a, float b){
    float c = a + b;
    printf("%f\n", c);
}
void q2(float a, float b){
    float c = a * b;
    printf("%f\n", c);
}
void q3(float a, float b){
    float c = a - b;
    printf("%f\n", c);
}
void w(float a, float b){
    float c = a / b;
    printf("%f", c);
}

void e(int a , int b){
    if(a + b == 10){
        printf("YEs");
    }
    else{
        printf("NO");
    }

}

void r(float a , float b){
    if(a + b == 10){
        printf("YES");
    }
    else if (a + b > 10){
        printf("OK");
    }
    
    else if (a + b < 10){
        printf("NO");
    }

}

void t(int year){
    if(year % 4 == 0){
        printf("L");
    } 
    else{
        printf("Not");
    }
}

void y(int a){
    while (a <= 10){
        printf("%d", a);
        a = a + 1;
    }
    
}

void u(int b){
    int a = 1;
    int sum = 0;
    while (a <= 10){
        sum = sum + a;
        a = a + 1;
    }
    printf("%d", sum);
}

void i(int b){
    int a = 1;
    do{
        printf("%d", a);
        a = a + 1;

    } while (a <= b);
}
// better version is void u. UPdate: Fixed
void p(){
    int sum = 0;
    int i = 0;
    for (int i = 1; i <= 10; i = i + 1){
        sum = sum + i;
    }
    printf("%d", sum);
} 

void a(int num){
    for (int i = 1; i > 0; i = i + 1){
        printf("%d", i);
        if (i == num){
            break;
        }
    }
}

void s(int a){
    int b = 10;
    while (b){
        printf("%d", a * b);
        b = b - 1;
    }
    
}

void d(int b){
    int a = 1;
    int sum = 0;
    while (a <= 10){
        int c = a * b;
        sum = sum + c;
        a = a + 1;
    }
    printf("%d", sum);
}

void f(int a){
    int factorial = 1;
    while (a){
        factorial = factorial * a;
        a = a - 1;
    }
    printf("%d", factorial);
}

void g(int a){
    int div = 2;
    while (div < a){
        if (a % div == 0){
            printf("Not");
            break;
        }
        else{
            printf("YEs");
            break;
        }
        div = div + 1;
    }
    
}

int h(int a, int b){
    int c = a + b;
    return c;
}

int fact(int a){
    if(a == 1){
        return 1;
    }
    else{
        return a * fact(a -1);
    }
}

int fib(int a){
    if(a == 0){
        return 0;
    }
    if (a == 1){
        return 1;
    }
    else{
        return fib(a -1) + fib(a - 2);
    }
}

void ii(int a){
    while (a <= 50){
        if (a% 5 != 0)
        {
        printf("%d   ", a);
        
        }
     a = a + 1;    

    }
}

void pp(){
    for (int i = 1; i <= 6; i = i + 1){
        printf(" H E L L O ! \n");
    }
    
}

void celtofah(float cel){
    printf("%g", (9.0/5.0)* cel + 32);
}

void length(double x1, double y1, double x2, double y2){
    printf("%g",sqrt(pow(x2- x1, 2) + pow(y2 - y1, 2)));
}

void ap(int lenght, int breadth){
    printf("%i\n",lenght * breadth);
    printf("%i",(2 * lenght) + (2 * breadth));
}

void kk(char a){
    printf("%i", a);
}

int biggest(int a, int b, int c){
    if (a >= b && a >= c)
    {
        return a;
    }
    else if (b >= a && b >= c){
        return b;
    }
    else if (c >= a && c >= b)
    {
        return c;
    }
}

void aaary(void){
    
    float a = 2.1;
    float b = 0.3;
    int c = 0;
    int d;
    printf(" 2.subtract\n 3.Sum\n 4.Mul\n 1.Exit\n");
    while (c == 0){

    printf("Enter your Choice : ");
    scanf("%i",&d);
    switch(d)
    {
    case 1	:
        c = 1;
        continue;
    case 2	:
        q3(a,b);
        continue;
    case 3	:
        q1(a,b);
        continue;
    case 4	:
        q2(a,b);
        continue;
    default	:
        
        continue;
    }
}
}

void swap(int a, int b){//swap without third
    printf("a %i\n", a);
    printf("b %i\n", b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a then %i\n", a);
    printf("b then %i\n", b);
}


void ppo(void){
    static int ziegler = 1;
    printf("%i\n", ziegler);
    ziegler = ziegler + 1;
}
//=====================================================================================================================================================
void ptr(void){
    int x = 10;
    int *p = &x;
    
}

void swapp(int *a, int *b){     //int a = 12;int b = 13;
    int temp = *a;              //printf("%i %i", a, b);
    *a = *b;                    //swapp(&a, &b);
    *b = temp;                  //printf("%i %i", a, b);
}

void jum(){     
    char x;
    char *p = &x;
    printf("%p\n", p);
    p = p + 5;
    printf("%p", p); //jumps by 5*4 = 20
}


void dble(int *a, int *b, int *c){      //doubles the value
    *a = a + 1;                         //dble(&a, &b,&c);
    *b = (*b) * 2;
    *c = (*c) * 2;
}

void aryandptr(){
    int x[10] = {0,10,20,30,40,50,60,70,80,90};
    int *p = x;
    printf("%p\n", x);
    printf("%p\n", &x[0]);
    printf("%i\n", *x);// prints 0
    printf("%i\n", *(x + 1));// jumps memory location by 4(1 position in array)
    printf("%i\n", (*x) + 1);// increaces value at *x by 1
    printf("%i\n", p[2]);//   p[2] means *(p + 2)
    //p++;
    p = p + 3; //jumps and assigns 3 places
    printf("%i\n", 2[p]);  // 2[p] means p[2] means *(p + 2) means *(2 + p)
    printf("%i\n", p[10]);
}

void a1(void){
    int x[10] = {0,10,20,30,40,50,60,70,80,90};
    int *p = x;
    p[5] = 7;
    int *p2 = x;
    printf("%i", p2[8]);
}

int a2(int l[9]){
    int sum = 0;
    for (int i = -1; i < 11; i++)
    {
        sum = sum + l[i];
    }
    return sum;
}

int a3(int l[9]){

    return l[-1];
}

void ptrsm(int *p, int *q, int *s){  //printf("%i+ %i= %i\n", a, b, sum);
    *s = *p + *q;                    //ptrsm(&a,&b,&sum);
}                                    //printf("%i+ %i= %i", a, b, sum);

void a4(void){
    int a = 1000;
    int b = 2000;
    int x[10] = {0,10,20,30,40,50,60,70,80,90};
    int d = 3000; int c = 4000;
    printf("%i\n", &a);
    printf("%p\n", &b);
    printf("%i\n", &c);
    printf("%i\n", &d);
    printf("%i\n", x);
    printf("%i\n", &x[10]);
    printf("%i\n", &x[11]);

} 

int mystrln(char *s){
    int i = 0;
    for (; *(s) != '\0'; s++, i++);
    return i;
    
}

void mystrcpy(char *a, char *b, char *c){
    int i = 0;
    for (; *(a) != '\0'; *c++, *a++){
        *c = *a;
    }
    *(c + i ) = ' ';
        for (; *(b) != '\0'; c++, b++){
        *(c + 1) = *b;
    }
}

void mystrcpy1(char *a, char *b){
    while (*a++ = *b++ );
}

void mystrcpy2(char *a, char *b){

    for (; *(a) != '\0'; a++);
    *(a) = ' ';
    a++;
    while (*(a)++ = *b++ );

}

void memall(void){
    unsigned long int n, *x;
        scanf("%i", &n);
    x = (unsigned long int *) malloc(n * sizeof(unsigned long int));
    if (x != NULL)
    {
        printf("a new array of size %i is created at location %i", n, x);
    }
    else{
        printf("not allocated\nquitting...");
        exit(1);    //exit stops programme
     }
    
}

void memall1(void){
    unsigned long int n, *x;
        scanf("%i", &n);
    x = (unsigned long int *) calloc(n , sizeof(unsigned long int));// malloc(n * sizeof(unsigned long int));
    if (x != NULL)
    {
        printf("a new array of size %i is created at location %i\n", n, x);
    }
    else{
        printf("not allocated\nquitting...");
        exit(1);    //exit stops programme
    }
    *x = 11;
    x++;
        *x = 12;
    x++;
        *x = 13;
    x++;
        *x = 14;


    for (int i = 0;i < n;i++, *x--)
    {
        printf("%i\n", *x);
    }    
}

//=====================================================================================================================================================

struct date{
    int s;
    int m;
    int h;
};


struct kiddo{
    int prn;
    char name[30];
    float marks;
};

struct kid{
    int prn;
    char name[30];
    float marks;
    struct date dob;
};


void VOID(void){
    struct kiddo ziegler, catalyst;
    //declaration
    struct kiddo arya = {37, "Arya" , 9.0};
    ziegler = arya;
    catalyst.prn = 12210060;
    strcpy(catalyst.name, "Arya");
    catalyst.marks = 9.6;
    struct kiddo zieglernatta[30];
    struct kid zigga, aRYA;
    zigga.dob.s = 45;
    //aRYA = {37, "Arya" , 9.0,{3,4,40}};
    printf("%i", arya.prn);
}



void VOIDD(void){
    struct kiddo ziegler = {12210, "Arya" , 9.0};
    struct kiddo arya;
    struct kiddo cat = {132177, "fh" , 9.3};
    printf("rg\n");
    scanf("%i", &arya.prn);
    printf("rgasdqwswsf\n");
    scanf("%f", &arya.marks);
    printf("rgasd\n");
    scanf("%s", &arya.name);
    printf("\n%i", arya.prn);
    printf("\n%f\n", arya.marks);
    puts(arya.name);
}

void dipslay(struct kiddo div_n[], int n){
        for (int i = 0; i < n; i++){ 
        printf("name of %i is %s \t", i + 1, div_n[i].name);
        printf("prn of %i is %i \t", i + 1, div_n[i].prn);
        printf("marks of %i is %f \t ", i + 1, div_n[i].marks);
        printf("\n");
    }
}

int feepaid(struct kiddo div_n[], int n){
    int m;
    printf("HOw many studnet?\n");
    scanf("%i", &m);
    for (int i = n; i < n + m; i++){ 
        printf("name of %i\n", i + 1);
        scanf("%s", &div_n[i].name);  
        printf("prn of %i\n", i + 1);
        scanf("%i", &div_n[i].prn);
        printf("marks of %i\n", i + 1);
        scanf("%f", &div_n[i].marks);
    }
    return (n + m);
}
void kitty(void){
    int n;
    printf("HOw many studnet?\n");
    scanf("%i", &n);
    struct kiddo div_n[n];
    for (int i = 0; i < n; i++){ 
        printf("name of %i\n", i + 1);
        scanf("%s", &div_n[i].name);  
        printf("prn of %i\n", i + 1);
        scanf("%i", &div_n[i].prn);
        printf("marks of %i\n", i + 1);
        scanf("%f", &div_n[i].marks);
    }
    dipslay(div_n,n);
    
}

void sorrt(struct kiddo *div_n, int n){
    int p = n - 2;
    for (int i = 1; i < n; i++)
    {   int flag = 0;
        for (int j = 0; j <= p; j++)
        {
            if (div_n[i].prn > div_n[i +1].prn)
            {
                struct kiddo temp;
                temp = div_n[i];
                div_n[i] = div_n[i + 1];
                div_n[i + 1] = temp;
                flag = 1;    
                
            }
            
        }
        p--;
        if (flag == 0)
        {
            break;
        }
        
    }
}

void my_sort(struct kiddo *div_n, int n){
    for (int i = 0; i < n; i++)
    {
        for (int i = 1; i < n - 1; i++)
        {
            if (div_n[i].prn > div_n[i +1].prn){
                struct kiddo temp;
                temp = div_n[i];
                div_n[i] = div_n[i + 1];
                div_n[i + 1] = temp;
                
            }
        }
        
    }
    
}
int remooo(struct kiddo *div_n, int n){
    dipslay(div_n, n);
    int d;
    printf("\ngive record to be deleted");
    scanf("%i", &d);
    if (d > n || d < 1){
        return n;
    }
  //  else if (d == n)
   // {
    //    return div_n[n - 1];
    //}
    
    div_n[d - 1] = div_n[n - 1];

    
}
int main(){
    //length(0.0,0.0,4.0e1,3.0e1);
    //ap(4,5);
    //kk('r');
    //printf("%i", biggest(3,5,3));
    //aaary();
    //swap(3,2);
    //jum();
    //aryandptr();
    //int x[10] = {10,20,30,40,50,60,70,80,90, 100};
    //printf("SUm: %i", a2(x));
    memall1();
   /* int exit = 1;
    int n = 0;
    int op = 0;
   struct kiddo div_n[100] = {{1221,"Arya",8.9},{1220,"Pathak",8.7},{1121,"Ziegler",9.0},{2221,"Catallyst",3.4},{1211,"Natta",5.6},{2222,"Moew",1.0}}; 
    while(exit){
        printf("0.exit \n 1.Add\n 2.dislay\n 3.sort name\n 4.sort roll_prn\n5.sort roll_marks\ns6.sort by age\n7.store to file\n8. retrive from file\n");
        printf("Enter your Choice : ");
        scanf("%d",&op);
        switch(op){
            case 0	:
                exit = 0;
                break;
            case 1	:
                n = feepaid(div_n, n);
                break;
            
            case 2	:
                dipslay(div_n,n);
                break;
                
            case 3	:
                my_sort(div_n, n);
                dipslay(div_n,n);
                break;
               
            case 4	:
                //printf("Difference of %f and %f is : %d",a,b,a-b);
                
            case 5	:
                //printf("Multiplication of %f and %f is : %d",a,b,a*b);
                
            case 6	:
                //printf("Division of Two Numbers is %f : ",a/b);
                
            case 7	:
                //printf("Multiplication of %f and %f is : %d",a,b,a*b);
                
            case 8	:
                //printf("Division of Two Numbers is %f : ",a/b);
            
                   

            default	:
                printf(" Enter Your Correct Choice.");
                continue;
        }
    }
    */

    return 0;
}