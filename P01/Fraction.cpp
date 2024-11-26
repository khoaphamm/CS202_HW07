#include "Fraction.h"

// Constructor with validation for zero denominator
Fraction::Fraction(int n, int d) : numerator(n), denominator(d)
{
    if (d == 0)
    {
        throw invalid_argument("Denominator cannot be zero");
    }
}

// Accessors
int Fraction::getNumerator() const
{
    return numerator;
}

int Fraction::getDenominator() const
{
    return denominator;
}

// Equality operator
bool Fraction::operator==(const Fraction &f) const
{
    return numerator * f.denominator == denominator * f.numerator;
}

// Less-than operator
bool Fraction::operator<(const Fraction &f) const
{
    return numerator * f.denominator < denominator * f.numerator;
}

// Greater-than operator
bool Fraction::operator>(const Fraction &f) const
{
    return numerator * f.denominator > denominator * f.numerator;
}

// Output operator
ostream &operator<<(ostream &os, const Fraction &f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}
