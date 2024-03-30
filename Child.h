// Child.h
#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include "Relasi.h"
#include <iostream>
#include <string>
using namespace std;

typedef struct elementPenumpang *adr_Penumpang;
typedef struct penumpang infoPenumpang;

struct penumpang{
    string nama, alamat, jenisKelamin;
    int usia;
};

struct elementPenumpang{
    infoPenumpang info;
    adr_Penumpang next;
};

struct list_C{
    adr_Penumpang first;
};

void createListPenumpang(list_C &LC);
void insertFirstPenumpang(list_C &LC, adr_Penumpang P);
void insertAfterPenumpang(adr_Penumpang Prec, adr_Penumpang P);
void insertLastPenumpang(list_C &LC, adr_Penumpang P);
void deleteFirstPenumpang(list_C &LC, adr_Penumpang &P);
void deleteAfterPenumpang(adr_Penumpang Prec, adr_Penumpang &P);
void deleteLastPenumpang(list_C &LC, adr_Penumpang &P);
void showListPenumpang(list_C LC, adr_Penumpang P);
void printInfoPenumpang(list_C LC);
adr_Penumpang allocatePenumpang(string nama, string alamat, string jenisKelamin, int usia);
adr_Penumpang searchP(list_C LC, string nama, int umur);
void searchPenumpang(list_C &LC, string nama, int umur);
void deletePenumpang(list_C &LC, string nama, int umur);
#endif