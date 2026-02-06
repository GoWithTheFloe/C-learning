#include <stdio.h>

typedef double (*binary_double_fn)(double, double);

double combine_right(double a, double b, double c, double d, binary_double_fn combiner){
    return combiner(a, combiner(b, combiner(c, d)));
}

double combine_left(double a, double b, double c, double d, binary_double_fn combiner){
    return combiner(combiner(combiner(a, b), c), d);
}

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

double result;

  result = combine_right(5, 7, 8, 11, &minus);  /* minus(5, minus(7, minus(8, 11))) = 5 - (7 - (8 - 11)) = -5 */
  printf("Minus combination result: %f\n", result);

  result = combine_right(5, 7, 8, 11, &plus); 
  printf("Plus combination result: %f\n", result);

  result = combine_right(5, 7, 8, 11, &min); 
  printf("Min combination result: %f\n", result);

  result = combine_right(5, 7, 8, 11, &max); 
  printf("Max combination result: %f\n", result);

    //SKIFTER SIDE

  result = combine_left(5, 7, 8, 11, &minus);   /* minus(minus, minus(5, 7), 8), 11) = ((5 - 7) - 8) - 11 = -21 */
  printf("Minus combination result: %f\n", result);


  return 0;

}