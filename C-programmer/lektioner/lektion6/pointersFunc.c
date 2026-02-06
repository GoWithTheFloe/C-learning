	
#include <stdio.h>

/* Output: We pass pointers two variables to g. 
   Scanf receives these pointers. Scanf can hereby affect variables in main. */

void g(int *fp1, int *fp2){
  printf("Enter two integers: ");
  scanf(" %d %d", fp1, fp2);
}

int main(void) {

  int i, j;   /* Not initialized */
  
  g(&i, &j);  
  printf("i + j = %d + %d = %d\n", i, j, i + j);
  
  return 0;
}