#ifndef STACK_H
#define STACK_H

#define MaxE1 20
#define Nil -1

typedef int infotype;

struct Stack {
    infotype info[MaxE1];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
#endif