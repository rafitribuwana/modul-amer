#include "stack.h"
#include <iostream>
using namespace std;
void CreateStack(Stack &S) {
    S.top = Nil;
}
bool isEmpty(Stack S) {
    return S.top == Nil;
}
bool isFull(Stack S) {
    return S.top == MaxE1 - 1;
}
void push(Stack &S, infotype X) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = X;
    }
}
infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype X = S.info[S.top];
        S.top--;
        return X;
    } else {
        cout << "Stack Kosong" << endl;
    }
    return -1; 
}
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
        return;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}
void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1);
        CreateStack(temp2);
        while (!isEmpty(S)) {push(temp1, pop(S));}
        while (!isEmpty(temp1)) {push(temp2, pop(temp1));}
        while (!isEmpty(temp2)) {push(S, pop(temp2));}
    }
}