#include <iostream>
#include "Decimal.h"

using namespace std;

class Person {
public:
  Person() {
    cout << "create..." << endl;

    const char * defaultName = "N/A";
    name = new char[strlen(defaultName) + 1];
    strcpy(name, defaultName);

    age = 0;
  }

  ~Person() {
    cout << "dest..." << endl;
    delete name;
  }

  void read() {
    char buf[1000];
    cout << "Enter name, age: ";
    cin.getline(buf, 1000, ',');

    delete name;
    name = new char[strlen(buf) + 1];
    strcpy(name, buf);

    cin >> age;
  }

  void print() const {
    cout << name << " (" << age << ")" << endl;
  }

  int getAge() const {
    return age;
  }

private:
  char * name;
  int age;
};
