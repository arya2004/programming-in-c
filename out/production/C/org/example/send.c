#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

int is_leap(int y);
int days_in_month(int m,int y);
void printcalendar(int m,int y);
int week_day_number(int d,int m,int y);
int dd(int d1,int m1,int y1,int d2,int m2,int y2);
int ddy(int y1,int y2);
int ddm(int y,int m1,int m2);


int is_leap(int y)
{
    /*
    this function tells as if a given year is a leap year
    input y:year number(4 digit)
    return value 1 : leap year, 0 : not a leap year 
    */

    if(y%100==0)
        if(y%400==0) return 1;
        else return 0;
    else 
        if(y%4==0) return 1;
        else return 0;
}

int days_in_month(int m,int y)
{
    /*
    this function gives no of days in given month
    input m:month no (1 to 12) , y:year no (4 digit)
    retun value :no of days in given month(28/29/30/31)
    */

    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leap(y) && m==2)  return 29;
    return days[m];
}

void printcalendar(int m,int y)
{
    /*
    this function print calendar of given month
    input m:month no (1 to 12) , y:year no (4 digit)
    return value :no
    output:
    */
    int n=days_in_month(m,y);
    int start=week_day_number(1,m,y);
    printf("\nSun\tMon\tTue\tWen\tThus\tfri\tSat\n");

    for (int i = 0; i < start; i++)
    {
        printf("\t");
    }
    int pos=start;
    for (int i = 1; i <= n; i++)
    {
        printf("%2d\t",i);
        pos++;
        if (pos==7)
        {
            printf("\n");
            pos=0;
        }
        
    }
    
}

int week_day_number(int d,int m,int y)
{
    /*
    this function gives week day number for a given date
    intput: d:day of month(1 to 31),m:month no (1 to 12) , y:year no (4 digit)
    output: week day no(0 to 6)
    0:sun,1:mon,...,6:sat
    */

    int rd=13;
    int rm=1;
    int ry=2023;
    int rdow=5;
    int days=dd(rd,rm,ry,d,m,y);
    int dow = (rdow + days)%7;
    dow = (dow + 7)%7;
    
    
    return dow;

}

int dd(int d1,int m1,int y1,int d2,int m2,int y2)
{
    /*
    gives no of days between given two dates
    intput:d1,m1,y1:day,no month no and year no of first day
    d2,m2,y2:day no, month no and year no of second day
    output:day difference between first day and second day 
    if first day is smaller than second day then return value :positive
    if first day is greater than second day then return value :negative
    if first day is equal to second day then return value :zero  
    */
    
    return ddy(y1,y2)+(ddm(y2,1,m2)+d2)-(ddm(y1,1,m1)+d1);
}

int ddy(int y1,int y2)
{
    /*
    this function calculates no of days between 1 jan of year y1 to 1st jan of year y2
    intput :y1 year 1(4 digit)
    y2 year 2(4 digit)
    output:no of days 
    y1<y2: positive no
    y1>y2: negative no
    y1=y2: zero
    */

    int days=0;
    int temp,flag=0;
    if(y1>y2)
    {
        int temp=y1;
        y1=y2;
        y2=temp;
        flag=1;
    }
    for(int i=y1;i<y2;i++)   
        days+=365+is_leap(i);

    if (flag==1){
       days=-days;
    }
    return days;
}

int ddm(int y,int m1,int m2)
{
    /*
    this function return no of days between 1st day of month m1 to 1st day of m2 for year y
    intput :y year no ,m1 :month no (1 to 12),m2: 2nd month no(1 to 12)
    output:no of days
    m1<m2:positive
    m1>m2:negative
    m1=m2:zero
    */
   int temp,flag=0;
   if(m1>m2)
   {
      temp=m1;
      m1=m2;
      m2=temp;
      flag=1;
    }
    int days=0;
    for(int i=m1;i<m2;i++){
      days+=days_in_month(i,y);
    }

    if (flag==1){
      days=-days;
    }
    return days;  
}

void printer(int d,int m,int y){
    char ani_name[6][17] = {"Janma dinank","Raupya Mahotsav","Suvarna Mahotsav","Hirak Mahotsav","Amrut Mahotsav","Janma Shatabdi"};
    int ani_year[6] = {0,25,50,60,75,100};
    char dae[7][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char moth[12][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    for (int i = 0; i < 6; i++){
        printf("\n%-17s : %-10s , %d %-10s %d\t Your age in days: %5d ",ani_name[i], dae[week_day_number(d,m,y + ani_year[i])],d, moth[m-1],y+ ani_year[i],dd(d,m,y,d,m,y + ani_year[i]));
    }
}

int main(){
    int d,m,y;
    printf("Give your date of birth(dd mm yyyy):");
    scanf("%d %d %d",&d,&m,&y);
    printf("\nHere is calendar of your birth month:\n");
    printcalendar(m,y);
    printf("\nFollowing are the important dates in your life:\n");
    printer(d,m,y);
}