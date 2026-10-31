# include <iostream>
using namespace std;

int main (){
    float hasil;
    float angka_1;
    float angka_2;

    cout << "Masukkan angka pertama: ";
    cin >> angka_1;
    cout << "Masukkan angka kedua: ";
    cin >> angka_2;
    cout << endl;

    hasil = (88+12) / 5 * (10 - angka_1) * angka_2 + 11 / 3 + 100;
    cout << "Hasil dari perhitungan adalah: " << hasil << endl;

    return 0;
}