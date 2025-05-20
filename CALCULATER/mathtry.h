#ifndef MATHTRY_H
#define MATHTRY_H

extern double pi;
extern double epsilon;

enum MathError {
    MATH_SUCCESS = 0,
    ERROR_DIV_BY_ZERO = -1,
    ERROR_ZERO_POWER = -2,
    ERROR_NEGATIVE_SQRT = -3
    
};

float sum(float x, float y);
float subtract(float x, float y);
float multiply(float x, float y);
float divide(float x, int y);

float squared(float x);
float cubed(float x);
double power(double x, int y);
double sqrt(double x);

float absolute(float x);
float abs_diff(float x, float y);
float average(float x, float y);

double mod(double x, double y);
float inverse(float x);

double factorial(int x);
unsigned long long factorial_perm_comb(int x);

double exp_e(double x);
float ln(float a);
float log(float a, float b);

float hypo(float a, float b);

double degree_to_radian(double angle);
double radian_to_degree(double angle);
double sinus(double x); 
double cosinus(double x);
double tangent(double x);
double cotangent(double x);
double secant(double x);
double cosecant(double x);
double arcsinus(double x);
double arccosinus(double x);
double arctangent(double x);
double arccotangent(double x);

unsigned long long permutation(int n, int r);
unsigned long long combination(int n, int r);

#endif





/*
#ifndef MATHTRY_H     
#define MATHTRY_H     

// ...the function types...

#endif                 

*/