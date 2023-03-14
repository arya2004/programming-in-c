#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student  //user drfined data type
{
 int roll_no;
 char name[30];
 float marks;
};


/*int retrive_from_file_T(struct student *s,int n)
{
    FILE*fp=fopen("student_data.txt","rt");
    if(fp==NULL)
    {
        printf("unable to open the file. QUITTING");
        return 1;
    }
    fscanf(fp, "%d\n",&n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d\n", &s[i].roll_no);
        fgets(s[i].name,29, fp);
        s[i].name[strlen(s[i].name) - 1] = '\0';
        fscanf(fp, "%f\n", &s[i].marks);
       // printf("\nstudent number %d roll no %d name %s marks %f", i, s[i].roll_no, s[i].name, s[i].marks);
    }
    fclose(fp);
    
    return n;
}
int retrive_from_file_B(struct student *s,int n)
{
    FILE*fp=fopen("student_data.dat","rb");
    if(fp==NULL)
    {
        printf("unable to open the file. QUITTING");
        return 1;
    }
    fread(&n, sizeof(int), 1, fp );
    fread(s,sizeof(struct student), n, fp );


    fclose(fp);
    
    return n;
}

void store_to_file_T(struct student s[100], int n)
{
    FILE*fp=fopen("student_data.txt","wt");
    if(fp==NULL)
    {
        printf("unable to open the file. QUITTING");
        return;
    }
    fprintf(fp, "%d\n", n);
    for(int i=0;i<n;i++)
    {
        fprintf(fp, "%d\n",s[i].roll_no);
        fprintf(fp, "%s\n",s[i].name);
        fprintf(fp, "%f\n",s[i].marks);
    }
    fclose(fp);
}
void store_to_file_B(struct student s[100], int n)
{
    FILE*fp=fopen("student_data.dat","wb");
    if(fp==NULL)
    {
        printf("unable to open the file. QUITTING");
        return;
    }
    fwrite(&n, sizeof(int), 1, fp );
    fwrite(s,sizeof(struct student), n, fp );

    fclose(fp);
}

*/
void display(struct student **s,int n)
{for(int i=0;i<n;i++)
    {
        printf("\n%3d\t%3d\t%-30s\t%10.2f",i+1,s[i]->roll_no,s[i]->name,s[i]->marks);
    }
}
int add(struct student **s,int n)
{   
    int m;
    printf("give the number of students to add");
    scanf("%d",&m);
    for(int i=n;i<n+m;i++)
    {   s[i] = (struct student *) malloc(sizeof(struct student));
        if(s[i]==NULL){
        printf("out of mem");
        return i - 1;
    }
        printf("\ngive information about student %d\n",i+1);
        printf("roll no :  ");
        scanf("%d%*c",&s[i]->roll_no);
        printf("name     : ");
        gets(s[i]->name);
        printf("marks    : ");
        scanf("%f",&s[i]->marks);

    } 
    return n+m;
}

void sortby_rollno(struct student **s,int n) 
{
    int lasti=n-2;
    for(int pass=1;pass<n;pass++)
    {
        int flag=0;
        for(int i=0;i<=lasti;i++)
        { 
            if(s[i]->roll_no>s[i+1]->roll_no)
            {
                struct student *temp;
                temp= s[i];
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
/*
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
*/
int remove1(struct student **s,int n)
{
    display(s,n);
    int d;
    printf("\ngive the serial no/record no to be deleted : ");
    scanf("%d",&d);
    if(d<1 || d>n) return n;
    if(d==n){
        free(s[n-1]);
    return n-1;
    }
    free(s[d - 1]);
    s[d-1] = s[n-1];
    return n-1;

}
int main()
{
    struct student *s[100];
    int n=0;
    //struct student s[100]={{5,"rupali paimode",40},{3,"harsh wardhan",36},{8,"kanaad patil",64},{1,"maitreyi panchale",55},{10,"aaditya patil",37}};
    //int n=5;
    int choice;
    while (1)
    {
        printf("\n\t\t* * * MENU * * *");
        printf("\n1:add");
        printf("\n2.display");
        printf("\n3.sort by roll no ");
        printf("\n4.sort by name");
        printf("\n5.sort by marks");
        printf("\n6.sort by age");
        printf("\n7.store to file");
        printf("\n8.retrive from file");
        printf("\n0.exit");
        printf("\n10.remove1 ");
        printf("\n\n give your choice");
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
            /*case 4:
                 sortby_name(s,n);
                 display(s,n);
                break;
            case 5:
                sortby_marks(s,n);
                display(s,n);
                break;
            case 7:
                store_to_file_B(s,n);
                display(s,n);
                break;
            case 8:
                n=retrive_from_file_B(s,n);
                display(s,n);
                break;
            */
            case 10:
                n=remove1(s,n);
                display(s,n);
                break;
            case 0:
            return 0;
        }

    }
    n=add(s,n);    
    display(s,n);

    
}