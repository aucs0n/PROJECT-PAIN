/*
================================================================================
FILE        : main.c
AUTHOR      : Justine Catalan, Wmffre Requieron, Lorenz Soriano
DESCRIPTION : Header files of the search project
COPYRIGHT   : 20 march 2024
REVISION HISTORY
Date: 				By: 		Description:
3/19/2024      Lorenz Soriano   Making of the Code
3/19/2024      Justine Catalan  Fixing bugs
3/20/2024      Wmffre Requieron Documentation
================================================================================
*/
/*
================================================================================
Header Files
================================================================================
*/
#include "stack.h"

/*
================================================================================
FUNCTION    : main
DESCRIPTION : executes the main function of the stack project.
RETURNS     : return 0
================================================================================
*/
int main() {
  int decimalNumber;
  printf("DECIMAL: ");
  scanf("%d", &decimalNumber);

  decimalToHexadecimal(decimalNumber);

  return 0;
}

