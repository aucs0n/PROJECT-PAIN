#include <stdlib.h>
#include "header.h"
#include "primeChecking.c"

void initializeArray(void) {
    for (int i = 0; i < capacity; i++) {
        database[i] = NULL;
    }
}
