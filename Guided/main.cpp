/* file : main.c */
/* Program Single Linked List Lengkap dalam Satu File */

#include <stdio.h>
#include <stdlib.h>

/* Definisi boolean */
#define boolean int
#define true 1
#define false 0

#define Nil NULL

/* Deklarasi record dan struktur data list */
typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;      // Menyimpan data/informasi elemen
    address next;       // Pointer ke elemen berikutnya
};

/* Definisi list */
struct list {
    address first;      // Pointer ke elemen pertama list
};

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

/********** FUNGSI UNTUK DEMONSTRASI **********/
void demoSearching() {
    printf("\n=== DEMO OPERASI SEARCHING ===\n");
    
    list L;
    CreateList(&L);
    
    // Tambahkan beberapa elemen
    insertFirst(&L, alokasi(30));
    insertFirst(&L, alokasi(20));
    insertFirst(&L, alokasi(10));
    insertLast(&L, alokasi(40));
    insertLast(&L, alokasi(50));
    
    printf("List awal: ");
    printInfo(L);
    
    // Demo searching
    infotype nilaiCari;
    address hasil;
    
    nilaiCari = 20;
    hasil = findElm(L, nilaiCari);
    if (hasil != Nil) {
        printf("Nilai %d DITEMUKAN pada address: %p\n", nilaiCari, hasil);
    } else {
        printf("Nilai %d TIDAK DITEMUKAN\n", nilaiCari);
    }
    
    nilaiCari = 99;
    hasil = findElm(L, nilaiCari);
    if (hasil != Nil) {
        printf("Nilai %d DITEMUKAN pada address: %p\n", nilaiCari, hasil);
    } else {
        printf("Nilai %d TIDAK DITEMUKAN\n", nilaiCari);
    }
    
    // Demo findBefore
    address elemen20 = findElm(L, 20);
    if (elemen20 != Nil) {
        address sebelum20 = findBefore(L, elemen20);
        if (sebelum20 != Nil) {
            printf("Elemen sebelum 20 adalah: %d\n", sebelum20->info);
        } else {
            printf("20 adalah elemen pertama\n");
        }
    }
    
    delAll(&L);
}

void demoInsertDelete() {
    printf("\n=== DEMO OPERASI INSERT DAN DELETE ===\n");
    
    list L;
    CreateList(&L);
    
    printf("1. Insert First (10, 20, 30):\n");
    insertFirst(&L, alokasi(10));
    insertFirst(&L, alokasi(20));
    insertFirst(&L, alokasi(30));
    printInfo(L);
    
    printf("\n2. Insert Last (40, 50):\n");
    insertLast(&L, alokasi(40));
    insertLast(&L, alokasi(50));
    printInfo(L);
    
    printf("\n3. Insert After 20 (25):\n");
    address elemen20 = findElm(L, 20);
    if (elemen20 != Nil) {
        insertAfter(&L, alokasi(25), elemen20);
    }
    printInfo(L);
    
    printf("\n4. Delete First:\n");
    address deleted;
    delFirst(&L, &deleted);
    printf("Elemen yang dihapus: %d\n", deleted->info);
    dealokasi(deleted);
    printInfo(L);
    
    printf("\n5. Delete elemen 25:\n");
    delP(&L, 25);
    printInfo(L);
    
    printf("\n6. Delete Last:\n");
    delLast(&L, &deleted);
    printf("Elemen yang dihapus: %d\n", deleted->info);
    dealokasi(deleted);
    printInfo(L);
    
    delAll(&L);
}

void demoAdvancedOperations() {
    printf("\n=== DEMO OPERASI LANJUT ===\n");
    
    list L;
    CreateList(&L);
    
    // Buat list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 1; i <= 5; i++) {
        insertLast(&L, alokasi(i));
    }
    
    printf("List awal: ");
    printInfo(L);
    printf("Jumlah elemen: %d\n", nbList(L));
    
    printf("\n1. Invert List:\n");
    invertList(&L);
    printf("Setelah diinvert: ");
    printInfo(L);
    
    printf("\n2. Copy List:\n");
    list L2;
    copyList(L, &L2);
    printf("List asli: ");
    printInfo(L);
    printf("List salinan: ");
    printInfo(L2);
    
    printf("\n3. Modifikasi list salinan:\n");
    insertFirst(&L2, alokasi(99));
    printf("List asli (tetap): ");
    printInfo(L);
    printf("List salinan (berubah): ");
    printInfo(L2);
    
    delAll(&L);
    delAll(&L2);
}

int main() {
    printf("=== PROGRAM SINGLE LINKED LIST LENGKAP ===\n");
    printf("=== PRAKTIKUM STRUKTUR DATA ===\n\n");
    
    // Demo berbagai operasi
    demoSearching();
    demoInsertDelete();
    demoAdvancedOperations();
    
    printf("\n=== PROGRAM SELESAI ===\n");
    
    return 0;
}