#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    Fraction first;
    Fraction second(2, 25);
    Fraction third(second);

    first.Init(7, 50);

    cout << "First fraction: " << first.toString() << endl;
    cout << "Second fraction: " << second.toString() << endl;
    cout << "Third fraction: " << third.toString() << endl;

    Fraction sum = first + second;
    Fraction difference = first - second;
    Fraction product = first * second;

    cout << "\nAddition: " << sum.toString() << endl;
    cout << "Subtraction: " << difference.toString() << endl;
    cout << "Multiplication: " << product.toString() << endl;

    cout << "\nComparison:" << endl;
    cout << "Equal: " << (first == second) << endl;
    cout << "Not Equal: " << (first != second) << endl;
    cout << "Less Than: " << (first < second) << endl;
    cout << "Greater Than: " << (first > second) << endl;
    cout << "Less Than or Equal: " << (first <= second) << endl;
    cout << "Greater Than or Equal: " << (first >= second) << endl;

    cout << "\nEnter first fraction:" << endl;
    first.Read();

    cout << "\nYour fraction: " << first.toString() << endl;

    return 0;
}