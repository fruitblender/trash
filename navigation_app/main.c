#include <stdio.h>
#include "geometry.h"

int main() {

    Complex c = {3, 4};

    printf("Magnitude = %.2f\n",
           magnitude(c));

    printf("Phase = %.2f radians\n",
           phase(c));

    return 0;
}

//compile object file: gcc -c geometry.c
//create static library: ar rcs libgeometry.a geometry.o
//compile main program: gcc main.c -L. -lgeometry -lm -o main
//./main
