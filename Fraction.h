#pragma once
#include <string>

using namespace std;

class Fraction
{
private:
    long first;
    unsigned short second;

public:
    void Init(long f, unsigned short s);
    void Read();
    void Display();
    string toString();

    Fraction Add(Fraction other);
    Fraction Subtract(Fraction other);
    Fraction Multiply(Fraction other);

    bool Equal(Fraction other);
    bool NotEqual(Fraction other);
    bool Less(Fraction other);
    bool Greater(Fraction other);
    bool LessOrEqual(Fraction other);
    bool GreaterOrEqual(Fraction other);
};