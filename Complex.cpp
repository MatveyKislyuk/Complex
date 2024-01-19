#include "Complex.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

const double Epsilon = std::numeric_limits<double>::epsilon();

template<typename T>
Complex<T>::Complex(T real, T imag) : real(real), imaginary(imag) {}

template<typename T>
void Complex<T>::setReal(T rl) {
    real = rl;
}

template<typename T>
void Complex<T>::setImaginary(T img) {
    imaginary = img;
}

template<typename T>
T Complex<T>::getReal() const {
    return real;
}

template<typename T>
T Complex<T>::getImaginary() const {
    return imaginary;
}

template<typename T>
Complex<T> Complex<T>::operator+(const Complex<T> &other) const {
    return Complex<T>(real + other.real, imaginary + other.imaginary);
}

template<typename T>
Complex<T> Complex<T>::operator-(const Complex<T> &other) const {
    return Complex<T>(real - other.real, imaginary - other.imaginary);
}

template<typename T>
Complex<T> Complex<T>::operator*(const Complex<T> &other) const {
    T newReal = (real * other.real) - (imaginary * other.imaginary);
    T newImaginary = (real * other.imaginary) + (imaginary * other.real);
    return Complex<T>(newReal, newImaginary);
}

template<typename T>
Complex<T> Complex<T>::operator/(const Complex<T> &other) const {
    T denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
    if (std::abs(denominator) < Epsilon) {
        throw std::runtime_error("Division by zero");
    }
    T newReal = ((real * other.real) + (imaginary * other.imaginary)) / denominator;
    T newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / denominator;
    return Complex<T>(newReal, newImaginary);
}

template<typename T>
bool Complex<T>::operator==(const Complex<T> &other) const {
    return std::abs(real - other.real) < Epsilon &&
           std::abs(imaginary - other.imaginary) < Epsilon;
}

template<typename T>
bool Complex<T>::operator==(const int value) const {
    return std::abs(real - static_cast<T>(value)) < Epsilon &&
           std::abs(imaginary) < Epsilon;
}

template<typename T>
bool Complex<T>::operator==(const double value) const {
    return std::abs(real - static_cast<T>(value)) < Epsilon &&
           std::abs(imaginary) < Epsilon;
}

template<typename T>
Complex<T> Complex<T>::power(int exponent) const {
    T r = std::pow(getModulus(), exponent);
    T theta = std::atan2(imaginary, real) * exponent;
    return Complex<T>(r * std::cos(theta), r * std::sin(theta));
}

template<typename T>
T Complex<T>::getModulus() const {
    return std::sqrt((real * real) + (imaginary * imaginary));
}

template<typename T>
void Complex<T>::display() const {
    std::cout << std::fixed << std::setprecision(2) << real;
    if (imaginary >= T(0)) {
        std::cout << " + " << imaginary << "i";
    } else {
        std::cout << " - " << -imaginary << "i";
    }
    std::cout << std::endl;
}

template
class Complex<double>;

template
class Complex<float>;

template
class Complex<int>;
