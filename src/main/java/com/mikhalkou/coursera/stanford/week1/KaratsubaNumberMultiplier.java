package com.mikhalkou.coursera.stanford.week1;

import java.math.BigInteger;

public class KaratsubaNumberMultiplier implements NumberMultiplier {
    public static final BigInteger BASE_10 = BigInteger.valueOf(10);
    private long callsCounter = 0;

    public synchronized BigInteger multiply(BigInteger a, BigInteger b) {
        callsCounter = 0;
        return multiplyNums(a, b);
    }

    public BigInteger multiplyNums(BigInteger a, BigInteger b) {
        callsCounter++;
        if (a.equals(BigInteger.ZERO) || b.equals(BigInteger.ZERO)) {
            return BigInteger.ZERO;
            // added this base because it cases saves a lot of recursive calls,
            // e.g. for test shouldMultiplyBigNumbers - before: 197,200, after: 3340 calls
            // for test shouldMultiplyBigNumbers - before: 258,022,333, after: 6025 calls
            // for test shouldMultiplyBigAndSmallNumbers - before: 15,134,969,440, after: 373 calls
            // (number of calls grows very rapidly as difference between length of a and b increases)
        }
        if (lessThan(a, 10) && lessThan(b, 10)) {
            return a.multiply(b);
        }
        String aStr = a.toString();
        String bStr = b.toString();

        int minLength = Math.min(aStr.length(), bStr.length());
        int mPower = Math.max(1, minLength / 2);

        int aSplitIdx = aStr.length() - mPower;
        BigInteger aHigh = parseBigInt(aStr.substring(0, aSplitIdx));
        BigInteger aLow = parseBigInt(aStr.substring(aSplitIdx));

        int bSplitIds = bStr.length() - mPower;
        BigInteger bHigh = parseBigInt(bStr.substring(0, bSplitIds));
        BigInteger bLow = parseBigInt(bStr.substring(bSplitIds));

        BigInteger z0 = multiplyNums(aLow, bLow);
        BigInteger z2 = multiplyNums(aHigh, bHigh);
        BigInteger z1 = multiplyNums(aLow.add(aHigh), bLow.add(bHigh)).subtract(z0).subtract(z2);

        return z2.multiply(BASE_10.pow(mPower * 2)).add(z1.multiply(BASE_10.pow(mPower))).add(z0);
    }

    private BigInteger parseBigInt(String val) {
        if (val.isBlank()) {
            return BigInteger.ZERO;
        } else {
            return new BigInteger(val);
        }
    }

    private boolean lessThan(BigInteger n, long val) {
        return n.compareTo(BigInteger.valueOf(val)) < 0;
    }

    public long getCallsCounter() {
        return callsCounter;
    }
}
