//Mohamad Naufal Ammar
//103112430036
//12-IF-03
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Masukkan jumlah elemen array (N): ";
    cin >> N;
    int *ptr = new int[N];

    cout << "\nMasukkan " << N << " bilangan:\n";
    for (int i = 0; i < N; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> *(ptr + i); 
    }


    int jumlah = 0;
    int maks = *ptr; 
    int min = *ptr;

    for (int i = 0; i < N; i++) {
        int nilai = *(ptr + i); 
        jumlah += nilai;
        if (nilai > maks) maks = nilai;
        if (nilai < min) min = nilai;
    }

    cout << "Jumlah semua bilangan : " << jumlah << endl;
    cout << "Nilai maksimum        : " << maks << endl;
    cout << "Nilai minimum         : " << min << endl;


    return 0;
}
