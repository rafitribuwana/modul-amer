#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int tahunBuat;
};

typedef Kendaraan Infotype;
struct ElmList {
    Infotype info;
    ElmList* next;
    ElmList* prev;
};

typedef ElmList* Address;
struct List {
    Address first;
    Address last;
};
void createList(List &L);
Address alokasi(Infotype x);
void dealokasi(Address &P);
void printInfo(List L);
void insertLast(List &L, Address P);
Address findElm(List L, Infotype x);
void deleteFirst(List &L, Address &P);
void deleteLast(List &L, Address &P);
void deleteAfter(Address Prec, Address &P);

#endif
