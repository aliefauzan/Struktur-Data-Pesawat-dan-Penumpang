#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "Parent.h"
#include "Child.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct elementRelasi *adr_Relasi;

struct elementRelasi{
    adr_Maskapai Parent;
    adr_Penumpang Child;
    adr_Relasi next;
};

struct list_R{
    adr_Relasi first;
};

void createListRelasi(list_R &LR);
adr_Relasi createElemenRelasi(adr_Maskapai P, adr_Penumpang C);
void insertFirstRelasi(list_R &LR, adr_Relasi R);
void insertLastRelasi(list_R &LR, adr_Relasi R);
void showListRelasi(list_R LR, adr_Relasi R);
void showRelasi(list_R LR);
void showRelasi2(list_R LR, list_P LP);
void showRelasi3(list_R LR);
adr_Relasi searchR(list_R &LR, list_P &LP, string namaMaskapai, string kode);
void connect(list_R &LR, list_P LP, list_C LC, string namaMaskapai, string kode, string namaPenumpang, int umur, string insert);
void disconnect(list_R &LR, list_P LP, list_C LC, string namaMaskapai, string kode, string namaPenumpang, int umur);
void searchRelasi(list_R LR, list_P LP, list_C LC, string namaMaskapai, string kode);
void searchRelasi2(list_R LR, list_P LP, list_C LC, string namaPenumpang, int usia);
void reschedule(list_R &LR, list_P &LP, list_C &LC, string namaMaskapai, string kodeMaskapai, string namaPenumpang, int usia, string newNamaMaskapai, string newKodeMaskapai);
void editNamaPenumpang(list_R &LR, list_P LP, list_C LC, string namaMaskapai, string kode, string namaPenumpang, int usia, string namaBaru, int umurBaru);
void hitungRelasiParent(list_R LR, list_P LP);
void hitungRelasiChild(list_R LR, list_C LC, string nama, int usia);
void hitungParentTidakBerelasi(list_R LR, list_P LP);
void hitungChildTidakBerelasi(list_R LR, list_C LC);

#endif