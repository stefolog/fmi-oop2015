#include <iostream>
using namespace std;


/*
  Задача 1.
  Клас Decimal, който представя точно десетично число. Операции върху числото:
    * събиране: Decimal add(Decimal other)
    * изваждана Decimal substract(Decimal other)
  И двете операции не трябва да променят състоянието на текущата инстанция,
  а да връщат нова инстанция на класа Decimal.
    * print() - отпечатва числото във формат: XXX.XX
    * equal(Decimal other) - проверява дали две числа са равни

  Числото се създава само чрез конструктор, който приема цяла и десетична част.
*/

bool testDecimal() {
  Decimal x(0, 0), y(1, 0), z(3, 0);
  Decimal a(1, 5), b(2, 25);
  Decimal n(0, -25), m(-1, 25); // !!!

  if (x.equal(y)) return false;
  if (!y.equal(y)) return false;

  if (!x.add(y).equal(Decimal(1, 0))) return false;

  if (!x.add(y).add(y).add(y).equal(Decimal(3, 0))) return false;
  if (!z.substract(y).equal(Decimal(2, 0))) return false;

  if (!a.add(a).equals(Decimal(3, 0))) return false;
  if (!b.add(b).equals(Decimal(4, 5))) return false;
  if (!a.add(b).equals(Decimal(3, 75))) return false;

  if (!n.add(n).equals(Decimal(0, -50))) return false;
  if (!n.substract(n).equals(Decimal(0, 0))) return false;

  if (!n.add(b).equals(Decimal(2, 0))) return false;
  if (!b.add(n).equals(Decimal(2, 0))) return false;
  if (!a.add(n).equals(Decimal(1, 25))) return false;

  if (!a.add(m).equals(Decimal(0, 25))) return false;
  if (!y.add(m).equals(Decimal(0, -25))) return false;
  if (!a.add(n).add(m).equals(Decimal(0, 0))) return false;

  return true;
}

int main() {

  return 0;
}











