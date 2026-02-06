#include <stdio.h>
#include <stdlib.h>

void make_lasagne(void);
void make_lasagne_plates(void);
void make_white_sauce(void);
void make_meat_sauce(void);

int main(void) {
  make_lasagne();
  return 0;
}

void make_lasagne(void) {
  make_lasagne_plates();
  make_white_sauce();
  make_meat_sauce();
  
  mix plates, meat sauce, and white sauce;
  sprinkle with paramesan cheese;
  bake 15 minutes at 225 degrees;  
}

void make_lasagne_plates(void) {
  mix flour, egs, salt and oil;
  process the pasta in the pasta machine;
}

void make_white_sauce(void) {
  melt butter and stir in some flour;
  add milk and boil the sauce;
}

void make_meat_sauce(void){
  chop the onion, and add meat, salt and pebber;
  add tomatos and garlic;
  boil the sauce 10 minutes;
}