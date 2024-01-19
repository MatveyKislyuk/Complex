#include "ComplexNumber.h"
#include <cassert>
#include <iostream>
#include <cmath>

int main() {
    ComplexNumber<double> z1(1, 2);
    ComplexNumber<double> z2(3, 4);
    ComplexNumber<double> z3(5, 8);
    ComplexNumber<double> z4(2, 3);
    ComplexNumber<double> z5(2, 3);
    ComplexNumber<double> z6(4, 5);
    ComplexNumber<double> z7(1, -3);
    ComplexNumber<double> z8(2, -2);
    ComplexNumber<double> z9(5, 0);

    assert((z1 + z2) == (ComplexNumber<double>(4, 6)));

    assert((z3 - z4) == (ComplexNumber<double>(3, 5)));

    assert((z5 * z6) == (ComplexNumber<double>(-7, 22)));

    assert((z7 / z8) == (ComplexNumber<double>(1, -0.5)));

    try {
        z1 / ComplexNumber<double>(0, 0);
        assert(false);
    } catch (const std::runtime_error &e) {
        assert(std::string(e.what()) == "Division by zero");
    }

    assert(z7.power(2).getReal() - (-5.0) < 10e-9);
    assert(z7.power(2).getImaginary() - 12.0 < 10e-9);

    assert(std::abs(z7.getModulus() - sqrt(1 + 9)) < 10e-9);

    assert(z9 == 5);

    std::cout << "All tests passed." << std::endl;

    return 0;
}