#include "DoublyList.h"
#include "DoublyList.cpp"
#include <iostream>
using namespace std;

bool isExist(List L, string nopol) {
    Address P = L.first;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}
int main() {
    List L;
    createList(L);

    Infotype x;
    Address P;
    int n = 4;
    string nopolInput, warnaInput;
    int tahunInput;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> nopolInput;
        if (isExist(L, nopolInput)) {
            cout << "Nomor polisi sudah terdaftar!" << endl;
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        cin >> warnaInput;
        cout << "Masukkan tahun kendaraan: ";
        cin >> tahunInput;

        x.nopol = nopolInput;
        x.warna = warnaInput;
        x.tahunBuat = tahunInput;

        P = alokasi(x);
        insertLast(L, P);
    }

    cout << endl;
    printInfo(L);
    cout << endl;
    cout << "Masukkan nomor polisi yang dicari: ";
    cin >> x.nopol;

    P = findElm(L, x);
    if (P != nullptr) {
        cout << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.tahunBuat << endl;
    } else {
        cout << "Data dengan nomor polisi tersebut tidak ditemukan." << endl;
    }
    cout << endl;
    cout << "Masukkan nomor polisi yang akan dihapus: ";
    cin >> x.nopol;

    Address prec = nullptr;
    P = L.first;
    while (P != nullptr && P->info.nopol != x.nopol) {
        prec = P;
        P = P->next;
    }
    if (P == nullptr) {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan." << endl;
    } else {
        if (P == L.first) {
            deleteFirst(L, P);
        } else if (P == L.last) {
            deleteLast(L, P);
        } else {
            deleteAfter(prec, P);
        }
        cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus." << endl;
        dealokasi(P);
    }

    cout << endl;
    printInfo(L);

    return 0;
    }
