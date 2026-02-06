/* Computes the sizes of some fundamental types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){

    printf("test 1\n");
    printf("\n");
    printf("Here are the sizes of some integral types:\n\n");

    printf("           int:%3u bytes\n", sizeof(int));
    printf("      unsigned:%3u bytes\n", sizeof(unsigned));
    printf("          long:%3u bytes\n", sizeof(long));
    printf(" unsigned long:%3u bytes\n", sizeof(unsigned long));
    printf("         short:%3u bytes\n", sizeof(short));
    printf("unsigned short:%3u bytes\n", sizeof(unsigned short));
    printf("          char:%3u byte \n", sizeof(char));
    printf("\n");


    // Her bruges headerfilen limits.h
    printf("test 2\n");
    printf("\n");
    printf("Here are the limits of some integral types:\n\n");

    printf("Min. int:            %12i   Max. int:            %12i\n", 
            INT_MIN, INT_MAX);
            
    printf("Min. unsigned int:   %12u   Max. unsigned int:   %12u\n", 
            0, UINT_MAX);

    printf("Min. long:           %12li   Max. long:           %12li\n", 
            LONG_MIN, LONG_MAX);

    printf("Min. unsigned long:  %12i   Max. unsigned long:  %12lu\n", 
            0, ULONG_MAX);

    printf("Min. short:          %12hi   Max. short:          %12hi\n", 
            SHRT_MIN, SHRT_MAX);

    printf("Min. unsigned short: %12hu   Max. unsigned short: %12hu\n", 
            0, USHRT_MAX);

    printf("\n");

    // Her bruges headerfilen float.h
    printf("test 3\n");
    printf("\n");

    printf("Min. float:       %20.16e  \nMax. float:       %20.16e\n\n", 
            FLT_MIN, FLT_MAX);
            
    printf("Min. double:      %20.16le \nMax. double:      %20.16le\n\n", 
            DBL_MIN, DBL_MAX);

    printf("Min. long double: %26.20Le \nMax. long double: %26.20Le\n\n", 
            LDBL_MIN, LDBL_MAX);
    
    return 0;
}
