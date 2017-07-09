#include "stdafx.h"
#include "Multiply.h"


CMultiply::CMultiply(void)
{
}

// This is the constructor of a class that has been exported.
// see Calculation.h for the class definition
int CMultiply::twoValues(const int x, const int y)
{
    return x * y;
}

