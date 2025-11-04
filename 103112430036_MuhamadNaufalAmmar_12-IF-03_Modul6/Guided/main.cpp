#include "DoublyList.h"
#include "DoublyList.cpp"
#include <iostream>
using namespace std;

void demoModul() {
    cout << "=== DEMO DOUBLY LINKED LIST SESUAI MODUL ===" << endl;
    cout << "oleh: [Nama Anda]" << endl;
    cout << "NIM: [NIM Anda]" << endl << endl;
    
    List L;
    address P, Prec;
    
    // Inisialisasi list
    createList(L);
    cout << "1. Create List - List kosong dibuat" << endl;
    printForward(L);
    cout << endl;
    
    // Insert First sesuai modul
    cout << "2. INSERT FIRST (30, 20, 10):" << endl;
    insertFirst(L, alokasi(30));
    cout << "   Insert First 30" << endl;
    printForward(L);
    
    insertFirst(L, alokasi(20));
    cout << "   Insert First 20" << endl;
    printForward(L);
    
    insertFirst(L, alokasi(10));
    cout << "   Insert First 10" << endl;
    printForward(L);
    printBackward(L);
    cout << endl;
    
    // Insert Last sesuai modul
    cout << "3. INSERT LAST (40, 50):" << endl;
    insertLast(L, alokasi(40));
    cout << "   Insert Last 40" << endl;
    printForward(L);
    
    insertLast(L, alokasi(50));
    cout << "   Insert Last 50" << endl;
    printForward(L);
    cout << endl;
    
    // Insert After sesuai modul
    cout << "4. INSERT AFTER 20 (25):" << endl;
    Prec = L.first->next; // Menunjuk ke elemen 20
    insertAfter(Prec, alokasi(25));
    cout << "   Insert After 20: 25" << endl;
    printForward(L);
    cout << endl;
    
    // Insert Before
    cout << "5. INSERT BEFORE 40 (35):" << endl;
    Prec = L.last->prev; // Menunjuk ke elemen 40
    insertBefore(Prec, alokasi(35));
    cout << "   Insert Before 40: 35" << endl;
    printForward(L);
    cout << endl;
    
    // Delete First sesuai modul
    cout << "6. DELETE FIRST:" << endl;
    deleteFirst(L, P);
    cout << "   Elemen terhapus: " << P->info << endl;
    dealokasi(P);
    printForward(L);
    cout << endl;
    
    // Delete Last sesuai modul
    cout << "7. DELETE LAST:" << endl;
    deleteLast(L, P);
    cout << "   Elemen terhapus: " << P->info << endl;
    dealokasi(P);
    printForward(L);
    cout << endl;
    
    // Delete After sesuai modul
    cout << "8. DELETE AFTER 20:" << endl;
    Prec = L.first->next; // Menunjuk ke elemen 20
    deleteAfter(Prec, P);
    cout << "   Elemen terhapus: " << P->info << endl;
    dealokasi(P);
    printForward(L);
    cout << endl;
    
    // Delete Before
    cout << "9. DELETE BEFORE 35:" << endl;
    Prec = L.last->prev; // Menunjuk ke elemen 35
    deleteBefore(Prec, P);
    cout << "   Elemen terhapus: " << P->info << endl;
    dealokasi(P);
    printForward(L);
    cout << endl;
    
    // Traversal dua arah
    cout << "10. TRAVERSAL DUA ARAH:" << endl;
    printForward(L);
    printBackward(L);
    cout << endl;
    
    // Bersihkan memory
    cout << "11. CLEAN UP - Dealokasi semua elemen:" << endl;
    while (!isEmpty(L)) {
        deleteFirst(L, P);
        cout << "   Dealokasi: " << P->info << endl;
        dealokasi(P);
    }
    printForward(L);
    
    cout << endl << "=== DEMO SELESAI ===" << endl;
}

int main() {
    demoModul();
    return 0;
}