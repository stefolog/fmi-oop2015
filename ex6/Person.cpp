#include <iostream>
#include "Decimal.h"

using namespace std;

class Person {
public:

  void read() {
    char buf[20];
    cout << "Enter name, age: ";
    cin.getline(name, 31, ',');
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
