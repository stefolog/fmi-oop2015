#include <iostream>
using namespace std;

template <typename T>
T myMax(T x, T y) {
  return x < y ? y : x;
}

template <typename T>
T myMax(T arr[], int n) {
  T maxValue = arr[0];
  for (int i = 1; i < n; i++) {
    maxValue = myMax(maxValue, arr[i]);
  }
  return maxValue;
}

template <typename T, typename G>
class Utils {
public:
  T min(T x, T y);

  T min(T arr[], int n) {
    T minValue = arr[0];
    for (int i = 1; i < n; i++) {
      minValue = min(minValue, arr[i]);
    }
    return minValue;
  }

  void print(T x, G y) {
    cout << x << ":" << y << endl;
  }
};

template <typename T, typename G>
T Utils<T, G>::min(T x, T y) {
  return x < y ? x : y;
}

template <typename T, int MAX_SIZE>
class FixedArray {
public:
  void atIdx(int idx, T value) {
    if (0 < idx && idx < MAX_SIZE) {
      arr[idx] = value;
    }
  }
  void print() {
    for (int i = 0; i < MAX_SIZE; ++i) {
      cout << arr[i] << endl;
    }
  }
private:
  T arr[MAX_SIZE];
};

template <typename T, int ROWS, int COLS>
class Matrix {
public:
  Matrix<T, ROWS, COLS> sum(Matrix<T, ROWS, COLS>& other) {

  }
private:
  T mat[ROWS][COLS];
};

template <typename T, int N, int M, int K>
Matrix<T, N, K> mult(Matrix<T, N, M> m1, Matrix<T, M, K> m2) {
  Matrix<T, N, K> res;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      res.setAt(i, j, calculate(i, j, m1, m2));
    }
  }
  return res;
}

int main() {
  char arr[] = {'a', 'b', 'z'};
  cout << myMax(5, 6) << endl;
  cout << myMax(arr, 3) << endl;

  Utils<int, char> utils;
  utils.min(5, 6);
  utils.print(5, 'a');

  FixedArray<char, 10> fa1;
  FixedArray<int, 50> fa2;
  FixedArray<double, 1000> fa3;

  return 0;
}
