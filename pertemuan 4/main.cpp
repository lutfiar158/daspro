#include <iostream>
using namespace std;


// int main(){
//     int a;
//     const int x = 10;

//     cout << "Masukkan nilai a: ";
//     cin >> a;
//     if(a > x){
//         cout << a << endl;
//     }
//     cout << "Selesai chek";
// }

int main(){
    int a;
    const int x = 2;

    cout << "Masukkan nilai a: ";
    cin >> a;
    if(a % 2 == 0 && a > 2){
        cout << a << " adalah bilangan genap lebih dari 2 \n";
    }
    cout << "Selesai cek";
}