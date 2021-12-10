//
// Created by mikhalkou on 12/9/21.
//
#ifndef STANFORD_ALGORITHMS_SPECIALIZATION_CPP_MAIN_H
#define STANFORD_ALGORITHMS_SPECIALIZATION_CPP_MAIN_H
#endif //STANFORD_ALGORITHMS_SPECIALIZATION_CPP_MAIN_H

#include <gmpxx.h>

class Calc {
public:
    Calc() = default;

    Calc(int calculationBase) : base(calculationBase) {};

    mpz_class karatsubaNumberMultiply(mpz_class a, mpz_class b);

private:
    mpz_class karatsubaNumberMultiply_private(mpz_class a, mpz_class b, long &opCounter);

    const int base = 10;
};