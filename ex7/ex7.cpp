#include <iostream>
using namespace std;
#include "Person.cpp"

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
  Person Y;
  // Person Z;
  // Z = f(Y);

  // Y.write();
  // Z.write();

  return 0;
}
