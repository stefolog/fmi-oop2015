#include <iostream>
#include "Decimal.cpp"

using namespace std;

bool test_length() {
  if (0 != length(0)) return false;
  if (1 != length(6)) return false;
  if (2 != length(63)) return false;
  if (6 != length(871242)) return false;

  cout << "Test length ... OK" << endl;
  return true;
}

bool test_pad() {
  if (0 != pad(0, 10)) return false;
  if (100 != pad(1, 3)) return false;
  if (520 != pad(52, 3)) return false;
  if (420 != pad(420, 3)) return false;
  if (13 != pad(13, 1)) return false;

  cout << "Test pad ... OK" << endl;
  return true;
}

bool test_trimRight() {
  if (0 != trimRight(0)) return false;
  if (1 != trimRight(10)) return false;
  if (1 != trimRight(100)) return false;
  if (2 != trimRight(200000)) return false;
  if (5002 != trimRight(500200)) return false;
  if (42 != trimRight(42)) return false;

  cout << "Test trimRight ... OK" << endl;
  return true;
}

bool test_Decimal() {
  Decimal x(0, 0), y(1, 0), z(3, 0);
  Decimal a(1, 5), b(2, 25);
  Decimal n(0, -25), m(-1, 25);

  cout << "Test print ... " << endl;
  cout << "\t\t\t\t";
  b.print();
  cout << "\t\t\t\t";
  m.print();

  cout << "Test 1..." << endl;
  if (x.equals(y)) return false;

  cout << "Test 2..." << endl;
  if (!y.equals(y)) return false;

  cout << "Test 3..." << endl;
  if (!x.add(y).equals(Decimal(1, 0))) return false;

  cout << "Test 4..." << endl;
  if (!x.add(y).add(y).add(y).equals(Decimal(3, 0))) return false;
  cout << "Test 5..." << endl;
  if (!z.substract(y).equals(Decimal(2, 0))) return false;

  cout << "Test 6..." << endl;
  if (!a.add(a).equals(Decimal(3, 0))) return false;
  cout << "Test 7..." << endl;
  if (!b.add(b).equals(Decimal(4, 5))) return false;
  cout << "Test 8..." << endl;
  if (!a.add(b).equals(Decimal(3, 75))) return false;

  cout << "Test 9..." << endl;
  if (!n.add(n).equals(Decimal(0, -50))) return false;
  cout << "Test 10..." << endl;
  if (!n.substract(n).equals(Decimal(0, 0))) return false;

  cout << "Test 11..." << endl;
  if (!n.add(b).equals(Decimal(2, 0))) return false;
  cout << "Test 12..." << endl;
  if (!b.add(n).equals(Decimal(2, 0))) return false;
  cout << "Test 13..." << endl;
  if (!a.add(n).equals(Decimal(1, 25))) return false;

  cout << "Test 14..." << endl;
  if (!a.add(m).equals(Decimal(0, 25))) return false;
  cout << "Test 15..." << endl;
  if (!y.add(m).equals(Decimal(0, -25))) return false;
  cout << "Test 16..." << endl;
  if (!a.add(n).add(m).equals(Decimal(0, 0))) return false;

  cout << "Test 17..." << endl;
  Decimal zero1(0, 01);
  Decimal zero2(0, 2);

  if (!zero1.add(zero2).equals(Decimal(0, 21))) return false;
   
  // 0.01
  // 0.01 + 0.20 -> 0.21

  return true;
}

int main() {
  if (test_length() && test_pad() && test_trimRight() && test_Decimal()) {
    cout << "All tests pass" << endl;
  } else {
    cout << "Error!!!" << endl;
  }
  return 0;
}
