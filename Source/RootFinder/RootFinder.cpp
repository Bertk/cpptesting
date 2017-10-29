// Sample1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <math.h>
#include <stdexcept> 
#include "RootFinder.h"


// Find the square root of a number.  
double CRootFinder::SquareRoot(double v)
{
    // Validate parameter:  
    if (v < 0.0)
    {
        throw std::out_of_range("Can't do square roots of negatives");
    }

    double result = v;
    double diff = v;
    while (diff > result / 1000)
    {
        const double oldResult = result;
        result = result - (result*result - v) / (2 * result);
        diff = fabs(oldResult - result);
    }
    return result;
}
