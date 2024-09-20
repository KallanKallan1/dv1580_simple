#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <math.h>


int is_number(const char *str) { 
    char *endptr; 
    errno = 0; // Reset errno before the call 
 
    long val = strtol(str, &endptr, 10); 
 
    // Check for various conditions 
    if (errno == ERANGE || (endptr == str)) { 
        return 0; // Not a number 
    } 
 
    return 1; // It's a number 
} 
 
int main(int argc, char *argv[]) {

    if (!is_number(argv[1]) || !is_number(argv[2])) {
        fprintf(stderr, "Both arguments must be real numbers.\n");
        return 1;
    }

    double a1 = atof(argv[1]);
    double a2 = atof(argv[2]);
    double result = a1 * a2;

    printf("Result: %.4f\n", result);

    return 0;
}


