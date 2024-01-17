#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double real;
    double imaginary;

public:
    explicit Complex(double real = 0.0, double imag = 0.0);

    double getReal() const;

    double getImaginary() const;

    void setReal(double re);

    void setImaginary(double im);

    Complex operator+(const Complex &other) const;

    Complex operator-(const Complex &other) const;

    Complex operator*(const Complex &other) const;

    Complex operator/(const Complex &other) const;

    bool equals(const Complex &other) const;

    Complex power(int exponent) const;

    double getModulus() const;

    void display() const;
};

#endif // COMPLEX_H
