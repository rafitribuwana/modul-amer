//Muhamad Naufal Ammar
//103112430036
//12-IF-03
#include "Playlist.h"
#include "Playlist.cpp"
using namespace std;
int main() {
    Playlist myPlaylist;
    createPlaylist(myPlaylist);

    int pilihan;
    string judul, penyanyi;
    float durasi;

    do {
        cout << "\n=== MENU PLAYLIST LAGU ===" << endl;
        cout << "1. Tambah lagu di awal playlist" << endl;
        cout << "2. Tambah lagu di akhir playlist" << endl;
        cout << "3. Tambah lagu setelah playlist ke-3" << endl;
        cout << "4. Hapus lagu berdasarkan judul" << endl;
        cout << "5. Tampilkan seluruh lagu dalam playlist" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan Judul Lagu  : ";
                getline(cin, judul);
                cout << "Masukkan Nama Penyanyi: ";
                getline(cin, penyanyi);
                cout << "Masukkan Durasi (menit): ";
                cin >> durasi;
                tambahAwal(myPlaylist, judul, penyanyi, durasi);
                cout << "Lagu berhasil ditambahkan di awal playlist.\n";
                break;

            case 2:
                cout << "\nMasukkan Judul Lagu  : ";
                getline(cin, judul);
                cout << "Masukkan Nama Penyanyi: ";
                getline(cin, penyanyi);
                cout << "Masukkan Durasi (menit): ";
                cin >> durasi;
                tambahAkhir(myPlaylist, judul, penyanyi, durasi);
                cout << "Lagu berhasil ditambahkan di akhir playlist.\n";
                break;

            case 3:
                cout << "\nMasukkan Judul Lagu  : ";
                getline(cin, judul);
                cout << "Masukkan Nama Penyanyi: ";
                getline(cin, penyanyi);
                cout << "Masukkan Durasi (menit): ";
                cin >> durasi;
                tambahSetelahKe3(myPlaylist, judul, penyanyi, durasi);
                break;

            case 4:
                cout << "\nMasukkan Judul Lagu yang akan dihapus: ";
                getline(cin, judul);
                hapusLagu(myPlaylist, judul);
                break;

            case 5:
                tampilkanPlaylist(myPlaylist);
                break;

            case 0:
                cout << "\nTerima kasih! Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }

    } while (pilihan != 0);

    return 0;
}
