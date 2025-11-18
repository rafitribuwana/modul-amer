#ifndef STACK_H
#define STACK_H

#define MAX 20

typedef int infotype;

typedef struct {
    infotype info[MAX];
    int top;
} Stack;

void CreateStack(Stack *S);
void push(Stack *S, infotype x);
infotype pop(Stack *S);
void printInfo(Stack S);
void balikStack(Stack *S);
void pushAscending(Stack *S, infotype x);
void GetInputStream(Stack *S);

#endif
