#include <stdio.h>
#include <stdlib.h>

double max(double a, double b){
    return a > b ? a:b;
}

double min(double a, double b){
    return a > b ? b:a;
}

double plus(double a, double b){
    return a + b;
}

double minus(double a, double b){
    return a - b;
}

int main(void){
    double (*fn)(double, double);
    double result;
    int i, choice;

    for (i = 1; i <= 4; ++i){

        
        printf("Which function (1: max, 2: min, 3: plus, 4: minus):\n");
        scanf(" %d", &choice);

        switch(choice){
            case 1: fn = max; break;
            case 2: fn = min; break;
            case 3: fn = plus; break;
            case 4: fn = minus; break;
            default: exit(-1);
        }

        result = fn(5.0, 7.0);
        printf("Result: %f\n", result);

    }
    
    return 0;

}