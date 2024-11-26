#include "Fraction.h"
#include "MyVector.h"
#include <iostream>
using namespace std;

int main()
{
    try
    {
        // create a vector of integers
        MyVector<int> intVector;
        intVector.add(1);
        intVector.add(2);
        intVector.add(3);
        cout << "Integer Vector: " << intVector.toString() << endl;

        // create an array of fractions
        Fraction fractions[] = {Fraction(2, 1), Fraction(4, 3), Fraction(6, 5)};

        // create a vector of fractions
        MyVector<Fraction> fractionVector(fractions, 3);
        fractionVector.add(Fraction(7, 8));
        cout << "Fraction Vector: " << fractionVector.toString() << endl;

        // reverse the fraction vector
        fractionVector.reverse();
        cout << "Reversed Fraction Vector: " << fractionVector.toString() << endl;

        // test exception handling
        cout << "Accessing out-of-range index:" << endl;
        cout << intVector.getItem(5) << endl; // this will throw an exception
    }
    catch (const exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
