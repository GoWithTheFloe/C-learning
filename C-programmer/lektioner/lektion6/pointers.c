	
#include <stdio.h>


int main(void) {

  int a = 7, x = 8;
  double b = 7.89, y = 1.2;

  // *pa og *pb henvises til adresserne &a og &b
  int *pa = &a;
  double *pb = &b;
  
  // nu assignes adresserne værdier, som ryger tilbage på adressen, altså &a og &b
  *pa = x;
  *pb = y;
  
  printf("a = %d, b = %f\n", a, b);

  int c[3] = {7,8,9};
  // *pc ingår i en typebetegnelse. er en pointer til int. indgår i en erklæring. Erklæringen af pa.
  int *pc = &c[0];

  pc += 2;

  // *pa er en dereferencing operator. - udtryk 
  printf("pa points at %d\n", *pc);
  return 0;
}