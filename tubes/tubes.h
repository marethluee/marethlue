#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

struct Anggota{
    string nama;
    string proker;
};

struct Divisi {
    string nama;
    string desc;
    int jumlah_anggota;
};

typedef struct elmAnggota *adr_anggota;

typedef struct elmDivisi *adr_divisi;

struct elmAnggota{
    Anggota info;
    adr_anggota next,prev;
};

struct elmDivisi{
    Divisi info;
    adr_anggota kadiv;
    adr_divisi next;
};


struct list_divisi{
    adr_divisi first;
};

void createListDivisi(list_divisi &L);

adr_anggota createAnggota(string nama,string proker);
adr_divisi createDivisi(string nama,string desc);

//insert last
void tambahAnggota(adr_divisi &L,adr_anggota &p);

adr_anggota hapusKadiv(adr_divisi &L);
adr_anggota deleteLastAnggota(adr_divisi &L);
adr_anggota deleteAfterAnggota(adr_divisi &L,adr_anggota &p);

adr_anggota searchAnggota(adr_divisi L, string nama);
adr_anggota hapusAnggotaDivisi(adr_divisi &L, string nama);
adr_anggota hapusAnggota(list_divisi L, string nama);
void printAnggota(adr_divisi L);

void insertFirstDivisi(list_divisi &L, adr_divisi &p);
void insertLastDivisi(list_divisi &L,adr_divisi &p);
void insertAfterDivisi(adr_divisi &p, adr_divisi &q);

void deleteAllAnggota(adr_divisi &p);
adr_divisi deleteFirstDivisi(list_divisi &L);
adr_divisi deleteLastDivisi(list_divisi &L);
adr_divisi deleteAfterDivisi(adr_divisi &p);
adr_divisi hapusDivisi(list_divisi &L, string nama);


adr_divisi searchDivisi(list_divisi L, string nama);
void printDivisi(list_divisi L);
void printAll(list_divisi L);

#endif // HEADER_H_INCLUDED
