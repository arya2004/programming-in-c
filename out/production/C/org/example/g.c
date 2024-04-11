#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

int binary_s_rec(int x[10], int middle, int number, int lower, int highest){
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

double Fact(double i) { //not unsigned long int, cause double stores more.useless after 15
    if(i <= 1) {
        return 1;
    }
    else{
        return i * Fact(i - 1);
    }
}

double power(double a, unsigned int n ) {
    if(n == 0) {
        return 1;
    }
    else{
        return a * power(a , n-1);
    }
}


double sinx(double x){
    double result = 0;
    for (int j = 0; (power(-1,j)*(power(x, (2*j) + 1))/Fact((2 * j) + 1)) >= 0.000001 || (power(-1,j)*(power(x, (2*j) + 1))/Fact((2 * j) + 1)) <= -0.000001; j++){
        result = result + (power(-1,j)*(power(x, (2*j) + 1))/Fact((2 * j) + 1));
    }

    return result;
}

double cosx(double x){
    double result = 0;
    for (int j = 0; (power(-1,j)*(power(x, (2*j)))/Fact((2 * j))) >= 0.000001 ||(power(-1,j)*(power(x, (2*j)))/Fact((2 * j))) <= -0.000001  ; j++){
        result = result + (power(-1,j)*(power(x, (2*j)))/Fact((2 * j)));
    }
    return result;
}

void printer(double radian){
    printf("\nsin(x) My programme answer : %lf\n",sinx(radian));
    printf("sin(x) LIbrary function answer : %lf\n\n",sin(radian));
    printf("cos(x) My programme answer : %lf\n",cosx(radian));
    printf("cos(x) LIbrary function answer : %lf\n",cos(radian));

}
//CALENDR BEGINS FROM HERE 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
int calender[42];

int leap(int year){
    if (year % 4 == 0 && year % 100 != 0 && year % 400 != 0 || year % 4 == 0 && year % 100 == 0 && year % 400 == 0 ){
        return 366 % 7;
    }
    else{
        return 365 % 7;
    }
}
int leap1(int year){
    if (year % 4 == 0 && year % 100 != 0 && year % 400 != 0 || year % 4 == 0 && year % 100 == 0 && year % 400 == 0 ){
        return 366 ;
    }
    else{
        return 365 ;
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

int days_elapsed(int year,int month,int day){
    int dayse = 0;
    for (int i = 1; i < year; i++)
    {
        dayse = dayse + leap1(year);
    }
    int days_in_months_leapyear1[11] = {31,29,31,30,31,30,31,31,30,31,30};
    int days_in_months_notleapear1[11] = {31,28,31,30,31,30,31,31,30,31,30};
    if (leap1(year) == 366){
        for (int i = 0; i < month - 1; i++){
            dayse = dayse + days_in_months_leapyear1[i];
        }
        
    }
    else if (leap1(year) == 365){
        for (int i = 0; i < month - 1; i++){
            dayse = dayse + days_in_months_notleapear1[i];
        }
        
    }
    dayse = dayse + day - 1;
    return dayse;
}
int main(){
    int year = 9;
    int month = 2;
    int dae = 29;
    //calendar_printer(year,month);
    printf("%i", days_elapsed(year,month,dae));
    //printf("%i", leap1(year));
    return 0;
}