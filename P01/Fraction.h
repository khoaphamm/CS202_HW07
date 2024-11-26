#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor with default values
    Fraction(int n = 0, int d = 1);

    // Accessors
    int getNumerator() const;
    int getDenominator() const;

    // Overloaded operators for equality and comparison
    bool operator==(const Fraction &f) const;
    bool operator<(const Fraction &f) const;
    bool operator>(const Fraction &f) const;

    // Friend function for output
    friend ostream &operator<<(ostream &os, const Fraction &f);
};

#endif
