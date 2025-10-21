//Muhamad Naufal Ammar
//103112430036
//12-IF-03
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>

#define Nil NULL

typedef int infotype;
typedef struct Elmtlist *address;

struct Elmtlist {
    infotype info;
    address next;
};
struct list {
    address first;
};

void createList(list &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address P, address Prec);
void printInfo(list L);

#endif