//Muhamad Naufal Ammar
//103112430036
//12-IF-03
#include <iostream>
#include "arrayPointer.h"
#include "arrayPointer.cpp"
using namespace std;

int main() {
    int arr1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int arr2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int a = 10, b = 20;
    int *ptr1 = &a;
    int *ptr2 = &b;

    cout << "Array 1 awal:\n";
    tampilArray(arr1);

    cout << "\nArray 2 awal:\n";
    tampilArray(arr2);

    tukarArray(arr1, arr2, 1, 1);

    cout << "\nSetelah pertukaran elemen [1][1]:\n";
    cout << "Array 1:\n";
    tampilArray(arr1);
    cout << "Array 2:\n";
    tampilArray(arr2);

    cout << "\nSebelum pertukaran pointer:\n";
    cout << "a = " << a << ", b = " << b << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah pertukaran pointer:\n";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
