#include <stdio.h>

enum days {sunday, monday, tuesday, wednesday, thursday, 
           friday, saturday};

/* Tedious function. An alternative version appears later in this lecture */
enum days  next_day_of(enum days  d){
  enum days  next_day;
  switch (d){
    case sunday: next_day = monday; 
      break;
    case monday: next_day = tuesday;
      break;
    case tuesday: next_day = wednesday;
      break;
    case wednesday: next_day = thursday;
      break;
    case thursday: next_day = friday;
      break;
    case friday: next_day = saturday;
      break;
    case saturday: next_day = sunday;
      break;
  }
  return next_day;
}  

void prnt_day(enum days d){
  switch (d) {
    case sunday: printf("Sunday");
       break;
    case monday: printf("Monday");
       break;
    case tuesday: printf("Tuesday");
       break;
    case wednesday: printf("Wednesday");
       break;
    case thursday: printf("Thursday");
       break;
    case friday: printf("Friday");
       break;
    case saturday: printf("Saturday");
       break;
  }
}   

int main(void){
  
  enum days day1 = saturday,  another_day;
  int i;

  printf("Day1 is %d\n", day1);

  printf("Day1 is also "); prnt_day(day1); printf("\n");

  another_day = day1;
  for(i = 1; i <= 3; i++)
    another_day = next_day_of(another_day);
  
  printf("Three days after day1: ");  prnt_day(another_day); 
  printf("\n");

  return 0;
}    

