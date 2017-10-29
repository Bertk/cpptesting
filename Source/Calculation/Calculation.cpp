
#include "stdafx.h"
#include "Addition.h" 
#include "Multiply.h" 
#include <stdio.h> 

int main()

{
        const int x = 4;
        const int y = 5;

        const int z1 = CAddition::twoValues(x, y);
        printf("\nAddition Result: %d\n", z1);

        const int z2 = CMultiply::twoValues(x, y);
        printf("Multiply Result: %d\n", z2);

//        delete corporation;
        return 0;
}
