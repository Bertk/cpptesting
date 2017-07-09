#include "stdafx.h"
#include "Addition.h"


CAddition::CAddition(void)
{
}

// This is the constructor of a class that has been exported.
// see Calculation.h for the class definition
int CAddition::twoValues(const int x, const int y)
{
        return x + y;
}

