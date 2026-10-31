#include <iostream>
using namespace std;

int main() {
  char belok;
  do {
    cout << "apakah mau belok (y/t): ";
    cin >> belok;
  } while (belok != 'y');
  cout << "finish";
  return 0;
}
