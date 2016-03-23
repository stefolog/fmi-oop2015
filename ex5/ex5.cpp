#include <iostream>
#include "Decimal.h"

using namespace std;

class Person {
public:

  void read() {
    char buf[20];
    cout << "Enter name, age: ";
    cin.getline(name, 31, ',');
    // TODO: add buf to read till ',' for longer text
    cin >> age;
  }

  void print() const {
    cout << name << " (" << age << ")" << endl;
  }

  int getAge() const {
    return age;
  }

private:
  char name[31];
  int age;
};

int main() {
  // Decimal(5, 3).print();

  Person people[10];

  for (int i = 0; i < 2; i++) {
    people[i].read();
  }

  for (int i = 0; i < 2; i++) {
    people[i].print();
  }

  return 0;
}
