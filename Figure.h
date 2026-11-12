
#pragma once

class Figure
{
protected:
    double centerX;
    double centerY;
    double angle;
    double scale;

public:
    Figure(double x = 0, double y = 0,
        double angle = 0, double scale = 1);

    virtual void show() = 0;
    virtual void hide() = 0;

    virtual void rotate(double degrees);
    virtual void move(double dx, double dy);

    virtual ~Figure() = default;
};

class Rectangle : public Figure
{
private:
    double width;
    double height;
    bool visible;

public:
    Rectangle(double x, double y,
        double width, double height);

    void show() override;
    void hide() override;

    void printInfo() const;
};
