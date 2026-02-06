	
int main(void) {

  int a = 1;                /* a is an integer */
  const int b = 1;          /* b is a constant integer */

  const int *c = &b;        /* c is pointer to a constant integer */  
 
  int *const d = &a;        /* d is a constant pointer to an integer */   

  const int *const e = &a;  /* d is a constant pointer to a constant integer */   

  c = &a;                   /* OK - the pointer in c is not constant */
  *c = 2;                   /* NOT OK */

  d = &b;                   /* NOT OK. d is a constant pointer */
  *d = 3;                   /* OK - the integer pointed to is not constant */

  e = &b;                   /* NOT OK. e is a constant pointer */
  *e = 4;                   /* NOT OK. *e is a constant integer */

  return 0;
}