#define CATCH_CONFIG_MAIN

#include <iostream>
#include "complex_numbers.h"
#include "catch.hpp"
#include <complex>

using namespace std;

TEST_CASE("INIT") {
    SECTION("Rational") {
        const RationalNumber Num(5, 10);
        REQUIRE(Num.GetNumerator() == 1);
        REQUIRE(Num.GetDenominator() == 2);
    }
    SECTION("Complex") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber NumI(3, 4);
        const ComplexNumber Num(FirstNum, NumI);
        const RationalNumber FirstNum1;
        const RationalNumber NumI1;
        const ComplexNumber Num1;
        const ComplexNumber Num2(Num);
        REQUIRE(Num.GetReal() == FirstNum);
        REQUIRE(Num.GetIm() == NumI);
        REQUIRE(Num1.GetReal() == FirstNum1);
        REQUIRE(Num1.GetIm() == NumI1);
        REQUIRE(Num2.GetReal() == FirstNum);
        REQUIRE(Num2.GetIm() == NumI);
    }
}
TEST_CASE("SET") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber NumI(3, 4);
    ComplexNumber Num;
    Num.SetReal(FirstNum);
    Num.SetIm(NumI);
    REQUIRE(Num.GetReal() == FirstNum);
    REQUIRE(Num.GetIm() == NumI);
}


TEST_CASE("+") {
    SECTION("Rational") {
        const RationalNumber Num(5, 10);
        const RationalNumber Num1(5, 10);
        RationalNumber Num2;
        Num2 = Num + Num1;
        REQUIRE(Num2.GetNumerator() == 1);
        REQUIRE(Num2.GetDenominator() == 1);
    }
    SECTION("Complex") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNum1(2, 10);
        const RationalNumber FirstNumSum(7, 10);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumI1(1, 4);
        const RationalNumber NumISum(1, 1);
        const ComplexNumber Num(FirstNum, NumI);
        const ComplexNumber Num1(FirstNum1, NumI1);
        ComplexNumber Num2;
        Num2 = Num + Num1;
        REQUIRE(Num2.GetReal() == FirstNumSum);
        REQUIRE(Num2.GetIm() == NumISum);
    }
}

TEST_CASE("-") {
    SECTION("Rational") {
        const RationalNumber Num(5, 10);
        const RationalNumber Num1(3, 10);
        RationalNumber Num2;
        Num2 = Num - Num1;
        REQUIRE(Num2.GetNumerator() == 1);
        REQUIRE(Num2.GetDenominator() == 5);
    }
    SECTION("Complex") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNum1(2, 10);
        const RationalNumber FirstNumSum(3, 10);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumI1(1, 4);
        const RationalNumber NumISum(2, 4);
        const ComplexNumber Num(FirstNum, NumI);
        const ComplexNumber Num1(FirstNum1, NumI1);
        ComplexNumber Num2;
        Num2 = Num - Num1;
        REQUIRE(Num2.GetReal() == FirstNumSum);
        REQUIRE(Num2.GetIm() == NumISum);
    }
}

TEST_CASE("*") {
    SECTION("Rational") {
        const RationalNumber Num(2, 10);
        const RationalNumber Num1(3, 10);
        RationalNumber Num2;
        Num2 = Num * Num1;
        REQUIRE(Num2.GetNumerator() == 3);
        REQUIRE(Num2.GetDenominator() == 50);
    }
    SECTION("Complex") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNum1(2, 10);
        const RationalNumber FirstNumSum(-7, 80);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumI1(1, 4);
        const RationalNumber NumISum(11, 40);
        const ComplexNumber Num(FirstNum, NumI);
        const ComplexNumber Num1(FirstNum1, NumI1);
        ComplexNumber Num2;
        Num2 = Num * Num1;
        REQUIRE(Num2.GetReal() == FirstNumSum);
        REQUIRE(Num2.GetIm() == NumISum);
    }
}

TEST_CASE("/") {
    SECTION("Rational") {
        const RationalNumber Num(2, 10);
        const RationalNumber Num1(3, 10);
        RationalNumber Num2;
        Num2 = Num / Num1;
        REQUIRE(Num2.GetNumerator() == 2);
        REQUIRE(Num2.GetDenominator() == 3);
    }
    SECTION("Complex") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNum1(2, 10);
        const RationalNumber FirstNumSum(115, 41);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumI1(1, 4);
        const RationalNumber NumISum(10, 41);
        const ComplexNumber Num(FirstNum, NumI);
        const ComplexNumber Num1(FirstNum1, NumI1);
        ComplexNumber Num2;
        Num2 = Num / Num1;
        REQUIRE(Num2.GetReal() == FirstNumSum);
        REQUIRE(Num2.GetIm() == NumISum);
    }
}

TEST_CASE("==") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber FirstNum1(10, 20);
    const RationalNumber NumI(3, 4);
    const RationalNumber NumI1(75, 100);
    const ComplexNumber Num(FirstNum, NumI);
    const ComplexNumber Num1(FirstNum1, NumI1);
    REQUIRE(Num == Num1);
}

TEST_CASE("!=") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber FirstNum1(10, 20);
    const RationalNumber NumI(3, 4);
    const RationalNumber NumI1(74, 100);
    const ComplexNumber Num(FirstNum, NumI);
    const ComplexNumber Num1(FirstNum1, NumI1);
    REQUIRE(Num != Num1);
}

TEST_CASE("Output in terminal") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber NumI(3, 4);
    const ComplexNumber Num(FirstNum, NumI);
    stringstream Out;
    Out << Num;
    REQUIRE(Out.str() == "1/2 + (3/4)i");
}

TEST_CASE("+=") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber FirstNum1(2, 10);
    const RationalNumber FirstNumSum(7, 10);
    const RationalNumber NumI(3, 4);
    const RationalNumber NumI1(1, 4);
    const RationalNumber NumISum(1, 1);
    ComplexNumber Num(FirstNum, NumI);
    ComplexNumber Num1(FirstNum1, NumI1);
    Num += Num1;
    REQUIRE(Num.GetReal() == FirstNumSum);
    REQUIRE(Num.GetIm() == NumISum);
}

TEST_CASE("-=") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber FirstNum1(2, 10);
    const RationalNumber FirstNumSum(3, 10);
    const RationalNumber NumI(3, 4);
    const RationalNumber NumI1(1, 4);
    const RationalNumber NumISum(2, 4);
    ComplexNumber Num(FirstNum, NumI);
    ComplexNumber Num1(FirstNum1, NumI1);
    Num -= Num1;
    REQUIRE(Num.GetReal() == FirstNumSum);
    REQUIRE(Num.GetIm() == NumISum);
}

TEST_CASE("*=") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber FirstNum1(2, 10);
    const RationalNumber FirstNumSum(-7, 80);
    const RationalNumber NumI(3, 4);
    const RationalNumber NumI1(1, 4);
    const RationalNumber NumISum(11, 40);
    ComplexNumber Num(FirstNum, NumI);
    ComplexNumber Num1(FirstNum1, NumI1);
    Num *= Num1;
    REQUIRE(Num.GetReal() == FirstNumSum);
    REQUIRE(Num.GetIm() == NumISum);
}

TEST_CASE("/=") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber FirstNum1(2, 10);
    const RationalNumber FirstNumSum(115, 41);
    const RationalNumber NumI(3, 4);
    const RationalNumber NumI1(1, 4);
    const RationalNumber NumISum(10, 41);
    ComplexNumber Num(FirstNum, NumI);
    ComplexNumber Num1(FirstNum1, NumI1);
    Num /= Num1;
    REQUIRE(Num.GetReal() == FirstNumSum);
    REQUIRE(Num.GetIm() == NumISum);
}

TEST_CASE("one-") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber NumI(3, 4);
    const ComplexNumber Num(FirstNum, NumI);
    ComplexNumber Num1(Num);
    Num1 = -Num1;
    REQUIRE(Num1 != Num);
}

TEST_CASE("+ Int Number") {
    SECTION("+=") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum(5, 2);
        const RationalNumber NumI(3, 4);
        ComplexNumber Num(FirstNum, NumI);
        Num += 2;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumI);
    }
    SECTION("+") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum(5, 2);
        const RationalNumber NumI(3, 4);
        ComplexNumber Num(FirstNum, NumI);
        Num = Num + 2;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumI);
    }
}
TEST_CASE("- Int Number") {
    SECTION("-=") {
        const RationalNumber FirstNum(5, 10); // 5/10 - 2 = -1,5; -3/2
        const RationalNumber FirstNumSum(-3, 2);
        const RationalNumber NumI(3, 4);
        ComplexNumber Num(FirstNum, NumI);
        Num -= 2;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumI);
    }
    SECTION("-") {
        const RationalNumber FirstNum(5, 10); // 5/10 - 2 = -1,5; -3/2
        const RationalNumber FirstNumSum(-3, 2);
        const RationalNumber NumI(3, 4);
        ComplexNumber Num(FirstNum, NumI);
        Num = Num - 2;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumI);
    }
}
TEST_CASE("* Int Number") {
    SECTION("*=") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum(1, 1);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumISum(3, 2);
        ComplexNumber Num(FirstNum, NumI);
        Num *= 2;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumISum);
    }
    SECTION("*") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum(1, 1);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumISum(3, 2);
        ComplexNumber Num(FirstNum, NumI);
        Num = Num * 2;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumISum);
    }
}
TEST_CASE("/ Int Number") {
    SECTION("/=") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum(1, 4);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumISum(3, 8);
        ComplexNumber Num(FirstNum, NumI);
        Num /= 2;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumISum);
    }
    SECTION("/") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum(1, 4);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumISum(3, 8);
        ComplexNumber Num(FirstNum, NumI);
        Num = Num / 2;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumISum);
    }
}

TEST_CASE("Double_To_Rational") {
    const RationalNumber FirstNum(12, 5);
    const double number = 2.4;
    RationalNumber FirstNum1 = RationalNumber::to_rational(number);
    REQUIRE(FirstNum == FirstNum1);
}
TEST_CASE("+ Double") {
    SECTION("+=") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum = FirstNum + RationalNumber::to_rational(2.4);
        const RationalNumber NumI(3, 4);
        ComplexNumber Num(FirstNum, NumI);
        Num += 2.4;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumI);
    }
    SECTION("+") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum = FirstNum + RationalNumber::to_rational(2.4);
        const RationalNumber NumI(3, 4);
        ComplexNumber Num(FirstNum, NumI);
        Num = Num + 2.4;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumI);
    }
}
TEST_CASE("- Double") {
    SECTION("-=") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum = FirstNum - RationalNumber::to_rational(2.4);
        const RationalNumber NumI(3, 4);
        ComplexNumber Num(FirstNum, NumI);
        Num -= 2.4;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumI);
    }
    SECTION("-") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum = FirstNum - RationalNumber::to_rational(2.4);
        const RationalNumber NumI(3, 4);
        ComplexNumber Num(FirstNum, NumI);
        Num = Num - 2.4;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumI);
    }
}
TEST_CASE("* Double") {
    SECTION("*=") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum = FirstNum * RationalNumber::to_rational(2.4);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumISum = NumI * RationalNumber::to_rational(2.4);
        ComplexNumber Num(FirstNum, NumI);
        Num *= 2.4;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumISum);
    }
    SECTION("*") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum = FirstNum * RationalNumber::to_rational(2.4);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumISum = NumI * RationalNumber::to_rational(2.4);
        ComplexNumber Num(FirstNum, NumI);
        Num = Num * 2.4;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumISum);
    }
}
TEST_CASE("/ Double") {
    SECTION("/=") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum = FirstNum / RationalNumber::to_rational(2.4);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumISum = NumI / RationalNumber::to_rational(2.4);
        ComplexNumber Num(FirstNum, NumI);
        Num /= 2.4;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumISum);
    }
    SECTION("/") {
        const RationalNumber FirstNum(5, 10);
        const RationalNumber FirstNumSum = FirstNum / RationalNumber::to_rational(2.4);
        const RationalNumber NumI(3, 4);
        const RationalNumber NumISum = NumI / RationalNumber::to_rational(2.4);
        ComplexNumber Num(FirstNum, NumI);
        Num = Num / 2.4;
        REQUIRE(Num.GetReal() == FirstNumSum);
        REQUIRE(Num.GetIm() == NumISum);
    }
}
TEST_CASE("abs") {
    SECTION("sqrtRational") {
        RationalNumber FirstNum(4, 16);
        RationalNumber sqrt = RationalNumber::sqrt(FirstNum);
        const RationalNumber sqrtResult(1, 2);
        REQUIRE(sqrt == sqrtResult);
    }
//    SECTION("ABS") {
//        const RationalNumber FirstNum(5, 10);
//        const RationalNumber NumI(3, 10);
//        const ComplexNumber Abs(FirstNum, NumI);
//        const RationalNumber absResult(6, 10);
//        REQUIRE(Abs.abs() == absResult);
//    }
}
TEST_CASE("POW") {
    const RationalNumber FirstNum(5, 10);
    const RationalNumber FirstNum1;
    const RationalNumber NumI(5, 10);
    const RationalNumber NumI1(1, 2);
    ComplexNumber Num(FirstNum, NumI);
    Num.myPowForComplex(2);
    REQUIRE(Num.GetReal() == FirstNum1);
    REQUIRE(Num.GetIm() == NumI1);
}