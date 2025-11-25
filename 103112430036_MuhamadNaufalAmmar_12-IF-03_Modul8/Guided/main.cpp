#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;

int main () {
    Queue Q;

    createQueue(Q);
    printInfo(Q);

    cout << "Enqueue 3 Elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 9);
    printInfo(Q);

    cout << "Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "Enqueue 1 Elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);
    
    cout << "Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;

}