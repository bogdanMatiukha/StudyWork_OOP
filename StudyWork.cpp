#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction first;
    Fraction second;

    first.Init(7, 50);
    second.Init(2, 25);

    cout << "First fraction: " << first.toString() << endl;
    cout << "Second fraction: " << second.toString() << endl;

    Fraction sum = first.Add(second);
    Fraction difference = first.Subtract(second);
    Fraction product = first.Multiply(second);

    cout << "\nAddition: " << sum.toString() << endl;
    cout << "Subtraction: " << difference.toString() << endl;
    cout << "Multiplication: " << product.toString() << endl;

    cout << "\nComparison:" << endl;

    cout << "Equal: " << first.Equal(second) << endl;
    cout << "Not equal: " << first.NotEqual(second) << endl;
    cout << "Less: " << first.Less(second) << endl;
    cout << "Greater: " << first.Greater(second) << endl;
    cout << "Less or equal: " << first.LessOrEqual(second) << endl;
    cout << "Greater or equal: " << first.GreaterOrEqual(second) << endl;

    cout << "\nEnter first fraction:" << endl;
    first.Read();

    cout << "\nYour fraction: " << first.toString() << endl;

    return 0;
}