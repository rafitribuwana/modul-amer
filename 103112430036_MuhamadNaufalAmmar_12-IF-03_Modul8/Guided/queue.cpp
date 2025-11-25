#include "queue.h"
#include <iostream>

using namespace std;

//definisi prosedur dan fungsi queue
void createQueue(Queue &Q){
    Q.head = 0; //set kepala indeks menjadi 0
    Q.tail = 0; //set ekor indeks menjadi 0
    Q.count = 0; //set jumlah elemen menjadi 0
}

//definisi fungsi untuk mengecek apakah queue kosong
bool isEmpty(const Queue Q){
    return (Q.count == 0); //mengembalikan true jika jumlah elemen 0
}

//efinisi fungsi untuk mengecek apakah queue penuh
bool isFull(const Queue Q){
    return (Q.count == MAX_QUEUE); //mengembalikan true jika jumlah elemen sama dengan kapasitas maksimum
}

//definisi prosedur untuk menambah elemen ke dalam queue(enqueue)
void enqueue(Queue &Q, int x){
    if (!isFull(Q)){ //cek apakah queue penuh
        Q.info[Q.tail] = x; //menambahkan elemen pada posisi ekor
        Q.tail = (Q.tail + 1) % MAX_QUEUE; //mengupdate indeks ekor secara melingkar
        Q.count++; //menambah jumlah elemen
    } else {
        cout << "Antrean Penuh" << endl; //pesan jika queue penuh
    }
}
//definisi fungsi untuk menghapus elemen dari dalam queue(dequeue)
int dequeue(Queue &Q){
    if (!isEmpty(Q)){ //cek apakah queue kosong
        int x = Q.info[Q.head]; //mengambil elemen pada posisi kepala
        Q.head = (Q.head + 1) % MAX_QUEUE; //mengupdate indeks kepala secara melingkar
        Q.count--; //mengurangi jumlah elemen
        return x; //mengembalikan elemen yang dihapus
    } else {
        cout << "Antrean Kosong" << endl; //pesan jika queue kosong
        return -1; //mengembalikan nilai -1 sebagai indikasi queue kosong
    }
}
//definisi prosedur untuk menampilkan isi queue
void printInfo(Queue Q){
    cout << "Isi Antrean: ["; // tampilkan awalan
    if (!isEmpty(Q)){ //cek apakah queue kosong
        int i = Q.head; //mulai dari indeks kepala
        int n = 0; //inisialisasi penghitung elemen yang ditampilkan
        while (n < Q.count){ //loop sebanyak jumlah elemen
            cout << Q.info[i] << " "; //tampilkan elemen pada indeks i
            i = (i + 1) % MAX_QUEUE; //update indeks i secara melingkar
            n++; //increment penghitung elemen
        }
        cout <<  "]" << endl; //tampilkan akhiran
    }
}