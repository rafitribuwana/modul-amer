#include "stack.h"
#include "stack.cpp"
#include <iostream>

int main () {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);


    cout << "Stack Awal: "<< endl;
    printInfo(S);

    cout << "Balik Stack" << endl;
    balikStack(S);
    cout << "Stack Setelah dibalik: " << endl;
    printInfo(S);
    return 0;
}