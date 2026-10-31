#include <iostream>
using namespace std;

string name, nim, alamat, sma, tempatLahir, tanggalLahir;

// untuk menginput data dari user
void inputData() {
  cout << "===========================\n"
       << "Sistem Pendataan Mahasiswa\n"
       << "===========================\n\n";
  cout << "Silakan masukkan data Mahasiswa:\n\n";
  cout << "Nama Lengkap: ";
  getline(cin, name);
  cout << "NIM: ";
  getline(cin, nim);
  cout << "Alamat: ";
  getline(cin, alamat);
  cout << "Asal SMA: ";
  getline(cin, sma);
  cout << "Tempat Lahir: ";
  getline(cin, tempatLahir);
  cout << "Tanggal Lahir: ";
  getline(cin, tanggalLahir);
}

// untuk menampilkan data dari inputan yang di isi oleh user
void tampilkanData() {
  cout << "\n===========================\n";
  cout << "Data Mahasiswa";
  cout << "\n===========================\n";
  cout << "Nama Lengkap: " << name << "\n";
  cout << "NIM: " << nim << "\n";
  cout << "Alamat: " << alamat << "\n";
  cout << "Asal SMA: " << sma << "\n";
  cout << "Tempat Lahir: " << tempatLahir << "\n";
  cout << "Tanggal Lahir: " << tanggalLahir << "\n";
}
