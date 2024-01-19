#ifndef COMPLEX_H
#define COMPLEX_H

template<typename T>
class Complex {
private:
    T real;
    T imaginary;

public:
    explicit Complex(T real = 0.0, T imag = 0.0);

    T getReal() const;

    T getImaginary() const;

    void setReal(T re);

    void setImaginary(T im);

    Complex<T> operator+(const Complex<T> &other) const;

    Complex<T> operator-(const Complex<T> &other) const;

    Complex<T> operator*(const Complex<T> &other) const;

    Complex<T> operator/(const Complex<T> &other) const;

    bool operator==(const Complex<T> &other) const;

    bool operator==(int value) const;

    bool operator==(double value) const;

    Complex<T> power(int exponent) const;

    T getModulus() const;

    void display() const;
};

#endif // COMPLEX_H
