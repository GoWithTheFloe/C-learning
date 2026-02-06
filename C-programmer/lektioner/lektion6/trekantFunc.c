#include <stdio.h>
#include <math.h>

double sum_of_sides(double p1_x, double p1_y, 
                    double p2_x, double p2_y,
                    double p3_x, double p3_y);
void print_sum(double sum);
double calc_side(double pA_x,double pA_y,double pB_x,double pB_y);

int main(void)
{
  double p1_x, p1_y; /* Point 1's coordinates */
  double p2_x, p2_y; /* Point 2's coordinates */
  double p3_x, p3_y; /* Point 3's coordinates */
  double sum;

  // læs punkterne ind
  printf("Tast punkt 1:\n");
  scanf(" %lf %lf", &p1_x, &p1_y);
  
  printf("Tast punkt 2:\n");
  scanf(" %lf %lf", &p2_x, &p2_y);

  printf("Tast punkt 3:\n");
  scanf(" %lf %lf", &p3_x, &p3_y);

  sum = sum_of_sides(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y);

  print_sum(sum);

  return 0;
}

void print_sum(double sum){
  printf("Summen hele vejen rundt var %lf!!! Hurra!!!\n\n", sum);
  return;
}

double sum_of_sides(double p1_x, double p1_y, 
                    double p2_x, double p2_y,
                    double p3_x, double p3_y){
  double side12, side23, side31;

  side12 = calc_side(p1_x, p1_y, p2_x, p2_y);
  side23 = calc_side(p2_x, p2_y, p3_x, p3_y);
  side31 = calc_side(p3_x, p3_y, p1_x, p1_y);
  return side12 + side23 + side31;
}

double calc_side(double pA_x,double pA_y,double pB_x,double pB_y){
  double delta_x = pA_x - pB_x;
  double delta_y = pA_y - pB_y;

  double side = sqrt(pow(delta_x,2) + pow(delta_y,2));
  return side;  
}
