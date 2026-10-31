# include <iostream>
using namespace std;

int main(){
    int nilai;
    cout << "Masukkan nilai anda: ";
    cin >> nilai;
    if(nilai > 80){
        cout << "Selamat Kamu dinyatakan lulus ujian\n";
    } else {
        cout << "Sayang sekali kamu belum dinyatakan lulus ujian\n";
    }
}