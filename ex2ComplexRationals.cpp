#include <iostream>
using namespace std;

// input: 2 rational numbers, output: their sum
// e.g. 1/3, 2/5 -> 11/15

void sum(
      // число 1
      int n1nom, int n1denom, int n1inom, int n1idenom
      // число 2
      int n2nom, int n2denom, int n2inom, int n2idenom
      // резултат
      int & resultNom, int & resultDenom, int & resultiNom, int & resultiDenom) {
  // ...
}

void sum(int n1nom, int n1denom,
         int n2nom, int n2denom,
         int & resultNom, int & resultDenom) {

  resultNom = n1nom * n2denom + n2nom * n1denom;
  resultDenom = n1denom * n2denom;
}

int main() {
   // число 1
  int n1nom;
  int n1denom;
  int n1inom;
  int n1idenom;

  // число 2
  int n2nom;
  int n2denom;
  int n2inom;
  int n2idenom;

  // резултат
  int resultNom;
  int resultDenom;
  int resultiNom;
  int resultiDenom;

  cout << "Enter n1: ";
  cin >> n1nom;
  cin >> n1denom;
  cin >> n1inom;
  cin >> n1idenom;

  cout << "Enter n2: ";
  cin >> n2nom;
  cin >> n2denom;
  cin >> n2inom;
  cin >> n2idenom;

  sum(n1nom, n1denom, n1inom, n1idenom,
      n2nom, n2denom, n2inom, n2idenom,
      resultNom, resultDenom, resultiNom, resultiDenom);

  cout << "Result: "
       << resultNom << "/" << resultDenom
       << " + i("
       << resultiNom << "/" << resultiDenom
       << ")"
       << endl;
  return 0;
}
