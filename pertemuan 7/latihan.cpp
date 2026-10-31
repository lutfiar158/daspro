#include <iostream>
using namespace std;

int main() {
  int x, y, z;
  cout << "masukkan angka x: ";
  cin >> x;
  cout << "masukkan angka y: ";
  cin >> y;
  cout << "masukkan angka z: ";
  cin >> z;

  if (x < y && x < z) {
    cout << "x adalah yang terkecil";
  } else if (y < z) {
    cout << "y adalah yang terkecil";
  } else {
    cout << "z adalah yang terkecil";
  }
  return 0;
}
