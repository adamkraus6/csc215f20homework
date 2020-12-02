#include "Circle.h"
#include "..\catch.hpp"

TEST_CASE("default constructor")
{
    Circle c;
    REQUIRE(c.getRadius() == 0);
}

TEST_CASE("constructor")
{
    Circle* c = new Circle(6);
    REQUIRE(c->getRadius() == 6);
}

TEST_CASE("setRadius")
{
    Circle* c = new Circle(6);

    SECTION("positive radius")
    {
        REQUIRE(c->setRadius(10) == true);
        REQUIRE(c->getRadius() == 10);
    }
    
    SECTION("zero radius")
    {
        REQUIRE(c->setRadius(0) == false);
    }

    SECTION("negative radius")
    {
        REQUIRE(c->setRadius(-10) == false);
    }
}

TEST_CASE("getRadius")
{
    SECTION("default")
    {
        Circle* c = new Circle();
        REQUIRE(c->getRadius() == 0);
    }

    SECTION("normal")
    {
        Circle* c = new Circle(6);
        REQUIRE(c->getRadius() == 6);
    }
}

TEST_CASE("getDiameter")
{
    SECTION("default")
    {
        Circle* c = new Circle();
        REQUIRE(c->getDiameter() == 0);
    }

    SECTION("normal")
    {
        Circle* c = new Circle(6);
        REQUIRE(c->getDiameter() == 12);
    }
}

TEST_CASE("getCircumference")
{
    Circle* c = new Circle(6);
    double circumference = c->getCircumference();
    REQUIRE(circumference - (PI * 12) < 0.001);
}

TEST_CASE("getArea")
{
    SECTION("default")
    {
        Circle* c = new Circle();
        REQUIRE(c->getArea() == 0);
    }

    SECTION("normal")
    {
        Circle* c = new Circle(6);
        double area = c->getArea();
        REQUIRE(area - (PI * 36) < 0.001);
    }
}

TEST_CASE("getSectorArea")
{
    SECTION("default")
    {
        Circle* c = new Circle();
        REQUIRE(c->getSectorArea(90) == 0);
        REQUIRE(c->getSectorArea(180) == 0);
    }

    SECTION("90 degrees")
    {
        Circle* c = new Circle(6);
        double area = c->getSectorArea(90);
        REQUIRE(area - (PI * 9) < 0.001);
    }

    SECTION("180 degrees")
    {
        Circle* c = new Circle(6);
        double area = c->getSectorArea(180);
        REQUIRE(area - (PI * 18) < 0.001);
    }
}