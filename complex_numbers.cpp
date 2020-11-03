#include "complex_numbers.h"
#include <iostream>
#include <string>

RationalNumber ComplexNumber::GetReal() const noexcept {
    return firstNum_;
}

RationalNumber ComplexNumber::GetIm() const noexcept {
    return numI_;
}

ComplexNumber ComplexNumber::SetReal(const RationalNumber &number) noexcept {
    firstNum_ = number;
    return *this;
}

ComplexNumber ComplexNumber::SetIm(const RationalNumber &number) noexcept {
    numI_ = number;
    return *this;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &number) const noexcept {
    ComplexNumber newNum;
    newNum.firstNum_ = firstNum_ + number.firstNum_;
    newNum.numI_ = numI_ + number.numI_;
    return newNum;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &number) const noexcept {
    ComplexNumber newNum;
    newNum.firstNum_ = firstNum_ - number.firstNum_;
    newNum.numI_ = numI_ - number.numI_;
    return newNum;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &number) const noexcept {
    ComplexNumber newNum;
    newNum.firstNum_ = (firstNum_ * number.firstNum_) - (numI_ * number.numI_);
    newNum.numI_ = (firstNum_ * number.numI_) + (numI_ * number.firstNum_);
    return newNum;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &number) const noexcept {
    ComplexNumber newNum;
    newNum.firstNum_ = ((firstNum_ * number.firstNum_) + (numI_ * number.numI_)) / ((number.firstNum_ * number.firstNum_) + (number.numI_ * number.numI_));
    newNum.numI_ = ((number.firstNum_ * numI_) - (firstNum_ * number.numI_)) / ((number.firstNum_ * number.firstNum_) + (number.numI_ * number.numI_));
    return newNum;
}

ComplexNumber &ComplexNumber::operator=(const ComplexNumber &number) noexcept = default;

bool ComplexNumber::operator==(const ComplexNumber &number) const noexcept {
    if (firstNum_ == number.firstNum_ && numI_ == number.numI_) {
        return true;
    } else {
        return false;
    }
}

bool ComplexNumber::operator!=(const ComplexNumber &number) const noexcept {
    if (firstNum_ != number.firstNum_ || numI_ != number.numI_) {
        return true;
    } else {
        return false;
    }
}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &number) noexcept {
    *this = *this + number;
    return *this;
}

ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &number) noexcept {
    *this = *this * number;
    return *this;
}

ComplexNumber &ComplexNumber::operator-=(const ComplexNumber &number) noexcept {
    *this = *this - number;
    return *this;
}

ComplexNumber &ComplexNumber::operator/=(const ComplexNumber &number) noexcept {
    *this = *this / number;
    return *this;
}

ComplexNumber &ComplexNumber::operator-() noexcept {
    firstNum_ = -firstNum_;
    numI_ = -numI_;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const ComplexNumber &number) noexcept {
    out << number.firstNum_ << " + " << "(" << number.numI_ << ")" << "i";
    return out;
}

ComplexNumber &ComplexNumber::myPowForComplex(int a) noexcept {
    ComplexNumber newNum;
    newNum = *this;
    for (int i = 0; i < a - 1; i++) {
        *this = *this * newNum;
    }
    return *this;
}

RationalNumber ComplexNumber::abs() const noexcept {
    ComplexNumber newNum;
    RationalNumber Abs;
    newNum.firstNum_ = firstNum_ * firstNum_;
    newNum.numI_ = numI_ * numI_;
    Abs = newNum.firstNum_ + newNum.numI_;
    return RationalNumber::sqrt(Abs);
}

ComplexNumber ComplexNumber::operator+(int number) noexcept {
    RationalNumber newRatNum(number);
    ComplexNumber newCompNum(*this);
    newCompNum.firstNum_ = firstNum_ + newRatNum;
    return newCompNum;
}

ComplexNumber ComplexNumber::operator-(int number) noexcept {
    RationalNumber newRatNum(number);
    ComplexNumber newCompNum(*this);
    newCompNum.firstNum_ = firstNum_ - newRatNum;
    return newCompNum;
}

ComplexNumber ComplexNumber::operator*(int number) noexcept {
    RationalNumber newRatNum(number);
    ComplexNumber newCompNum(*this);
    newCompNum.firstNum_ = firstNum_ * newRatNum;
    newCompNum.numI_ = numI_ * newRatNum;
    return newCompNum;
}

ComplexNumber ComplexNumber::operator/(int number) noexcept {
    RationalNumber newRatNum(number);
    ComplexNumber newCompNum(*this);
    newCompNum.firstNum_ = firstNum_ / newRatNum;
    newCompNum.numI_ = numI_ / newRatNum;
    return newCompNum;
}


ComplexNumber ComplexNumber::operator+(double number) noexcept {
    RationalNumber newRatNum = RationalNumber::to_rational(number);
    ComplexNumber newCompNum;
    newCompNum.firstNum_ = firstNum_ + newRatNum;
    newCompNum.numI_ = numI_;
    return newCompNum;
}

ComplexNumber ComplexNumber::operator-(double number) noexcept {
    RationalNumber newRatNum = RationalNumber::to_rational(number);
    ComplexNumber newCompNum;
    newCompNum.firstNum_ = firstNum_ - newRatNum;
    newCompNum.numI_ = numI_;
    return newCompNum;
}

ComplexNumber ComplexNumber::operator*(double number) noexcept {
    RationalNumber newRatNum = RationalNumber::to_rational(number);
    ComplexNumber newCompNum;
    newCompNum.firstNum_ = firstNum_ * newRatNum;
    newCompNum.numI_ = numI_ * newRatNum;
    return newCompNum;
}

ComplexNumber ComplexNumber::operator/(double number) noexcept {
    RationalNumber newRatNum = RationalNumber::to_rational(number);
    ComplexNumber newCompNum;
    newCompNum.firstNum_ = firstNum_ / newRatNum;
    newCompNum.numI_ = numI_ / newRatNum;
    return newCompNum;
}

ComplexNumber &ComplexNumber::operator+=(int number) noexcept {
    RationalNumber newNum(number);
    firstNum_ = firstNum_ + newNum;
    return *this;
}

ComplexNumber &ComplexNumber::operator-=(int number) noexcept {
    RationalNumber newNum(number);
    firstNum_ = firstNum_ - newNum;
    return *this;
}

ComplexNumber &ComplexNumber::operator*=(int number) noexcept {
    RationalNumber newNum(number);
    firstNum_ = firstNum_ * newNum;
    numI_ = numI_ * newNum;
    return *this;
}

ComplexNumber &ComplexNumber::operator/=(int number) noexcept {
    RationalNumber newNum(number);
    firstNum_ = firstNum_ / newNum;
    numI_ = numI_ / newNum;
    return *this;
}

ComplexNumber &ComplexNumber::operator+=(double number) noexcept {
    RationalNumber newRatNum = RationalNumber::to_rational(number);
    firstNum_ = firstNum_ + newRatNum;
    return *this;
}

ComplexNumber &ComplexNumber::operator-=(double number) noexcept {
    RationalNumber newRatNum = RationalNumber::to_rational(number);
    firstNum_ = firstNum_ - newRatNum;
    return *this;
}

ComplexNumber &ComplexNumber::operator*=(double number) noexcept {
    RationalNumber newRatNum = RationalNumber::to_rational(number);
    firstNum_ = firstNum_ * newRatNum;
    numI_ = numI_ * newRatNum;
    return *this;
}

ComplexNumber &ComplexNumber::operator/=(double number) noexcept {
    RationalNumber newRatNum = RationalNumber::to_rational(number);
    firstNum_ = firstNum_ / newRatNum;
    numI_ = numI_ / newRatNum;
    return *this;
}