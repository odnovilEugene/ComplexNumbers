#pragma once

#include <iostream>
#include "rational_numbers.h"


class ComplexNumber { // класс комплексных чисел
public:
    explicit ComplexNumber(RationalNumber firstNum, RationalNumber numI) noexcept : firstNum_(firstNum), numI_(numI) {}
    explicit ComplexNumber() noexcept = default;
    RationalNumber GetReal() const noexcept;
    RationalNumber GetIm() const noexcept;
    ComplexNumber SetReal(const RationalNumber &number) noexcept;
    ComplexNumber SetIm(const RationalNumber &number) noexcept;
    ComplexNumber operator+(const ComplexNumber &number) const noexcept;
    ComplexNumber operator-(const ComplexNumber &number) const noexcept;
    ComplexNumber operator*(const ComplexNumber &number) const noexcept;
    ComplexNumber operator/(const ComplexNumber &number) const noexcept;
    ComplexNumber &operator=(const ComplexNumber &number) noexcept;
    ComplexNumber &myPowForComplex(int a) noexcept;
    bool operator==(const ComplexNumber &number) const noexcept;
    bool operator!=(const ComplexNumber &number) const noexcept;
    ComplexNumber &operator+=(const ComplexNumber &number) noexcept;
    ComplexNumber &operator*=(const ComplexNumber &number) noexcept;
    ComplexNumber &operator-=(const ComplexNumber &number) noexcept;
    ComplexNumber &operator/=(const ComplexNumber &number) noexcept;
    ComplexNumber operator+(int number) noexcept;
    ComplexNumber operator-(int number) noexcept;
    ComplexNumber operator*(int number) noexcept;
    ComplexNumber operator/(int number) noexcept;
    ComplexNumber &operator+=(int number) noexcept;
    ComplexNumber &operator*=(int number) noexcept;
    ComplexNumber &operator-=(int number) noexcept;
    ComplexNumber &operator/=(int number) noexcept;
    ComplexNumber operator+(double number) noexcept;
    ComplexNumber operator-(double number) noexcept;
    ComplexNumber operator*(double number) noexcept;
    ComplexNumber operator/(double number) noexcept;
    ComplexNumber &operator+=(double number) noexcept;
    ComplexNumber &operator*=(double number) noexcept;
    ComplexNumber &operator-=(double number) noexcept;
    ComplexNumber &operator/=(double number) noexcept;
    ComplexNumber &operator-() noexcept;
    RationalNumber abs() const noexcept;
//    RationalNumber arg() const noexcept;
    friend std::ostream &operator<<(std::ostream &out, const ComplexNumber &number) noexcept;

private:
    RationalNumber firstNum_;
    RationalNumber numI_;
};
