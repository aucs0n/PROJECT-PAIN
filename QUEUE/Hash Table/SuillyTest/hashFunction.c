#include <stdlib.h>
#include <string.h>
#include "header.h"

int hashFunction(int keyValue){
    return (keyValue % capacity);
}
