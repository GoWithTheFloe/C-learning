
#include <stdio.h>
#include <math.h>

int main(void){
    double p1_x, p1_y;
    double p2_x, p2_y;
    double p3_x, p3_y;
    double delta_x1, delta_y1;
    double delta_x2, delta_y2;
    double delta_x3, delta_y3;
    double length, length1, length2, length3;
    double area;
    double s;

    //Brugeren angicer et linjestykke som to punkter i planet
    //Indlæs punkt 1
    printf("Indtast punkt 1(x-koordinat mellemrum y-koordinat -- efterfulgt af enter): ");
    scanf("%lf %lf", &p1_x, &p1_y);

    //Indlæs punkt 2
    printf("Indtast punkt 2(x-koordinat mellemrum y-koordinat -- efterfulgt af enter): ");
    scanf("%lf %lf", &p2_x, &p2_y);

    //Indlæs punkt 3
    printf("Indtast punkt 3(x-koordinat mellemrum y-koordinat -- efterfulgt af enter): ");
    scanf("%lf %lf", &p3_x, &p3_y);

    //Vores program skal udregne længderne af hver linje
    delta_x1 = p2_x - p1_x;
    delta_y1 = p2_y - p1_y;
    length1 = sqrt(delta_x1 * delta_x1 + delta_y1 *delta_y1);

    delta_x2 = p3_x - p2_x;
    delta_y2 = p3_y - p2_y;
    length2 = sqrt(delta_x2 * delta_x2 + delta_y2 *delta_y2);

    delta_x3 = p1_x - p3_x;
    delta_y3 = p1_y - p3_y;
    length3 = sqrt(delta_x3 * delta_x3 + delta_y3 *delta_y3);

    length = length1 + length2 + length3;


    //dividerer omkredsen med 2
    s = (length1 + length2 + length3)/2;

    //Udregner arealet
    area = sqrt(s*(s-length1)*(s-length2)*(s-length3));


    //Programmet skriver længden ud
    printf("The length of the coordinates are %lf, %lf, and %lf \n", length1, length2, length3);
    printf("The circumference of the triangle is %lf \n", length);
    printf("The area of the triangle is %lf \n", area);


    return 0;
}

