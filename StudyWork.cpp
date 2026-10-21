
#include <iostream>
#include <stdexcept>
#include "Exceptions.h"

using namespace std;

int main()
{
    double a, b;
    double angleA = 0, angleB = 0;

    cout << "Enter cathetus A: ";
    if (!(cin >> a))
    {
        cout << "Invalid input." << endl;
        return 1;
    }

    cout << "Enter cathetus B: ";
    if (!(cin >> b))
    {
        cout << "Invalid input." << endl;
        return 1;
    }

    cout << "\n1. Without exception specification\n";

    try
    {
        calculateAngles1(a, b, angleA, angleB);
        cout << "Angle A = " << angleA << " degrees\n";
        cout << "Angle B = " << angleB << " degrees\n";
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "\n2. With noexcept\n";

    if (calculateAngles2(a, b, angleA, angleB))
    {
        cout << "Angle A = " << angleA << " degrees\n";
        cout << "Angle B = " << angleB << " degrees\n";
    }
    else
    {
        cout << "Invalid catheti. Exception handled inside the function.\n";
    }

    cout << "\n3. With noexcept(false) and standard exception\n";

    try
    {
        calculateAngles3(a, b, angleA, angleB);
        cout << "Angle A = " << angleA << " degrees\n";
        cout << "Angle B = " << angleB << " degrees\n";
    }
    catch (const invalid_argument& e)
    {
        cout << "Caught invalid_argument: " << e.what() << endl;
    }

    cout << "\n4a. Empty custom exception\n";

    try
    {
        calculateAngles4a(a, b, angleA, angleB);
        cout << "Angle A = " << angleA << " degrees\n";
        cout << "Angle B = " << angleB << " degrees\n";
    }
    catch (const TriangleEmptyException&)
    {
        cout << "Caught empty custom exception.\n";
    }

    cout << "\n4b. Independent custom exception\n";

    try
    {
        calculateAngles4b(a, b, angleA, angleB);
        cout << "Angle A = " << angleA << " degrees\n";
        cout << "Angle B = " << angleB << " degrees\n";
    }
    catch (const TriangleException& e)
    {
        cout << "Caught custom exception.\n";
        cout << "Cathetus A = " << e.getA() << endl;
        cout << "Cathetus B = " << e.getB() << endl;
    }

    cout << "\n4c. Exception derived from std::exception\n";

    try
    {
        calculateAngles4c(a, b, angleA, angleB);
        cout << "Angle A = " << angleA << " degrees\n";
        cout << "Angle B = " << angleB << " degrees\n";
    }
    catch (const TriangleStandardException& e)
    {
        cout << "Caught custom exception: " << e.what() << endl;
        cout << "Cathetus A = " << e.getA() << endl;
        cout << "Cathetus B = " << e.getB() << endl;
    }

    return 0;
}
