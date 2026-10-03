#include "Fraction.h"
#include <iostream>
#include <sstream>

using namespace std;

Fraction::Fraction()
{
    first = 0;
    second = 0;
}

Fraction::Fraction(long f, unsigned short s)
{
    first = f;
    second = s;
}

Fraction::Fraction(const Fraction& other)
{
    first = other.first;
    second = other.second;
}

Fraction::~Fraction()
{}

void Fraction::Init(long f, unsigned short s)
{
    first = f;
    second = s;
}

void Fraction::Read()
{
    cout << "Enter integer part: ";
    cin >> first;

    cout << "Enter fractional part: ";
    cin >> second;
}

void Fraction::Display()
{
    cout << "Integer part: " << first << endl;
    cout << "Fractional part: " << second << endl;
}

string Fraction::toString()
{
    stringstream sstring;

    sstring << first << "." << second;

    return sstring.str();
}

Fraction Fraction::operator+(const Fraction& other) const
{
    Fraction result;

    result.first = first + other.first;
    result.second = second + other.second;

    if (result.second >= 100)
    {
        result.first++;
        result.second -= 100;
    }

    return result;
}

Fraction Fraction::operator-(const Fraction& other) const
{
    Fraction result;

    result.first = first - other.first;

    if (second >= other.second)
    {
        result.second = second - other.second;
    }
    else
    {
        result.first--;
        result.second = 100 + second - other.second;
    }

    return result;
}

Fraction Fraction::operator*(const Fraction& other) const
{
    Fraction result;

    unsigned long number1 = first * 100 + second;
    unsigned long number2 = other.first * 100 + other.second;

    unsigned long answer = number1 * number2;

    result.first = answer / 10000;
    result.second = (answer % 10000) / 100;

    return result;
}

bool Fraction::operator==(const Fraction& other) const
{
    return first == other.first && second == other.second;
}

bool Fraction::operator!=(const Fraction& other) const
{
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const
{
    if (first < other.first)
        return true;

    if (first == other.first && second < other.second)
        return true;

    return false;
}

bool Fraction::operator>(const Fraction& other) const
{
    return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const
{
    return *this < other || *this == other;
}

bool Fraction::operator>=(const Fraction& other) const
{
    return *this > other || *this == other;
}

Fraction Fraction::Add(Fraction other)
{
    return *this + other;
}

Fraction Fraction::Subtract(Fraction other)
{
    return *this - other;
}

Fraction Fraction::Multiply(Fraction other)
{
    return *this * other;
}

bool Fraction::Equal(Fraction other)
{
    return *this == other;
}

bool Fraction::NotEqual(Fraction other)
{
    return !(*this == other);
}

bool Fraction::Less(Fraction other)
{
    if (first < other.first)
        return true;

    if (first == other.first && second < other.second)
        return true;

    return false;
}

bool Fraction::Greater(Fraction other)
{
    if (first > other.first)
        return true;

    if (first == other.first && second > other.second)
        return true;

    return false;
}

bool Fraction::LessOrEqual(Fraction other)
{
    return Less(other) || Equal(other);
}

bool Fraction::GreaterOrEqual(Fraction other)
{
    return Greater(other) || Equal(other);
}