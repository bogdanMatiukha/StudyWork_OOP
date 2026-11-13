
#include "Triangle.h"

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

static void validateTriangle(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a)
    {
        throw invalid_argument("Invalid triangle sides!");
    }
}

Triangle::Triangle(double a, double b, double c)
{
    validateTriangle(a, b, c);

    this->a = a;
    this->b = b;
    this->c = c;
}

Triangle::Triangle(double medianA, double medianB,
    double medianC, bool byMedians)
{
    if (!byMedians || medianA <= 0 ||
        medianB <= 0 || medianC <= 0 ||
        medianA + medianB <= medianC ||
        medianA + medianC <= medianB ||
        medianB + medianC <= medianA)
    {
        throw invalid_argument("Invalid medians!");
    }

    a = (2.0 / 3.0) * sqrt(
        2 * medianB * medianB +
        2 * medianC * medianC -
        medianA * medianA);

    b = (2.0 / 3.0) * sqrt(
        2 * medianA * medianA +
        2 * medianC * medianC -
        medianB * medianB);

    c = (2.0 / 3.0) * sqrt(
        2 * medianA * medianA +
        2 * medianB * medianB -
        medianC * medianC);

    validateTriangle(a, b, c);
}

double Triangle::getArea() const
{
    double p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::getMedian(int side) const
{
    if (side < 1 || side > 3)
    {
        throw invalid_argument("Side must be from 1 to 3!");
    }

    double x, y, z;

    if (side == 1)
    {
        x = a;
        y = b;
        z = c;
    }
    else if (side == 2)
    {
        x = b;
        y = a;
        z = c;
    }
    else
    {
        x = c;
        y = a;
        z = b;
    }

    return 0.5 * sqrt(2 * y * y + 2 * z * z - x * x);
}

double Triangle::getMidline(int side) const
{
    return getSide(side) / 2.0;
}

// Повертає довжину вибраної сторони
double Triangle::getSide(int side) const
{
    if (side == 1) return a;
    if (side == 2) return b;
    if (side == 3) return c;

    throw invalid_argument("Side must be from 1 to 3!");
}

TriangleByVertices::TriangleByVertices(
    double x1, double y1,
    double x2, double y2,
    double x3, double y3)
    : Triangle(
        sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2)),
        sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)),
        sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)))
{}

void TriangleByVertices::printInfo() const
{
    cout << "Triangle by vertices" << endl;
    cout << "Side A: " << a << endl;
    cout << "Side B: " << b << endl;
    cout << "Side C: " << c << endl;
    cout << "Area: " << getArea() << endl;
}

TriangleBySides::TriangleBySides(double a, double b, double c)
    : Triangle(a, b, c)
{}

void TriangleBySides::printInfo() const
{
    cout << "Triangle by sides" << endl;
    cout << "Side A: " << a << endl;
    cout << "Side B: " << b << endl;
    cout << "Side C: " << c << endl;
    cout << "Area: " << getArea() << endl;
}

TriangleByMedians::TriangleByMedians(
    double medianA, double medianB, double medianC)
    : Triangle(medianA, medianB, medianC, true)
{}

void TriangleByMedians::printInfo() const
{
    cout << "Triangle by medians" << endl;
    cout << "Side A: " << a << endl;
    cout << "Side B: " << b << endl;
    cout << "Side C: " << c << endl;
    cout << "Area: " << getArea() << endl;
}

RightTriangle::RightTriangle(double legA, double legB)
    : TriangleBySides(
        legA,
        legB,
        sqrt(legA* legA + legB * legB))
{}

double RightTriangle::getInscribedRadius() const
{
    return (a + b - c) / 2.0;
}

double RightTriangle::getCircumscribedRadius() const
{
    return c / 2.0;
}

void RightTriangle::printInfo() const
{
    cout << "Right triangle" << endl;
    cout << "Leg A: " << a << endl;
    cout << "Leg B: " << b << endl;
    cout << "Hypotenuse: " << c << endl;
    cout << "Area: " << getArea() << endl;

    cout << "Inscribed radius: "
        << getInscribedRadius() << endl;

    cout << "Circumscribed radius: "
        << getCircumscribedRadius() << endl;
}
