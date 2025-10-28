//Mohamad Naufal Ammar
//103112430036
//12-IF-03
#include <iostream>

using namespace std;

int main() {
    int x, y;
    int *px;
    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat X    = " << &x << endl;
    cout << "Isi px      = " << px << endl;
    cout << "Isi X       = " << x << endl;
    cout << "Nilai *px   = " << *px << endl;
    cout << "Nilai Y     = " << y << endl;

    return 0;
}