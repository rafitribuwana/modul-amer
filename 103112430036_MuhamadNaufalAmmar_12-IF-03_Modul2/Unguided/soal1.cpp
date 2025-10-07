//Mohamad Naufal Ammar
//103112430036
//12-IF-03
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int JUMLAH_MHS = 5;
    const int JUMLAH_MK = 3;
    string nama[JUMLAH_MHS];
    float nilai[JUMLAH_MHS][JUMLAH_MK];
    float rata[JUMLAH_MHS];
    int terbaik = 0;

    cout << "=== PROGRAM NILAI MAHASISWA ===\n";

    for (int i = 0; i < JUMLAH_MHS; i++) {
        cout << "\nMasukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin >> ws, nama[i]);

        float total = 0;
        for (int j = 0; j < JUMLAH_MK; j++) {
            cout << "  Nilai mata kuliah ke-" << j + 1 << ": ";
            cin >> nilai[i][j];
            total += nilai[i][j];
        }

        rata[i] = total / JUMLAH_MK;

        if (rata[i] > rata[terbaik]) {
            terbaik = i;
        }
    }

    cout << "\n\n=== DAFTAR NILAI MAHASISWA ===\n";
    cout << "Nama\t\tMK1\tMK2\tMK3\tRata-rata\tKeterangan\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < JUMLAH_MHS; i++) {
        cout << nama[i] << "\t";
        for (int j = 0; j < JUMLAH_MK; j++) {
            cout << nilai[i][j] << "\t";
        }
        cout << rata[i] << "\t";
        if (i == terbaik)
            cout << "Terbaik";
        cout << endl;
    }

    cout << "\nMahasiswa dengan rata-rata tertinggi adalah: "
         << nama[terbaik]
         << " (" << rata[terbaik] << ")\n";

    return 0;
}
