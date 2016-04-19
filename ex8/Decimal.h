#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>
#include <cmath>
using namespace std;

int length(int x);
int pad(int n, int target);
int trimRight(int n);

// class declaration
class Decimal {
public:
  Decimal(int intPart, int decPart, int zeroesAfterDecPoint);
  Decimal(char sign, int intPart, int decPart);
  Decimal(bool isPositive, int intPart, int decPart);

  static Decimal createPositive(int intPart, int decPart);
  static Decimal createNegative(int intPart, int decPart);

  bool operator==(const Decimal& other) const;
  const Decimal operator+(const Decimal& other) const;

  const Decimal operator-(const Decimal& other) const {
    return *this + Decimal(-other.intPart, other.decPart, other.zeroesAfterDecPoint);
  }

  // TODO: test me :)
  const Decimal operator*(const Decimal& other) const {
    int maxLength = max(length(decPart), length(other.decPart));
    int decPart1 = pad(decPart, maxLength);
    int decPart2 = pad(other.decPart, maxLength);

    long long n1 = this->intPart * (int) pow(10, maxLength) + decPart1;
    long long n2 = other.intPart * (int) pow(10, maxLength) + decPart2;

    int resIntPart = n1 * n2 / (int) pow(10, 2 * maxLength);
    int resDecPart = n1 * n2 % (int) pow(10, 2 * maxLength);
    int resZeroesAfterDecPoint = 2 * maxLength - length(resDecPart);

    return Decimal(resIntPart, resDecPart, resZeroesAfterDecPoint);
  }

  // TODO: zeroesAfterDecPoint
  bool operator<(const Decimal& other) const {
    int maxLength = max(length(decPart), length(other.decPart));
    int decPart1 = pad(decPart, maxLength);
    int decPart2 = pad(other.decPart, maxLength);

    long long n1 = this->intPart * (int) pow(10, maxLength) + decPart1;
    long long n2 = other.intPart * (int) pow(10, maxLength) + decPart2;

    return n1 < n2;
  }

  bool operator>(const Decimal& other) const {
    return !(*this < other || *this == other);
  }

  bool operator>=(const Decimal& other) const {
    return !(*this < other);
  }

  bool operator<=(const Decimal& other) const {
    return (*this < other || *this == other);
  }

  Decimal add(Decimal other) const;
  Decimal substract(Decimal other) const;
  bool equals(Decimal other) const;
  bool isNegative() const;

  void read() {
    cout << "Enter decimal number: " << endl;

    cout << "int part: ";
    cin >> thintPart;

    cout << "dec part: ";
    cin >> decPart;
  }

  void print() const; // ф-я за извеждане
private:
  int intPart;
  int decPart;
  bool negative;
  int zeroesAfterDecPoint;
};

#include "Decimal.cpp"
#endif // DECIMAL_H
