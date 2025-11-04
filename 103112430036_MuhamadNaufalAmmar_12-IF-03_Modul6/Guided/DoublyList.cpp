#include "DoublyList.h"
// Alokasi memori untuk elemen baru
address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

// Dealokasi memori
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Inisialisasi list kosong
void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

// Cek apakah list kosong
bool isEmpty(List L) {
    return (L.first == Nil);
}

// INSERT FIRST - 
void insertFirst(List &L, address P) {
    if (isEmpty(L)) {
        // Jika list kosong
        L.first = P;
        L.last = P;
    } else {
        // Jika list tidak kosong
        P->next = L.first;      // Step 1: P->next menunjuk first lama
        L.first->prev = P;      // Step 2: first lama->prev menunjuk P
        L.first = P;            // Step 3: first baru = P
    }
}

// INSERT LAST - 
void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        // Jika list kosong
        L.first = P;
        L.last = P;
    } else {
        // Jika list tidak kosong
        P->prev = L.last;       // Step 1: P->prev menunjuk last lama
        L.last->next = P;       // Step 2: last lama->next menunjuk P
        L.last = P;             // Step 3: last baru = P
    }
}

// INSERT AFTER - 
void insertAfter(address Prec, address P) {
    if (Prec == Nil || P == Nil) return;
    
    P->next = Prec->next;       // Step 1: P->next menunjuk elemen setelah Prec
    P->prev = Prec;             // Step 2: P->prev menunjuk Prec
    
    if (Prec->next != Nil) {
        Prec->next->prev = P;   // Step 3: elemen setelah Prec->prev menunjuk P
    }
    Prec->next = P;             // Step 4: Prec->next menunjuk P
}

// INSERT BEFORE - kebalikan insert after
void insertBefore(address Prec, address P) {
    if (Prec == Nil || P == Nil) return;
    
    P->next = Prec;             // Step 1: P->next menunjuk Prec
    P->prev = Prec->prev;       // Step 2: P->prev menunjuk elemen sebelum Prec
    
    if (Prec->prev != Nil) {
        Prec->prev->next = P;   // Step 3: elemen sebelum Prec->next menunjuk P
    }
    Prec->prev = P;             // Step 4: Prec->prev menunjuk P
}

// DELETE FIRST -
void deleteFirst(List &L, address &P) {
    if (isEmpty(L)) {
        P = Nil;
        return;
    }
    
    P = L.first;                // Step 1: P menunjuk elemen pertama
    
    if (L.first == L.last) {
        // Hanya ada satu elemen
        L.first = Nil;
        L.last = Nil;
    } else {
        // Lebih dari satu elemen
        L.first = L.first->next;    // Step 2: first menunjuk elemen kedua
        L.first->prev = Nil;        // Step 3: first baru->prev = Nil
    }
    
    // Isolasi elemen yang dihapus
    P->next = Nil;
    P->prev = Nil;
}

// DELETE LAST - 
void deleteLast(List &L, address &P) {
    if (isEmpty(L)) {
        P = Nil;
        return;
    }
    
    P = L.last;                 // Step 1: P menunjuk elemen terakhir
    
    if (L.first == L.last) {
        // Hanya ada satu elemen
        L.first = Nil;
        L.last = Nil;
    } else {
        // Lebih dari satu elemen
        L.last = L.last->prev;      // Step 2: last menunjuk elemen sebelum last
        L.last->next = Nil;         // Step 3: last baru->next = Nil
    }
    
    // Isolasi elemen yang dihapus
    P->next = Nil;
    P->prev = Nil;
}

// DELETE AFTER -
void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
        return;
    }
    
    P = Prec->next;             // Step 1: P menunjuk elemen setelah Prec
    
    if (P->next != Nil) {
        P->next->prev = Prec;   // Step 2: elemen setelah P->prev menunjuk Prec
    }
    Prec->next = P->next;       // Step 3: Prec->next menunjuk elemen setelah P
    
    // Isolasi elemen yang dihapus
    P->next = Nil;
    P->prev = Nil;
}

// DELETE BEFORE - kebalikan delete after
void deleteBefore(address Prec, address &P) {
    if (Prec == Nil || Prec->prev == Nil) {
        P = Nil;
        return;
    }
    
    P = Prec->prev;             // Step 1: P menunjuk elemen sebelum Prec
    
    if (P->prev != Nil) {
        P->prev->next = Prec;   // Step 2: elemen sebelum P->next menunjuk Prec
    }
    Prec->prev = P->prev;       // Step 3: Prec->prev menunjuk elemen sebelum P
    
    // Isolasi elemen yang dihapus
    P->next = Nil;
    P->prev = Nil;
}

// PRINT FORWARD (dari first ke last)
void printForward(List L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    
    address P = L.first;
    cout << "Forward: ";
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " <-> ";
        P = P->next;
    }
    cout << endl;
}

// PRINT BACKWARD (dari last ke first)
void printBackward(List L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
        return;
    }
    
    address P = L.last;
    cout << "Backward: ";
    while (P != Nil) {
        cout << P->info;
        if (P->prev != Nil) cout << " <-> ";
        P = P->prev;
    }
    cout << endl;
}