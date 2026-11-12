
#include "Figure.h"

#include <iostream>
#include <cmath>

using namespace std;

Figure::Figure(double x, double y, double angle, double scale)
{
    centerX = x;
    centerY = y;
    this->angle = angle;
    this->scale = scale;
}

void Figure::rotate(double degrees)
{
    angle = fmod(angle + degrees, 360.0);

    if (angle < 0)
    {
        angle += 360.0;
    }
}

void Figure::move(double dx, double dy)
{
    centerX += dx;
    centerY += dy;
}

Rectangle::Rectangle(double x, double y,
    double width, double height)
    : Figure(x, y)
{
    this->width = width;
    this->height = height;
    visible = false;
}

void Rectangle::show()
{
    if (visible)
    {
        cout << "Rectangle is already visible." << endl;
        return;
    }

    visible = true;

    cout << "Rectangle is displayed." << endl;

    cout << "Center: (" << centerX << ", "
        << centerY << ")" << endl;

    cout << "Width: " << width * scale << endl;
    cout << "Height: " << height * scale << endl;
    cout << "Angle: " << angle << " degrees" << endl;
}

void Rectangle::hide()
{
    if (visible)
    {
        cout << "Rectangle is hidden." << endl;
        visible = false;
    }
    else
    {
        cout << "Rectangle is already hidden." << endl;
    }
}

void Rectangle::printInfo() const
{
    cout << "Center: (" << centerX << ", "
        << centerY << ")" << endl;

    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Angle: " << angle << " degrees" << endl;
    cout << "Scale: " << scale << endl;
}
