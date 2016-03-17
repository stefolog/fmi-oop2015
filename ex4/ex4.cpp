#include <iostream>
#include <math.h>
#include "Decimal.cpp" // ex3.cpp
using namespace std;

int main() {
  Decimal(5, 5).print();
  Decimal(5, -5).print();
  Decimal(-5, 5).print();
  Decimal(-5, -5).print();

  Decimal(0, 25).print();
  Decimal(0, -25).print();

  Decimal('+', 5, 5).print();
  Decimal('+', 5, -5).print();
  Decimal('-', 5, 5).print();
  Decimal('-', -5, 5).print();

  Decimal('+', 0, 25).print();
  Decimal('-', 0, 25).print();

  Decimal(true, 0, 25).print();
  Decimal(true, 0, -25).print();
  Decimal(false, 0, 25).print();
  Decimal(false, 0, -25).print();

  Decimal::createPositive(5, 5).print();
  Decimal::createPositive(-5, -5).print();
  Decimal::createNegative(5, -5).print();
  Decimal::createNegative(5, 5).print();

  // Decimal("0.25").print();
  // Decimal("-0.25").print();


  Decimal(0, 1).print();
  Decimal(0, 1, 0).print();
  Decimal(0, -1, -5).print();

  Decimal(0, -1, 1).print();
  Decimal(0, 1, 2).print();
  Decimal(0, -1, 3).print();
  Decimal(0, 1, 4).print();

  return 0;
}


