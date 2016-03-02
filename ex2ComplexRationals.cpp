#include <iostream>
using namespace std;

// input: 2 rational numbers, output: their sum
// e.g. 1/3, 2/5 -> 11/15

int main() {
  // число 1
  int n1nom;
  int n1denom;

  // число 2
  int n2nom;
  int n2denom;

  // резултат
  int resultNom;
  int resultDenom;

  cout << "Enter n1: ";
  cin >> n1nom;
  cin >> n1denom;

  cout << "Enter n2: ";
  cin >> n2nom;
  cin >> n2denom;

  resultNom = n1nom * n2denom + n2nom * n1denom;
  resultDenom = n1denom * n2denom;

  cout << "Result: "
       << resultNom << "/" << resultDenom
       << endl;
  return 0;
}
