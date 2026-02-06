#include <stdio.h>

typedef double (*binary_double_fn)(double, double);

double plus(double a, double b){
    return a + b;
}

double minus(double a, double b){
    return a - b;
}

int main(void){
    double result;
    double *resultp;
    //double (*fn)(double, double);
    binary_double_fn fn;

    result = 7;
    resultp = &result;
    fn = minus;
    //fn = &plus;

    //result = (*fn)(5.0, 7.0);
    result = fn(5.0, 7.0);
    
    printf("Result: %f\n", result);

    return 0;

}