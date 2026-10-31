# include <iostream>
using namespace std;

int main(){
    int x;
    cout << "Masukkan bilangan bulat:";
    cin >> x;
    if(x < 0){
        x = -x;
    }
    cout << x << endl;
}