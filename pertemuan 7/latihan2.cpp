#include <iostream>
using namespace std;

int main() {
  int pilihan;
  float ipk, penghasilan;
  char status_mahasiswa;
  int jumlah_laptop;

  cout << "=== sistem Layanan Mahasigma ===" << endl
       << "1. Beasiswa \n"
       << "2. Peminjaman Laptop\n"
       << "3. Keringanan UKT\n\n"
       << "Masukkan Pilihan: ";
  cin >> pilihan;
  switch (pilihan) {
  case 1:
    cout << "\n === Layanan Beasiswa ===\n";
    cout << "Berapa IPK mu pamerin aja: ";
    cin >> ipk;
    cout << "Berapa penghasilan orang tua kamu: ";
    cin >> penghasilan;
    if (ipk >= 3.5) {
      if (penghasilan <= 4000000) {
        cout << "wanjay cik dapet beasigma";
      } else {
        cout << "yahh kamu terlalu kaya nono ya dapet beasigma";
      }
    } else {
      cout << "yah ipk mu kurang jadi gak dapet beasigma :(";
    }
    break;
  case 2:
    cout << "\n === Layanan Peminjaman Laptop ===\n";
    cout << "Apakah kamu mahasigma aktif(y/t): ";
    cin >> status_mahasiswa;
    if (status_mahasiswa == 'y') {
      cout << "Berapa jumlah laptop yang dipinjam: ";
      cin >> jumlah_laptop;
      if (jumlah_laptop == 0) {
        cout << "Boleh meminjam laptop";
      } else {
        cout << "Tidak boleh meminjam, masih punya laptop kamu cik";
      }

    } else {
      cout << "Kamu penyusup gak boleh minjam laptop";
    }
    break;
  case 3:
    cout << "\n === Layanan keringanan UKT ===\n";
    int penghasilan, tanggungan;
    cout << "berapa penghasilan orang tua: ";
    cin >> penghasilan;
    if (penghasilan <= 5000000) {
      cout << "berapa jumlah tanggungan keluarga";
      cin >> tanggungan;
      if (tanggungan >= 3) {
        cout << "Mendapat Keringanan UKT";
      } else {
        cout << "Dipertimbangkan untuk dapat keringanan UKT";
      }
    } else {
      cout << "huuu kamu terlalu kaya";
    }
  default:
    cout << "pilihanmu ngawur cik";
    break;
  }
  return 0;
}
