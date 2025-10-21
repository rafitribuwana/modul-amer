//Muhamad Naufal Ammar
//103112430036
//12-IF-03
#include "Playlist.h"

void createPlaylist(Playlist &P) {
    P.head = NULL;
}

Lagu* createLagu(string judul, string penyanyi, float durasi) {
    Lagu* laguBaru = new Lagu;
    laguBaru->judul = judul;
    laguBaru->penyanyi = penyanyi;
    laguBaru->durasi = durasi;
    laguBaru->next = NULL;
    return laguBaru;
}

void tambahAwal(Playlist &P, string judul, string penyanyi, float durasi) {
    Lagu* laguBaru = createLagu(judul, penyanyi, durasi);
    laguBaru->next = P.head;
    P.head = laguBaru;
}

void tambahAkhir(Playlist &P, string judul, string penyanyi, float durasi) {
    Lagu* laguBaru = createLagu(judul, penyanyi, durasi);
    if (P.head == NULL) {
        P.head = laguBaru;
    } else {
        Lagu* temp = P.head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = laguBaru;
    }
}

void tambahSetelahKe3(Playlist &P, string judul, string penyanyi, float durasi) {
    Lagu* laguBaru = createLagu(judul, penyanyi, durasi);
    Lagu* temp = P.head;
    int count = 1;

    while (temp != NULL && count < 3) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        laguBaru->next = temp->next;
        temp->next = laguBaru;
    } else {
        cout << "Playlist kurang dari 3 lagu, tidak bisa menambah setelah lagu ke-3.\n";
        delete laguBaru;
    }
}

void hapusLagu(Playlist &P, string judul) {
    if (P.head == NULL) {
        cout << "Playlist kosong.\n";
        return;
    }

    Lagu* temp = P.head;
    Lagu* prev = NULL;

    if (temp != NULL && temp->judul == judul) {
        P.head = temp->next;
        delete temp;
        cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
        return;
    }

    while (temp != NULL && temp->judul != judul) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Lagu dengan judul \"" << judul << "\" tidak ditemukan.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Lagu \"" << judul << "\" berhasil dihapus.\n";
}

void tampilkanPlaylist(Playlist P) {
    if (P.head == NULL) {
        cout << "Playlist kosong.\n";
        return;
    }

    Lagu* temp = P.head;
    int i = 1;

    cout << "\nDaftar Lagu dalam Playlist:\n";
    cout << "---------------------------------------------\n";
    while (temp != NULL) {
        cout << i << ". Judul   : " << temp->judul << endl;
        cout << "   Penyanyi: " << temp->penyanyi << endl;
        cout << "   Durasi  : " << temp->durasi << " menit\n";
        cout << "---------------------------------------------\n";
        temp = temp->next;
        i++;
    }
}
