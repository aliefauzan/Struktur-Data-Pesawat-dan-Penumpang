// Child.cpp
#include "Child.h"

void createListPenumpang(list_C &LC) {
    LC.first = NULL;
}

void insertFirstPenumpang(list_C &LC, adr_Penumpang P) {
    P->next = LC.first;
    LC.first = P;
}

void insertAfterPenumpang(adr_Penumpang Prec, adr_Penumpang P) {
    P->next = Prec->next;
    Prec->next = P;
}

void insertLastPenumpang(list_C &LC, adr_Penumpang P) {
    if (LC.first == NULL) {
        insertFirstPenumpang(LC, P);
    } else {
        adr_Penumpang last = LC.first;
        while (last->next != NULL) {
            last = last->next;
        }
        insertAfterPenumpang(last, P);
    }
}

void deleteFirstPenumpang(list_C &LC, adr_Penumpang &P) {
    if (LC.first != NULL) {
        P = LC.first;
        LC.first = P->next;
        P->next = NULL;
        cout << "Delete Penumpang Berhasil" << endl;
    }else{
        cout << "Tidak Ada List Penumpang Yang Dapat Di Hapus" << endl;

    }
}

void deleteAfterPenumpang(adr_Penumpang Prec, adr_Penumpang &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

void deleteLastPenumpang(list_C &LC, adr_Penumpang &P) {
    if (LC.first != NULL) {
        if (LC.first->next == NULL) {
            deleteFirstPenumpang(LC, P);
        } else {
            adr_Penumpang last = LC.first;
            while (last->next->next != NULL) {
                last = last->next;
            }
            cout << "Delete Penumpang Berhasil" << endl;
            deleteAfterPenumpang(last, P);
        }
    }else{
        cout << "Tidak Ada List Penumpang Yang Dapat Di Hapus" << endl;
    }
}

void showListPenumpang(list_C LC, adr_Penumpang P){
    cout << "Nama: " << P->info.nama << endl;
    cout << "Alamat: " << P->info.alamat << endl;
    cout << "Jenis Kelamin: " << P->info.jenisKelamin << endl;
    cout << "Usia: " << P->info.usia << endl;
	cout << "---------------------------------------" << endl;
}

void printInfoPenumpang(list_C LC) {
    adr_Penumpang P = LC.first;
    if(P == NULL){
        cout << "Tidak Ada List Penumpang" << endl;
    }else{
        while (P != NULL) {
            showListPenumpang(LC, P);
            P = P->next;
        }
    }
}

adr_Penumpang allocatePenumpang(string nama, string alamat, string jenisKelamin, int usia) {
    adr_Penumpang P = new elementPenumpang;
    P->info.nama = nama;
    P->info.alamat = alamat;
    P->info.jenisKelamin = jenisKelamin;
    P->info.usia = usia;
    P->next = NULL;
    return P;
}

adr_Penumpang searchP(list_C LC, string nama, int umur){
    adr_Penumpang P = LC.first;
    while (P != NULL){
        if(P->info.nama == nama && P->info.usia == umur){
            return P;
        }
        P = P->next;
    }
    cout << "Penumpang Bernama " << nama << ", Usia" << umur << ", Tidak Di Temukan" << endl; 
    return NULL;
}

void searchPenumpang(list_C &LC, string nama, int umur){
    adr_Penumpang P = searchP(LC, nama, umur);
    if(P != NULL){
        showListPenumpang(LC, P);
    }
}

void deletePenumpang(list_C &LC, string nama, int umur) {
    adr_Penumpang P = searchP(LC, nama, umur);
    if (P != NULL) {
        if (P == LC.first) {
            deleteFirstPenumpang(LC, P);
        } else {
            if (P->next == NULL) {
                deleteLastPenumpang(LC, P);
            } else {
                adr_Penumpang Prec = LC.first;
                while (Prec->next != P) {
                    Prec = Prec->next;
                }
                deleteAfterPenumpang(Prec, P);
            }
        }
        delete P;
    } 
}
