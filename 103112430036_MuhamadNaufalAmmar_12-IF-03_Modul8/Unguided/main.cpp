#include <iostream>
#include "queue.h"
#include "queue.cpp"
using namespace std;

int main() {
    Queue Q;
    CreateQueue(Q);

    int choice, value;

    do {
        cout << "\n=== MENU QUEUE ===" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print Queue" << endl;
        cout << "4. Cek Queue Penuh" << endl;
        cout << "5. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                enqueue(Q, value);
                printInfo(Q);
                break;

            case 2:
                value = dequeue(Q);
                if (value != -1)
                    cout << "Data yang dikeluarkan: " << value << endl;
                printInfo(Q);

                break;

            case 3:
                printInfo(Q);
                break;

            case 4:
                if (isFullQueue(Q))
                    cout << "Queue penuh" << endl;
                else
                    cout << "Queue belum penuh" << endl;
                break;

            case 5:
                cout << "Keluar program..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 4);

    return 0;
}
