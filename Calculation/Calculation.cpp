
#include "stdafx.h"
#include "Addition.h" 
#include "Multiply.h" 
#include <stdio.h> 

int main()

{
        int x = 4;
        int y = 5;

        int z1 = CAddition::twoValues(x, y);
        printf("\nAddition Result: %d\n", z1);

        int z2 = CMultiply::twoValues(x, y);
        printf("Multiply Result: %d\n", z2);

//        delete corporation;
        return 0;
}
