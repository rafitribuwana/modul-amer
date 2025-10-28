//Muhamad Naufal Ammar
//103112430036
//12-IF-03
#include "Singlylist.h"
#include <iostream>
void createList(list &L) {
    L.first = Nil;
}
address alokasi(infotype x) {
    address P = new Elmtlist;
    P->info = x;
    P->next = Nil;
    return P;
}
void dealokasi(address &P) {
    delete P;
}
void insertFirst(list &L, address P) {
    if (L.first == Nil) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}
void insertLast(list &L, address P) {
    if (L.first == Nil) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertAfter(list &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}
void printInfo(list L) {
    address P = L.first;
    while (P != Nil) {
        std::cout << P->info << " ";
        P = P->next;
    }
    std::cout << std::endl;
}