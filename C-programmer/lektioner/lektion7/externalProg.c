	
// In file external-prog.c

#include <stdio.h>

int gv = 5;  // A global variable. 
             // The definition which allocates storage.
             // Storage class external per default.

void h(void); 

void f (void){
  // ...
  gv += 2;
  // ...
}

void g (void){
  // ...
  printf("The global variable gv = %d\n", gv  );
  // ...
}
  

int main(void) {
        // gv is 5
  f();  //       7
  h();  //       8
  g();  
  
  return 0;
}