#include <stdio.h>
#include "math.h"

int main() {

    Complex c = {3, 4};

    float magnitude = abs_complex(c);

    Complex square = power_complex(c);

    printf("Magnitude = %.2f\n", magnitude);

    printf("Square = %.2f + %.2fi\n",
           square.real, square.imag);

    return 0;
}

//Create shared library: gcc -fPIC -shared -o libmath.so math.c -lm
//Compile test program: gcc test.c -L. -lmath -Wl,-rpath,. -o test