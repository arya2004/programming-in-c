
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
/*struct Date{  
    int dd;  
    int mm;  
    int yy;  
};  
struct Date date;*/  
  
struct Remainder{  
    int dd;  
    int mm;  
    char note[50];  
};  
struct Remainder R;  
char checkNote(int dd, int mm);
int calender[42];
void sortby_rollno(struct Remaider *s,int n);
void sortby_marks(struct Remaider *s,int n);
void sortby_name(struct Remaider *s,int n);
int remove1(struct Remaider *s,int n);
void store_to_file_T(struct Remaider s[100], int n);

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
    fp = fopen("note.dat","rb");  
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
  
  
void AddNote(){  
    FILE *fp;  
    fp = fopen("note.dat","ab+");   
    printf("Enter the date (DD MM): ");  
    scanf("%d%d",&R.dd, &R.mm);   
    printf("Enter the Note(50 character max): ");  
    fflush(stdin);  
    scanf("%[^\n]",R.note);  
    if(fwrite(&R,sizeof(R),1,fp)){   
        puts("Note is saved sucessfully");  
        fclose(fp);  
    }else{   
        puts("\aFail to save!!\a");  
    }  

}  
  
void showNote(int mm){  
    FILE *fp;  
    int i = 0, isFound = 0;  
    fp = fopen("note.dat","rb");  
    if(fp == NULL){  
        printf("Error in opening the file");  
    }  
    while(fread(&R,sizeof(R),1,fp) == 1){  
        if(R.mm == mm){ 
            printf("\nNote %d Day = %d: %s\n", i+1, R.dd,  R.note);  
            isFound = 1;  
            i++;  
        }  
    }  
    if(isFound == 0){  
        printf("\nThis Month contains no note\n");  
    }   

  
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
            if(s[i].mm==s[i+1].mm && s[i].dd >= s[i+1].dd )
            {
                struct rRmainder temp;
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
int add(struct Remainder *s,int n)
{
    int m;
    printf("give the number of students to add");
    scanf("%d",&m);
    for(int i=n;i<n+m;i++)
    {   printf("\ngive information about Remainder %d\n",i+1);
        printf("roll no :  ");
        scanf("%d%*c",&s[i].roll_no);
        printf("name     : ");
        gets(s[i].name);
        printf("marks    : ");
        scanf("%f",&s[i].marks);

    } 
    return n+m;
}

int main(){    
    int choice;  
    char ch = 'a';  
    int year;
    int month;
    int mm;
    struct Remaider s[100];
    int n=0;
    int dd;
    while(1){      
        printf("\n0. EXIT \n1. Print the calendar\n2. Add Remainder\n3.Show Remainder\n"); 
        printf("ENTER YOUR CHOICE : ");  
        scanf("%d",&choice);    
        switch(choice){    
            case 1 :  
                printf("Enter month(MM) : ");  
                scanf("%i",&month);
                printf("Enter year (YYYY) : ");  
                scanf("%i",&year);      
                calendar_printer(year,month); 
                break;  
            case 2:  
                AddNote();  
                break; 
            case 3:  
                printf("Enter month(MM) : ");  
                scanf("%i",&mm);
                showNote(mm);  
                break;
            case 4:  
                printf("sort rem ");  
                sortby_rollno();
                showNote(mm);  
                break;
            case 5:
                sortby_rollno(s,n);
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

            case 10:
                n=remove1(s,n);
                display(s,n);
                break;
            case 9:    
            case 0 :  
    			return 0;  
            default	:
                printf("\nEnter Your Correct Choice.\n");
                continue;
    }
        }  
      

    //printf("%c",checkNote(02,02));
    return 0;  
}