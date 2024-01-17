#include "Complex.h"
#include <cassert>
#include <iostream>
#include <cmath>

int main() {
    Complex compl1(1, -3);
    Complex compl2(2, -2);

    assert((compl1 + compl2).equals(Complex(3, -5)));

    assert((compl1 - compl2).equals(Complex(-1, -1)));

    assert((compl1 * compl2).equals(Complex(-4, -8)));

    assert((compl1 / compl2).equals(Complex(1, -0.5)));

    assert(compl1.power(2).getReal() - (-5.0) < 10e-9);
    assert(compl1.power(2).getImaginary() - 12.0 < 10e-9);

    assert(std::abs(compl1.getModulus() - sqrt(1 + 9)) < 10e-9);

    std::cout << "All tests passed." << std::endl;

    return 0;
}