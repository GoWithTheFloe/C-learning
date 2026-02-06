#include <stdio.h>

void main (){
printf("Enter an integer> ");
scanf(" %d", &product);
int product;
int count = 0;

while (count < 4) {
 printf("%d\n", &product);
 product *= product;
 count += 1;
}
}