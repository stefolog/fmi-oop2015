#include <iostream>
#include "Decimal.h"
using namespace std;

int main() {
  Decimal x(5, 5);
  Decimal y(7, 5);
  Decimal z(0, 0);
  z.read();


  int a = 5;
  int b = 10;

  if (x + y == Decimal(13, 0)) {
    cout << "Yes!!!" << endl;
  } else {
    cout << "Nope" << endl;
  }

  return 0;
}
