#include <stdio.h>  

int threeNumberAverage(void){
    int i;

    float nums[3];

    float sum = 0.0;

    float divided_number = 3.0;

    char tr[] = "The average of ";

    printf("This calculater will calculate the average number of three numbers \n");


        for (i=0; i < 3; i++){
            printf("Give me a number %d: ", i+1);
            scanf("%f", &nums[i]);
            sum += nums[i];

        }
    printf("%s %f, %f, and %f is: %f", tr, nums[0], nums[1], nums[2], sum / divided_number);
    return 0;

}
int main(void){
    
    threeNumberAverage();
    
    return 0;
}