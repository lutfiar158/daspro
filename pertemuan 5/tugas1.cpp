# include <iostream>
using namespace std;

int main(){
    int umur;
    string kategori;
    
    cout << "Masukkan umur kamu: ";
    cin >> umur;

    if(umur >= 60){
        kategori = "Lansia";
    } else if(umur > 18){
        kategori = "Dewasa";
    } else if(umur > 9){
        kategori = "Remaja";
    } else if(umur > 4){
        kategori = "Anak-anak";
    } else if(umur >= 0){
        kategori = "Balita";
    } else {
        kategori = "Tidak valid";
    }
    cout << "Kamu termasuk Kategori: " << kategori << endl;
    return 0;
}