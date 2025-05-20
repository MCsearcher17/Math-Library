#include "mathtry.h"
#define MAX_ITE 200

double pi = 3.141592653589793;
double epsilon = 0.000001;

//1. Basic Arithmetic Operations**********************************************************************************************

float sum(float x, float y) {
    return x + y;
}

float subtract(float x, float y) {
    return x - y;
}

float multiply(float x, float y) {
    return x * y;
}

float divide(float x, int y) {
    if(y == 0) {
        puts("MATH ERROR: Division by zero");
        return 0;
    }
    return x / y;
}

//2. Power and Root Calculations**********************************************************************************************

float squared(float x) {
    return x * x;
}

float cubed(float x) {
    return x * x * x;
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

//Based on Newton - Raphson algorithm
double sqrt(double x) { 
    double x_new, error, starter;

    if(x < 0) {
        puts("MATH ERROR: Inside of root can't be less than zero");
        return 0;   
    }
    starter = x / 2.0; 
    error = epsilon + 1.0; 

    while (error > epsilon) {
        x_new = ( starter + (x / starter) ) / 2.0; 
        error = (x_new > starter) ? (x_new - starter) : (starter - x_new);
        starter = x_new;                    
    }

    return x_new;
}

//3. Absolute Value and Averaging**********************************************************************************************

float absolute(float x) {
    return (x < 0) ? -x : x;
}

float abs_diff(float x, float y) {
    return (x > y) ? (x - y) : (y - x); 
}

float average(float x, float y) {
    return (x + y) / 2;
}

//4. Modular Arithmetic and Reciprocal**********************************************************************************************

//Based on Basic Divison Algorithm
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

float inverse(float x) {
    if(x == 0) {
        puts("MATH ERROR: Inverse of zero is not valid");
        return 0;
    }
    return 1 / x;
}

//5. Factorial Calculation**********************************************************************************************************

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

unsigned long long factorial_perm_comb(int x) {
    unsigned long long result = 1.0;
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

//6. Exponential and Logarithmic Functions**********************************************************************************************

//Based on Maclaurin series
double exp_e(double x) { 
    int n;
    double term, result = 0.0;
    
    for(n = 0; n < MAX_ITE; n++) {
        term = power(x, n) / factorial(n);
        result += term;
    }
    return result;
}

//Based on Newton - Raphson Method
float ln(float a) { 
    double epsilon = 0.000001; 
    float ln_b, fx, dfx;
    float starter = 1; 

    if(a <= 0) {
        puts("MATH ERROR: Logarithm of non-positive number");
        return 0;
    }

    for(int i = 0; i < MAX_ITE; i++) {
        fx = exp_e(starter) - a;
        dfx = exp_e(starter);
        ln_b = starter - (fx / dfx);

        if(abs_diff(ln_b , starter) < epsilon) 
            return ln_b;

        starter = ln_b;
    }
    return starter;
}

float log(float a, float b) {
    float ln_a, ln_b; 

    if(a <= 0 || b < 0 || a == 1) {
        puts("MATH ERROR: Invalid logarithm arguments");
        return 0;
    }
    ln_b = ln(b);
    ln_a = ln(a);

    return ln_b / ln_a;
}

//7. Special Constants*************************************************************************************************************




//8. Geometry Functions*************************************************************************************************************

//Based on Pythagorean Theorem
float hypo(float a, float b)  { 
    return sqrt(squared(a) + squared(b));
}

//9. Tyrigonometric Functions*************************************************************************************************************

//Angle conversions
double degree_to_radian(double angle) { 
    double radian;
    
    radian = (pi * angle) / 180.0;
    radian = mod(radian, 2 * pi);
    
    return radian;
}

double radian_to_degree(double angle) {
    double degree;
    
    degree = 180.0 * (angle / pi);
    degree = mod(degree, 360.0);
    
    return degree;
}

//Based on Taylor Series
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

//Based on Taylor Series
double cosinus(double x) { 
    double term = 0.0, result = 0.0;
    int n; 
    for(n = 0; n < 20; n++){
        term = (n % 2 == 0 ? 1.0 : -1.0);
        term *= power(x , 2 * n) / factorial(2 * n);
        result += term;
    }
    return result;
}

double tangent(double x) {
    if(cosinus(x) == 0) {
        puts("MATH ERROR: ");
    }
    return sinus(x) / cosinus(x);
}

double cotangent(double x) {
     if(sinus(x) == 0) {
        puts("MATH ERROR: Denominator can't be zero");
        return 0;
    }
    return cosinus(x) / sinus(x);
}

double secant(double x) {
    if(cosinus(x) == 0) {
        puts("MATH ERROR: Denominator can't be zero");
        return 0;
    }
    return 1 / cosinus(x);
}

double cosecant(double x) {
    if(sinus(x) == 0) {
        puts("MATH ERROR: Denominator can't be zero");
        return 0;
    }
    return 1 / sinus(x);
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
        
        if(abs_diff(y_new, y_start) < epsilon) {
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
        
        if(abs_diff(y_new, y_start) < epsilon) {
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
        
        if(abs_diff(y_new , y_start) < epsilon) {
            return y_new;
        }
        y_start = y_new;
    }
    puts("The approximation couldn't have been done successfully");
    return y_new;
}

double arccotangent(double x) {
    return (pi / 2 - arctangent(x));
}

double arcsecant(double x) {
    return arccosinus(1 / x);
}

double arccosecant(double x) {
    return arcsinus(1 / x);
}

//10. Permutaion and Combination*************************************************************************************************************

unsigned long long permutation(int n, int r) {
    return factorial_perm_comb(n) / factorial_perm_comb(n - r);
}

unsigned long long combination(int n, int r) {
    return factorial_perm_comb(n) / (factorial_perm_comb(r) * factorial_perm_comb(n - r));
}

