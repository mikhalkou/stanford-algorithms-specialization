package com.mikhalkou.coursera.stanford.week1;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.math.BigInteger;

import static org.junit.jupiter.api.Assertions.*;

class NumberMultiplierTest {
    private NumberMultiplier numberMultiplier;

    @BeforeEach
    public void initMultiplier() {
        numberMultiplier = new KaratsubaNumberMultiplier();
    }

    @AfterEach
    public void destroyMultiplier() {
        System.out.println("Multiply called: " + ((KaratsubaNumberMultiplier) numberMultiplier).getCallsCounter());
        numberMultiplier = null;
    }

    @Test
    public void shouldMultiply1DigitNumbers() {
        BigInteger actual = numberMultiplier.multiply(BigInteger.ONE, BigInteger.valueOf(5));
        BigInteger expected = BigInteger.valueOf(5);
        assertEquals(expected, actual);
    }

    @Test
    public void shouldMultiplySameLenghtNumbers() {
        BigInteger a = BigInteger.valueOf(123);
        BigInteger b = BigInteger.valueOf(512);
        BigInteger actual = numberMultiplier.multiply(a, b);
        BigInteger expected = a.multiply(b);
        assertEquals(expected, actual);
    }

    @Test
    public void shouldMultiplyDifferentLengthNumbers() {
        BigInteger a = BigInteger.valueOf(1253245233);
        BigInteger b = BigInteger.valueOf(5163422);
        BigInteger actual = numberMultiplier.multiply(a, b);
        BigInteger expected = a.multiply(b);
        assertEquals(expected, actual);
    }

    @Test
    public void shouldMultiplyBigNumbers() {
        BigInteger a = new BigInteger("1253245233546324867653483274231042312532453");
        BigInteger b = new BigInteger("527324523354632486765348322311423");
        BigInteger actual = numberMultiplier.multiply(a, b);
        BigInteger expected = a.multiply(b);
        assertEquals(expected, actual);
    }

    @Test
    public void shouldMultiplyBigAndSmallNumbers() {
        BigInteger a = new BigInteger("527324523354632486765348322311423");
        BigInteger b = new BigInteger("123");
        BigInteger actual = numberMultiplier.multiply(a, b);
        BigInteger expected = a.multiply(b);
        assertEquals(expected, actual);
    }

    @Test
    public void shouldMultiplyVeryBigNumbers() {
        BigInteger a = new BigInteger("125324523354632486765348327423104231253245233546324867653483");
        BigInteger b = new BigInteger("527324523354632486765348327423114231432");
        BigInteger actual = numberMultiplier.multiply(a, b);
        BigInteger expected = a.multiply(b);
        assertEquals(expected, actual);
    }


    @Test
    public void shouldMultiplyAssignmentNumbers() {
        BigInteger a = new BigInteger("3141592653589793238462643383279502884197169399375105820974944592");
        BigInteger b = new BigInteger("2718281828459045235360287471352662497757247093699959574966967627");
        BigInteger actual = numberMultiplier.multiply(a, b);
        System.out.println(actual); //Great, it worked!
    }
}