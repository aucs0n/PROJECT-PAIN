#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    // Removing spaces from the input expression
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] != ' ') {
            infix[j++] = infix[i];
        }
    }
    infix[j] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
