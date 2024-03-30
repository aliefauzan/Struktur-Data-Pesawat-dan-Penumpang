#include "Relasi.cpp"

void Menu(list_P &LP, list_C &LC, list_R &LR);
void Menu1_LihatDataMaskapai(list_P &LP, list_C &LC, list_R &LR);
void Menu2_TambahMaskapai(list_P &LP, list_C &LC, list_R &LR);
void Menu3_HapusMaskapai(list_P &LP, list_C &LC, list_R &LR);
void Menu4_LihatDataPenumpang(list_P &LP, list_C &LC, list_R &LR);
void Menu5_TambahPenumpang(list_P &LP, list_C &LC, list_R &LR);
void Menu6_HapusPenumpang(list_P &LP, list_C &LC, list_R &LR);
void Menu7_LihatDataBooking(list_P &LP, list_C &LC, list_R &LR);
void Menu8_TambahBooking(list_P &LP, list_C &LC, list_R &LR);
void Menu9_GantiStatusBooking(list_P &LP, list_C &LC, list_R &LR);
void Menu10_MenuLainnya(list_P &LP, list_C &LC, list_R &LR);

void Menu(list_P &LP, list_C &LC, list_R &LR){
    int pilihan;
        cout << "----====[ MENU ]====----" << "\n";
        cout << "1. Lihat Data Maskapai" << "\n";
        cout << "2. Tambah Maskapai" << "\n";
        cout << "3. Hapus Maskapai" << "\n";
        cout << "4. Lihat Data Penumpang" << "\n";
        cout << "5. Tambah Penumpang" << "\n";
        cout << "6. Hapus Penumpang" << "\n";
        cout << "7. Lihat Data Booking" << "\n";
        cout << "8. Tambah Booking" << "\n";
        cout << "9. Edit Status Booking" << "\n";
        cout << "10. Menu Lainnya" << "\n";
        cout << "11. Keluar" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                Menu1_LihatDataMaskapai(LP, LC, LR);
                break;
            case 2:
                Menu2_TambahMaskapai(LP, LC, LR);
                break;
            case 3:
                Menu3_HapusMaskapai(LP, LC, LR);
                break;
            case 4:
                Menu4_LihatDataPenumpang(LP, LC, LR);
                break;
            case 5:
                Menu5_TambahPenumpang(LP, LC, LR);
                break;
            case 6:
                Menu6_HapusPenumpang(LP, LC, LR);
                break;
            case 7:
                Menu7_LihatDataBooking(LP, LC, LR);
                break;
            case 8:
                Menu8_TambahBooking(LP, LC, LR);
                break;
            case 9:
                Menu9_GantiStatusBooking(LP, LC, LR);
                break;
            case 10:
                Menu10_MenuLainnya(LP, LC, LR);
                break;
            default:
                break;
        }
    }

void Menu1_LihatDataMaskapai(list_P &LP, list_C &LC, list_R &LR){
    int pilihan;
    while (pilihan != 3){
        cout << "----====[ Lihat Data Maskapai ]====----" << "\n";
        cout << "1. Lihat Seluruh List Maskapai" << "\n";
        cout << "2. Lihat Data Maskapai Berdasarkan Nama Dan Kode Maskapai" << "\n";
        cout << "3. Kembali ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if(pilihan == 1) {
            showMaskapai(LP);
        }else if(pilihan == 2){
            string namaMaskapai, kodeMaskapai;
            cout << "Masukkan Nama Maskapai: ";
            cin >> namaMaskapai;
            cout << "Masukkan Kode Maskapai: ";
            cin >> kodeMaskapai;
            cout << "------------------------" << "\n";
            searchMaskapai(LP, namaMaskapai, kodeMaskapai);
        }else if(pilihan == 3){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

void Menu2_TambahMaskapai(list_P &LP, list_C &LC, list_R &LR){
    int pilihan, jumlahPenumpang;
    string nama, kode, asal, tujuan, waktu;
    adr_Maskapai P;

    while (pilihan != 3){
        cout << "----====[ Tambah Maskapai ]====----" << "\n";
        cout << "1. Insert First" << "\n";
        cout << "2. Insert Last" << "\n";
        cout << "3. Kembali ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "------------------------" << "\n";

        if(pilihan == 1) {
            cout << "Masukkan Nama Maskapai: ";
            cin >> nama;
            cout << "Masukkan kode Maskapai: ";
            cin >> kode;
            cout << "Masukkan Asal Maskapai: ";
            cin >> asal;
            cout << "Masukkan Tujuan Maskapai: ";
            cin >> tujuan;
            cout << "Masukkan Waktu Keberangkatan: ";
            cin >> waktu;
            cout << "Masukkan Daya Tampung Pesawat: ";
            cin >> jumlahPenumpang;
            insertFirstMaskapai(LP, createElemenMaskapai({nama, kode, asal, tujuan, waktu, jumlahPenumpang}));
        }else if(pilihan == 2){
            cout << "Masukkan Nama Maskapai: ";
            cin >> nama;
            cout << "Masukkan kode Maskapai: ";
            cin >> kode;
            cout << "Masukkan Asal Maskapai: ";
            cin >> asal;
            cout << "Masukkan Tujuan Maskapai: ";
            cin >> tujuan;
            cout << "Masukkan Waktu Keberangkatan: ";
            cin >> waktu;
            cout << "Masukkan Daya Tampung Pesawat: ";
            cin >> jumlahPenumpang;
            insertLastMaskapai(LP, createElemenMaskapai({nama, kode, asal, tujuan, waktu, jumlahPenumpang}));
        }else if(pilihan == 3){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

void Menu3_HapusMaskapai(list_P &LP, list_C &LC, list_R &LR){
    int pilihan;
    string nama, kode;
    adr_Maskapai deleteP;
    while (pilihan != 4){
        cout << "----====[ Hapus Maskapai ]====----" << "\n";
        cout << "1. Delete First" << "\n";
        cout << "2. Delete Last" << "\n";
        cout << "3. Delete Berdasarkan Nama Dan Kode Maskapai" << "\n";
        cout << "4. Kembali Ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "------------------------" << "\n";

        if(pilihan == 1) {
            deleteFirstMaskapai(LP, deleteP);
        }else if(pilihan == 2){
            deleteLastMaskapai(LP, deleteP);
        }else if(pilihan == 3){
            cout << "Masukkan Nama Maskapai: ";
            cin >> nama;
            cout << "Masukkan Kode Maskapai: ";
            cin >> kode;
            deleteMaskapai(LP, nama, kode);
        }else if(pilihan == 4){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

void Menu4_LihatDataPenumpang(list_P &LP, list_C &LC, list_R &LR){
    int pilihan, usia;
    string nama;

    while (pilihan != 3){
        cout << "----====[ Lihat Data Penumpang ]====----" << "\n";
        cout << "1. Lihat Seluruh List Penumpang" << "\n";
        cout << "2. Lihat Data Penumpang Berdasarkan Nama Dan Umur Penumpang" << "\n";
        cout << "3. Kembali ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if(pilihan == 1) {
            printInfoPenumpang(LC);
        }else if(pilihan == 2){
            cout << "Masukkan Nama Penumpang: ";
            cin >> nama;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;
            cout << "------------------------" << "\n";
            searchPenumpang(LC, nama, usia);
        }else if(pilihan == 3){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

void Menu5_TambahPenumpang(list_P &LP, list_C &LC, list_R &LR){
    int pilihan, usia;
    string nama, alamat, JK;

    while (pilihan != 3){
        cout << "----====[ Tambah Data Penumpang ]====----" << "\n";
        cout << "1. Insert First" << "\n";
        cout << "2. Insert Last" << "\n";
        cout << "3. Kembali ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "------------------------" << "\n";

        if(pilihan == 1) {
            cout << "Masukkan Nama Penumpang: ";
            cin >> nama;
            cout << "Masukkan Alamat Penumpang: ";
            cin >> alamat;
            cout << "Masukkan Jenis Kelamin Penumpang: ";
            cin >> JK;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;
            insertFirstPenumpang(LC, allocatePenumpang(nama, alamat, JK, usia));
        }else if(pilihan == 2){
            cout << "Masukkan Nama Penumpang: ";
            cin >> nama;
            cout << "Masukkan Alamat Penumpang: ";
            cin >> alamat;
            cout << "Masukkan Jenis Kelamin Penumpang: ";
            cin >> JK;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;
            insertLastPenumpang(LC, allocatePenumpang(nama, alamat, JK, usia));
        }else if(pilihan == 3){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

void Menu6_HapusPenumpang(list_P &LP, list_C &LC, list_R &LR){
    int pilihan, usia;
    string nama;
    adr_Penumpang deleteP;
    while (pilihan != 4){
        cout << "----====[ Hapus Data Penumpang ]====----" << "\n";
        cout << "1. Delete First" << "\n";
        cout << "2. Delete Last" << "\n";
        cout << "3. Delete Berdasarkan Nama Dan Usia Penumpang" << "\n";
        cout << "4. Kembali Ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "------------------------" << "\n";

        if(pilihan == 1) {
            deleteFirstPenumpang(LC, deleteP);
        }else if(pilihan == 2){
            deleteLastPenumpang(LC, deleteP);
        }else if(pilihan == 3){
            cout << "Masukkan Nama Penumpang: ";
            cin >> nama;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;
            deletePenumpang(LC, nama, usia);
        }else if(pilihan == 4){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

void Menu7_LihatDataBooking(list_P &LP, list_C &LC, list_R &LR){
    int pilihan, usia;
    string namaMaskapai, kodeMaskapai, namaPenumpang;

    while (pilihan != 5){
        cout << "----====[ Lihat Data Maskapai ]====----" << "\n";
        cout << "1. Lihat Seluruh List Booking Maskapai" << "\n";
		cout << "2. Lihat Seluruh List Booking Penumpang" << "\n";
        cout << "3. Lihat Data Booking Berdasarkan Nama Dan Kode Maskapai" << "\n";
        cout << "4. Lihat Data Booking Berdasarkan Nama Dan Usia Penumpang" << "\n";
        cout << "5. Kembali ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "------------------------" << "\n";

        if(pilihan == 1) {
            showRelasi(LR);
            // showRelasi2(LR, LP); buat testing versi lain
		}else if(pilihan == 2) {
            showRelasi3(LR);
        }else if(pilihan == 3){
            cout << "Masukkan Nama Maskapai: ";
            cin >> namaMaskapai;
            cout << "Masukkan Kode Maskapai: ";
            cin >> kodeMaskapai;
            cout << "------------------------" << "\n";
            searchRelasi(LR, LP, LC, namaMaskapai, kodeMaskapai);
        }else if(pilihan == 4){
            cout << "Masukkan Nama Penumpang: ";
            cin >> namaPenumpang;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;
            cout << "------------------------" << "\n";
            searchRelasi2(LR, LP, LC, namaPenumpang, usia);
        }else if(pilihan == 5){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

void Menu8_TambahBooking(list_P &LP, list_C &LC, list_R &LR){
    int pilihan, usia;
    string namaMaskapai, kode, namaPenumpang;
    adr_Maskapai P;

    while (pilihan != 3){
        cout << "----====[ Tambah Booking ]====----" << "\n";
        cout << "1. Insert First" << "\n";
        cout << "2. Insert Last" << "\n";
        cout << "3. Kembali ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "------------------------" << "\n";

        if(pilihan == 1) {
            cout << "Masukkan Nama Maskapai: ";
            cin >> namaMaskapai;
            cout << "Masukkan kode Maskapai: ";
            cin >> kode;
            cout << "Masukkan Nama Penumpang: ";
            cin >> namaPenumpang;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;

            connect(LR, LP, LC, namaMaskapai, kode, namaPenumpang, usia, "first");
        }else if(pilihan == 2){
            cout << "Masukkan Nama Maskapai: ";
            cin >> namaMaskapai;
            cout << "Masukkan kode Maskapai: ";
            cin >> kode;
            cout << "Masukkan Nama Penumpang: ";
            cin >> namaPenumpang;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;

            connect(LR, LP, LC, namaMaskapai, kode, namaPenumpang, usia, "last");
        }else if(pilihan == 3){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

void Menu9_GantiStatusBooking(list_P &LP, list_C &LC, list_R &LR){
    int pilihan, usia, usiaBaru;
    string namaMaskapai, kode, namaPenumpang, maskapaiBaru, kodeBaru, namaBaru;
    
    while (pilihan != 4){
        cout << "----====[ Ganti Status Booking ]====----" << "\n";
        cout << "1. Hapus Booking" << "\n";
        cout << "2. Ganti Maskapai(Reschedule)" << "\n";
        cout << "3. Ganti Nama Penumpang" << "\n";
        cout << "4. Kembali Ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "------------------------" << "\n";

        if(pilihan == 1) {
            cout << "Masukkan Nama Maskapai: ";
            cin >> namaMaskapai;
            cout << "Masukkan kode Maskapai: ";
            cin >> kode;
            cout << "Masukkan Nama Penumpang: ";
            cin >> namaPenumpang;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;

            disconnect(LR, LP, LC, namaMaskapai, kode, namaPenumpang, usia);
        }else if(pilihan == 2){
            cout << "Masukkan Nama Maskapai: ";
            cin >> namaMaskapai;
            cout << "Masukkan kode Maskapai: ";
            cin >> kode;
            cout << "Masukkan Nama Penumpang: ";
            cin >> namaPenumpang;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;
            cout << "Masukkan Nama Maskapai Baru: ";
            cin >> maskapaiBaru;
            cout << "Masukkan kode Maskapai Baru: ";
            cin >> kodeBaru;

            reschedule(LR, LP, LC, namaMaskapai, kode, namaPenumpang, usia, maskapaiBaru, kodeBaru);
        }else if(pilihan == 3){
            cout << "Masukkan Nama Maskapai: ";
            cin >> namaMaskapai;
            cout << "Masukkan kode Maskapai: ";
            cin >> kode;
            cout << "Masukkan Nama Penumpang: ";
            cin >> namaPenumpang;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;
            cout << "Masukkan Nama Baru Penumpang: ";
            cin >> namaBaru;
            cout << "Masukkan Usia Baru Penumpang: ";
            cin >> usiaBaru;

            editNamaPenumpang(LR, LP, LC, namaMaskapai, kode, namaPenumpang, usia, namaBaru, usiaBaru);
        }else if(pilihan == 4){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

void Menu10_MenuLainnya(list_P &LP, list_C &LC, list_R &LR){
    int pilihan, usia;
    string nama;
    
    while (pilihan != 5){
        cout << "----====[ Menu Lainnya ]====----" << "\n";
        cout << "1. Hitung Relasi Parent" << "\n";
        cout << "2. Hitung Relasi Child" << "\n";
        cout << "3. Lihat Parent Yang Tidak Memiliki Relasi" << "\n";
        cout << "4. Lihat Child Yang Tidak Memiliki Relasi" << "\n";
        cout << "5. Kembali Ke Menu Utama" << "\n";
        cout << "------------------------" << "\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << "------------------------" << "\n";

        if(pilihan == 1) {
            hitungRelasiParent(LR, LP);
        }else if(pilihan == 2){
            cout << "Masukkan Nama Penumpang: ";
            cin >> nama;
            cout << "Masukkan Usia Penumpang: ";
            cin >> usia;
            hitungRelasiChild(LR, LC, nama, usia);
        }else if(pilihan == 3){
            hitungParentTidakBerelasi(LR, LP);
        }else if(pilihan == 4){
            hitungChildTidakBerelasi(LR, LC);
        }else if(pilihan == 5){
            Menu(LP, LC, LR);
        }else{
            cout << "Pilihan Tidak Valid" << endl;
        }
    }
}

int main() {
    list_P LP;
    list_C LC;
    list_R LR;
    createListMaskapai(LP);
    createListPenumpang(LC);
    createListRelasi(LR);

    /*insertLastMaskapai(LP, createElemenMaskapai({"LP1", "lar-100", "jakarta", "denpasar", "19:40", 100}));
    insertLastMaskapai(LP, createElemenMaskapai({"LP2", "lar-200", "bali", "papua", "20:45", 200}));
    insertLastMaskapai(LP, createElemenMaskapai({"LP3", "lar-300", "medan", "kendari", "10:10", 3003}));
    insertLastMaskapai(LP, createElemenMaskapai({"LP4", "lar-400", "surabaya", "jakarta", "20:50", 4004}));
    insertLastMaskapai(LP, createElemenMaskapai({"LP5", "lar-500", "kendari", "bali", "00:40", 500}));
    insertLastMaskapai(LP, createElemenMaskapai({"LP6", "lar-600", "kendari", "bali", "00:40", 500}));
    insertLastMaskapai(LP, createElemenMaskapai({"LP7", "lar-700", "kendari", "bali", "00:40", 500}));
    insertLastMaskapai(LP, createElemenMaskapai({"LP8", "lar-800", "kendari", "bali", "00:40", 500}));

    adr_Penumpang A = allocatePenumpang("tes1", "Jl. ABC", "Laki-laki", 1);
    insertLastPenumpang(LC, A);
    adr_Penumpang B = allocatePenumpang("tes2", "Jl. XYZ", "Perempuan", 2);
    insertLastPenumpang(LC, B);
    adr_Penumpang C = allocatePenumpang("tes3", "Jl. 123", "Laki-laki", 3);
    insertLastPenumpang(LC, C);
    adr_Penumpang D = allocatePenumpang("tes4", "Jl. 123", "Perempuan", 4);
    insertLastPenumpang(LC, D);
    adr_Penumpang E = allocatePenumpang("tes5", "Jl. 123", "Laki-Laki", 5);
    insertLastPenumpang(LC, E);
    adr_Penumpang F = allocatePenumpang("tes6", "Jl. 123", "Laki-Laki", 6);
    insertLastPenumpang(LC, F);
    adr_Penumpang G = allocatePenumpang("tes7", "Jl. 123", "Laki-Laki", 7);
    insertLastPenumpang(LC, G);
    adr_Penumpang H = allocatePenumpang("tes8", "Jl. 123", "Laki-Laki", 8);
    insertLastPenumpang(LC, H);
    adr_Penumpang I = allocatePenumpang("tes9", "Jl. 123", "Laki-Laki", 9);
    insertLastPenumpang(LC, I);

    connect(LR, LP, LC, "LP1", "lar-100" , "tes1", 1, "last");
    connect(LR, LP, LC, "LP2", "lar-200" , "tes1", 1, "last");
    connect(LR, LP, LC, "LP2", "lar-200" , "tes2", 2, "last");
    connect(LR, LP, LC, "LP3", "lar-300" , "tes3", 3, "last");
    connect(LR, LP, LC, "LP1", "lar-100" , "tes4", 4, "last");
    connect(LR, LP, LC, "LP2", "lar-200" , "tes5", 5, "last");
    connect(LR, LP, LC, "LP3", "lar-300" , "tes6", 6, "last");
    connect(LR, LP, LC, "LP6", "lar-600" , "tes1", 1, "last");
    connect(LR, LP, LC, "LP1", "lar-100" , "tes3", 3, "first");
    connect(LR, LP, LC, "LP2", "lar-200" , "tes3", 3, "last");*/
    Menu(LP, LC, LR);
    
   return 0;


/*LP1->tes3, tes1
LP2->tes1, tes2
LP3->tes3
LP1->tes4
LP2->tes5
LP3->tes6
LP6->tes1
LP2->tes3*/

     
}
