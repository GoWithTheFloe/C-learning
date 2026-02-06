	
#include <stdio.h>

int main(void) {

  char c;
  long int y;
  float x;
  double z;

  c = 'A' + 10;                  /* 'A' is char 65. 'A' + 10 is the character 'K'. c becomes 'K' */

  // c bliver konverteret til long value i y
  y = (long) (c);                /* y becomes 75L */
  
  // Narrowing - indsnævring af y fra long int til int, og denne værdi bliver casted til float i x
  x = (float) ((int) y + 1);     /* x becomes 76.0F in type float */
  // Widening - x laves til double fra float, og ligges i double z
  z = (double) (x);              /* z becomes 76.0  in type double */

  printf("c: %c, y: %li, x: %f, z: %f", c, y, x, z);
  return 0;
}
