#include <stdio.h>

void match_girl(void);
void head(void);
void arms(void);
void body(void);
void legs(void);

void circle(void)
{
    printf("      *          \n");
    printf("    *   *        \n");
    printf("  *       *      \n");
    printf("  *       *      \n");
    printf("    *   *        \n");
    printf("      *          \n");
}

void horizontal_line(void)
{
    printf("-------------    \n");
}

void reverse_v(void)
{
    printf("     /\\         \n");
    printf("    /  \\        \n");
    printf("   /    \\       \n");
    printf("  /      \\      \n");
    printf(" /        \\     \n");
    printf("/          \\    \n");
}

int main(void)
{
  match_girl();
  return 0;
}

void match_girl(void)
{
    head();
    arms();
    body();
    legs();
}

void head(void)
{
    circle();
}

void arms(void)
{
    horizontal_line();
}

void body(void)
{
    reverse_v();
    horizontal_line();
} 

void legs(void)
{
    reverse_v();
}