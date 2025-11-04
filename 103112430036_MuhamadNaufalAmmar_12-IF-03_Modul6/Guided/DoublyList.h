#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

/*deklarasi record dan struktur data Doubly linked list*/
typedef int infotype;
typedef struct elmlist *address;
struct elmlist {
    infotype info;
    address next;
    address prev;
};

/* definisi list: */
/* list kosong jika L.first=Nil */
struct List {
    address first;
    address last;
};

/** Deklarasi fungsi primitif **/
address alokasi(infotype x);
void dealokasi(address &P);
void createList(List &L);
bool isEmpty(List L);

// Insert operations
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(address Prec, address P);
void insertBefore(address Prec, address P);

// Delete operations
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
void deleteBefore(address Prec, address &P);

// View operations
void printForward(List L);
void printBackward(List L);

#endif