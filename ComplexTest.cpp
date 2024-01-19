#include "Complex.h"
#include <cassert>
#include <iostream>
#include <cmath>

int main() {
    Complex<double> compl1(1, -3);
    Complex<double> compl2(2, -2);
    Complex<double> compl3(2, 0);

    assert((compl1 + compl2) == (Complex<double>(3, -5)));

    assert((compl1 - compl2) == (Complex<double>(-1, -1)));

    assert((compl1 * compl2) == (Complex<double>(-4, -8)));

    assert((compl1 / compl2) == (Complex<double>(1, -0.5)));

    try {
        compl1 / Complex<double>(0, 0);
        assert(false);
    } catch (const std::runtime_error &e) {
        assert(std::string(e.what()) == "Division by zero");
    }

    assert(compl3 == 2);

    assert(compl1.power(2).getReal() - (-5.0) < 10e-9);
    assert(compl1.power(2).getImaginary() - 12.0 < 10e-9);

    assert(std::abs(compl1.getModulus() - sqrt(1 + 9)) < 10e-9);

    std::cout << "All tests passed." << std::endl;

    return 0;
}