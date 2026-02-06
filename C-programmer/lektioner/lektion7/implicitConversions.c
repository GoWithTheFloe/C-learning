#include <stdio.h>

int main(void) {

  short s = 12; 
  char c = 'a';     /* c is an one byte integer with the value 97 */

  double d = 123456.7;
  float f = 4322.1F;

  int i;
 
  printf("c - s = %i is converted to int\n", c - s);
  /* INTEGRAL PROMOTION: The type of c - s is promoted to int */
  
  printf("d + f = %f is converted to a double\n", d + f);
  /* WIDENING: f is converted to double before adding the numbers */

  i = d;
  printf("In assigning d to i %f is demoted to the int %i\n", d, i);
  /* NARROWING: d is converted to an int - information is lost */
  
  return 0;
}