#include "PhoneCall.h"
#include <iostream>
#include <sstream>

using namespace std;

void PhoneCall::Init(int f, double s)
{
    if (f > 0 && s > 0)
    {
        first = f;
        second = s;
    }
    else
    {
        cout << "Error: Values must be positive!" << endl;
        first = 1;
        second = 1.0;
    }
}

void PhoneCall::Read()
{
    do
    {
        cout << "Enter call duration (minutes): ";
        cin >> first;

        if (first <= 0)
            cout << "Error! Duration must be positive" << endl;

    } while (first <= 0);

    do
    {
        cout << "Enter cost per minute (UAH): ";
        cin >> second;

        if (second <= 0)
            cout << "Error! Cost must be positive" << endl;

    } while (second <= 0);
}

void PhoneCall::Display()
{
    cout << "Call duration: " << first << " minutes" << endl;
    cout << "Cost per minute: " << second << " UAH" << endl;
}

double PhoneCall::cost()
{
    return first * second;
}

string PhoneCall::ToString()
{
    stringstream sstring;

    sstring << "Call duration: " << first << " minutes\n"
        << "Cost per minute: " << second << " UAH\n"
        << "Total cost: " << cost() << " UAH";

    return sstring.str();
}