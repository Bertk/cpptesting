#pragma once
#ifndef CALCULATION_API

#ifdef CALCULATION_EXPORTS
#define CALCULATION_API __declspec(dllexport)
#else
#define CALCULATION_API __declspec(dllimport)
#endif

#endif
// This class is exported from the Calculation.dll
class CALCULATION_API CMultiply {
public:
    CMultiply(void);
    static int twoValues(const int x, const int y);
};
