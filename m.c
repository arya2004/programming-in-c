#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
int calender[42];

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
        else if (calender[row1] != 0){
            printf("%3i\t",calender[row1]);
        }
    }
        printf("\n");
    for (int row2 = 7; row2 <14 ; row2++){
        printf("%3i\t",calender[row2]);
    }
        printf("\n");
    for (int row3 = 14; row3 <21 ; row3++){
        printf("%3i\t",calender[row3]);
    }
        printf("\n");
    for (int row4 = 21; row4 <28 ; row4++){
        printf("%3i\t",calender[row4]);
    }
        printf("\n");
    for (int row5 = 28; row5 <35 ; row5++){
        if (calender[row5] != 0){
            printf("%3i\t",calender[row5]);
        }
    }
        printf("\n");
    for (int row6 = 35; row6 <42 ; row6++){
        if (calender[row6] != 0){
            printf("%3i\t",calender[row6]);
        }
    }
}

int main(){
    int year = 2022;
    int month = 12;
    calendar_printer(year,month);
    return 0;
}