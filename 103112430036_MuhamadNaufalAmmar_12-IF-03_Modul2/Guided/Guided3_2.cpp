//Mohamad Naufal Ammar
//103112430036
//12-IF-03
#include <iostream>
using namespace std;

int maks3(int a, int b, int c) ;
int main () {
    int x, y, z;
    cout << "Masukkan nilai bilangan ke-1: ";
    cin >> x;
    cout << "Masukkan nilai bilangan ke-2: ";
    cin >> y;
    cout << "Masukkan nilai bilangan ke-3: ";
    cin >> z;

    cout << "Nilai maksimum dari ketiga bilangan tersebut adalah " << maks3(x, y, z) << endl;
    return 0;
}

int maks3(int a, int b, int c) {
    int temp_maks = a;
    if (b > temp_maks) {
        temp_maks = b;
    }
    if (c > temp_maks) {
        temp_maks = c;
    }
    return temp_maks;
}

//Mohamad Naufal Ammar
//103112430036
//12-IF-03

#include <iostream>
using namespace std;

void tulis(int x) ;
int main () {
    int jum;
    cout << "Masukkan jumlah perulangan: ";
    cin >> jum;
    tulis(jum);
    return 0;
}

void tulis(int x) {
    for (int i = 1; i <= x; i++) {
        cout << "Baris ke-" << i << endl;
    }
}