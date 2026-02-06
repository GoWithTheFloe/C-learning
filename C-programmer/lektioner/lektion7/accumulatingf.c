#include <stdio.h>

int accumulating_f(int input){
    int result;

    // if not static, it will not save the old value
    static int previous_result = 1;

    if (previous_result == 1) result = input;
    else result = previous_result * input;

    previous_result = result;
    return result;

}

int main(void){
    int i;

    for(i = 0; i < 10; i++)
        printf("accumulating_f(%d) = %d\n", 3, accumulating_f(3));

    return 0;

}