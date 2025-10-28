//Muhamad Naufal Ammar
//103112430036
//12-IF-03
#include "mahasiswa.h"
#include "mahasiswa.cpp"
#include <iostream>
using namespace std;

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah mahasiswa melebihi batas maksimal (10)!" << endl;
        return 0;
    }

    inputData(mhs, n);
    tampilData(mhs, n);

    return 0;
}