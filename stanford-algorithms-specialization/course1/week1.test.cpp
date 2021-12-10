#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../doctest.h"
#include "week1.hpp"


TEST_CASE("karatsubaNumberMultiply - test Small Numbers (int)") {
    Calc calc = Calc();
    int a = 122;
    int b = 121;
    CHECK(calc.karatsubaNumberMultiply(a, b) == a * b);
}


TEST_CASE("karatsubaNumberMultiply - big numbers with same length") {
    Calc calc = Calc();
    const mpz_class &a = 28841971693993751058209749445924_mpz;
    const mpz_class &b = 62497757247093699959574966967627_mpz;
    CHECK(calc.karatsubaNumberMultiply(a, b) == a * b);
}

TEST_CASE("karatsubaNumberMultiply - big numbers with different lengths") {
    Calc calc = Calc();
    const mpz_class &a = 125324523354632486765348327423104231253245233546324867653483_mpz;
    const mpz_class &b = 527324523354632486765348327423114231432_mpz;
    CHECK(calc.karatsubaNumberMultiply(a, b) == a * b);
}

TEST_CASE("karatsubaNumberMultiply - big and tiny number") {
    Calc calc = Calc();
    const mpz_class &a = 527324523354632486765348322311423_mpz;
    const mpz_class &b = 123_mpz;
    CHECK(calc.karatsubaNumberMultiply(a, b) == a * b);
}

TEST_CASE("karatsubaNumberMultiply - huge numbers") {
    Calc calc = Calc();
    const mpz_class &a = 45243754358743576348957436577868457898689576438967345647895764376543276856437873919300754517857915509127525325605623700123890231_mpz;
    const mpz_class &b = 54674057235290980574561645161242352162313472300877645556143505498055857230572108543242316534266870898766451345155745549294869917_mpz;
    CHECK(calc.karatsubaNumberMultiply(a, b) == a * b);
}

TEST_CASE(": karatsubaNumberMultiply 4 - huge numbers using calculation base 16") {
    Calc calc = Calc(16);
    const mpz_class &a = 45243754358743576348957436577868457898689576438967345647895764376543276856437873919300754517857915509127525325605623700123890231_mpz;
    const mpz_class &b = 54674057235290980574561645161242352162313472300877645556143505498055857230572108543242316534266870898766451345155745549294869917_mpz;
    CHECK(calc.karatsubaNumberMultiply(a, b) == a * b);
}


TEST_CASE(": karatsubaNumberMultiply - Assignment Answer") {
    Calc calc = Calc();
    const mpz_class &a = 3141592653589793238462643383279502884197169399375105820974944592_mpz;
    const mpz_class &b = 2718281828459045235360287471352662497757247093699959574966967627_mpz;
    std::cout << calc.karatsubaNumberMultiply(a, b);
}