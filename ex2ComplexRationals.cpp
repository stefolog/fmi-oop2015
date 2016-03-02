#include <iostream>
using namespace std;

// input: 2 rational numbers, output: their sum
// e.g. 1/3, 2/5 -> 11/15

struct rationalNumber {
  int nom;
  int denom;
};

struct complexRationalNumber {
  rationalNumber realPart;
  rationalNumber imagPart;
};

rationalNumber sum(rationalNumber n1,
                   rationalNumber n2) {
  rationalNumber res;
  res.nom = n1.nom * n2.denom + n2.nom * n1.denom;
  res.denom = n1.denom * n2.denom;
  return res;
}

complexRationalNumber sum(complexRationalNumber n1,
                          complexRationalNumber n2) {

  complexRationalNumber res;
  res.realPart = sum(n1.realPart, n2.realPart);
  res.imagPart = sum(n1.imagPart, n2.imagPart);
  return res;
}

void readNumber(rationalNumber & n) {
  cin >> n.nom;
  cin >> n.denom;
}

void readNumber(complexRationalNumber & n) {
  cout << "Real part: ";
  readNumber(n.realPart);
  cout << "Imag part: ";
  readNumber(n.imagPart);
}

void writeNumber(rationalNumber n) {
  cout << n.nom << "/" << n.denom << endl;
}

void writeNumber(complexRationalNumber n) {
  writeNumber(n.realPart);
  cout << "i:";
  writeNumber(n.imagPart);
}

int main() {
  complexRationalNumber n1;
  complexRationalNumber n2;

  cout << "Enter n1: ";
  readNumber(n1);

  cout << "Enter n2: ";
  readNumber(n2);

  complexRationalNumber result = sum(n1, n2);
  cout << "Result: ";
  writeNumber(result);
  return 0;
}
