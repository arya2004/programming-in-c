#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

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


double sine_x(double x){
    double result = 0;
    for (int j = 0; (power(-1,j)*(power(x, (2*j) + 1))/Fact((2 * j) + 1)) >= 0.0000001 || (power(-1,j)*(power(x, (2*j) + 1))/Fact((2 * j) + 1)) <= -0.0000001; j++){
        result = result + (power(-1,j)*(power(x, (2*j) + 1))/Fact((2 * j) + 1));
    }

    return result;
}

double cosine_x(double x){
    double result = 0;
    for (int j = 0; (power(-1,j)*(power(x, (2*j)))/Fact((2 * j))) >= 0.0000001 ||(power(-1,j)*(power(x, (2*j)))/Fact((2 * j))) <= -0.0000001  ; j++){
        result = result + (power(-1,j)*(power(x, (2*j)))/Fact((2 * j)));
    }
    return result;
}

void printer(double radian){
    printf("\nsin(x) My programme answer     : %lf\n",sine_x(radian));
    printf("sin(x) LIbrary function answer : %lf\n\n",sin(radian));
    printf("cos(x) My programme answer     : %lf\n",cosine_x(radian));
    printf("cos(x) LIbrary function answer : %lf\n",cos(radian));

}

int  main() {
    double rad;
    printf("Give angle in radians    :");
    scanf("%lf", &rad);
    if (rad > 2 *3.14159265358979323846)
    {
        while (rad > 2 *3.14159265358979323846){
        rad = rad - (2 *3.14159265358979323846);  //gives error for big value without this
    }
    }
        if (rad < -(2 *3.14159265358979323846))
    {
        while (rad < -(2 *3.14159265358979323846)){
        rad = rad + (2 *3.14159265358979323846);  //gives error for big value without this
    }
    }

    printer(rad);

    return 0;
}
