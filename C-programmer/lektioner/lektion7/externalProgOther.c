// In file external-prog-other.c

extern int gv;  // A declaration of gv.
                // Does not allocate storage.
                // gv is defined elsewhere.
void h(void){
  // ...
  gv++;
  // ...
}