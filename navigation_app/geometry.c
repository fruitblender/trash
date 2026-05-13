#include <math.h>
#include "geometry.h"

float magnitude(Complex c) {

    return sqrt((c.real * c.real) +
                (c.imag * c.imag));
}

float phase(Complex c) {

    return atan2(c.imag, c.real);
}