# Aplikasi Manajemen Maskapai //Parent.h & Parent.cpp
Aplikasi ini adalah program sederhana untuk manajemen daftar maskapai penerbangan. Program ini memungkinkan pengguna untuk menambah, mengubah, menghapus, serta melihat daftar maskapai dan detail informasinya.

## Fitur
1. **Tambah Maskapai :** Menambahkan data maskapai baru ke dalam sistem.
2. **Ubah Maskapai :** Mengubah data maskapai yang sudah ada.
3. **Hapus Maskapai :** Menghapus data maskapai dari sistem.
4. **Tampilkan Maskapai :** Melihat daftar maskapai beserta informasi detailnya.
5. **Pencarian Maskapai :** Mencari maskapai berdasarkan nama dan kode maskapai.

## Cara Penggunaan
1. **Menambah Maskapai :** Pilih opsi "Tambah Maskapai" dari menu dan masukkan data maskapai yang baru.
2. **Mengubah Maskapai :** Pilih opsi "Ubah Maskapai" dari menu dan ikuti instruksi untuk mengubah data maskapai yang sudah ada.
3. **Menghapus Maskapai :** Pilih opsi "Hapus Maskapai" dari menu dan ikuti instruksi untuk menghapus data maskapai.
4. **Melihat Daftar Maskapai :** Pilih opsi "Tampilkan Maskapai" dari menu untuk melihat daftar maskapai beserta informasi detailnya.
5. **Mencari Maskapai :** Pilih opsi "Pencarian Maskapai" dari menu dan masukkan nama dan kode maskapai yang ingin dicari.

## Catatan
- Program ini menggunakan fungsi `createListMaskapai()` untuk membuat list kosong dari maskapai.
- Fungsi `insertFirstMaskapai()` dan `insertLastMaskapai()` digunakan untuk memasukkan maskapai ke dalam list.
- Fungsi `searchM()` digunakan untuk mencari maskapai berdasarkan nama dan kode maskapai.
- Fungsi `deleteMaskapai()`, `deleteFirstMaskapai()`, dan `deleteLastMaskapai()` digunakan untuk menghapus maskapai dari list.

# Aplikasi Manajemen Penumpang //Child.h & Child.cpp
Aplikasi ini adalah program sederhana untuk manajemen daftar penumpang maskapai penerbangan. Program ini memungkinkan pengguna untuk menambah, mengubah, menghapus, serta melihat daftar penumpang dan detail informasinya.

## Fitur
1. **Tambah Penumpang :** Menambahkan data penumpang baru ke dalam sistem.
2. **Ubah Penumpang :** Mengubah data penumpang yang sudah ada.
3. **Hapus Penumpang :** Menghapus data penumpang dari sistem.
4. **Tampilkan Penumpang :** Melihat daftar penumpang beserta informasi detailnya.
5. **Pencarian Penumpang :** Mencari penumpang berdasarkan nama dan usia.

## Cara Penggunaan
1. **Menambah Penumpang :** Pilih opsi "Tambah Penumpang" dari menu dan masukkan data penumpang yang baru.
2. **Mengubah Penumpang :** Pilih opsi "Ubah Penumpang" dari menu dan ikuti instruksi untuk mengubah data penumpang yang sudah ada.
3. **Menghapus Penumpang :** Pilih opsi "Hapus Penumpang" dari menu dan ikuti instruksi untuk menghapus data penumpang.
4. **Melihat Daftar Penumpang :** Pilih opsi "Tampilkan Penumpang" dari menu untuk melihat daftar penumpang beserta informasi detailnya.
5. **Mencari Penumpang :** Pilih opsi "Pencarian Penumpang" dari menu dan masukkan nama dan usia penumpang yang ingin dicari.

## Catatan
- Program ini menggunakan fungsi `createListPenumpang()` untuk membuat list kosong dari penumpang.
- Fungsi `insertFirstPenumpang()`, `insertAfterPenumpang()`, dan `insertLastPenumpang()` digunakan untuk memasukkan penumpang ke dalam list.
- Fungsi `searchP()` digunakan untuk mencari penumpang berdasarkan nama dan usia.
- Fungsi `deletePenumpang()`, `deleteFirstPenumpang()`, `deleteAfterPenumpang()`, dan `deleteLastPenumpang()` digunakan untuk menghapus penumpang dari list.

# Aplikasi Manajemen Relasi Maskapai dan Penumpang //Relasi.h & Relasi.cpp
Aplikasi ini merupakan program untuk manajemen relasi antara maskapai penerbangan dan penumpang. Program ini memungkinkan pengguna untuk menghubungkan, memutuskan hubungan, mencari, serta melihat relasi antara maskapai dan penumpang.

## Fitur
1. **Connect :** Menghubungkan maskapai penerbangan dengan penumpang.
2. **Disconnect :** Memutuskan hubungan antara maskapai penerbangan dan penumpang.
3. **Cari Relasi :** Mencari relasi antara maskapai penerbangan dan penumpang berdasarkan nama maskapai, kode, nama penumpang, atau usia.
4. **Tampilkan Relasi :** Melihat daftar relasi antara maskapai penerbangan dan penumpang.
5. **Reschedule :** Mengubah relasi antara maskapai penerbangan dan penumpang.
6. **Edit Nama Penumpang :** Mengubah nama dan usia penumpang pada relasi yang sudah ada.
7. **Hitung Jumlah Relasi :** Menghitung jumlah relasi untuk maskapai penerbangan dan penumpang.
8. **Hitung Parent/Child Tanpa Relasi :** Menghitung maskapai penerbangan atau penumpang yang tidak memiliki relasi.

## Cara Penggunaan
1. **Connect :** Pilih opsi "Tambah Booking" dari menu lalu pilih jenis yang di inginkan dan masukkan nama maskapai, kode, nama penumpang, dan usia.
2. **Disconnect :** Pilih opsi "Ganti Status Booking" dari menu lalu pilih opsi "Hapus Booking" dan masukkan nama maskapai, kode, nama penumpang, dan usia.
3. **Cari Relasi :** Pilih opsi "Cari Relasi" dari menu dan masukkan informasi yang ingin dicari (nama maskapai, kode, nama penumpang, atau usia).
4. **Tampilkan Relasi :** Pilih opsi "Tampilkan Relasi" dari menu untuk melihat daftar relasi antara maskapai dan penumpang.
5. **Reschedule :** Pilih opsi "Reschedule" dari menu dan ikuti instruksi untuk mengubah relasi antara maskapai dan penumpang.
6. **Edit Nama Penumpang :** Pilih opsi "Edit Nama Penumpang" dari menu dan ikuti instruksi untuk mengubah nama dan usia penumpang pada relasi yang sudah ada.
7. **Hitung Jumlah Relasi :** Pilih opsi "Hitung Jumlah Relasi" dari menu untuk menghitung jumlah relasi untuk maskapai penerbangan atau penumpang.
8. **Hitung Parent/Child Tanpa Relasi :** Pilih opsi "Hitung Parent/Child Tanpa Relasi" dari menu untuk menghitung maskapai penerbangan atau penumpang yang tidak memiliki relasi.

## Catatan
- Program ini menggunakan konsep relasi antara maskapai penerbangan (parent) dan penumpang (child).
- Fungsi `connect()` digunakan untuk menghubungkan relasi antara maskapai dan penumpang.
- Fungsi `disconnect()` digunakan untuk memutuskan relasi antara maskapai dan penumpang.
- Fungsi `searchRelasi()` dan `searchRelasi2()` digunakan untuk mencari relasi berdasarkan nama maskapai, kode, nama penumpang, atau usia.
- Fungsi `reschedule()` digunakan untuk mengubah relasi antara maskapai dan penumpang.
- Fungsi `editNamaPenumpang()` digunakan untuk mengubah nama dan usia penumpang pada relasi yang sudah ada.
- Fungsi `hitungRelasiParent()` dan `hitungRelasiChild()` digunakan untuk menghitung jumlah relasi untuk maskapai penerbangan dan penumpang.
- Fungsi `hitungParentTidakBerelasi()` dan `hitungChildTidakBerelasi()` digunakan untuk menghitung maskapai penerbangan atau penumpang yang tidak memiliki relasi.

