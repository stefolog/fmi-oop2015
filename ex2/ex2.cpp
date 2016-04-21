// 1. Вход: 2 рационални числа, Изход: сумата им
// пример: 1/5 + 2/3
#include <iostream>

using namespace std;

struct rationalNumber {
  int nom;
  int denom;


  // imutable
  rationalNumber add(rationalNumber n) {
    rationalNumber result;
    result.nom = (*this).nom * n.denom + n.nom * (*this).denom;
    result.denom = (*this).denom * n.denom;
    return result;
  }

  rationalNumber addMutable(rationalNumber n) {
    (*this).nom = (*this).nom * n.denom + n.nom * (*this).denom;
    (*this).denom = (*this).denom * n.denom;
    return *this;
  }
};

struct complexRationalNumber {
  rationalNumber realPart;
  rationalNumber imagPart;

  // n1.add(n2)
  complexRationalNumber add(complexRationalNumber n) {
    // n1 -> *this
    // n2 -> n
    complexRationalNumber result;

    result.realPart = (*this).realPart.add(n.realPart);
    result.imagPart = (*this).imagPart.add(n.imagPart);
    return result;
  }

};

rationalNumber sum(rationalNumber n1, rationalNumber n2) {
  rationalNumber result;
  result.nom = n1.nom * n2.denom + n2.nom * n1.denom;
  result.denom = n1.denom * n2.denom;
  return result;
}

complexRationalNumber sum(complexRationalNumber n1,
                          complexRationalNumber n2) {

  complexRationalNumber result;
  result.realPart = sum(n1.realPart, n2.realPart);
  result.imagPart = sum(n1.imagPart, n2.imagPart);
  return result;
}

void readNumber(rationalNumber & n) {
  cin >> n.nom;
  cin >> n.denom;
}

void readNumber(complexRationalNumber & n) {
  readNumber(n.realPart);
  readNumber(n.imagPart);
}

void writeNumber(rationalNumber n) {
  cout << n.nom << "/" << n.denom << endl;
}

void writeNumber(complexRationalNumber n) {
  writeNumber(n.realPart);
  cout << " + i";
  writeNumber(n.imagPart);
}

int main() {
  complexRationalNumber n1;
  complexRationalNumber n2;

  cout << "число 1:";
  readNumber(n1);

  cout << "число 2:";
  readNumber(n2);

  complexRationalNumber result1 = sum(n1, n2);
  cout << "Result 1: ";
  writeNumber(result1);

  complexRationalNumber result2 = n1.add(n2);
  cout << "Result 2: ";
  writeNumber(result2);

}
