#include <iostream>
using namespace std;

int main() {
  int pilihan, umur;
  char weekend;
  cout << "==== Pemesanan tiket bioskop ====\n"
       << "1. Studio Reguler\n"
       << "2. Studio Premier\n"
       << "3. Studio IMAX \n\n";
  cout << "Pilih jenis studio: ";
  cin >> pilihan;
  switch (pilihan) {
  case 1:
    cout << "masukkan Umur Anda: ";
    cin >> umur;
    if (umur >= 12) {
      cout << "Apakah ini weekend(y/t): ";
      cin >> weekend;
      if (weekend == 'y') {
        cout << "\nStudio: Reguler\n";
        cout << "harga tiket kamu Rp50.000";
      } else {
        cout << "\nStudio: Reguler\n";
        cout << "harga tiket kamu Rp40.000";
      }
    } else {
      cout << "\nStudio: Reguler\n";
      cout << "harga tiket kamu Rp25.000";
    }
    break;
  case 2:
    cout << "masukkan Umur anda: ";
    cin >> umur;
    if (umur >= 17) {
      cout << "apakah ini weekend(y/t): ";
      cin >> weekend;
      if (weekend == 'y') {
        cout << "\nStudio: Premier\n";
        cout << "Harga tiket kamu Rp150.000";
      } else {
        cout << "\nStudio: Premier\n";
        cout << "Harga tiket kamu Rp100.000";
      }
    } else {
      cout << "\nStudio: Premier\n";
      cout << "tidak diperbolehkan membeli tiket premier";
    }
    break;
  case 3:
    cout << "masukkan umur anda: ";
    cin >> umur;
    if (umur >= 12) {
      cout << "apakah ini weekend(y/t): ";
      cin >> weekend;
      if (weekend == 'y') {
        cout << "\nStudio: IMAX\n";
        cout << "harga tiket kamu Rp100.000";
      } else {
        cout << "\nStudio: IMAX\n";
        cout << "harga tiket kamu Rp75.000";
      }
    } else {
      cout << "\nStudio: IMAX\n";
      cout << "harga tiket kamu Rp50.000";
    }
    break;
  default:
    cout << "pilihan studio tidak tersedia";
    break;
  }
  return 0;
}
