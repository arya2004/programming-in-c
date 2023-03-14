#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
//1A
void size_of(int a, double b, char c, float d){
    printf("SIze of int is: %i\n", sizeof(a));
    printf("SIze of double is: %i\n", sizeof(b));
    printf("SIze of int + double is: %i\n", sizeof(a + b));
    printf("SIze of char is: %i\n", sizeof(c));
    printf("SIze of float is: %i\n", sizeof(d));
    

}
//1B
int grd(float a, float b, float c, float d, float e){
    float avg = (a + b + c + d + e)/5;
    if (avg >90)
    {
        printf("Grade is A");
    }
    else if (avg > 70 && avg <= 90)
    {
        printf("Grade is B");
    }
        else if (avg > 50 && avg <= 70)
    {
        printf("Grade is C");
    }
        else if (avg > 35 && avg <= 50)
    {
        printf("Grade is D");
    }
    else{
        printf("Grade is F");
    }

    return 0;
}
//1C
void leap(int year){
    if (year % 4 == 0 && year % 100 != 0 && year % 400 != 0 || year % 4 == 0 && year % 100 == 0 && year % 400 == 0 ){
         printf("Leap");
    }
    else{
        printf("Not Leap");
    }
}
//2A
void root(double a, double b, double c){
    double root1, root2, imaginaryPart, discriminant;

    discriminant = b * b - 4 * a * c;

   
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("\nThe roots are real and different.\n");
        printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
    }

    
    else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("\nThe roots are real and same.\n");
        printf("root1 = root2 = %.2lf;", root1);
    }

    
    else {
        root1 = root2 = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("\nThe roots are complex and different.\n");
        printf("root1 = %.2lf + %.2lfi and root2 = %.2lf - %.2lfi", root1, imaginaryPart, root2, imaginaryPart);
    }
}
//2b
void table(int a){
    for (int i = 1; i <= 10; i++)
    {
        printf("%i x %2i = %3i\n", a, i, a *i);
    }
    
}
//2c
int z(float a, float b, char op)
{



    switch(op)
    {
    case 'a'	:
        printf("Sum of %f and %f is : %f",a,b,a+b);
        break;
    case 's'	:
        printf("Difference of %f and %f is : %f",a,b,a-b);
        break;
    case 'm'	:
        printf("Multiplication of %f and %f is : %f",a,b,a*b);
        break;
    case 'd'	:
        printf("Division of Two Numbers is %f : ",a/b);
        break;
    default	:
        printf(" Enter Your Correct Choice.");
        break;
    }
    return 0;
}
//3a
void ls(int a[], int f){
    int flag = 0;
    int loc = -1;
    for (int i = 0; a[i]; i++)
    {
        if (a[i] == f)
        {   flag = 1;
            loc = i;

            
            break;
        }
    }
    printf("%i",loc);
}

void aeo(int a[]){
    int o[100];
    int e[100];
    int k = 0; int l = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] % 2 == 0)
        {  o[k] = a[i];
           k = k + 1; 
            
        }
        if (a[i] % 2 == 1)
        {  e[l] = a[i];
            l = l + 1;
            
        }
    }
    printf("\nodd\n");
    for (int ll = 0; ll < l; ll++)
    {
        printf("%i\n", e[ll]);
    }
    printf("\neven\n");
        for (int lll = 0; lll < k; lll++)
    {
        printf("%i\n", o[lll]);
    }
    
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
//5A
int strle(char s[]){
    return strlen(s);
}
//5A
int mystrln(char *s){
    int i = 0;
    for (; *(s) != '\0'; s++, i++);
    return i;
}
//5B
void strconc(char a[], char b[]){
    strcat(a,b);
}
//5B
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
//5E
void mystrcpy1(char *a, char *b){
    while (*a++ = *b++ );
}
//6A
int binary_s_rec(int x[], int middle, int number, int lower, int highest){
    if (x[middle] == number)
    {
        return middle;
    }
    else if (x[middle] > number)
    {
        binary_s_rec(x,(middle - lower) / 2, number, lower, middle);
    }
    else if (x[middle] < number)
    {
         binary_s_rec(x,(highest + middle) / 2, number, middle, highest);
    }
    
}
//6B
void swapp(int *a, int *b){     //int a = 12;int b = 13;
    int temp = *a;              //printf("%i %i", a, b);
    *a = *b;                    //swapp(&a, &b);
    *b = temp;                  //printf("%i %i", a, b);
}
float avg(float a, float b, float c, float d, float e){
    return (a + b + c + d + e)/5;
}
//7A
void ptr_ad(int *a, int *b){     //int a = 12;int b = 13;
    *a = *a + *b;              //printf("%i %i", a, b);
                        //swapp(&a, &b);
                //printf("%i %i", a, b);
}

//8A
void ptr_sort(void){
    
   int *a,i,j,tmp,n;  
   for(i=0;i != '\0';i++)
   {
    for(j=i+1;j != '\0';j++)
    {
       if( *(a+i) > *(a+j))
       {
      tmp = *(a+i);
      *(a+i) = *(a+j);
      *(a+j) = tmp;
       }
    }
   }
   printf("\n The elements in the array after sorting : \n");
   for(i=0;i != '\0';i++)
      {
	  printf(" element - %d : %d \n",i+1,*(a+i));
	  }         
printf("\n");

}

//8B
int ptr_vc(char *a){
    int c = 0;
    int v = 0;
    for (;*a != '\0' ; *a++)
    {
       if (*a == 'a' ||*a == 'e' ||*a == 'i' ||*a == 'o' ||*a == 'u')
       {
        v= v + 1;
       }
       else  if (*a == 'b' ||*a == 'c' ||*a == 'd' ||*a == 'f' ||*a == 'g'||*a == 'h' ||*a == 'q' ||*a == 'j' ||*a == 'k' ||*a == 'l'||*a == 'm' ||*a == 'n' ||*a == 'p' ||*a == 'r' ||*a == 's'||*a == 't' ||*a == 'v' ||*a == 'w' ||*a == 'x' ||*a == 'y'||*a == 'z')
       {
        c= c + 1;
       }
    }
    printf("vovels: %i", v);
    printf("\nconsonents: %i", c);
}
//4
void display(int matrix[3][3])
{
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<3; j++)
      printf("%d\t",matrix[i][j]);


    printf("\n"); 
  }
}

void add(int m[3][3], int n[3][3], int sum[3][3])
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      sum[i][j] = m[i][j] + n[i][j];
  
    for(int ii=0; ii<3; ii++)
  {
    for(int jj=0; jj<3; jj++)
      printf("%d\t",sum[ii][jj]);


    printf("\n"); 
  }
}

void subtract(int m[3][3], int n[3][3], int result[3][3])
{
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      result[i][j] = m[i][j] - n[i][j];
      for(int ii=0; ii<3; ii++)
  {
    for(int jj=0; jj<3; jj++)
      printf("%d\t",result[ii][jj]);


    printf("\n"); 
  }
}


void multiply(int m[3][3], int n[3][3], int mul[3][3])
{
  for(int i=0; i < 3; i++)
  {
    for(int j=0; j < 3; j++)
    {
      mul[i][j] = 0; 
      for (int k = 0; k < 3; k++)
      mul[i][j] = mul[i][j] + ( m[i][k] * n[k][j]);
    }
  }
      for(int ii=0; ii<3; ii++)
  {
    for(int jj=0; jj<3; jj++)
      printf("%d\t",mul[ii][jj]);


    printf("\n"); 
  }
}


void transpose(int matrix[3][3], int trans[3][3])
{
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      printf("%d\t",matrix[j][i]);
    }printf("\n"); 
  }
}


  int c[3][3];


  void revstr(char *str1)  
{  
  
    int i, len, temp;  
    len = strlen(str1); 
      
     
    for (i = 0; i < len/2; i++)  
    {  
     
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  
      
int  main() {
    //size_of(2,3.3,'a', 5.5);
    //j(4,3.4,'e', 3.3);
   // char h[40] = "Arya ";
   // char i[40] = "Pathak";
    //grd(76,99,40,66,83);
    //root(7,6,3);
    //table(3);
    //leap(2016);
    int a[10] = {11,22,33,44,55,66,77,88,99,110};
    //ls(a, 33);
    //z(4.5,6.3,'m');
    char z[] = "arya mahesh path";
    //char *zz = z;
    //ptr_vc(zz);
    //printf("%i\n", strle(z));
    //printf("%i\n",mystrln(z));
char aa[] = "arya ";
char ab[] = "pathak";
char bb[] = "ziegler";
char bbb[] = "catalyst";
char bc[sizeof(bb)+ sizeof(bbb)];
    //aeo(a);
    printf("%s\n",aa);
    printf("%s\n",ab);
    strconc(aa,ab);
    printf("%s\n",aa);
        printf("%s\n",bb);
    printf("%s\n",bbb);
    mystrcpy(bb,bbb,bc);
    printf("%s\n",bc);
    //printf("%s",h);
    //int a[10] = {11,22,33,44,55,66,77,88,99,110};
    //int lowest = 0;
    //int highest = 9;
    //int middle = (highest - lowest) % 2;
    //int number = 44;
    //printf("%i",binary_s_rec(a,middle, number, lowest, highest));
    //j(4,3.4,'e', 3.3);
   return 0;
}
