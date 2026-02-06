#include <stdio.h>
#include "primes.h"

int main(void) {

    int i = 1, j = 1, n;

    printf("How many primes do you want to see: \n");
    scanf(" %d", &n);

    while (j <= n) {
        if (is_prime(i)){
            printf("prime %d: %d \n", j, i);
            j++;
            i++;
        } else {
            i++;
        }
    }
    
    return 0;

}