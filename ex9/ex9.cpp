#include <iostream>
#include "Decimal.h"
using namespace std;


// operator++()
// operator--()

// operator[]
//  a[0] -> intPart
//  a[1] -> decPart
//  a[*] -> 0

int main() {
  Decimal a(5, 5);
  Decimal b(5, 5);

  cout << "++a: ";
  (++a).print();
  a.print();

  cout << "a[0]: " << a[0] << endl; // expected: 6
  cout << "a[1]: " << a[1] << endl; // expected: 5
  cout << "a[10]: " << a[10] << endl;

  cout << "b++: ";
  (b++).print();
  b.print();

  int x = 10;
  int y = 10;
  cout << "x: " << (++x) << endl;
  cout << "y: " << (y++) << endl;
  return 0;
}
