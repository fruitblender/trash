#include <stdio.h>
#include "complex.h"

int main() {

    Complex c1 = {2, 3};
    Complex c2 = {4, 5};

    Complex sum = add_complex(c1, c2);
    Complex product = mul_complex(c1, c2);
 
    printf("Addition = %.2f + %.2fi\n",
           sum.real, sum.imag);

    printf("Multiplication = %.2f + %.2fi\n",
           product.real, product.imag);

    return 0;
}


// Compile object file: gcc -c complex.c 
//Creates: complex.o
// Create static library: ar rcs libcomplex.a complex.o
// Link test program: gcc test.c -L. -lcomplex -o test
//./test