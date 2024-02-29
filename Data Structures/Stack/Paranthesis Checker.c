#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 100

int TOP = -1;

bool isfull() {
    if (TOP >= MAX_SIZE - 1) {
        return true;
    } else {
        return false;
    }
}

bool isempty() {
    if (TOP == -1) {
        return true;
    } else {
        return false;
    }
}

void push(char A, char stack[MAX_SIZE]) {
    if (isfull()) {
        printf("The stack is already full");
    } else {
        TOP = TOP + 1;
        stack[TOP] = A;
    }
}

void pop(char *k, char stack[MAX_SIZE]) {
    if (isempty()) {
        printf("The stack is empty");
    } else {
        *k = stack[TOP];
        TOP = TOP - 1;
    }
}

int main() {
    int n;
    int validity;
    char stack[MAX_SIZE];
    char exp[MAX_SIZE];
    char k;
    printf("Enter an expression to check validity: ");
    fgets(exp, sizeof exp, stdin);
    n = strlen(exp);

    for (int i = 0; i < n; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i], stack);
        }

        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (TOP == -1) {
                validity = 0;
            } else {
                pop(&k, stack);

                if (k == '(') {
                    if (exp[i] == ')') {
                        validity = 1;
                    } else {
                        validity = 0;
                    }
                } else if (k == '{') {
                    if (exp[i] == '}') {
                        validity = 1;
                    } else {
                        validity = 0;
                    }
                } else {
                    if (exp[i] == '[') {
                        validity = 1;
                    } else {
                        validity = 0;
                    }
                }
            }
        }
    }
    if (TOP != -1) {
        validity = 0;
    }

    if (validity == 1) {
        printf("The expression is valid");
    } else {
        printf("The expression is invalid");
    }
    return 0;
}
