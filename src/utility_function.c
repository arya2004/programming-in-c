#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void multiplier(int a, int b){
    int c = a * b;
    printf("%d", c); 
}

void area(int length, int breadth){
    int z =  length * breadth;
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
        printf("Yes");
    }
    else{
        printf("No");
    }
}

void r(float a , float b){
    if(a + b == 10){
        printf("Yes");
    }
    else if (a + b > 10){
        printf("OK");
    }
    else if (a + b < 10){
        printf("No");
    }
}

void t(int year){
    if(year % 4 == 0){
        printf("Leap Year");
    } 
    else{
        printf("Not a Leap Year");
    }
}

void y(int a){
    while (a <= 10){
        printf("%d ", a);
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
        printf("%d ", a);
        a = a + 1;
    } while (a <= b);
}

void p(){
    int sum = 0;
    for (int i = 1; i <= 10; i = i + 1){
        sum = sum + i;
    }
    printf("%d", sum);
}

void a(int num){
    for (int i = 1; i > 0; i = i + 1){
        printf("%d ", i);
        if (i == num){
            break;
        }
    }
}

void s(int a){
    int b = 10;
    while (b){
        printf("%d ", a * b);
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
            printf("Not Prime");
            return;
        }
        div = div + 1;
    }
    printf("Prime");
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
        if (a % 5 != 0){
            printf("%d ", a);
        }
        a = a + 1;    
    }
}

void pp(){
    for (int i = 1; i <= 6; i = i + 1){
        printf("HELLO!\n");
    }
}

void celtofah(float cel){
    printf("%g", (9.0/5.0) * cel + 32);
}

void length(double x1, double y1, double x2, double y2){
    printf("%g", sqrt(pow(x2- x1, 2) + pow(y2 - y1, 2)));
}

void ap(int length, int breadth){
    printf("%i\n", length * breadth);
    printf("%i", (2 * length) + (2 * breadth));
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
    else {
        return c;
    }
}

void aaary(void){
    float a = 2.1;
    float b = 0.3;
    int c = 0;
    int d;
    printf("2. Subtract\n3. Sum\n4. Multiply\n1. Exit\n");
    while (c == 0){
        printf("Enter your choice: ");
        scanf("%i",&d);
        switch(d){
        case 1:
            c = 1;
            continue;
        case 2:
            q3(a,b);
            continue;
        case 3:
            q1(a,b);
            continue;
        case 4:
            q2(a,b);
            continue;
        default:
            continue;
        }
    }
}

void swap(int a, int b){
    printf("a: %i, b: %i\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swap - a: %i, b: %i\n", a, b);
}

void ppo(void){
    static int ziegler = 1;
    printf("%i\n", ziegler);
    ziegler = ziegler + 1;
}

void ptr(void){
    int x = 10;
    int *p = &x;
    printf("Pointer p points to address %p with value %d\n", p, *p);
}

void swapp(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void jum(){
    char x;
    char *p = &x;
    printf("%p\n", p);
    p = p + 5;
    printf("%p\n", p); // jumps by 5*4 = 20
}

void dble(int *a, int *b, int *c){
    *a = (*a) * 2;
    *b = (*b) * 2;
    *c = (*c) * 2;
}

void aryandptr(){
    int x[10] = {0,10,20,30,40,50,60,70,80,90};
    int *p = x;
    printf("%p\n", x);
    printf("%p\n", &x[0]);
    printf("%i\n", *x); // prints 0
    printf("%i\n", *(x + 1)); // jumps memory location by 4 (1 position in array)
    printf("%i\n", (*x) + 1); // increases value at *x by 1
    printf("%i\n", p[2]); // p[2] means *(p + 2)
    p = p + 3; // jumps and assigns 3 places
    printf("%i\n", 2[p]); // 2[p] means p[2] means *(p + 2) means *(2 + p)
    printf("%i\n", p[7]);
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
    for (int i = 0; i < 9; i++)
    {
        sum = sum + l[i];
    }
    return sum;
}

int a3(int l[9]){
    return l[0];
}

void ptrsm(int *p, int *q, int *s){
    *s = *p + *q;
}

void a4(void){
    int a = 1000;
    int b = 2000;
    int x[10] = {0,10,20,30,40,50,60,70,80,90};
    int d = 3000; 
    int c = 4000;
    printf("%p\n", (void*)&a);
    printf("%p\n", (void*)&b);
    printf("%p\n", (void*)&c);
    printf("%p\n", (void*)&d);
    printf("%p\n", (void*)x);
    printf("%p\n", (void*)&x[0]);
    printf("%p\n", (void*)&x[9]);
}

void a5(void){
    int x[10] = {0,10,20,30,40,50,60,70,80,90};
    int *p = x;
    for (int i = 0; i < 10; i++)
    {
        p[i] = p[i] * 2;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", p[i]);
    }
}

void arraysandfunctions(int *p){
    for (int i = 0; i < 9; i++)
    {
        p[i] = p[i] * 2;
    }
}

int a6(void){
    int x[10] = {0,10,20,30,40,50,60,70,80,90};
    arraysandfunctions(x);
    int *p = x;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum = sum + p[i];
    }
    return sum;
}

struct date{
    int day;
    int month;
    int year;
};

int a7(struct date a){
    if (a.month == 1 || a.month == 2)
    {
        a.year--;
        a.month += 12;
    }
    return 365 * a.year + a.year / 4 - a.year / 100 + a.year / 400 + 306 * (a.month + 1) / 10 + a.day - 428;
}

struct person{
    char name[20];
    int age;
};

void a8(void){
    struct person a[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Enter name: ");
        scanf("%s", a[i].name);
        printf("Enter age: ");
        scanf("%i", &a[i].age);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\n", a[i].name);
        printf("Age: %i\n", a[i].age);
    }
}

struct tdate{
    int day;
    int month;
    int year;
};

struct ttime{
    int hour;
    int minute;
    int second;
};

struct datetime{
    struct tdate sdate;
    struct ttime stime;
};

void a9(void){
    struct datetime s1;
    printf("Enter Date\nDay: ");
    scanf("%i", &s1.sdate.day);
    printf("Month: ");
    scanf("%i", &s1.sdate.month);
    printf("Year: ");
    scanf("%i", &s1.sdate.year);
    printf("Enter Time\nHour: ");
    scanf("%i", &s1.stime.hour);
    printf("Minute: ");
    scanf("%i", &s1.stime.minute);
    printf("Second: ");
    scanf("%i", &s1.stime.second);
    printf("Date: %02i/%02i/%04i\n", s1.sdate.day, s1.sdate.month, s1.sdate.year);
    printf("Time: %02i:%02i:%02i\n", s1.stime.hour, s1.stime.minute, s1.stime.second);
}

void a10(void){
    int a = 5;
    printf("%i\n", a);
    {
        int a = 10;
        printf("%i\n", a);
    }
    printf("%i\n", a);
}

void swapp2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void f1(void){
    int x[3][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8}
    };
    printf("%i\n", x[0][0]);
    printf("%i\n", *x[0]);
    printf("%i\n", **x);
    printf("%i\n", **(x + 1));
    printf("%i\n", x[1][0]);
    printf("%i\n", *(*(x+2) + 2));
}

void f2(int a, int b, int (*f)(int, int)){
    printf("%i\n", f(a,b));
}

int sum(int a, int b){
    return a + b;
}

int product(int a, int b){
    return a * b;
}

void f3(void){
    f2(3, 4, sum);
    f2(3, 4, product);
}

void f4(int (*f)(int)){
    printf("%i\n", f(3));
}

int square(int a){
    return a * a;
}

int cube(int a){
    return a * a * a;
}

void f5(void){
    f4(square);
    f4(cube);
}

int main(){
    // Examples of usage
    multiplier(2, 3);
    area(5, 7);
    q1(2.5, 3.0);
    q2(2.5, 3.0);
    q3(2.5, 3.0);
    w(5.0, 2.0);
    e(5, 5);
    r(5.0, 5.0);
    t(2020);
    y(1);
    u(10);
    i(10);
    p();
    a(5);
    s(2);
    d(5);
    f(5);
    g(5);
    int result = h(3, 4);
    printf("%d\n", result);
    int factorial = fact(5);
    printf("%d\n", factorial);
    int fibonacci = fib(5);
    printf("%d\n", fibonacci);
    ii(1);
    pp();
    celtofah(37.0);
    length(0.0, 0.0, 3.0, 4.0);
    ap(5, 7);
    kk('A');
    int biggestNum = biggest(5, 7, 3);
    printf("%d\n", biggestNum);
    aaary();
    swap(3, 4);
    ppo();
    ptr();
    int a = 3, b = 4;
    swapp(&a, &b);
    printf("a: %d, b: %d\n", a, b);
    jum();
    int c = 5;
    dble(&a, &b, &c);
    printf("a: %d, b: %d, c: %d\n", a, b, c);
    aryandptr();
    a1();
    int l[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sumArray = a2(l);
    printf("%d\n", sumArray);
    int firstElement = a3(l);
    printf("%d\n", firstElement);
    int p1 = 3, p2 = 4, s = 0;
    ptrsm(&p1, &p2, &s);
    printf("%d\n", s);
    a4();
    a5();
    int sumArray2 = a6();
    printf("%d\n", sumArray2);
    struct date date1 = {7, 6, 2024};
    int julianDay = a7(date1);
    printf("%d\n", julianDay);
    a8();
    a9();
    a10();
    int x = 3, y = 4;
    swapp2(&x, &y);
    printf("x: %d, y: %d\n", x, y);
    f1();
    f3();
    f5();
    
    return 0;
}
