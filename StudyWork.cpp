#include <iostream>

#include "Exceptions.h"

using namespace std;

int main()
{
    double a, b;
    double angleA, angleB;

    cout << "Enter cathetus A: ";
    cin >> a;

    cout << "Enter cathetus B: ";
    cin >> b;

    cout << "\n===== 1. Without exception specification =====\n";

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

    cout << "\n===== 2. With throw() specification =====\n";

    try
    {
        calculateAngles2(a, b, angleA, angleB);

        cout << "Angle A = " << angleA << " degrees\n";
        cout << "Angle B = " << angleB << " degrees\n";
    }
    catch (const exception& e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Caught unknown exception." << endl;
    }

    cout << "\n===== 3. With standard exception specification =====\n";

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
    catch (const exception& e)
    {
        cout << "Caught standard exception: " << e.what() << endl;
    }

    cout << "\n===== 4. With custom exception =====\n";

    try
    {
        calculateAngles4(a, b, angleA, angleB);

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