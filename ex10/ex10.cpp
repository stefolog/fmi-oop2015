#include <iostream>
using namespace std;

template <typename T>
class SingletonFactory {
public:
  // Canonical presentation -------------------------------
  SingletonFactory() {
    this->instance = NULL;
  }

  SingletonFactory(const SingletonFactory& other) {
    instance = other.instance;
  }

  SingletonFactory& operator=(const SingletonFactory& other) {
    if (this != &other) {
      if (instance != NULL) {
        delete instance;
      }
      instance = other.instance;
    }

    return *this;
  }

  ~SingletonFactory() {
    if (instance != NULL)
      delete instance;
  }
  // Canonical presentation END ---------------------------

  T& getInstance() {
    if (instance == NULL) {
      instance = new T();
    }
    return *instance;
  }
private:
  T* instance;
};

// Singleton
class ChessBoard {

private:
  ChessBoard() {
    cout << "ChessBoard::New instance created" << endl;
  }

private:
  int board[8][8];

friend class SingletonFactory<ChessBoard>;
};


// Multiton
// max 22 instances
// ActivePlayer& getPlayer(int idx) [0 - 21]
class ActivePlayer {
public:
  static ActivePlayer& getPlayer(int idx) {
    if (idx < 0 || idx > 21) {
      throw "Invalid player number";
    }

    if (instances[idx] == NULL) {
      instances[idx] = new ActivePlayer();
    }

    return *instances[idx];
  }

  static void leaseInstances() {
    for (int i = 0; i < 22; ++i) {
      if (instances[i] != NULL) {
        delete instances[i];
        instances[i] = NULL;
      }
    }
  }

private:
  static ActivePlayer* instances[22];

private:
  ActivePlayer() {
    cout << "ActivePlayer::New instance created" << endl;
  }
};

// init with NULLs
ActivePlayer* ActivePlayer::instances[22] = {0};

int main() {
  // ChessBoard board; // Error because of private constructor

  SingletonFactory<ChessBoard> factory;
  ChessBoard& board = factory.getInstance(); // create new instace
  ChessBoard& board1 = factory.getInstance();
  ChessBoard& board2 = factory.getInstance();
  ChessBoard& board3 = factory.getInstance();

  if (&board == &board1 && &board1 == &board2 && &board2 == &board3) {
    cout << "All references point to one instance" << endl;
  }

  cout << endl << endl << endl << endl;

  for (int i = 0 ; i < 22; i++) {
    // only this will create new instance
    ActivePlayer& player = ActivePlayer::getPlayer(i);
    ActivePlayer& player1 = ActivePlayer::getPlayer(i);
    ActivePlayer& player2 = ActivePlayer::getPlayer(i);

    if (&player == &player1 && &player1 == &player2) {
      cout << "All refereces for player (" << i << ") point to one instance" << endl;
    }
  }

  // free memory
  ActivePlayer::leaseInstances();

  return 0;
}


