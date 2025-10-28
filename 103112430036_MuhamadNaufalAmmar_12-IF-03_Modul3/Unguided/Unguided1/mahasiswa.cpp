//Muhamad Naufal Ammar
//103112430036
//12-IF-03
#include "mahasiswa.h"

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void inputData(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << (i + 1) << endl;
        cout << "Nama  : ";
        cin >> mhs[i].nama;
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
}

void tampilData(Mahasiswa mhs[], int n) {
    cout << "\n=== DATA NILAI MAHASISWA ===" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Nama\tNIM\t\tUTS\tUAS\tTugas\tNilai Akhir" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << "\t"
             << mhs[i].nim << "\t"
             << mhs[i].uts << "\t"
             << mhs[i].uas << "\t"
             << mhs[i].tugas << "\t"
             << mhs[i].nilaiAkhir << endl;
    }
}
