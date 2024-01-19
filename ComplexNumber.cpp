#include <limits>
#include "ComplexNumber.h"
#include <iostream>
#include <cmath>
#include <iomanip>


const double Epsilon = std::numeric_limits<double>::epsilon();

template<typename T>
ComplexNumber<T>::ComplexNumber(T real, T imag) : real(real), imaginary(imag) {}

template<typename T>
void ComplexNumber<T>::setReal(T rl) {
    real = rl;
}

template<typename T>
void ComplexNumber<T>::setImaginary(T img) {
    imaginary = img;
}

template<typename T>
T ComplexNumber<T>::getReal() const {
    return real;
}

template<typename T>
T ComplexNumber<T>::getImaginary() const {
    return imaginary;
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::operator+(const ComplexNumber<T> &other) const {
    return ComplexNumber<T>(real + other.real, imaginary + other.imaginary);
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::operator-(const ComplexNumber<T> &other) const {
    return ComplexNumber<T>(real - other.real, imaginary - other.imaginary);
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::operator*(const ComplexNumber<T> &other) const {
    T newReal = (real * other.real) - (imaginary * other.imaginary);
    T newImaginary = (real * other.imaginary) + (imaginary * other.real);
    return ComplexNumber<T>(newReal, newImaginary);
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::operator/(const ComplexNumber<T> &other) const {
    T denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
    if (std::abs(denominator) < Epsilon) {
        throw std::runtime_error("Division by zero");
    }
    T newReal = ((real * other.real) + (imaginary * other.imaginary)) / denominator;
    T newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / denominator;
    return ComplexNumber<T>(newReal, newImaginary);
}

template<typename T>
bool ComplexNumber<T>::operator==(const ComplexNumber<T> &other) const {
    return std::abs(real - other.real) < Epsilon &&
           std::abs(imaginary - other.imaginary) < Epsilon;
}

template<typename T>
bool ComplexNumber<T>::operator==(const int value) const {
    return std::abs(real - static_cast<T>(value)) < Epsilon &&
           std::abs(imaginary) < Epsilon;
}

template<typename T>
bool ComplexNumber<T>::operator==(const double value) const {
    return std::abs(real - static_cast<T>(value)) < Epsilon &&
           std::abs(imaginary) < Epsilon;
}

template<typename T>
ComplexNumber<T> ComplexNumber<T>::power(int exponent) const {
    T r = std::pow(getModulus(), exponent);
    T theta = std::atan2(imaginary, real) * exponent;
    return ComplexNumber<T>(r * std::cos(theta), r * std::sin(theta));
}

template<typename T>
T ComplexNumber<T>::getModulus() const {
    return std::sqrt((real * real) + (imaginary * imaginary));
}

template<typename T>
void ComplexNumber<T>::display() const {
    std::cout << std::fixed << std::setprecision(2) << real;
    if (imaginary >= T(0)) {
        std::cout << " + " << imaginary << "i";
    } else {
        std::cout << " - " << -imaginary << "i";
    }
    std::cout << std::endl;
}

template
class ComplexNumber<double>;

template
class ComplexNumber<float>;

template
class ComplexNumber<int>;
