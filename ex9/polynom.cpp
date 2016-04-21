#include<iostream>
#include<math.h>
using namespace std;

class Polynom {
public:
  Polynom(int n) {
    power = n;
    coefs = new double[power + 1];
  }

  Polynom(const Polynom & other) {
    copy(other);
  }

  Polynom& operator=(const Polynom & other) {
    if (this != &other) {
      erase();
      copy(other);
    }
    return *this;
  }

  ~Polynom() {
    erase();
  }

  double operator[](int idx) const {
    if (idx < 0 || idx > power) {
      return 0;
    }
    return coefs[idx];
  }

  bool operator<(const Polynom & other) const {
    if (other.power < power) {
      return false;
    }
    if (other.power > power) {
      return true;
    }

    for (int i = power; i >= 0; i--) {
      if ((*this)[i] >= other[i]) {
        return false;
      }
    }
    return true;
  }

  bool operator==(const Polynom & other) const {
    int maxPower = max(power, other.power);
    for(int i = 0; i <= maxPower; i++) {
      if ((*this)[i] != other[i]) {
        return false;
      }
    }

    return true;
  }

  bool operator>(const Polynom& other) const {
    return other < *this;
  }

  bool operator>=(const Polynom& other) const {
    return *this > other || *this == other;
  }

  bool operator<=(const Polynom& other) const {
    return *this < other || *this == other;
  }

  Polynom operator+(const Polynom& other) const {
    Polynom res(max(power, other.power));
    for (int i = 0; i <= res.power; i++) {
      res.coefs[i] = (*this)[i] + other[i];
    }
    return res.normalise();
  }

  Polynom operator-(const Polynom& other) const {
    Polynom res(max(power, other.power));
    for (int i = 0; i <= res.power; i++) {
      res.coefs[i] = (*this)[i] - other[i];
    }
    return res.normalise();
  }

  Polynom operator--(int idx) const {
    Polynom res(power - 1);
    for (int i = 1; i <= power; ++i) {
      res.coefs[i - 1] = i*(*this)[i];
    }
    return res.normalise();
  }

  void read() {
    for (int i = power; i >= 0; i--) {
      cout << "x^" << i << ": ";
      cin >> coefs[i];
    }
    normalise();
  }

  void print() const {
    for (int i = power; i >= 0; i--) {
      if (coefs[i] == 0) {
        continue;
      }
      cout << " ";
      if (coefs[i] > 0) {
        cout << "+";
      }
      cout << coefs[i] << "x^" << i;
    }
    cout << endl;
  }

private:
  double * coefs;
  int power;

  void copy(const Polynom& other) {
    power = other.power;
    coefs = new double[power + 1];
    for (int i = 0; i <= power; ++i) {
      coefs[i] = other.coefs[i];
    }
  }

  void erase() {
    delete coefs;
  }

  int maxPower() const {
    for (int i = power; i >= 0; i--) {
      if (coefs[i] != 0) {
        return i;
      }
    }
    return 0;
  }

  Polynom& normalise() {
    int maxPower = this->maxPower();

    if (maxPower != this->power) {
      double* newCoefs = new double[maxPower + 1];
      for (int i = 0; i <= maxPower; i++) {
        newCoefs[i] = this->coefs[i];
      }
      delete this->coefs;
      this->coefs = newCoefs;
      this->power = maxPower;
    }
    return *this;
  }
};
