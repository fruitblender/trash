#include "complex.h"

Complex add_complex(Complex c1, Complex c2) {
    Complex result;

    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;

    return result;
}

Complex mul_complex(Complex c1, Complex c2) {
    Complex result;

    result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result.imag = (c1.real * c2.imag) + (c1.imag * c2.real);

    return result;
}