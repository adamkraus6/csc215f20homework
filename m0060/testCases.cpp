#include "newton.h"
#include "..\catch.hpp"

double f( double x )
{
    return pow( x, 3 ) + 2;
}

double fP( double x )
{
    return 3 * pow( x, 2 );
}

TEST_CASE( "newtonApprox - x^3 + 2" )
{
    double epsilon = .001;
    double n = 2;
    double ans;
    
    // note, you pass the name of your functions
    ans = newtonApprox( n, f, fP, epsilon ); 

    REQUIRE( fabs( f( ans ) ) <= epsilon );
}

double h(double x)
{
    return 2 * pow(x, 7) + 12;
}

double hP(double x)
{
    return 14 * pow(x, 6);
}

TEST_CASE("newtonApprox - 2x^7 + 12")
{
    double epsilon = .001;
    double n = -1;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, h, hP, epsilon);

    REQUIRE(fabs(h(ans)) <= epsilon);
}

double g(double x)
{
    return (7 / 3) * pow(x, 3) + 6 * x + 81;
}

double gP(double x)
{
    return 7 * pow(x, 2) + 6;
}

TEST_CASE("newtonApprox - 7/3x^2 + 6x + 81")
{
    double epsilon = .001;
    double n = -2;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, g, gP, epsilon);

    REQUIRE(fabs(g(ans)) <= epsilon);
}

double j(double x)
{
    return (57 / 7) * pow(x, 21) + 2 * pow(x, 5) + 17;
}

double jP(double x)
{
    return 171 * pow(x, 20) + 10 * pow(x, 4);
}

TEST_CASE("newtonApprox - 57/7x^21 + 2x^5 + 17")
{
    double epsilon = .001;
    double n = -2;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, j, jP, epsilon);

    REQUIRE(fabs(j(ans)) <= epsilon);
}

double k(double x)
{
    return (61 / 77) * pow(x, 11) + 19 * pow(x, 3) + 2 * x + 11;
}

double kP(double x)
{
    return (61 / 7) * pow(x, 10) + 57 * pow(x, 2) + 2;
}

TEST_CASE("newtonApprox - 61/77x^11 + 19x^3 + 2x + 11")
{
    double epsilon = .001;
    double n = -2;
    double ans;

    // note, you pass the name of your functions
    ans = newtonApprox(n, k, kP, epsilon);

    REQUIRE(fabs(k(ans)) <= epsilon);
}