#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	printf("Specifier for char: %c\n", 'A');
	printf("Specifier for short: %hd\n", 12345);
	printf("Specifier for int: %d\n", 1234567890);
	printf("Specifier for int: %c\n", 66);
	printf("Specifier for long: %ld\n", 1234567890123456L);
	printf("Specifier for float: %f\n", 3.14159f);
	printf("Specifier for double: %lf\n", 3.14159265359);



    printf("Size of char: %lu bytes\n", sizeof(char));
    printf("Minimum value of char: %d\n", CHAR_MIN);
    printf("Maximum value of char: %d\n\n", CHAR_MAX);


    printf("Size of short: %lu bytes\n", sizeof(short));
    printf("Minimum value of short: %d\n", SHRT_MIN);
    printf("Maximum value of short: %d\n\n", SHRT_MAX);


    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Minimum value of int: %d\n", INT_MIN);
    printf("Maximum value of int: %d\n\n", INT_MAX);


    printf("Size of long: %lu bytes\n", sizeof(long));
    printf("Minimum value of long: %ld\n", LONG_MIN);
    printf("Maximum value of long: %ld\n\n", LONG_MAX);


    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Minimum value of float: %f\n", -FLT_MAX);
    printf("Maximum value of float: %f\n\n", FLT_MAX);


    printf("Size of double: %lu bytes\n", sizeof(double));
    printf("Minimum value of double: %lf\n", -DBL_MAX);
    printf("Maximum value of double: %lf\n\n", DBL_MAX);

    return 0;
}
