//Mohamad Naufal Ammar
//103112430036
//12-IF-03
#include <iostream>
using namespace std;

float hitungRataRata(int nilai[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += nilai[i];
    }
    return total / n;
}
void cariNilaiTertinggiTerendah(int nilai[], int n, int &maks, int &min) {
    maks = nilai[0];
    min = nilai[0];
    for (int i = 1; i < n; i++) {
        if (nilai[i] > maks)
            maks = nilai[i];
        if (nilai[i] < min)
            min = nilai[i];
    }
}

int main() {
    int N;
    cout << "Masukkan jumlah siswa: ";
    cin >> N;
    int nilai[N];
    cout << "\nMasukkan nilai ujian untuk " << N << " siswa:\n";
    for (int i = 0; i < N; i++) {
        cout << "Nilai siswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }
    cout << endl;

    float rata = hitungRataRata(nilai, N);

    int maks, min;
    cariNilaiTertinggiTerendah(nilai, N, maks, min);

    cout << "Rata-rata kelas : " << rata << endl;
    cout << "Nilai tertinggi : " << maks << endl;
    cout << "Nilai terendah  : " << min << endl;

    return 0;
}
