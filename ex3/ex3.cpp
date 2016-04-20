#include <iostream>
#include <math.h>
using namespace std;

int length(int x) {
  int n = 0;
  while (x > 0) {
    x /= 10;
    n++;
  }
  return n;
}

int pad(int n, int target) {
  if (n == 0) {
    return 0;
  }

  int l = length(n);
  while (0 < target - l) {
    n *= 10;
    l++;
  }

  return n;
}

int trimRight(int n) {
  while (n > 0 && n % 10 == 0) {
    n /= 10;
  }
  return n;
}

class Decimal {
public:
  Decimal(int intPart, int decPart) {
    this->intPart = intPart;
    this->decPart = decPart;
  }

  Decimal add(Decimal other) const {
    int maxLength = max(length(decPart), length(other.decPart));
    int decPart1 = pad(decPart, maxLength);
    int decPart2 = pad(other.decPart, maxLength);

    int resIntPart = intPart + other.intPart;
    int resDecPart = decPart1 + decPart2;

    if (maxLength < length(resDecPart)) {
      resIntPart += resDecPart / (int) pow(10, maxLength);
      resDecPart = resDecPart % (int) pow(10, maxLength);
    }

    resDecPart = trimRight(resDecPart);

    return Decimal(resIntPart, resDecPart);
  }

  Decimal substract(Decimal other) const {
    return Decimal(intPart - other.intPart, decPart - other.decPart);
  }

  bool equals(Decimal other) const {
    return intPart == other.intPart && decPart == other.decPart;
  }

  void print() const {
    cout << intPart << "." << decPart << endl;
  }

private:
  int intPart;
  int decPart;
};
