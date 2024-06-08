#include<stdio.h>
#include<math.h>

// Function to calculate factorial of a number
double Fact(double i) {
    if(i <= 1) {
        return 1;
    }
    else{
        return i * Fact(i - 1);
    }
}

// Function to calculate power of a number
double power(double a, unsigned int n ) {
    if(n == 0) {
        return 1;
    }
    else{
        return a * power(a , n-1);
    }
}

// Function to calculate sine of an angle in radians
double sine_x(double x){
    double result = 0;
    for (int j = 0; fabs((power(-1,j)*(power(x, (2*j) + 1))/Fact((2 * j) + 1))) >= 0.0000001; j++){
        result = result + (power(-1,j)*(power(x, (2*j) + 1))/Fact((2 * j) + 1));
    }
    return result;
}

// Function to calculate cosine of an angle in radians
double cosine_x(double x){
    double result = 0;
    for (int j = 0; fabs((power(-1,j)*(power(x, (2*j)))/Fact((2 * j)))) >= 0.0000001; j++){
        result = result + (power(-1,j)*(power(x, (2*j)))/Fact((2 * j)));
    }
    return result;
}

// Function to print results
void printer(double radian){
    printf("\nsin(x) My program answer     : %lf\n", sine_x(radian));
    printf("sin(x) Library function answer: %lf\n\n", sin(radian));
    printf("cos(x) My program answer     : %lf\n", cosine_x(radian));
    printf("cos(x) Library function answer: %lf\n", cos(radian));
}

int  main() {
    double rad;
    printf("Give angle in radians: ");
    scanf("%lf", &rad);
    
    // Normalize the angle if it's outside the range [-2*pi, 2*pi]
    while (rad > 2 * M_PI) {
        rad = rad - (2 * M_PI);
    }

    while (rad < -(2 * M_PI)) {
        rad = rad + (2 * M_PI);
    }

    printer(rad);

    return 0;
}
