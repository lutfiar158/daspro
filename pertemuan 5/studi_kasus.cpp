# include <iostream>
using namespace std;

int main(){
    int a;
    cout << "Masukkan bilangan: ";
    cin >> a;

    if(a < 0){
        a = -a;
    }

    if(!(a % 5)){
        cout << "hore ketemu bilangan kelipatan 5\n";
    } else {
        cout << "yah... bukan bilangan kelipatan 5\n";
    }
    return 0;
}
