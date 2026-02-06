#include <stdio.h>  


int main(void){

    char gmt[] = "Give me three different digits";
    char tr[] = "The result";

    float first_digit, second_digit, third_digit;

    float divided_number = 3.0;

    printf("%s: \n", gmt);
  
    scanf("%f %f %f", &first_digit, &second_digit, &third_digit);   
    printf("%s: %f\n", tr, (first_digit + second_digit + third_digit) / divided_number);  
    
    return 0;
;}