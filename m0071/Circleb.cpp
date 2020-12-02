#include "Circle.h"

bool Circle::setRadius(double newRadius)
{
    if (newRadius <= 0)
    {
        return false;
    }

    theRadius = newRadius;
    return true;
}

double Circle::getRadius()
{
    return theRadius;
}

double Circle::getDiameter()
{
    return 2 * theRadius;
}

double Circle::getCircumference()
{
    return PI * getDiameter();
}

double Circle::getArea()
{
    return PI * theRadius * theRadius;
}

double Circle::getSectorArea(double angle)
{
    return (angle / 360) * PI * theRadius * theRadius;
}