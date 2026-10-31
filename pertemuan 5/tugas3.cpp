# include <iostream>
using namespace std;

int main(){
    int menu;
    string menu_dipilih;
    cout << "Pilihan Menu\n"
     << "1. Nasi Goreng \n"
     << "2. Mie Ayam \n"
     << "3. Nasi Padang \n"
     << "4. Soto Ayam \n"
     << "5. Bubur Ayam \n\n"
     << "Pilih Menu(hanya angka): ";
    cin >> menu;
    switch (menu){
        case 1:
            menu_dipilih = "Nasi Goreng";
            break;
        case 2:
            menu_dipilih = "Mie Ayam";
            break;
        case 3:
            menu_dipilih = "Nasi Padang";
            break;
        case 4:
            menu_dipilih = "Soto Ayam";
            break;
        case 5:
            menu_dipilih = "Bubur Ayam";
            break;
        default:
            menu_dipilih = "Tidak Valid";
            break;
    }
    cout << "Menu yang kamu pilih adalah: " << menu_dipilih << endl;
    return 0;
}