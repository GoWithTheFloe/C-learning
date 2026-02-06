#include <stdio.h>

int main(void) {

    char operator;
    
    printf("Choose an operator ['+', '-', '*', '/']: ");
    scanf(" %c", &operator);

    double num1, num2;

    printf("Enter first number: ");
    scanf(" %lf", &num1);

    printf("Enter second number: ");
    scanf(" %lf", &num2);

    double result;

    switch(operator) {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            result = num1 / num2;
            break;
    }

    printf("The result of %.2lf %c %.2lf is %.2lf", num1, operator, num2, result);




}