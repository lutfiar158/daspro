#include <iostream>
using namespace std;

int hitungTotal(int harga, int jumlah) {
  int total = harga * jumlah;
  return total;
}

int main() {
  int totalBelanja;
  totalBelanja = hitungTotal(500, 3);
  cout << "Total Belanja kamu: " << totalBelanja << "\n";
  return 0;
}
