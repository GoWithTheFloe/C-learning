#include <stdio.h>

double run_calculator(void);
void scan_data(char *operator_ptr, double *operand_ptr);
int is_binary_operator(char operator);
void do_next_op(char operator, double oprerand, double *accumulator_ptr);
void print_result(double accumulator, int final);

int main(void){

    double final_value = run_calculator();
    /* run_calculator kan allerede printe final result,
       men her har vi adgang til slutværdien hvis vi vil bruge den. */
    (void)final_value; /* undgå compiler-warning hvis ikke brugt */
    return 0;


}

/* Driverfunktionen: kører loop og returnerer sluttal */
double run_calculator(void){
    double accumulator = 0.0;
    char op = '\0';
    double operand = 0.0;

    //scan_data();
    //do_next_op();

    /* TODO: implementér input-loop der kalder scan_data og do_next_op */
    while(1){
        // Læs operator (og evt operand)
        scan_data(&op, &operand);
        
        // Stop hvis brugeren skriver "q"
        if(op == 'q'){
            //udskriv final result og return
            print_result(accumulator, 1);
            return accumulator;
        }

        //
        do_next_op(op, operand, &accumulator);

        // Vis resultatet indtil videre
        print_result(accumulator, 0);
    }

    return accumulator;

}

/* Læs operator (char) og evt operand (double)
   Output sker via pointers */
void scan_data(char *operator_ptr, double *operand_ptr){
    /* TODO: læs operator med scanf/gets, hvis binær -> læs operand */
    /* Sæt *op_ptr og *operand_ptr */
    printf("Enter operator: ");

    if (scanf(" %c", operator_ptr) != 1) {
        /* Hvis scanf fejler, sæt operator til 'q' for at afslutte pænt */
        *operator_ptr = 'q';
        *operand_ptr = 0.0;
        return;
    }

    if (is_binary_operator(*operator_ptr)) {
        printf("Enter operand: ");
        if(scanf(" %lf", operand_ptr) != 1) {
            *operand_ptr = 0.0;
        }

    } else {
        *operand_ptr = 0.0;
    }

}

/* Returner 1 hvis op er en binær operator (+ - * / ^), ellers 0 */
int is_binary_operator(char operator){
        /* TODO: return 1 eller 0 */


    if(operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^')
    {
        return 1;
    } else /*if (operator == '#')*/ {
        
        return 0;
    }
}

/* Udfør operationen på *accumulator_ptr baseret på op og operand.
   For unære operatorer ignoreres operand.
   Ulovlige operationer skal lade accumulator uændret. */
void do_next_op(char operator, double operand, double *accumulator_ptr){
    /* TODO: implementér cases for + - * / ^ og # % ! q */
    /* For nu: gør ingenting (akkumulator uændret) -> dette er til test af input-flow */
switch (operator) {
    case '+':
        *accumulator_ptr = *accumulator_ptr + operand;
        break;
    case '-':
        *accumulator_ptr = *accumulator_ptr - operand;
        break;
    case '/':
        if (operand != 0.0) {
            *accumulator_ptr = *accumulator_ptr / operand;
        }
        break;
    case '%':
        *accumulator_ptr = -(*accumulator_ptr);
        break;
    /* ... flere cases ... */
    default:
        /* ugyldig operator -> gør intet */
        break;
    
}

}

/* Print */
void print_result(double accumulator, int final){
    if(final) printf("Final result is: %f\n", accumulator);
    else printf("Result so far is : %f. \n", accumulator);
}
