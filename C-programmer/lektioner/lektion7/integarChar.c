#include <stdio.h>

int main(void){
    int i = 65;
    int j = 66;
    int k = 67;
    char cha = 'a';
    char chb = 'b';
    char chc = 'C';

    printf("i = %d, i = %c\n", i, i);
    printf("i = %d, i = %c\n", j, j);
    printf("i = %d, i = %c\n", k, k);
    printf("ch = %d, ch = %c\n", cha, cha);
    printf("ch = %d, ch = %c\n", chb, chb);
    printf("ch = %d, ch = %c\n", chc+1, chc+1);

    int a = '!' + '%';

    printf("i = %d, i = %c\n", a, a);

    return 0;

}