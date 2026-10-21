
#include "Exceptions.h"

#include <cmath>
#include <stdexcept>

TriangleException::TriangleException(double a, double b)
    : a(a), b(b)
{}

double TriangleException::getA() const
{
    return a;
}

double TriangleException::getB() const
{
    return b;
}

TriangleStandardException::TriangleStandardException(double a, double b)
    : a(a), b(b)
{}

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

void calculateAngles1(double a, double b, double& angleA, double& angleB)
{
    if (a <= 0 || b <= 0)
        throw std::invalid_argument("Catheti must be greater than zero.");

    double c = std::sqrt(a * a + b * b);

    angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
    angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);
}

bool calculateAngles2(double a, double b, double& angleA, double& angleB) noexcept
{
    try
    {
        if (a <= 0 || b <= 0)
            throw std::invalid_argument("Catheti must be greater than zero.");

        double c = std::sqrt(a * a + b * b);

        angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
        angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

void calculateAngles3(double a, double b, double& angleA, double& angleB) noexcept(false)
{
    if (a <= 0 || b <= 0)
        throw std::invalid_argument("Catheti must be greater than zero.");

    double c = std::sqrt(a * a + b * b);

    angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
    angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);
}

void calculateAngles4a(double a, double b, double& angleA, double& angleB)
{
    if (a <= 0 || b <= 0)
        throw TriangleEmptyException();

    double c = std::sqrt(a * a + b * b);

    angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
    angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);
}

void calculateAngles4b(double a, double b, double& angleA, double& angleB)
{
    if (a <= 0 || b <= 0)
        throw TriangleException(a, b);

    double c = std::sqrt(a * a + b * b);

    angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
    angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);
}

void calculateAngles4c(double a, double b, double& angleA, double& angleB)
{
    if (a <= 0 || b <= 0)
        throw TriangleStandardException(a, b);

    double c = std::sqrt(a * a + b * b);

    angleA = std::asin(a / c) * 180.0 / std::acos(-1.0);
    angleB = std::asin(b / c) * 180.0 / std::acos(-1.0);
}
