#include <iostream>
using namespace std;


// Singleton
class ChessBoard {

public:
  static ChessBoard& getInstance() {
    if (instance == NULL) {
      instance = new ChessBoard();
    }

    return *instance;
  }

private:
  static ChessBoard* instance;

private:
  ChessBoard() {
    cout << "New instance created" << endl;
  }


private:
  int board[8][8];
};

ChessBoard* ChessBoard::instance = NULL;


int main() {
  // ChessBoard board; // Error because of private constructor
  ChessBoard& board = ChessBoard::getInstance(); // create new instace
  ChessBoard& board1 = ChessBoard::getInstance();
  ChessBoard& board2 = ChessBoard::getInstance();
  ChessBoard& board3 = ChessBoard::getInstance();

  if (&board == &board1 && &board1 == &board2 && &board2 == &board3) {
    cout << "All references point to one instance" << endl;
  }

  return 0;
}


