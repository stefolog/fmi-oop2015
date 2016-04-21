#include <iostream>
#include "Decimal.h"
#include "polynom.cpp"
using namespace std;


// operator++()
// operator--()

// operator[]
//  a[0] -> intPart
//  a[1] -> decPart
//  a[*] -> 0

int main() {
  int x = 5, y = 5;

  cout << "++x: " << (++x) << endl;
  cout << "y++: " << (y++) << endl;
  cout << "x/y: " << x << "/" << y << endl << endl;

  Decimal a(5, 5);
  Decimal b(5, 5);
  (++a).print();
  (b++).print();
  cout << endl;

  a.print();
  b.print();
  cout << endl;

  cout << a[0] << ":" << a[1] << endl;
  cout << a["intPart"] << ":" << a["decPart"] << endl;

  Polynom p1(1), p2(2), p3(3), p5(5), p6(6);
  p1.read(); // 5 3
  p2.read(); // 4 4 1
  p3.read(); // 3 2 1 0
  p5.read(); // 5 0 0 21 13 1
  p6.read(); // 0 -5 0 0 -21 13 -2
  cout << endl << endl;

  cout << "expected: +5x^1 +3x^0 \nactual  :";                  p1.print(); cout << endl;
  cout << "expected: +4x^2 +4x^1 +1x^0 \nactual  :";            p2.print(); cout << endl;
  cout << "expected: +3x^3 +2x^2 +1x^1 \nactual  :";            p3.print(); cout << endl;
  cout << "expected: +5x^5 +21x^2 +13x^1 +1x^0 \nactual  :";    p5.print(); cout << endl;
  cout << "expected: -5x^5 -21x^2 +13x^1 -2x^0 \nactual  :";    p6.print(); cout << endl;
  cout << endl << endl;

  cout << "expected: +4x^2 +9x^1 +4x^0 \nactual  :";            (p1 + p2).print();   cout << endl;
  cout << "expected: -3x^3 +2x^2 +3x^1 +1x^0 \nactual  :";      (p2 - p3).print();   cout << endl;
  cout << "expected: +25x^4 +42x^1 +13x^0 \nactual  :";         (p5--).print();      cout << endl;
  cout << "expected: +26x^1 -1x^0 \nactual  :";                 (p5 + p6).print();   cout << endl;
  cout << endl << endl;

  cout << "true?:  " << (p1 < p2) << endl;
  cout << "true?:  " << (p1 <= p2) << endl;
  cout << "false?: " << (p1 == p2) << endl;
  cout << "true?:  " << (p1 == p1) << endl;
  cout << "true?:  " << (p1 < p5) << endl;
  cout << endl << endl;

  return 0;
}







