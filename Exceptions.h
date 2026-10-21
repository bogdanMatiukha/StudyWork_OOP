#pragma once

#include <exception>

class TriangleEmptyException
{};

class TriangleException
{
private:
    double a;
    double b;

public:
    TriangleException(double a, double b);

    double getA() const;
    double getB() const;
};

class TriangleStandardException : public std::exception
{
private:
    double a;
    double b;

public:
    TriangleStandardException(double a, double b);

    const char* what() const noexcept override;

    double getA() const;
    double getB() const;
};

void calculateAngles1(double a, double b, double& angleA, double& angleB);

bool calculateAngles2(double a, double b, double& angleA, double& angleB) noexcept;

void calculateAngles3(double a, double b, double& angleA, double& angleB) noexcept(false);

void calculateAngles4a(double a, double b, double& angleA, double& angleB);
void calculateAngles4b(double a, double b, double& angleA, double& angleB);
void calculateAngles4c(double a, double b, double& angleA, double& angleB);
