#include <iostream>
#include "Decimal.h"
#include "Person.cpp"

using namespace std;

void problem1() {
  const int n = 50000;
  system( "read -n 1 -s -p \"Press any key to continue...\"" );

  Decimal** nums = new Decimal*[n];
  system( "read -n 1 -s -p \"Press any key to continue...\"" );

  for (int i = 0; i < n; i++) {
    // int intPart;
    // int decPart;
    // cout << "Enter dec number: ";
    // cin >> intPart >> decPart;

    nums[i] = new Decimal(i, i);
  }

  Decimal sum(0, 0);
  for (int i = 0; i < n; i++) {
    sum = sum.add(*nums[i]);
  }

  cout << "Sum is: ";
  sum.print();

  system( "read -n 1 -s -p \"Press any key to continue...\"" );

  for (int i = 0; i < n; i++) {
    delete nums[i];
  }
  delete[] nums;

  system( "read -n 1 -s -p \"Press any key to continue...\"" );
}

int main() {
  cout << "1" << endl;
  Person p1, p2;
  cout << "2" << endl;
  p1.read();
  cout << "3" << endl;
  p1.read();
  cout << "4" << endl;
  p1.print();
  cout << "5" << endl;
  p2.print();
  cout << "6" << endl;
  return 0;
}







