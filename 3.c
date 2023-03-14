#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
//11_A_and_B
struct student{
    char name[30];
    int prn;
    char div;
};

void aa(void) {
    int i;
    struct student s[2], r[2];
    FILE *fp, *fp2;//pointer to structure called FILE
    fp = fopen("11_A_and_B.txt", "w");
    for ( i = 0; i < 2; i++)
    {
       printf("\nEnter name:");
       fflush(stdin);
       gets(s[i].name);
       fflush(stdin);
       printf("\nEnter prn:");
       fflush(stdin);
       scanf("%i", &s[i].prn);
       fflush(stdin);
       printf("\nEnter division:");
       fflush(stdin);
       scanf("%c", &s[i].div);
       fflush(stdin);
       fwrite(&s[i], sizeof(struct student),1,fp); 
       
    }
    printf("\nStudent info\n");
    fclose(fp);//counterpart of fopen
    fp2 = fopen("11_A_and_B.txt", "r");
        for ( int j = 0; j < 2; j++)
    {   fread(&r[j],sizeof(struct student),1,fp2);
       printf("Name:");
       puts(r[j].name);

       printf("Enter prn:%i", r[j].prn);

       printf("\nEnter division:%c\n", r[j].div);

     
       
    }
}    

void bb(void){
    FILE *a;
    int z;
    a = fopen("zgntct.txt", "rt");
    if (a == NULL)
    {
        printf("ERROE");
        
    }
    while (!feof(a)){   

        fread(&z,sizeof(z),1,a);
        
        printf("\n %i  %c", z, z);
        a = a + 1;
    }
    
fclose(a);

}

void cc(void){
    FILE *a;
    a = fopen("aaa.txt", "wt");
    if (a == NULL)
    {
        printf("ERROE");
      
        
    }
    fputc('a', a);fputc('b', a);fputc('b', a);fputc('\n', a);fputc('D', a);fputc('E', a);fputc('F', a);fputc('\n', a);

    
fclose(a);
}
//copy file
void dd(void){
    FILE *a, *b;
    
    b = fopen("bbb.txt", "wt");
    fclose(b);
    a = fopen("aaa.txt", "rt");
    b = fopen("bbb.txt", "wt");
    if (a == NULL)
    {
        printf("ERROE");
    }
    while (!feof(a))
    { 
        fputc(fgetc(a),b);
        
    }
    
    
fclose(a);
fclose(b);

}

void ee(void){
    FILE *a;
    a = fopen("aaa.txt", "rt");
    char i[100];
    while (!feof(a)){ 

        fgets(i,100,a);
        
    } 

        printf("%s", i);
    fclose(a); 
}

void ff(void){
    FILE *a;
    a = fopen("aaa.txt", "wt");
    fputs("First line\n",a);
    fputs("seec line\n",a);
    fputs("thrd line\n",a);
    fputs("Frth line\n",a); 

    
    fclose(a); 
}
void gg(int a){
    if (a == 0)
    {
       printf("No:");
    }
    
    else{
        gg(a/2);
        if (a%2 == 0){
            printf("0");
        }
        else{
            printf("1");
        }
        
    }
    
}
void g(void){
    FILE *a;
    a = fopen("aaa.txt", "wt");
    printf("\n%s\n%i", "ziegler", 12210060);
    fprintf(a,"zeigler");
    
    fclose(a); 
}
int main() {
    g();

    return 0;
}  