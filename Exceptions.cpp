#include "Exceptions.h"

#include <cmath>
#include <stdexcept>

void calculateAngles1(double a, double b, double& angleA, double& angleB)
{
    if (a <= 0 || b <= 0)
        throw std::invalid_argument("Catheti must be greater than zero.");

    double c = std::sqrt(a * a + b * b);

    angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
    angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);
}

void calculateAngles2(double a, double b, double& angleA, double& angleB) throw()
{
    if (a <= 0 || b <= 0)
        throw std::invalid_argument("Catheti must be greater than zero.");

    double c = std::sqrt(a * a + b * b);

    angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
    angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);
}

void calculateAngles3(double a, double b, double& angleA, double& angleB) noexcept(false)
{
    if (a <= 0 || b <= 0)
        throw std::invalid_argument("Catheti must be greater than zero.");

    double c = std::sqrt(a * a + b * b);

    angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
    angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);
}

TriangleException::TriangleException(double a, double b)
{
    this->a = a;
    this->b = b;
}

TriangleStandardException::TriangleStandardException(double a, double b)
{
    this->a = a;
    this->b = b;
}

const char* TriangleStandardException::what() const noexcept
{
    return "Invalid triangle catheti.";
}

double TriangleStandardException::getA() const
{
    return a;
}

double TriangleStandardException::getB() const
{
    return b;
}

void calculateAngles4(double a, double b, double& angleA, double& angleB)
{
    if (a <= 0 || b <= 0)
        throw TriangleStandardException(a, b);

    double c = std::sqrt(a * a + b * b);

    angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
    angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);
}