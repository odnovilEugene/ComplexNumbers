#include "rational_numbers.h"
#include <iostream>
#include <string>
#include <cmath>

RationalNumber RationalNumber::to_rational(double number) noexcept {
    double tolerance = 0.0000001;
    double x = number,
            c11 = 1.0, c12 = 0.0,
            c21 = 0.0, c22 = 1.0,
            epsilonTolerance = std::numeric_limits<double>::epsilon()*fabs(number),
            maxTolerance = std::max(tolerance*fabs(number), epsilonTolerance);

    while(true)
    {
        double d = (x > 0) ? floor(x + 0.5) : -floor(-x + 0.5); // round(x)
        x -= d;

        double tmp_c12 = c12;
        double tmp_c22 = c22;

        c12 = c11;
        c22 = c21;
        c11 = c11 * d + tmp_c12;
        c21 = c21 * d + tmp_c22;

        if(x == 0 || fabs(c11/c21 - number) <=  maxTolerance)
        {
            break;
        }

        x = 1.0 / x;
    }
    int numerator = (c21 > 0) ? c11 : -c11;
    int denominator = fabs(c21);
    RationalNumber newRatNum(numerator, denominator);
    return newRatNum;
}

std::ostream &operator<<(std::ostream &out, const RationalNumber &number) noexcept {
    if (number.denominator_ == 1) {
        out << number.numerator_;
    } else {
        out << number.numerator_ << "/" << number.denominator_;
    }
    return out;
}

bool RationalNumber::operator==(const RationalNumber &number) const noexcept {
    int LcmNumber = lcm(denominator_, number.denominator_);
    if ((numerator_ * (LcmNumber / denominator_)) == (number.numerator_ * (LcmNumber / number.denominator_))) {
        return true;
    } else {
        return false;
    }
}

bool RationalNumber::operator>(const RationalNumber &number) const noexcept {
    int LcmNumber = lcm(denominator_, number.denominator_);
    if ((numerator_ * (LcmNumber / denominator_)) > (number.numerator_ * (LcmNumber / number.denominator_))) {
        return true;
    } else {
        return false;
    }
}

bool RationalNumber::operator<(const RationalNumber &number) const noexcept {
    int LcmNumber = lcm(denominator_, number.denominator_);
    if ((numerator_ * (LcmNumber / denominator_)) < (number.numerator_ * (LcmNumber / number.denominator_))) {
        return true;
    } else {
        return false;
    }
}

bool RationalNumber::operator>=(const RationalNumber &number) const noexcept {
    int LcmNumber = lcm(denominator_, number.denominator_);
    if ((numerator_ * (LcmNumber / denominator_)) >= (number.numerator_ * (LcmNumber / number.denominator_))) {
        return true;
    } else {
        return false;
    }
}

bool RationalNumber::operator<=(const RationalNumber &number) const noexcept {
    int LcmNumber = lcm(denominator_, number.denominator_);
    if ((numerator_ * (LcmNumber / denominator_)) <= (number.numerator_ * (LcmNumber / number.denominator_))) {
        return true;
    } else {
        return false;
    }
}

RationalNumber RationalNumber::sqrt(RationalNumber &number) noexcept {
    if (number.numerator_ >= 0 && number.denominator_ >= 0) {
        RationalNumber number1 = to_rational(std::sqrt(number.numerator_));
        RationalNumber number2 = to_rational(std::sqrt(number.denominator_));
        RationalNumber newNum = number1 / number2;
        return newNum;
    } else {
        RationalNumber newNum1;
        return newNum1;
    }
}

RationalNumber RationalNumber::operator-() noexcept {
    numerator_ = -numerator_;
    slash();
    return *this;
}


bool RationalNumber::operator!=(const RationalNumber &number) const noexcept {
    int LcmNumber = lcm(denominator_, number.denominator_);
    if ((numerator_ * (LcmNumber / denominator_)) != (number.numerator_ * (LcmNumber / number.denominator_))) {
        return true;
    } else {
        return false;
    }
}


RationalNumber RationalNumber::operator+(const RationalNumber &number) const noexcept {
    RationalNumber newNum;
    if (denominator_ == number.denominator_) {
        newNum.numerator_ = numerator_ + number.numerator_;
        newNum.denominator_ = number.denominator_;
    } else {
        int LcmNumber = lcm(denominator_, number.denominator_);
        newNum.numerator_ = (numerator_ * (LcmNumber / denominator_)) + (number.numerator_ * (LcmNumber / number.denominator_));
        newNum.denominator_ = LcmNumber;
    }
    newNum.slash();
    return newNum;
}

RationalNumber RationalNumber::operator-(const RationalNumber &number) const noexcept {
    RationalNumber newNum;
    if (denominator_ == number.denominator_) {
        newNum.numerator_ = numerator_ - number.numerator_;
        newNum.denominator_ = number.denominator_;
    } else {
        int LcmNumber = lcm(denominator_, number.denominator_);
        newNum.numerator_ = (numerator_ * (LcmNumber / denominator_)) - (number.numerator_ * (LcmNumber / number.denominator_));
        newNum.denominator_ = LcmNumber;
    }
    newNum.slash();
    return newNum;
}

RationalNumber RationalNumber::operator*(const RationalNumber &number) const noexcept {
    RationalNumber newNum;
    newNum.numerator_ = numerator_ * number.numerator_;
    newNum.denominator_ = denominator_ * number.denominator_;
    newNum.slash();
    return newNum;
}

RationalNumber RationalNumber::operator/(const RationalNumber &number) const noexcept {
    RationalNumber newNum;
    newNum.numerator_ = numerator_ * number.denominator_;
    newNum.denominator_ = denominator_ * number.numerator_;
    newNum.slash();
    return newNum;
}

RationalNumber &RationalNumber::slash() noexcept {
    if (numerator_ != 0) {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        int GcdNumber = gcd(numerator_, denominator_);
        if (GcdNumber < 0)
            GcdNumber = -GcdNumber;
        numerator_ = numerator_ / GcdNumber;
        denominator_ = denominator_ / GcdNumber;
        return *this;
    } else {
        numerator_ = 0;
        denominator_ = 1;
        return *this;
    }
}

int RationalNumber::GetNumerator() const noexcept {
    return numerator_;
}

int RationalNumber::GetDenominator() const noexcept {
    return denominator_;
}

RationalNumber RationalNumber::SetNumerator(int numerator) noexcept {
    numerator_ = numerator;
    return *this;
}

RationalNumber RationalNumber::SetDenominator(int denominator) noexcept {
    denominator_ = denominator;
    return *this;
}
