#include "Parent.h"

void createListMaskapai(list_P &LP){
    LP.first = NULL;
}

adr_Maskapai createElemenMaskapai(infoMaskapai x){
    adr_Maskapai P;
    P = new elementMaskapai;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertFirstMaskapai(list_P &LP, adr_Maskapai p){
        p->next = LP.first;
        LP.first = p;
}

void insertLastMaskapai(list_P &LP, adr_Maskapai p){
    if(LP.first != NULL){
        adr_Maskapai M = LP.first;
        while(M->next != NULL){
            M = M->next;
        }
        M -> next = p;
    }else{
        LP.first = p;
    }
}

void showList(list_P LP, adr_Maskapai P){
        cout << "Nama Maskapai: " << P->info.nama << "\n";
        cout << "Kode Maskapai: " << P->info.kode << "\n";
        cout << "Asal: " << P->info.asal << "\n";
        cout << "Tujuan: " << P->info.tujuan << "\n";
        cout << "Waktu: " << P->info.waktu << "\n";
        cout << "Jumlah Penumpang: " << P->info.jumlahPenumpang << "\n";
        cout << "-------------------------------------------\n";
}

void showMaskapai(list_P LP){
    adr_Maskapai P = LP.first;
    cout << "----====[ Maskapai ]====----" << "\n";
    if(P == NULL){
        cout << "Tidak Ada List Maskapai" << endl;
    }else{
        while (P != NULL){
            showList(LP, P);
            P = P->next;
        }
    }
}

adr_Maskapai searchM(list_P &LP, string namaMaskapai, string kodeMaskapai){
    adr_Maskapai P = LP.first;
    while(P != NULL){
        if(P->info.nama == namaMaskapai && P->info.kode == kodeMaskapai){
            return P;
        }
        P = P->next;
    }
    cout << "Maskapai " << namaMaskapai << ", Dengan kode " << kodeMaskapai << ", Tidak Di Temukan" << endl;
    return NULL;
}

void searchMaskapai(list_P &LP, string namaMaskapai, string kodeMaskapai){
    adr_Maskapai P = searchM(LP, namaMaskapai, kodeMaskapai);
    if(P != NULL){
        showList(LP, P);
    }
}

void deleteMaskapai(list_P &LP, string namaMaskapai, string kodeMaskapai) {
    adr_Maskapai P = searchM(LP, namaMaskapai, kodeMaskapai);
    
    if (P != NULL) {
        if (P == LP.first) {
            LP.first = LP.first->next;
            delete P;
            cout << "Maskapai " << namaMaskapai << ", Dengan kode " << kodeMaskapai << ", Berhasil Di Hapus" << endl;
        } else {
            adr_Maskapai temp = LP.first;
            while (temp->next != P) {
                temp = temp->next;
            }
            temp->next = P->next;
            delete P;
            cout << "Maskapai " << namaMaskapai << ", Dengan kode " << kodeMaskapai << ", Berhasil Di Hapus" << endl;
        }
    } else {
        cout << "Maskapai " << namaMaskapai << ", Dengan kode " << kodeMaskapai << ", Tidak Ditemukan" << endl;
    }
}

void deleteFirstMaskapai(list_P &LP, adr_Maskapai &p){
    if(LP.first == NULL){
        cout << "Tidak Ada Maskapai Yang Dapat Di Hapus" << endl;
    }else{
        p = LP.first;
        LP.first = LP.first->next;
        delete p;
        cout << "Delete maskapai Berhasil" << endl;
    }
}

void deleteLastMaskapai(list_P &LP, adr_Maskapai &p){
    if(LP.first == NULL){
        cout << "Tidak Ada Maskapai Yang Dapat Di Hapus" << endl;
    }else{
        if(LP.first->next == NULL){
            deleteFirstMaskapai(LP, p);
        }else{
        adr_Maskapai current = LP.first;
            while (current->next->next != NULL) {
                current = current->next;
            }
            delete current->next;
            cout << "Delete maskapai Berhasil" << endl;
            current->next = NULL;
        }
    }
}



