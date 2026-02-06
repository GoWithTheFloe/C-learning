#include "char-graphics.h"

void prn_match_girl(void);
void prn_head(void);
void prn_arms(void);
void prn_body(void);
void prn_legs(void);

int main(void){
  prn_match_girl();
  return 0;
}

void prn_match_girl(void){
  prn_head();
  prn_arms();
  prn_body();
  prn_legs();
}

void prn_head(void){
  prn_circle();
}

void prn_arms(void){
  prn_horizontal_line();
}

void prn_body(void){
  prn_reverse_v();
  prn_horizontal_line();
}

void prn_legs(void){
  prn_reverse_v();
}