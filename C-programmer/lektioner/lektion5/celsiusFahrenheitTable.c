#include <stdio.h>

double fahrenheit_temperature(double celcius_temp){
  return (9.0 / 5.0) * celcius_temp + 32.0;
}

int main(void){
  double c;  

  printf("%-20s %-20s\n", "Celcius degrees", "Fahrenheit degrees");

  for (c = -30; c <= 45; c++)
    printf("%-20.2f %-20.2f\n", c, fahrenheit_temperature(c));
  
  return 0;
}