#include <stdio.h>
#include <stdlib.h>

void make_lasagne(int portion);
void make_lasagne_plates(int portion);
void make_white_sauce(int portion);
void make_meat_sauce(int portion);

int main(void) {
  int size;
 
  // Promt for size:
  printf("How large a portion do you want? ");
  scanf("%d", &size);

  // Make some food:
  make_lasagne(size);

  return 0;
}

void make_lasagne(int portion) {
  make_lasagne_plates(portion);
  make_white_sauce(portion);
  make_meat_sauce(portion);
  
  mix plates, meat sauce, and white sauce;

  sprinkle with paramesan cheese;
  bake 15 minutes at 225 degrees;  
}

void make_lasagne_plates(int portion) {
  get appropriate amounts of ingredients according to portion;
  mix flour, egs, salt and oil;
  process the pasta in the pasta machine;
}

void make_white_sauce(int portion) {
  get appropriate amounts of ingredients according to portion;
  melt butter and stir in some flour;
  add milk and boil the sauce;
}

void make_meat_sauce(int portion){
  get appropriate amounts of ingredients according to portion;
  chop the onion, and add meat, salt and pebber;
  add tomatos and garlic;
  boil the sauce 10 minutes;
}