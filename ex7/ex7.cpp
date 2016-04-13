#include <iostream>
#include "Person.cpp"

using namespace std;

Person f(Person p) {
  p.write();

  Person x;
  x.read();
  x.write();

  x = p;
  x.write();

  return x;
}

int main() {
  Person X;
  Person Y(f(X));
  return 0;
}
