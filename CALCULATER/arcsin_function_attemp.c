#include <stdio.h>

#define EPSILON 0.000001
#define PI 3.14159265

double degree_to_radian(double angle);
double radian_to_degree(double angle);
double abs_diff(double x, double y);
double arcsinus(double x);
double sinus(double x) ;
double cosinus(double x);
double power(double x, int y);
double factorial(int x);
double mod(double x, double y);
double absolute(double x);

double tangent(double x);
double arctangent(double x);
double arccotangent(double x);
double secant(double x);
double arccosinus(double x);
double arcsecant(double x);
double arccosecant(double x);

int main() {
    double transformed_number;
    double number = 45;
    double number2 = 0.0243;
    
    transformed_number = degree_to_radian(number);
    
    printf("sinus(%lf) = %lf\n", number, sinus(transformed_number));
    printf("cosinus(%lf) = %lf\n", number, cosinus(transformed_number));
    printf("arcsin(%lf) = %lf\n", number, radian_to_degree(arcsinus(transformed_number)));
    printf("arcsin(%lf) = %lf", number2, arcsinus(number2));
    
    double radian = 0.5;
    radian = radian_to_degree(radian);
    printf("\nNew value is %lf", radian);

    double number3 = 2.0;
    number3 = arctangent(number3); //the value is in radian type right now
    printf("\nthe arctan result is %lf degree", radian_to_degree(number3));

    double number4 = 2.0;
    number4 = arccotangent(number4); //the value is in radian type right now
    printf("\nthe arccotan result is %lf degree", radian_to_degree(number4));

    double number5 = 3.0;
    number5 = arcsecant(number5); //the value is in radian type right now
    printf("\nthe arcsec result is %lf degree", radian_to_degree(number5));

    double number6 = 3.0;
    number6 = arccosecant(number6); //the value is in radian type right now
    printf("\nthe arccosec result is %lf degree", radian_to_degree(number6));
    return 0;
}

double arcsinus(double x) {
    double fy, dfy, y_new;
    double y_start = 0.5;
    
    if(absolute(x) > 1) {
        puts("MATH ERROR: x values need to be between (-1,1)");
        return 0;
    }
    
    for(int i = 0; i < 10; i++) {
        fy = sinus(y_start) - x;
        dfy = cosinus(y_start);
        y_new = y_start - (fy / dfy);
        
        if(abs_diff(y_new, y_start) < EPSILON) {
            return y_new;
        }
        y_start = y_new;
    }
    puts("The approximation couldn't have been done successfully");
    return y_new;
}

double arccosinus(double x) {
    double fy, dfy, y_new;
    double y_start = 0.5;
    
    if(absolute(x) > 1) {
        puts("MATH ERROR: x values need to be between (-1,1)");
        return 0;
    }
    for(int i = 0; i < 10; i++) {
        fy = cosinus(y_start) - x;
        dfy = -1 * sinus(y_start);
        y_new = y_start - (fy / dfy);
        
        if(abs_diff(y_new, y_start) < EPSILON) {
            return y_new;
        }
        y_start = y_new;
    }
    puts("The approximation couldn't have been done successfully");
    return y_new;
}

double arctangent(double x) {
    double y_new, y_start, fy, dfy;
    
    y_start = 0.7;
    
    for(int i = 0; i < 10; i++) {
        fy = tangent(y_start) - x;
        dfy = power(secant(y_start), 2);
        
        y_new = y_start - (fy / dfy);
        
        if(abs_diff(y_new , y_start) < EPSILON) {
            return y_new;
        }
        y_start = y_new;
    }
    puts("The approximation couldn't have been done successfully");
    return y_new;
}

double arccotangent(double x) {
    return (PI / 2 - arctangent(x));
}

double arcsecant(double x) {
    return arccosinus(1 / x);
}

double arccosecant(double x) {
    return arcsinus(1 / x);
}

double tangent(double x) {
    if(cosinus(x) == 0) {
        puts("MATH ERROR: ");
        return 0;
    }
    return sinus(x) / cosinus(x);
}

double secant(double x) {
    if(cosinus(x) == 0) {
        puts("MATH ERROR: ");
        return 0;
    }
    return 1 / cosinus(x);
}

double abs_diff(double x, double y) {
    return (x > y) ? (x - y) : (y - x);
}

double degree_to_radian(double angle) {
    double radian;
    
    radian = PI * (angle / 180.0);
    radian = mod(radian, 2 * PI);
    
    return radian;
}

double radian_to_degree(double angle) {
    double degree;
    
    degree = 180.0 * (angle / PI);
    
    return degree;
}

double cosinus(double x) { 
    double term = 0.0, result = 0.0;
    int n; 
    for(n = 0; n < 10; n++){
        term = (n % 2 == 0 ? 1.0 : -1.0);
        term *= power(x , 2 * n) / factorial(2 * n);
        result += term;
    }
    return result;
}

double sinus(double x) { 
    int n;
    double result = 0.0, term;
    for(n = 0; n < 10; n++) {
        term = (n % 2 == 0 ? 1.0 : -1.0);
        term *=  power(x, ( 2 * n + 1 ));
        term /= factorial( 2 * n + 1 );
        result += term;
    }
    return result;
}

double factorial(int x) {
    double result = 1.0;
    int i;

    if(x < 0) {
        puts("MATH ERROR: Factorial of negative number");
        return 0;
    }
    for(i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}

double mod(double x, double y) {
    double remaind;
    double absX, absY;

    if(y == 0) {
        puts("MATH ERROR: Modulo by zero");
    }
    absX = (x < 0) ? -x : x;
    absY = (y < 0) ? -y : y;

    remaind = absX;
    while(remaind >= absY) {
        remaind -= absY;
    }
    return (x < 0) ? -remaind : remaind;
}

double power(double x, int y) {
    double result = 1.0;
    int i;

    if(x == 0 && y <= 0) {
        puts("MATH ERROR: Zero raised to non-positive power");
        return 0;
    }
    if(y < 0) {  
        for(i = 0; i < -y; i++) {
            result *= (1.0 / x) ;  
        }
    }
    else {
        for(i = 0; i < y; i++) {
            result *= x;
        }
    }
    return result;   
}

double absolute(double x) {
    return (x < 0) ? -x : x;
}