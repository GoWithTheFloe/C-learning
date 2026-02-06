#include <stdio.h>

double max(double, double);
double min(double, double);
double plus(double, double);
double minus(double, double);

double combine(double a, double b, double c, double d, 
                    double (*combiner)(double, double)){
  return combiner(a, combiner(b, combiner (c, d)));
}

int main(void) {
  double result;

  result = combine(5, 7, 8, 11, &minus);  /* minus(5, minus(7, minus(8, 11))) = 5 - (7 - (8 - 11)) = -5 */
  printf("Minus combination result: %f\n", result);

  result = combine(5, 7, 8, 11, &plus); 
  printf("Plus combination result: %f\n", result);

  result = combine(5, 7, 8, 11, &min); 
  printf("Min combination result: %f\n", result);

  result = combine(5, 7, 8, 11, &max); 
  printf("Max combination result: %f\n", result);

  return 0;
}

double max (double a, double b){
  return a > b ? a : b;
}

double min (double a, double b){
  return a > b ? b : a;
}

double plus(double a, double b){
  return a + b;
}

double minus(double a, double b){
  return a - b;
}