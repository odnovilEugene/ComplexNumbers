#pragma once

#include <iostream>

class RationalNumber { // класс рациональных чисел
public:
    explicit RationalNumber(int numerator=0, int denominator=1) noexcept : numerator_(numerator), denominator_(denominator){
        slash();
    }
    static int gcd(int a, int b) {
        if (a < b) {
            std::swap(a, b);
        }
        while (a % b != 0) {
            a = a % b;
            std::swap(a, b);
        }
        return b;
    }
    static int lcm(int a, int b) { // НОК
        return (a * b) / gcd(a, b);
    }
    static RationalNumber to_rational(double number) noexcept;
    RationalNumber operator*(const RationalNumber &number) const noexcept;
    RationalNumber operator+(const RationalNumber &number) const noexcept;
    RationalNumber operator-(const RationalNumber &number) const noexcept;
    RationalNumber operator/(const RationalNumber &number) const noexcept;
    bool operator==(const RationalNumber &number) const noexcept;
    bool operator!=(const RationalNumber &number) const noexcept;
    RationalNumber operator-() noexcept;
    bool operator>(const RationalNumber &number) const noexcept;
    bool operator>=(const RationalNumber &number) const noexcept;
    bool operator<(const RationalNumber &number) const noexcept;
    bool operator<=(const RationalNumber &number) const noexcept;
    friend std::ostream& operator<<(std::ostream& out, const RationalNumber &number) noexcept;
    RationalNumber &slash() noexcept;
    static RationalNumber sqrt(RationalNumber &number) noexcept;
    int GetNumerator() const noexcept;
    int GetDenominator() const noexcept;
    RationalNumber SetNumerator(int numerator) noexcept;
    RationalNumber SetDenominator(int denominator) noexcept;

private:
    int numerator_ ;
    int denominator_;
};
