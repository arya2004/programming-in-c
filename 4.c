#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
struct student  //user drfined data type
{
 int roll_no;
 char name[30];
 float marks;
};

void display(struct student s[100],int n)
{for(int i=0;i<n;i++)
    {
        printf("\n%3d\t%3d\t%-30s\t%10.2f",i+1,s[i].roll_no,s[i].name,s[i].marks);
    }
}
int add(struct student *s,int n)
{
    int m;
    printf("give the number of students to add");
    scanf("%d",&m);
    for(int i=n;i<n+m;i++)
    {   printf("\ngive information about student %d\n",i+1);
        printf("roll no :  ");
        scanf("%d%*c",&s[i].roll_no);
        printf("name     : ");
        gets(s[i].name);
        printf("marks    : ");
        scanf("%f",&s[i].marks);

    } 
    return n+m;
}

void sortby_rollno(struct student *s,int n) 
{
    int lasti=n-2;
    for(int pass=1;pass<n;pass++)
    {
        int flag=0;
        for(int i=0;i<=lasti;i++)
        { 
            if(s[i].roll_no>s[i+1].roll_no)
            {
                struct student temp;
                temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
                flag=1;
            }
        }
        lasti--;
        if(flag==0)
        {
            break;
        }
    }
}
void sortby_marks(struct student *s,int n) 
{
    int lasti=n-2;
    for(int pass=1;pass<n;pass++)
    {
        int flag=0;
        for(int i=0;i<=lasti;i++)
        { 
            if(s[i].marks<s[i+1].marks)
            {
                struct student temp;
                temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
                flag=1;
            }
        }
        lasti--;
        if(flag==0)
        {
            break;
        }
    }
}
void sortby_name(struct student *s,int n) 
{
    int lasti=n-2;
    for(int pass=1;pass<n;pass++)
    {
        int flag=0;
        for(int i=0;i<=lasti;i++)
        { 
            if(strcmp(s[i].name,s[i+1].name)>0)
            {
                struct student temp;
                temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
                flag=1;
            }
        }
        lasti--;
        if(flag==0)
        {
            break;
        }
    }
}
int Remove(struct student *s,int n)
{
    display(s,n);
    int d;
    printf("\ngive the serial no/record no to be deleted : ");
    scanf("%d",&d);
    if(d<1 || d>n) return n;
    if(d==n) return n-1;
    s[d-1]=s[n-1];
    return n-1;

}

void stf(struct student *s, int n){
    FILE *a;
    a = fopen("aaa.txt", "wt");
    //fprintf(a, "%i", n);
    for (int i = 0; i < n; i++)
    {

    fprintf(a,"\n%i", s[i].roll_no);
    fprintf(a,"\n%s", s[i].name );
    fprintf(a,"\n%f",s[i].marks);
  }  
    fclose(a);
     
}
int rtv(struct student *s, int n){
    FILE *a;
    a = fopen("aaa.txt", "rt");
   // fscanf(a,"%i\n", &n);
    for (int i = 0; i < n; i++)
    {

    fscanf(a,"%i\n", &s[i].roll_no);    fscanf(a,"%s\n", &s[i].name);    fscanf(a,"%f\n", &s[i].marks);
    printf("\nprn: %i NAme: %s mks %f ",s[i].roll_no,s[i].name,s[i].marks);
  }  
    fclose(a);
    return n;
     
}


int main()
{
    /*struct student s[100];
    int n=0;*/
    int g = 1;
    struct student s[100]={{5,"arya_pathak",40},{3,"zeiger_cat",36},{8,"catalyst_catt",64},{1,"tsgdf_sgereg",55},{10,"aadhf_weaf",37}};
    int n=5;
    int choice;
    while (g != 0)
    {
    // printf("\n\t\t* * * MENU * * *");
      //  printf("\t1:add");
       // printf("\t2.display");
       // printf("\t3.sort by roll no ");
       // printf("\t4.sort by name");
       // printf("\t5.sort by marks");
       // printf("\t6.sort by age");
       // printf("\t7.store to file");
       // printf("\t8.retrive from file");
       // printf("\t9.exit");
       // printf("\t10.Remove ");
        printf("\n give your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                n=add(s,n);
                display(s,n);
                break;
            case 3:
                sortby_rollno(s,n);
                display(s,n);
                break;
            case 4:
                 sortby_name(s,n);
                 display(s,n);
                break;
            case 5:
                sortby_marks(s,n);
                display(s,n);
                break;
            case 7:
                stf(s,n);
                                display(s,n);
                break;
               
            case 8:
                n = rtv(s,n);
                             //   display(s,n);
                break;
               
            case 10:
                n=Remove(s,n);
                display(s,n);
                break;
            case 0:
                g = 0;
        }

    }
    n=add(s,n);    
    display(s,n);

    
}