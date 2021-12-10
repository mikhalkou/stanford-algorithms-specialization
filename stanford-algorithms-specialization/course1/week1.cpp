#include <gmpxx.h>
#include <iostream>
#include "week1.hpp"

mpz_class Calc::karatsubaNumberMultiply(mpz_class a, mpz_class b) {
    long opCounter = 0;
    const mpz_class &expr = karatsubaNumberMultiply_private(a, b, opCounter);
    std::cout << "Recursive calls count: " << opCounter << "\n";
    return expr;
}

mpz_class Calc::karatsubaNumberMultiply_private(mpz_class a, mpz_class b, long &opCounter) {
    opCounter++;
    if (a == 0 || b == 0) {
        return 0;
        //added this base because it cases saves a lot of recursive calls,
        // e.g. for test 'huge numbers' - before: 6475, after: 6424 calls
        // for test 'big numbers with different lengths' - before: 182,503,978, after: 5065 calls
        // for test 'big and tiny number' - before: 15,134,969,440, after: 373 calls
        // (number of calls grows very rapidly as difference between length of a and b increases)increases
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }
    if (a < base && b < base) {
        return a * b;
    }
    size_t aSize = mpz_sizeinbase(a.get_mpz_t(), base);
    size_t bSize = mpz_sizeinbase(b.get_mpz_t(), base);

    int minLength = std::min(aSize, bSize);
    int mPower = std::max(1, minLength / 2);

    const std::string &aStr = a.get_str(base);
    const std::string &bStr = b.get_str(base);

    mpz_class aHigh, aLow, bHigh, bLow;
    int aSplitIdx = aStr.length() - mPower;
    aHigh.set_str(aStr.substr(0, aSplitIdx), base);
    aLow.set_str(aStr.substr(aSplitIdx), base);
    int bSplitIdx = bStr.length() - mPower;
    bHigh.set_str(bStr.substr(0, bSplitIdx), base);
    bLow.set_str(bStr.substr(bSplitIdx), base);

    mpz_class z0, z1, z2;
    z0 = karatsubaNumberMultiply_private(aLow, bLow, opCounter);
    z2 = karatsubaNumberMultiply_private(aHigh, bHigh, opCounter);
    z1 = karatsubaNumberMultiply_private(aHigh + aLow, bHigh + bLow, opCounter) - z2 - z0;

    mpz_class mpzBase = base;
    mpz_class mpzZ1Multiplier = base;
    mpz_pow_ui(mpzZ1Multiplier.get_mpz_t(), mpzBase.get_mpz_t(), mPower);
    mpz_class mpzZ2Multiplier = mpzZ1Multiplier * mpzZ1Multiplier;

    return z2 * mpzZ2Multiplier + z1 * mpzZ1Multiplier + z0;
}
