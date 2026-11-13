
#pragma once

class Triangle
{
protected:
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c);

    Triangle(double medianA, double medianB, double medianC, bool byMedians);

    double getArea() const;

    double getMedian(int side) const;

    double getMidline(int side) const;

    double getSide(int side) const;

    virtual void printInfo() const = 0;

    virtual ~Triangle() = default;
};

class TriangleByVertices : public Triangle
{
public:
    TriangleByVertices(double x1, double y1,
        double x2, double y2,
        double x3, double y3);

    void printInfo() const override;
};

class TriangleBySides : public Triangle
{
public:
    TriangleBySides(double a, double b, double c);

    void printInfo() const override;
};

class TriangleByMedians : public Triangle
{
public:
    TriangleByMedians(double medianA, double medianB, double medianC);

    void printInfo() const override;
};

class RightTriangle : public TriangleBySides
{
public:
    RightTriangle(double legA, double legB);

    double getInscribedRadius() const;

    double getCircumscribedRadius() const;

    void printInfo() const override;
};
