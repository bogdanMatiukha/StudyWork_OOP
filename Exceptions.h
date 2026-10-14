#pragma once

#include <exception>

void calculateAngles1(double a, double b, double& angleA, double& angleB);

void calculateAngles2(double a, double b, double& angleA, double& angleB) throw();

void calculateAngles3(double a, double b, double& angleA, double& angleB) noexcept(false);

class EmptyException
{};

class TriangleException
{
public:
    double a;
    double b;

    TriangleException(double a, double b);
};

class TriangleStandardException : public std::exception
{
    double a;
    double b;

public:
    TriangleStandardException(double a, double b);

    const char* what() const noexcept override;

    double getA() const;
    double getB() const;
};

void calculateAngles4(double a, double b, double& angleA, double& angleB);