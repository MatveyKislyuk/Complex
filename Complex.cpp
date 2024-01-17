#include "Complex.h"
#include <iostream>
#include <cmath>
#include <iomanip>

Complex::Complex(double real, double imag) : real(real), imaginary(imag) {}


void Complex::setReal(double rl) {
    real = rl;
}

void Complex::setImaginary(double img) {
    imaginary = img;
}

double Complex::getReal() const {
    return real;
}

double Complex::getImaginary() const {
    return imaginary;
}


Complex Complex::operator+(const Complex &other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}


Complex Complex::operator-(const Complex &other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

Complex Complex::operator*(const Complex &other) const {
    double newReal = (real * other.real) - (imaginary * other.imaginary);
    double newImaginary = (real * other.imaginary) + (imaginary * other.real);
    return Complex(newReal, newImaginary);
}

Complex Complex::operator/(const Complex &other) const {
    double denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
    double newReal = ((real * other.real) + (imaginary * other.imaginary)) / denominator;
    double newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / denominator;
    return Complex(newReal, newImaginary);
}

bool Complex::equals(const Complex &other) const {
    return (real == other.real) && (imaginary == other.imaginary);
}

Complex Complex::power(int exponent) const {
    double r = std::pow(getModulus(), exponent);
    double theta = std::atan2(imaginary, real) * exponent;
    return Complex(r * std::cos(theta), r * std::sin(theta));
}

double Complex::getModulus() const {
    return sqrt((real * real) + (imaginary * imaginary));
}

void Complex::display() const {
    std::cout << std::fixed << std::setprecision(2) << real;
    if (imaginary >= 0) {
        std::cout << " + " << imaginary << "i";
    } else {
        std::cout << " - " << -imaginary << "i";
    }
    std::cout << std::endl;
}
