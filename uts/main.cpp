#include "string"
#include <iostream>
using namespace std;

int main() {
  int pilihan_menu;
  float harga, harga_awal, tot_harga, diskon = 0, porsi;
  char mahasiswa;
  string menu;

  cout << "=== kantin kampus ===\n"
       << "1. Nasi Ayam \n"
       << "2. Nasi goreng \n"
       << "3. Mie Ayam\n\n"
       << "Pilih menu: ";
  cin >> pilihan_menu;

  switch (pilihan_menu) {
  case 1:
    harga = 15000;
    menu = "Nasi Ayam";
    cout << "Berapa porsi yang diinginkan: ";
    cin >> porsi;
    harga_awal = harga * porsi;
    if (porsi >= 3) {
      cout << "apakah kamu mahasiwa(y/t): ";
      cin >> mahasiswa;
      if (mahasiswa == 'y') {
        diskon = harga_awal * 0.2;
      } else {
        diskon = harga_awal * 0.1;
      }
    }
    break;
  case 2:
    harga = 18000;
    menu = "Nasi Goreng";
    cout << "Berapa porsi yang diinginkan: ";
    cin >> porsi;
    harga_awal = harga * porsi;
    if (porsi >= 3) {
      cout << "apakah kamu mahasiwa(y/t): ";
      cin >> mahasiswa;
      if (mahasiswa == 'y') {
        diskon = harga_awal * 0.15;
      } else {
        diskon = harga_awal * 0.05;
      }
    }
    break;
  case 3:
    harga = 12000;
    menu = "Mie Ayam";
    cout << "Berapa porsi yang diinginkan: ";
    cin >> porsi;
    harga_awal = harga * porsi;
    if (porsi >= 5) {
      cout << "apakah kamu mahasiwa(y/t): ";
      cin >> mahasiswa;
      if (mahasiswa == 'y') {
        diskon = harga_awal * 0.2;
      } else {
        diskon = harga_awal * 0.1;
      }
    }
    break;
  default:
    cout << "menu tidak tersedia";
    return 0;
    break;
  }
  tot_harga = harga_awal - diskon;
  cout << "\n==== Hasil pemesanan ====\n"
       << "Menu: " << menu << " | Jumlah: " << porsi << "\nHarga awal: Rp"
       << harga_awal << " | Diskon: Rp" << diskon << "\nTotal Bayar: Rp"
       << tot_harga;

  return 0;
}
