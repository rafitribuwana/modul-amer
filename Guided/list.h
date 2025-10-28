/* file : list.h */
/* Contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* Info tipe adalah integer */

#ifndef list_H
#define list_H

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
/* List kosong jika L.first = Nil */
/* Setiap elemen address P dapat diacu P→info atau P→next */
struct list {
    address first;      // Pointer ke elemen pertama list
};

/********* PENGE CEKAN APAKAH LIST KOSONG ***********/
boolean ListEmpty(list L);
/* Mengembalikan nilai true jika list kosong */

/********* PEMBUATAN LIST KOSONG *********/
void CreateList(list *L);
/* I.S. sembarang */
/* F.S. terbentuk list kosong */

/********* MANAJEMEN MEMORI *********/
void dealokasi(address P);
/* I.S. P terdefinisi */
/* F.S. memori yang digunakan P dikembalikan ke sistem */

address alokasi(infotype X);
/* Mengalokasikan memori untuk elemen baru dengan nilai X */
/* Mengembalikan address elemen yang dialokasi */

/********* PENCARIAN SEBUAH ELEMEN LIST *********/
address findElm(list L, infotype X);
/* Mencari apakah ada elemen list dengan P→info = X */
/* Jika ada, mengembalikan address elemen tsb, dan Nil jika sebaliknya */

boolean fFindElm(list L, address P);
/* Mencari apakah ada elemen list dengan alamat P */
/* Mengembalikan true jika ada dan false jika tidak ada */

address findBefore(list L, address P);
/* Mengembalikan address elemen sebelum P */
/* Jika prec berada pada awal list, maka mengembalikan nilai Nil */

/********* PENAMBAHAN ELEMEN **********/
void insertFirst(list *L, address P);
/* I.S. sembarang, P sudah dialokasi */
/* F.S. menempatkan elemen beralamat P pada awal list */

void insertAfter(list *L, address P, address Prec);
/* I.S. sembarang, P dan Prec alamat salah satu elemen list */
/* F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLast(list *L, address P);
/* I.S. sembarang, P sudah dialokasi */
/* F.S. menempatkan elemen beralamat P pada akhir list */

/********* PENGHAPUSAN SEBUAH ELEMEN *********/
void delFirst(list *L, address *P);
/* I.S. list tidak kosong */
/* F.S. P adalah alamat dari elemen pertama list sebelum dihapus */
/* Elemen pertama list hilang dan list mungkin menjadi kosong */

void delLast(list *L, address *P);
/* I.S. list tidak kosong */
/* F.S. P adalah alamat dari elemen terakhir list sebelum dihapus */
/* Elemen terakhir list hilang dan list mungkin menjadi kosong */

void delAfter(list *L, address *P, address Prec);
/* I.S. list tidak kosong, Prec alamat salah satu elemen list */
/* F.S. P adalah alamat dari Prec→next, menghapus Prec→next dari list */

void delP(list *L, infotype X);
/* I.S. sembarang */
/* F.S. jika ada elemen list dengan P→info = X, maka P dihapus dan di-dealokasi */
/* Jika tidak ada maka list tetap, list mungkin akan menjadi kosong karena penghapusan */

/********** PROSES SEMUA ELEMEN LIST *********/
void printInfo(list L);
/* I.S. list mungkin kosong */
/* F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

int nbList(list L);
/* Mengembalikan jumlah elemen pada list */

/********** PROSES TERHADAP LIST **********/
void delAll(list *L);
/* Menghapus semua elemen list dan semua elemen di-dealokasi */

void invertList(list *L);
/* I.S. sembarang */
/* F.S. elemen-elemen list dibalik */

void copyList(list L1, list *L2);
/* I.S. L1 sembarang */
/* F.S. L2 = L1, L2 merupakan salinan dari L1 */

list fCopyList(list L);
/* Mengembalikan list yang merupakan salinan dari L */

#endif