
#include <stdio.h>
#include <math.h>

int main(void){
    double p1_x, p1_y;
    double p2_x, p2_y;
    double delta_x, delta_y;
    double length;

    //Brugeren angicer et linjestykke som to punkter i planet
    //Indlæs punkt 1
    printf("Indtast punkt 1(x-koordinat mellemrum y-koordinat -- efterfulgt af enter): ");
    scanf("%lf %lf", &p1_x, &p1_y);

    //Indlæs punkt 2
    printf("Indtast punkt 2(x-koordinat mellemrum y-koordinat -- efterfulgt af enter): ");
    scanf("%lf %lf", &p2_x, &p2_y);

    //Vores program skal udregne længden.
    delta_x = p2_x - p1_x;
    delta_y = p2_y - p1_y;
    length = sqrt(delta_x * delta_x + delta_y *delta_y);

    //Programmet skriver længden ud
    printf("The length is: %lf \n", length);

    return 0;
}

