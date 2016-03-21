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
  Decimal(int intPart, int decPart, int zeroesAfterDecPoint = 0) {
    this->negative = (intPart < 0 || decPart < 0);

    this->intPart = abs(intPart);
    this->decPart = abs(decPart);
    this->zeroesAfterDecPoint = zeroesAfterDecPoint < 0 ? 0 : zeroesAfterDecPoint;
  }

  Decimal(char sign, int intPart, int decPart) {
    this->negative = (sign == '-');

    this->intPart = abs(intPart);
    this->decPart = abs(decPart);
    this->zeroesAfterDecPoint = 0;
  }

  Decimal(bool isPositive, int intPart, int decPart) {
    this->negative = (!isPositive);

    this->intPart = abs(intPart);
    this->decPart = abs(decPart);
    this->zeroesAfterDecPoint = 0;
  }

  static Decimal createPositive(int intPart, int decPart) {
    return Decimal('+', intPart, decPart);
  }

  static Decimal createNegative(int intPart, int decPart) {
    return Decimal('-', intPart, decPart);

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

  bool isNegative() const {
    return negative;
  }

  void print() const {
    if (isNegative()) {
      cout << "-";
    }
    cout << abs(intPart) << ".";
    for (int i = 0; i < zeroesAfterDecPoint; i++) {
      cout << 0;
    }
    cout << abs(decPart) << endl;
  }

private:
  int intPart;
  int decPart;
  bool negative;
  int zeroesAfterDecPoint;
};
