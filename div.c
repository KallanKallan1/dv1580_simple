#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 

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
        printf("Both arguments must be numbers.\n");
        return 1;
    }

    double a1 = strtod(argv[1], NULL);
    double a2 = strtod(argv[2], NULL);

    if (a2 == 0.0) {
        printf("DIV ZERO NOT ALLOWED!\n");
        return 1;
    }

    printf("%.4f\n", a1 / a2);
    
    return 0;
}
