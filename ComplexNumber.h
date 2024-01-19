#ifndef COMPLEX_H
#define COMPLEX_H

template<typename T>
class ComplexNumber {
private:
    T real;
    T imaginary;

public:
    explicit ComplexNumber(T real = 0.0, T imag = 0.0);

    T getReal() const;

    T getImaginary() const;

    void setReal(T re);

    void setImaginary(T im);

    ComplexNumber<T> operator+(const ComplexNumber<T> &other) const;

    ComplexNumber<T> operator-(const ComplexNumber<T> &other) const;

    ComplexNumber<T> operator*(const ComplexNumber<T> &other) const;

    ComplexNumber<T> operator/(const ComplexNumber<T> &other) const;

    bool operator==(const ComplexNumber<T> &other) const;

    bool operator==(int value) const;

    bool operator==(double value) const;

    ComplexNumber<T> power(int exponent) const;

    T getModulus() const;

    void display() const;
};

#endif // COMPLEX_H
