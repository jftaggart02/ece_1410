#include "rational.h"
#include <iostream>
#include <string>
#define EXIT_FAILURE 1


// PUBLIC MEMBER FUNCTIONS:

Rational::Rational(int n, int d) {

    // Set numerator and denominator to given values
    m_numerator = n;
    m_denominator = d;
    

    // Reduce fraction and clean up negative signs
    this->reduce();
    this->clean_negatives();

}

int Rational::get_numerator() {

    return m_numerator;

}

int Rational::get_denominator() {

    return m_denominator;

}

void Rational::add(int n, int d) {

    // Add given values to our fraction
    int new_numerator = m_numerator*d + n*m_denominator;
    int new_denominator = m_denominator*d;
    
    m_numerator = new_numerator;
    m_denominator = new_denominator;

    // Reduce fraction and clean up negative signs
    this->reduce();
    this->clean_negatives();

}

void Rational::sub(int n, int d) {

    // Subtract given values from our fraction
    int new_numerator = m_numerator*d - n*m_denominator;
    int new_denominator = m_denominator*d;
    
    m_numerator = new_numerator;
    m_denominator = new_denominator;

    // Reduce fraction and clean up negative signs
    this->reduce();
    this->clean_negatives();
    
}

void Rational::mul(int n, int d) {

    // Subtract given values from numerator and denominator
    m_numerator *= n;
    m_denominator *= d;

    // Reduce fraction and clean up negative signs
    this->reduce();
    this->clean_negatives();

}

void Rational::div(int n, int d) {

    // Subtract given values from numerator and denominator
    m_numerator *= d;
    m_denominator *= n;

    // Reduce fraction and clean up negative signs
    this->reduce();
    this->clean_negatives();

}


// PRIVATE MEMBER FUNCTIONS:

/*
PSEUDOCODE for Rational::reduce()

How to reduce fractions:

Loop

    Divide both numerator and denominator by n, which starts at 2 and increases by one each loop iteration.

    If the remainder is 0 for both, set numerator and denominator to new divided values.

    Stop when n becomes larger than either the numerator or denominator.

    Run this loop over and over until n becomes larager than the numerator or denominator.

Endloop
*/

void Rational::reduce() {

    bool fully_reduced = false;

    while (!fully_reduced) {

        for (int i = 2; i <= m_numerator || i <= m_denominator; i++) {

            int n_remainder = m_numerator % i;
            int d_remainder = m_denominator % i;

            if (n_remainder == 0 && d_remainder == 0) {

                m_numerator = m_numerator / i;
                m_denominator = m_denominator / i;
                break;

            }

            if (i == m_numerator || i == m_denominator) {

                fully_reduced = true;
                break;

            }

        }

    }

}

void Rational::clean_negatives() {

    // If both numerator and denominator are negative, make them both positive.
    if (m_numerator < 0 && m_denominator < 0) {

        m_numerator *= -1;
        m_denominator *= -1;

    }
    // If denominator is negative, make that positive and make the numerator negative.
    else if (m_numerator >= 0 && m_denominator < 0) {

        m_numerator *= -1;
        m_denominator *= -1;

    }

}