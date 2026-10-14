#pragma once
#include <string>

#ifdef FRACTIONLIBRARY_EXPORTS
#define FRACTION_API __declspec(dllexport)
#else
#define FRACTION_API __declspec(dllimport)
#endif

class FRACTION_API Fraction
{
    long first;
    unsigned short second;

public:
    Fraction();
    Fraction(long f, unsigned short s);
    Fraction(const Fraction& other);
    ~Fraction();

    void Init(long f, unsigned short s);
    void Read();
    void Display();
    std::string toString();

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

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