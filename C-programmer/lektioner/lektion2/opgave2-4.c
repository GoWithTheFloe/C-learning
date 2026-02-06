#include <stdio.h>

int main(void) {

  double d, e, f, g;

  printf("Enter three real numbers: ");
  scanf("%lf %lf %lf", &d, &e, &f);
  
  g = (d + e + f) / 3.0;

  printf("The average is: %f\n", g);
    
  return 0;
}
