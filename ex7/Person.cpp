#include <iostream>

using namespace std;

class Car {
public:
  Car() {
    cout << "Car const" << endl;
  }

  ~Car() {
    cout << "Car dest" << endl;
  }
};

class Person {
public:
  Person() {
    cout << "def const ... " << endl;

    const char * defaultName = "N/A";
    name = new char[strlen(defaultName) + 1];
    strcpy(name, defaultName);

    age = 0;
  }

  Person(const Person & p) {
    cout << "copy const ... " << endl;
    copy(p);
  }

  Person& operator=(const Person & p) {
    cout << "op= ..." << endl;
    if (this != &p) {
      erase();
      copy(p);
    }

    return *this;
  }

  ~Person() {
    cout << "dest ..." << endl;
    erase();
  }

  // precondition: erase was called or is new instance
  void copy(const Person & p) {
    name = new char[strlen(p.name) + 1];
    strcpy(name, p.name);

    age = p.age;
  }

  void erase() {
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

  void write() const {
    cout << name << " (" << age << ")" << endl;
  }

  int getAge() const {
    return age;
  }

private:
  char * name;
  int age;
  Car car;
};
