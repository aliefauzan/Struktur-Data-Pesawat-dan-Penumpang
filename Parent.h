#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include "Relasi.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct elementMaskapai *adr_Maskapai;
typedef struct maskapai infoMaskapai;

struct maskapai{
    string nama, kode, asal, tujuan, waktu;
    int jumlahPenumpang;
};

struct elementMaskapai{
    infoMaskapai info;
    adr_Maskapai next;
};

struct list_P{
    adr_Maskapai first;
};

void createListMaskapai(list_P &LP);
adr_Maskapai createElemenMaskapai(infoMaskapai x);
void insertFirstMaskapai(list_P &LP, adr_Maskapai p);
void insertLastMaskapai(list_P &LP, adr_Maskapai p);
void showList(list_P LP, adr_Maskapai P);
void showMaskapai(list_P LP);
adr_Maskapai searchM(list_P &LP, string namaMaskapai, string kodeMaskapai);
void searchMaskapai(list_P &LP, string namaMaskapai, string kodeMaskapai);
void deleteMaskapai(list_P &LP, string namaMaskapai, string kodeMaskapai);
void deleteFirstMaskapai(list_P &LP, adr_Maskapai &p);
void deleteLastMaskapai(list_P &LP, adr_Maskapai &p);

#endif