#include "Relasi.h"
#include "Parent.h"
#include "Child.h"
#include "Parent.cpp"
#include "Child.cpp"

void createListRelasi(list_R &LR){
    LR.first = NULL;
}

adr_Relasi createElemenRelasi(adr_Maskapai P, adr_Penumpang C){
    adr_Relasi R = new elementRelasi;
    R->Parent = P;
    R->Child = C;
    R->next = NULL;
    return R;
}

void insertFirstRelasi(list_R &LR, adr_Relasi R){
    R->next = LR.first;
    LR.first = R;
}

void insertLastRelasi(list_R &LR, adr_Relasi R){
    adr_Relasi Rel = LR.first;
    if(LR.first != NULL){
        while(Rel->next != NULL){
            Rel = Rel->next;
        }
        Rel->next = R;
    }else{
        LR.first = R;
    }
}

void showListRelasi(list_R LR, adr_Relasi R){
    cout << R->Parent->info.nama << "->" <<  R->Child->info.nama  <<endl;
    cout << "===========================================\n";
}

void showRelasi(list_R LR){
    adr_Relasi R = LR.first;
    if( R == NULL){
        cout << "Tidak Ada List Booking" << endl;
    }else{
        while(R != NULL){
            cout << R->Parent->info.nama << "->";

        adr_Relasi temp = R;
        while(temp != NULL && temp->Parent == R->Parent){
            cout << temp->Child->info.nama;
            temp = temp->next;

            if(temp != NULL && temp->Parent == R->Parent){
                cout << ", ";
            }
        }
        cout << endl;
        R = temp;
        }
    }
}

void showRelasi2(list_R LR, list_P LP){
    list_C LC;
    adr_Relasi R = LR.first;
    while(R != NULL){
        cout << "Data Parent: ";
        showList(LP, R->Parent);
        cout << "Data Child: ";
        showListPenumpang(LC, R->Child);
        R = R->next;
    }
}

void showRelasi3(list_R LR){
    adr_Relasi R = LR.first;
    if( R == NULL){
        cout << "Tidak Ada List Booking" << endl;
    }else{
        while (R != NULL){
            cout << R->Child->info.nama << "->";

        adr_Relasi temp = R;
        while (temp != NULL && temp->Child == R->Child){
            cout << temp->Parent->info.nama;
            temp = temp->next;

            if(temp != NULL && temp->Child == R->Child){
                cout << ", ";
            }
        }
        cout << endl;
        R = temp;
        }
    }
}

adr_Relasi searchR(list_R &LR, list_P &LP, string namaMaskapai, string kode){
    adr_Relasi R = LR.first;
    while(R != NULL){
        if(R->Parent->info.nama == namaMaskapai && R->Parent->info.kode == kode){
            return R;
        }
        R = R->next;
    }
    cout << "Maskapai " << namaMaskapai << " Dengan kode " << kode << " Tidak Di Temukan" << endl;
    return NULL;
}

void connect(list_R &LR, list_P LP, list_C LC, string namaMaskapai, string kode, string namaPenumpang, int umur, string insert){
    adr_Maskapai P = searchM(LP, namaMaskapai, kode);
    adr_Penumpang C = searchP(LC, namaPenumpang, umur);

    if(P != NULL && C != NULL && insert == "last"){
        adr_Relasi R = createElemenRelasi(P, C);
        insertLastRelasi(LR, R);
    }else if(P != NULL && C != NULL && insert == "first"){
        adr_Relasi R = createElemenRelasi(P, C);
        insertFirstRelasi(LR, R);    
    }
}

void disconnect(list_R &LR, list_P LP, list_C LC, string namaMaskapai, string kode, string namaPenumpang, int umur){
    adr_Relasi R = LR.first;
    adr_Relasi prevR = NULL;

    while(R != NULL){
        if(R->Parent->info.nama == namaMaskapai && R->Parent->info.kode == kode &&R->Child->info.nama == namaPenumpang && R->Child->info.usia == umur){
            if(prevR == NULL){
                LR.first = R->next;
            }else{
                prevR->next = R->next;
            }
            delete R;
            cout << "Booking Maskapai " << namaMaskapai << ", Dengan kode " << kode << ", Atas Nama " << namaPenumpang << "(" << umur << ")" << ", Berhasil Di Hapus" << endl;
            return;
        }
        prevR = R;
        R = R->next;
    }
    cout << "Booking Maskapai " << namaMaskapai << ", Dengan kode " << kode << ", Atas Nama " << namaPenumpang << "(" << umur << ")" << ", Tidak Ditemukan" << endl;
}

void searchRelasi(list_R LR, list_P LP, list_C LC, string namaMaskapai, string kode){
    adr_Maskapai P = searchM(LP, namaMaskapai, kode);
    adr_Relasi R = LR.first;

    if(P != NULL){
        while(R != NULL){
            if(R->Parent == P){
                cout << "Data Penumpang Maskapai " << P->info.nama << " (" << P->info.kode << "): " << endl;;
                showListPenumpang(LC, R->Child);
            }
            R = R->next;
        }
    }
}

void searchRelasi2(list_R LR, list_P LP, list_C LC, string namaPenumpang, int usia){
    adr_Penumpang P = searchP(LC, namaPenumpang, usia);
    adr_Relasi R = LR.first;

    if(P != NULL){
        while(R != NULL){
            if(R->Child == P){
                cout << "Data Penumpang " << P->info.nama << " (" << P->info.usia << "): " << endl;;
                showList(LP, R->Parent);
            }
            R = R->next;
        }
    }
}

void reschedule(list_R &LR, list_P &LP, list_C &LC, string namaMaskapai, string kodeMaskapai, string namaPenumpang, int usia, string newNamaMaskapai, string newKodeMaskapai){
    adr_Maskapai P = searchM(LP, newNamaMaskapai, newKodeMaskapai);
    adr_Penumpang C = searchP(LC, namaPenumpang, usia);
    adr_Relasi R = searchR(LR, LP, namaMaskapai, kodeMaskapai);

    if(P != NULL && C != NULL && R != NULL){
        while(R != NULL && (R->Parent->info.nama != namaMaskapai || R->Parent->info.kode != kodeMaskapai || R->Child->info.nama != namaPenumpang || R->Child->info.usia != usia)){
            R = R->next;
        }
        if(R != NULL){
            R->Parent = P;
            disconnect(LR, LP, LC, namaMaskapai, kodeMaskapai, namaPenumpang, usia);
            cout << "Reschedule berhasil." << endl;
        }else{
            cout << "Booking antara maskapai " << namaMaskapai << " dan penumpang " << namaPenumpang << " tidak ditemukan." << endl;
        }
    }else{
        cout << "Maskapai atau penumpang tidak ditemukan." << endl;
    }
}

void editNamaPenumpang(list_R &LR, list_P LP, list_C LC, string namaMaskapai, string kode, string namaPenumpang, int usia, string namaBaru, int umurBaru){
    adr_Relasi R = searchR(LR, LP, namaMaskapai, kode);
    if(R != NULL){
        while(R != NULL){
            if(R->Parent->info.nama == namaMaskapai && R->Parent->info.kode == kode &&R->Child->info.nama == namaPenumpang && R->Child->info.usia == usia){
                
                R->Child->info.nama = namaBaru;
                R->Child->info.usia = umurBaru;
                cout << "Edit nama penumpang berhasil." << endl;
                return;
                
            }
            R = R->next;
        }
        cout << "Relasi antara maskapai " << namaMaskapai << " dan penumpang " << namaPenumpang << " tidak ditemukan." << endl;
    }else{
        cout << "Maskapai atau penumpang tidak ditemukan." << endl;
    }
}

void hitungRelasiParent(list_R LR, list_P LP){
    adr_Maskapai P = LP.first;
    while(P != NULL){
    int count = 0;
    adr_Relasi R = LR.first;
        while(R != NULL){
            if(R->Parent == P){
                count++;
            }
            R = R->next;
        }
        cout << "Total Relasi " << P->info.nama << " (" << P->info.kode << "): " << count << endl;
        P = P->next;
    }
}

void hitungRelasiChild(list_R LR, list_C LC, string nama, int usia){
    adr_Penumpang C = searchP(LC, nama, usia);
    if(C != NULL){
    int count = 0;
    adr_Relasi R = LR.first;
        while(R != NULL){
            if(R->Child == C){
                count++;
            }
            R = R->next;
        }
        cout << "Total Relasi " << C->info.nama << ": " << count << endl;
    }
}

void hitungParentTidakBerelasi(list_R LR, list_P LP){
    adr_Maskapai P = LP.first;
    bool semuaParentMemilikiRelasi = true;
    int count = 0;

    while(P != NULL){
    bool hasChild = false;
    adr_Relasi R = LR.first;
        while(R != NULL){
            if(R->Parent == P){
                hasChild = true;
                break;
            }
            R = R->next;
        }
        if(!hasChild){
            count++;
            cout << "Parent " << P->info.nama << ", Tidak Memiliki Relasi" << endl;
            semuaParentMemilikiRelasi = false;
        }
        P = P->next;
    }

    if(semuaParentMemilikiRelasi){
        cout << "Seluruh Parent Memiliki Relasi" << endl;
    }else{
    cout <<"Total Parent Yang Tidak Memiliki Relasi Adalah: " << count << endl;
    }
}

void hitungChildTidakBerelasi(list_R LR, list_C LC){
    adr_Penumpang C = LC.first;
    bool semuaChildMemilikiRelasi = true;
    int count = 0;

    while(C != NULL){
    bool isRelated = false;
    adr_Relasi R = LR.first;
        while(R != NULL){
            if(R->Child == C){
                isRelated = true;
                break;
            }
            R = R->next;
        }
        if(!isRelated){
            count++;
            cout << "Child " << C->info.nama << ", Tidak Memiliki Relasi" << endl;
            semuaChildMemilikiRelasi = false;
        }
        C = C->next;
    }

    if(semuaChildMemilikiRelasi){
        cout << "Seluruh Child Memiliki Relasi" << endl;
    }else{
    cout <<"Total Child Yang Tidak Memiliki Relasi Adalah: " << count << endl;
    }
}


