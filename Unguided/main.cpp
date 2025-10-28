#include "Singlylist.h"
#include "Singlylist.cpp"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi list: ";
    printInfo(L);

    address hasilCari = findElm(L, 8);
    if (hasilCari != Nil) {
        cout << "Elemen dengan info 8 ditemukan di alamat: " << hasilCari << endl;
    } else {
        cout << "Elemen dengan info 8 tidak ditemukan." << endl;
    }

    int total = sumInfo(L);
    cout << "Jumlah total info: " << total << endl;

    return 0;
}
