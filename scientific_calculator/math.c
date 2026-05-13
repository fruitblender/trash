#include <math.h>
#include "math.h"

float abs_complex(Complex c) {

    return sqrt((c.real * c.real) +
                (c.imag * c.imag));
}

Complex power_complex(Complex c) {

    Complex result;

    result.real = (c.real * c.real) -
                  (c.imag * c.imag);

    result.imag = 2 * c.real * c.imag;

    return result;
}