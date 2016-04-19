#ifndef DECIMAL_H
#define DECIMAL_H

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

  Decimal add(Decimal other) const;
  Decimal substract(Decimal other) const;
  bool equals(Decimal other) const;
  bool isNegative() const;
  void print() const;
private:
  int intPart;
  int decPart;
  bool negative;
  int zeroesAfterDecPoint;
};

#include "Decimal.cpp"
#endif // DECIMAL_H
