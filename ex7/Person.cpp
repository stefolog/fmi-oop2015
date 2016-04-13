#include <iostream>

using namespace std;

char * copydyn(const char * other) {
  char * res = new char[strlen(other) + 1];
  strcpy(res, other);
  return res;
}

class Car {
public:
  Car() {
    brand = copydyn("N/A");
    model = copydyn("N/A");

    yearOfProduction = 2016;
  }

  Car(const Car & other) {
    copy(other);
  }

  Car& operator=(const Car & other) {
    if (this != &other) {
      erase();
      copy(other);
    }
    return *this;
  }

  ~Car() {
    erase();
  }

private:
  void copy(const Car & other) {
    brand = copydyn(other.brand);
    model = copydyn(other.model);

    yearOfProduction = other.yearOfProduction;
  }

  void erase () {
    delete brand;
    delete model;
  }

  char* brand;
  char* model;
  int yearOfProduction;
};


class Address {
public:
  Address() {
    city = copydyn("N/A");
    neighbourhood = copydyn("N/A");
    street = copydyn("N/A");
  }

  Address(const Address & other) {
    copy(other);
  }

  Address& operator=(const Address & other) {
    if (this != &other) {
      erase();
      copy(other);
    }
    return *this;
  }

  ~Address() {
    erase();
  }

private:
  void copy(const Address & other) {
    city = copydyn(other.city);
    neighbourhood = copydyn(other.neighbourhood);
    street = copydyn(other.street);

    n = other.n;
  }

  void erase () {
    delete city;
    delete neighbourhood;
    delete street;
  }

  char* city;
  char* neighbourhood;
  char* street;
  int n;
};

class Person {
public:
  Person() {
    cout << "def const ... " << endl;
    name = copydyn("N/A");

    cars = NULL;
    numberOfCars = 0;

    age = 0;
  }

  Person(const Person & p) {
    cout << "copy const... " << endl;
    copy(p);
  }

  Person& operator=(const Person & p) {
    cout << "op = ... " << endl;

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
  void copy(const Person & p) {
    name = copydyn(p.name);
    age = p.age;

    numberOfCars = p.numberOfCars;
    cars = new Car[numberOfCars];

    for (int i = 0; i < numberOfCars; i++) {
      cars[i] = p.cars[i];
    }

    address = p.address;
  }

  void erase() {
    delete name;
    delete[] cars;
  }

  char * name;
  int age;
  Car * cars;
  int numberOfCars;
  Address address;
};
