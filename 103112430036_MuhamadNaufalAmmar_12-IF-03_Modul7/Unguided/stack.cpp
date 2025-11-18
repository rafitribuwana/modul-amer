#include <iostream>
#include "stack.h"
using namespace std;

void CreateStack(Stack *S) {
    S->top = 0;
}

void push(Stack *S, infotype x) {
    if (S->top < MAX) {
        S->info[S->top] = x;
        S->top++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack *S) {
    if (S->top > 0) {
        S->top--;
        return S->info[S->top];
    } else {
        cout << "Stack kosong!" << endl;
        return -999;
    }
}

void printInfo(Stack S) {
    if (S.top == 0) {
        cout << "Stack kosong" << endl;
    } else {
        for (int i = S.top - 1; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack *S) {
    Stack Temp;
    CreateStack(&Temp);

    while (S->top > 0) {
        push(&Temp, pop(S));
    }

    *S = Temp;
}

void pushAscending(Stack *S, infotype x) {
    Stack Temp;
    CreateStack(&Temp);

    while (S->top > 0 && S->info[S->top - 1] > x) {
        push(&Temp, pop(S));
    }

    push(S, x);

    while (Temp.top > 0) {
        push(S, pop(&Temp));
    }
}

void GetInputStream(Stack *S) {
    string input;
    cin >> input;

    for (char c : input) {
        if (isdigit(c)) {
            int digit = c - '0';
            push(S, digit);
        }
    }
}
