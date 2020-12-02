#include "newton.h"

// write the function named newtonApprox here

double newtonApprox(double guess, function < double(double) > eval, function < double(double) > deriv, double epsilon)
{
    double x;
    // base case
    if (fabs(eval(guess)) <= epsilon)
    {
        return guess;
    }
    
    x = guess - (eval(guess) / deriv(guess));
    return newtonApprox(x, eval, deriv, epsilon);
}