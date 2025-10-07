//Mohamad Naufal Ammar
//103112430036
//12-IF-03
#include <iostream>
using namespace std;

void tampilSegitiga(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat n: ";
    cin >> n;
    tampilSegitiga(n);

    return 0;
}
