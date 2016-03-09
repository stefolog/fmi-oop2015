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

bool testLength() {
  if (0 != length(0)) return false;
  if (1 != length(6)) return false;
  if (2 != length(63)) return false;
  if (6 != length(871242)) return false;

  cout << "Test length ... OK" << endl;
  return true;
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

bool testPad() {
  if (0 != pad(0, 10)) return false;
  if (100 != pad(1, 3)) return false;
  if (520 != pad(52, 3)) return false;
  if (420 != pad(420, 3)) return false;
  if (13 != pad(13, 1)) return false;

  cout << "Test pad ... OK" << endl;
  return true;
}

int trimRight(int n) {
  while (n > 0 && n % 10 == 0) {
    n /= 10;
  }
  return n;
}

bool testTrimRight() {
  if (0 != trimRight(0)) return false;
  if (1 != trimRight(10)) return false;
  if (1 != trimRight(100)) return false;
  if (2 != trimRight(200000)) return false;
  if (5002 != trimRight(500200)) return false;
  if (42 != trimRight(42)) return false;

  cout << "Test trimRight ... OK" << endl;
  return true;
}

/*
  Задача 1.
  Клас Decimal, който представя точно десетично число. Операции върху числото:
    * събиране: Decimal add(Decimal other)
    * изваждана Decimal substract(Decimal other)
  И двете операции не трябва да променят състоянието на текущата инстанция,
  а да връщат нова инстанция на класа Decimal.
    * print() - отпечатва числото във формат: XXX.XX
    * equals(Decimal other) - проверява дали две числа са равни

  Числото се създава само чрез конструктор, който приема цяла и десетична част.
*/
class Decimal {
public:
  Decimal(int w, int d) { // default constructor
    this->w = w;
    this->d = d;
  }

  Decimal add(Decimal other) const {
    int maxLength = max(length(d), length(other.d));
    int d1 = pad(d, maxLength);
    int d2 = pad(other.d, maxLength);

    int resD = d1 + d2;
    int deltaW = 0;
    if (maxLength < length(resD)) {
      deltaW = resD / (int)pow(10, maxLength);
      resD = resD % (int)pow(10, maxLength);
    }

    resD = trimRight(resD);

    Decimal result(w + other.w + deltaW, resD);
    return result;
  }

  Decimal substract(Decimal other) const {
    Decimal result(w - other.w, d - other.d);
    return result;
  }

  bool equals(Decimal other) const {
    return w == other.w && d == other.d;
  }

  void print() const {
    cout << w << "." << d << endl;
  }

private:
  int w;
  int d;
};

bool testDecimal() {
  Decimal x(0, 0), y(1, 0), z(3, 0);
  Decimal a(1, 5), b(2, 25);
  Decimal n(0, -25), m(-1, 25);

  cout << "Test print ... " << endl;
  x.print();
  y.print();
  z.print();
  a.print();
  b.print();
  n.print();
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
  // 0.01
  // 0.01 + 0.20 -> 0.21
  return false;

  // return true;
}

int main() {
  if (testLength() && testPad() && testTrimRight() && testDecimal()) {
    cout << "All tests pass" << endl;
  } else {
    cout << "Error!!!" << endl;
  }
  return 0;
}
