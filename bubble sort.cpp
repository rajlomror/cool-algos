#include <iostream>

using namespace std;

int main() {
  int i, j;
  int k;
  cout << "Please enter length: ";
  cin >> k;
  int numb[k];
  for (i = 0; i <= k - 1; i++) {
    cout << "Please enter number: ";
    cin >> numb[i];
  }

  for (i = 0; i <= k - 2; i++) {
    for (j = i + 1; j <= k - 1; j++) {
      int temp;

      if (numb[i] > numb[j]) {
        temp = numb[i];
        numb[i] = numb[j];
        numb[j] = temp;
      }
    }
  }

  for (i = 0; i <= k - 1; i++) {
    cout << endl << numb[i] << endl;
  }

  cin.ignore();
  cin.get();
}