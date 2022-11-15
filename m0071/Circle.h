const double PI = 3.14159;

class Circle
{
public:
    Circle();
    ~Circle();
    Circle(double radius);
    Circle(Circle& c);

    bool setRadius(double newRadius);
    double getRadius();
    double getDiameter();
    double getCircumference();
    double getArea();
    double getSectorArea(double angle);

private:
    double theRadius;
};