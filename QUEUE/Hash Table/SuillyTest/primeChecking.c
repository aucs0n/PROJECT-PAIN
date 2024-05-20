#include <stdlib.h>
#include <math.h>
#include "header.h"

int checkPrime (int n){
    int i;
    if (n == 1 || n == 0){
        return 0;
    }
    for (i = 2; i < n/2; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int getPrime (int n){
    if (n % 2 == 0){
        n += 2;
    }
    while (!checkPrime(n)){
        n += 2;
    }
    return n;
}
