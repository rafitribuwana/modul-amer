/* file : list.c */
/* Implementasi ADT Single Linked List */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/********* PENGE CEKAN APAKAH LIST KOSONG ***********/
boolean ListEmpty(list L) {
    /* Keterangan: Mengembalikan true jika list kosong (first = NULL) */
    return (L.first == Nil);
}

/********* PEMBUATAN LIST KOSONG *********/
void CreateList(list *L) {
    /* Keterangan: Inisialisasi list menjadi kosong */
    (*L).first = Nil;
}

/********* MANAJEMEN MEMORI *********/
void dealokasi(address P) {
    /* Keterangan: Membebaskan memori yang digunakan oleh elemen P */
    free(P);
}

address alokasi(infotype X) {
    /* Keterangan: Mengalokasikan memori untuk elemen baru dengan nilai X */
    address P = (address)malloc(sizeof(struct elmlist));
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
    }
    return P;
}

/********* PENCARIAN SEBUAH ELEMEN LIST *********/
address findElm(list L, infotype X) {
    /* Keterangan: Mencari elemen dengan nilai X dalam list */
    /* Proses searching: mengunjungi setiap node sampai ditemukan atau sampai akhir list */
    address P = L.first;
    
    while (P != Nil) {
        if (P->info == X) {
            return P;  // Elemen ditemukan
        }
        P = P->next;
    }
    return Nil;  // Elemen tidak ditemukan
}

boolean fFindElm(list L, address P) {
    /* Keterangan: Mengecek apakah alamat P ada dalam list */
    address current = L.first;
    
    while (current != Nil) {
        if (current == P) {
            return true;
        }
        current = current->next;
    }
    return false;
}

address findBefore(list L, address P) {
    /* Keterangan: Mencari elemen sebelum P dalam list */
    if (L.first == P) {
        return Nil;  // P adalah elemen pertama
    }
    
    address current = L.first;
    while (current != Nil && current->next != P) {
        current = current->next;
    }
    return current;
}

/********* PENAMBAHAN ELEMEN **********/
void insertFirst(list *L, address P) {
    /* Keterangan: Menyisipkan elemen P di awal list */
    P->next = (*L).first;
    (*L).first = P;
}

void insertAfter(list *L, address P, address Prec) {
    /* Keterangan: Menyisipkan elemen P setelah elemen Prec */
    P->next = Prec->next;
    Prec->next = P;
}

void insertLast(list *L, address P) {
    /* Keterangan: Menyisipkan elemen P di akhir list */
    if (ListEmpty(*L)) {
        (*L).first = P;
    } else {
        address last = (*L).first;
        while (last->next != Nil) {
            last = last->next;
        }
        last->next = P;
    }
    P->next = Nil;
}

/********* PENGHAPUSAN SEBUAH ELEMEN *********/
void delFirst(list *L, address *P) {
    /* Keterangan: Menghapus elemen pertama dari list */
    *P = (*L).first;
    (*L).first = (*L).first->next;
    (*P)->next = Nil;
}

void delLast(list *L, address *P) {
    /* Keterangan: Menghapus elemen terakhir dari list */
    if ((*L).first->next == Nil) {
        // Hanya ada satu elemen
        *P = (*L).first;
        (*L).first = Nil;
    } else {
        address last = (*L).first;
        while (last->next->next != Nil) {
            last = last->next;
        }
        *P = last->next;
        last->next = Nil;
    }
}

void delAfter(list *L, address *P, address Prec) {
    /* Keterangan: Menghapus elemen setelah Prec */
    *P = Prec->next;
    Prec->next = (*P)->next;
    (*P)->next = Nil;
}

void delP(list *L, infotype X) {
    /* Keterangan: Menghapus elemen dengan nilai X dari list */
    address P = findElm(*L, X);
    if (P != Nil) {
        if (P == (*L).first) {
            delFirst(L, &P);
        } else {
            address Prec = findBefore(*L, P);
            delAfter(L, &P, Prec);
        }
        dealokasi(P);
    }
}

/********** PROSES SEMUA ELEMEN LIST *********/
void printInfo(list L) {
    /* Keterangan: Menampilkan semua elemen dalam list */
    address P = L.first;
    
    if (ListEmpty(L)) {
        printf("List kosong\n");
    } else {
        printf("Isi list: ");
        while (P != Nil) {
            printf("%d", P->info);
            P = P->next;
            if (P != Nil) {
                printf(" -> ");
            }
        }
        printf("\n");
    }
}

int nbList(list L) {
    /* Keterangan: Menghitung jumlah elemen dalam list */
    int count = 0;
    address P = L.first;
    
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

/********** PROSES TERHADAP LIST **********/
void delAll(list *L) {
    /* Keterangan: Menghapus semua elemen dalam list */
    address P;
    while (!ListEmpty(*L)) {
        delFirst(L, &P);
        dealokasi(P);
    }
}

void invertList(list *L) {
    /* Keterangan: Membalik urutan elemen dalam list */
    address prev = Nil;
    address current = (*L).first;
    address next = Nil;
    
    while (current != Nil) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*L).first = prev;
}

void copyList(list L1, list *L2) {
    /* Keterangan: Membuat salinan list L1 ke L2 */
    CreateList(L2);
    
    if (!ListEmpty(L1)) {
        address P1 = L1.first;
        address last = Nil;
        
        while (P1 != Nil) {
            address P2 = alokasi(P1->info);
            if (ListEmpty(*L2)) {
                (*L2).first = P2;
                last = P2;
            } else {
                last->next = P2;
                last = P2;
            }
            P1 = P1->next;
        }
    }
}

list fCopyList(list L) {
    /* Keterangan: Mengembalikan salinan list L */
    list L2;
    copyList(L, &L2);
    return L2;
}