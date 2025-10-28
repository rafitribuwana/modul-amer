//Mohamad Naufal Ammar
//103112430036
//12-IF-03
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };

    cout << "=== Input Nilai Siswa ===" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Nilai ke-" << (i + 1) << ": ";
        cin >> nilai[i];
    }

    cout << "\n=== Data Nilai Siswa ===" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "Nilai ke-" << (i + 1) << " = " << nilai[i] << endl;
    }

    cout << "\n=== Nilai Tahunan ===" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << nilai_tahun[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}