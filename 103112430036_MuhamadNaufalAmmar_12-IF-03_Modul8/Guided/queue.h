#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue
{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

//prosedur untuk mebuat queue kosong
void createQueue(Queue &Q);
//fungsi untuk mengecek apakah queue kosong
bool isEmpty(const Queue Q);
//fungsi untuk mengecek apakah queue penuh
bool isFull(const Queue Q);
//prosedur untuk menambah elemen ke dalam queue(enqueue)
void enqueue(Queue &Q, int x);
//fungsi untuk menghapus elemen dari dalam queue(dequeue)
int dequeue(Queue &Q);
//prosedur untuk menampilkan isi queue
void printInfo(Queue Q);
#endif