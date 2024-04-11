#include<stdio.h>
#include<string.h>
#include<stdlib.h>

  
struct Remainder{  
    int dd;  
    int mm;  
    char note[50];  
};  
struct Remainder R; 
char checkNote(int dd, int mm);
int calender[42];
void sortby_rollno(struct Remainder *s,int n);
void sortby_name(struct Remainder *s,int n);
int remove1(struct Remainder *s,int n);



int leap(int year){
    if (year % 4 == 0 && year % 100 != 0 && year % 400 != 0 || year % 4 == 0 && year % 100 == 0 && year % 400 == 0 ){
        return 366 % 7;
    }
    else{
        return 365 % 7;
    }
}

int jan_first_day(int year){
    int day = 1; //sunday is 0 //initially assumed 0. 1 was found by trial and error
    for (int i = 1; i < year; i++){
        day = day + leap(i);
    }
    return day % 7 ;
}

int month_first_day(int year, int month){
    int day = jan_first_day(year);
    int mod_days_in_months_leapyear[11] = {31%7,29%7,31%7,30%7,31%7,30%7,31%7,31%7,30%7,31%7,30%7};
    int mod_days_in_months_notleapear[11] = {31%7,28%7,31%7,30%7,31%7,30%7,31%7,31%7,30%7,31%7,30%7};
    if (leap(year) == 366 % 7){
        for (int i = 0; i < month - 1; i++){
            day = day + mod_days_in_months_leapyear[i];
        }
        return day % 7;
    }
    else if (leap(year) == 365 % 7){
        for (int i = 0; i < month - 1; i++){
            day = day + mod_days_in_months_notleapear[i];
        }
        return day % 7;
    }
}

void calendar_printer(int year, int month){
    int days_in_months_leapyear[12] = {31,29,31,30,31,30,31,31,30,31,30, 31};  
    int days_in_months_notleapear[12] = {31,28,31,30,31,30,31,31,30,31,30, 31};
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    int number = 1;
    for (int i = 0; i < month_first_day(year , month) ; i++){
        calender[i] = 0;
}
    if (leap(year) == 366%7){
        for (int e = 1; e <= days_in_months_leapyear[month - 1] ; e++){
            calender[month_first_day(year , month) + e -1] = e;
        }
    }

    else if (leap(year) == 365%7){
        for (int e = 1; e <= days_in_months_notleapear[month - 1] ; e++){
        calender[month_first_day(year , month) + e -1] = e;
        }
    }
//Below prints days
    for (int row1 = 0; row1 <7 ; row1++){
        if (calender[row1] == 0){
            printf(" \t");
        }
        else if (checkNote(calender[row1],month) == '*'){
            printf("%3i*\t",calender[row1]);
        }
        else if (calender[row1] != 0){
            printf("%3i\t",calender[row1]);
        }
    }
        printf("\n");
    for (int row2 = 7; row2 <14 ; row2++){
        if (checkNote(calender[row2],month) == '*'){
            printf("%3i*\t",calender[row2]);
        }
        else if (calender[row2] != 0){
            printf("%3i\t",calender[row2]);
        }
    }
        printf("\n");
    for (int row3 = 14; row3 <21 ; row3++){
                if (checkNote(calender[row3],month) == '*'){
            printf("%3i*\t",calender[row3]);
        }
        else if (calender[row3] != 0){
            printf("%3i\t",calender[row3]);
        }
    }
        printf("\n");
    for (int row4 = 21; row4 <28 ; row4++){
                if (checkNote(calender[row4],month) == '*'){
            printf("%3i*\t",calender[row4]);
        }
        else if (calender[row4] != 0){
            printf("%3i\t",calender[row4]);
        }
    }
        printf("\n");
    for (int row5 = 28; row5 <35 ; row5++){
                if (checkNote(calender[row5],month) == '*'){
            printf("%3i*\t",calender[row5]);
        }
        else if (calender[row5] != 0){
            printf("%3i\t",calender[row5]);
        }
        
    }
        printf("\n");
    for (int row6 = 35; row6 <42 ; row6++){
        if (checkNote(calender[row6],month) == '*'){
            printf("%3i*\t",calender[row6]);
        }
        else if (calender[row6] != 0){
            printf("%3i\t",calender[row6]);
        }
        
    }
}

char checkNote(int dd, int mm){  
    FILE *fp;  
    fp = fopen("student_data","rb");  
    if(fp == NULL){  
        printf(" ");  
    }  
    while(fread(&R,sizeof(R),1,fp) == 1){  
        if(R.dd == dd && R.mm == mm){  
            fclose(fp);  

            return '*';  
        }  
    }  

    fclose(fp);  
    return ' ';  
}  

int retrive_from_file_B(struct Remainder *s,int n)
{
    FILE*fp=fopen("student_data.dat","rb");
    if(fp==NULL)
    {
        printf("unable to open the file. QUITTING");
        return 1;
    }
    fread(&n, sizeof(int), 1, fp );
    fread(s,sizeof(struct Remainder), n, fp );

    fclose(fp);
    
    return n;
}


void store_to_file_B(struct Remainder s[100], int n)
{
    FILE*fp=fopen("student_data.dat","wb");
    if(fp==NULL)
    {
        printf("unable to open the file. QUITTING");
        return;
    }
    fwrite(&n, sizeof(int), 1, fp );
    fwrite(s,sizeof(struct Remainder), n, fp );
    fclose(fp);
}


void display(struct Remainder s[100],int n)
{for(int i=0;i<n;i++)
    {
        printf("\n%3d\t%3d\t%3d\t%-30s",i+1,s[i].dd,s[i].mm,s[i].note);
    }
}
int add(struct Remainder *s,int n)
{
    int m;
    printf("give the number of Remaindrs to add");
    scanf("%d",&m);
    for(int i=n;i<n+m;i++)
    {   printf("\ngive information about Remainder %d\n",i+1);
        printf("Day :  ");
        scanf("%d%*c",&s[i].dd);
        printf("mm    : ");
        scanf("%i%*c",&s[i].mm);
        printf("note     : ");
        gets(s[i].note);


    } 
    return n+m;
}

void sortby_rollno(struct Remainder *s,int n) 
{
    int lasti=n-2;
    for(int pass=1;pass<n;pass++)
    {
        int flag=0;
        for(int i=0;i<=lasti;i++)
        { 
            if(s[i].mm>s[i+1].mm)
            {
                struct Remainder temp;
                temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;
                flag=1;
            }
        }
        for(int i=0;i<=lasti;i++)
        { 
            if(s[i].mm==s[i+1].mm && s[i].mm>s[i+1].mm)
            {
                struct Remainder temp;
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

void sortby_name(struct Remainder *s,int n) 
{
    int lasti=n-2;
    for(int pass=1;pass<n;pass++)
    {
        int flag=0;
        for(int i=0;i<=lasti;i++)
        { 
            if(strcmp(s[i].note,s[i+1].note)>0)
            {
                struct Remainder temp;
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
int remove1(struct Remainder *s,int n)
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

int main()
{   int y = 1;
    int m = 1;
    struct Remainder s[100];
    int n=0;
    //struct Remainder s[100]={{5,"rupali paimode",40},{3,"harsh wardhan",36},{8,"kanaad patil",64},{1,"maitreyi panchale",55},{10,"aaditya patil",37}};
    //int n=5;
    int choice;
    while (1)
    {
        printf("\n\t\t* * * MENU * * *");
        printf("\n1:add");
        printf("\n2.display");
        printf("\n3.sort by roll no ");
        printf("\n4.sort by note");
        printf("\n5.calendar display");
        printf("\n6.sort by age");
        printf("\n7.store to file");
        printf("\n8.retrive from file");
        printf("\n9.exit");
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
            case 4:
                 sortby_name(s,n);
                 display(s,n);
                break;
            case 5:
            printf("\to display calendar\n");
            printf("Year :  ");
            scanf("%d%*c",&y);
            printf("mm    : ");
            scanf("%d%*c",&m);
                calendar_printer(y,m);
                break;
            case 7:
                store_to_file_B(s,n);
                display(s,n);
                break;
            case 8:
                n=retrive_from_file_B(s,n);
                display(s,n);
                break;

            case 10:
                n=remove1(s,n);
                display(s,n);
                break;
            case 9:
            return 0;
        }

    }
    n=add(s,n);    
    display(s,n);

    
}