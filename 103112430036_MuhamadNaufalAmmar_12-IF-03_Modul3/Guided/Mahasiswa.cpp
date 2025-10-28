//Muhamad Naufal Ammar
//103112430036
//12-IF-03      
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "NIM: " ;
    cin >> m.nim;
    cout << "Nilai 1: ";
    cin >> m.nilai1;
    cout << "Nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2.0;
}