#include <iostream>
using namespace std;

// input: 2 rational numbers, output: their sum
// e.g. 1/3, 2/5 -> 11/15

struct rationalNumber {
  void readNumber() {
    cin >> nom;
    cin >> denom;
  }

  void writeNumber() {
    cout << nom << "/" << denom << endl;
  }

  // imutable
  rationalNumber add(rationalNumber b) {
    rationalNumber res;
    res.nom = nom * b.denom + b.nom * denom;
    res.denom = denom * b.denom;
    return res;
  }

  rationalNumber& addMutable(rationalNumber b) {
    nom = nom * b.denom + b.nom * denom;
    denom = denom * b.denom;
    return *this;
  }

private:
  int nom;
  int denom;
};

struct complexRationalNumber {
  void readNumber() {
    cout << "Real part: ";
    realPart.readNumber();

    cout << "Imag part: ";
    imagPart.readNumber();
  }

  void writeNumber() {
    realPart.writeNumber();
    cout << "i:";
    imagPart.writeNumber();
  }

  complexRationalNumber add(complexRationalNumber b) {
    complexRationalNumber res;
    res.realPart = realPart.add(b.realPart);
    res.imagPart = imagPart.add(b.imagPart);
    return res;
  }

private:
  rationalNumber realPart;
  rationalNumber imagPart;
};

int main() {
  complexRationalNumber n1;
  complexRationalNumber n2;

  cout << "Enter n1: ";
  n1.readNumber();

  cout << "Enter n2: ";
  n2.readNumber();

  complexRationalNumber result = n1.add(n2);
  cout << "Result: ";
  result.writeNumber();
  return 0;
}
