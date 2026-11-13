
#pragma once

class Triangled
{
protected:
    double a;
    double b;
    double c;

public:
    Triangled(double a, double b, double c);

    Triangled(double medianA, double medianB, double medianC, bool byMedians);

    double getArea() const;

    double getMedian(int side) const;

    double getMidline(int side) const;

    double getSide(int side) const;

    virtual void printInfo() const = 0;

    virtual ~Triangled() = default;
};

class TriangleByVertices : public Triangled
{
public:
    TriangleByVertices(double x1, double y1,
        double x2, double y2,
        double x3, double y3);

    void printInfo() const override;
};

class TriangleBySides : public Triangled
{
public:
    TriangleBySides(double a, double b, double c);

    void printInfo() const override;
};

class TriangleByMedians : public Triangled
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
