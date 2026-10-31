#include <iostream>
using namespace std;

int main() {
    // int angka1 = 20;
    // int angka2 = 20;
    // bool hasil_relasi;

    // hasil_relasi = angka1 == angka2;
    // cout << boolalpha << hasil_relasi << endl;
    // return 0;

    bool operand_1 = true, operand_2 = false;
    bool hasil1, hasil2, hasil;
    
    hasil1 = operand_1 && operand_2;
    hasil2 = (operand_1 && operand_2) ^ true;
    hasil = (operand_1 && operand_2) ^ true || (100 < 90) && (!false) ^ (90 == 90);
    
    cout << boolalpha << hasil1 << endl
    << hasil2 << endl 
    << hasil << endl;
    return 0;

}