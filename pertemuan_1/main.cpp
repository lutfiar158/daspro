#include <iostream>
#include <string>
using namespace std;

int main(){
    string nama_lengkap;
    int umur;
    string alamat;
    float berat_badan;

    cout << "Masukan Nama: ";
    cin >> nama_lengkap;
    cout << "Masukkan alamat: ";
    cin >> alamat;
    cout << "Masukkan umur: ";
    cin >> umur;
    cout << "Masukkan berat badan: ";
    cin >> berat_badan;
    cout << endl;

    cout << "Nama: " << nama_lengkap << endl
     << "Alamat: " << alamat << endl
     << "Umur: " << umur << endl
     << "Berat Badan: " << berat_badan << endl;
    return 0;
}