//Muhamad Naufal Ammar
//103112430036
//12-IF-03
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    float durasi;
    Lagu* next;
};

struct Playlist {
    Lagu* head;
};

void createPlaylist(Playlist &P);
Lagu* createLagu(string judul, string penyanyi, float durasi);

void tambahAwal(Playlist &P, string judul, string penyanyi, float durasi);
void tambahAkhir(Playlist &P, string judul, string penyanyi, float durasi);
void tambahSetelahKe3(Playlist &P, string judul, string penyanyi, float durasi);
void hapusLagu(Playlist &P, string judul);
void tampilkanPlaylist(Playlist P);

#endif

