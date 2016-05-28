#include <iostream>
using namespace std;

class FigureColor {
public:
  bool isWhite() {
    return white;
  }

  bool isBlack() {
    return !white;
  }

  static FigureColor WHITE() {
    return FigureColor(true);
  }

  static FigureColor BLACK() {
    return FigureColor(false);
  }
private:
  FigureColor(bool white) {
    this->white = white;
  }
  bool white;
};

class Figure {
private:
  string name;
  FigureColor figureColor;
};

struct Position {
  int row;
  int col;
};

class MoveStatus {
public:
  bool isValid() {
    return valid;
  }

  string getMessage() const {
    return mesg;
  }

  static MoveStatus VALID() {
    return MoveStatus(true, string());
  }

  static MoveStatus ERROR(string mesg) {
    return MoveStatus(false, mesg);
  }
private:
  MoveStatus(bool valid, string mesg) {
    this->valid = valid;
    this->mesg = mesg;
  }
  bool valid;
  string mesg;
};

struct Move {
  Position from;
  Position to;
  Figure fig;
};

class Player {
public:
  Player(string name, FigureColor fc) : figureColor(fc) {
    this->name = name;
  }

private:
  string name;
  FigureColor figureColor;
};

class ChessBoard {};

class ChessMoveValidator {
public:
  ChessMoveValidator(ChessBoard& board, FigureColor& playerFigureColor) {
    this->board = board;
    this->playerFigureColor = playerFigureColor;
  }

  MoveStatus validate(Move move) {
    // TODO...
  }

private:
  ChessBoard& board;
  FigureColor& playerFigureColor;
};

class Game {
public:
  Game(Player& player1, Player& player2) {
    this->player1 = player1;
    this->player2 = player2;
    isPlayer1Turn = true;
  }

  ChessBoard applyMove(Move move) {
    return board; // TODO
  }

  void startGame() {
    while(!gameEnded()) {
      Player& currentPlayer = getPlayerOnTurn();

      ChessMoveValidator moveValidator(board, currentPlayer.getFigureColor());
      while (true) {
        Move move = currentPlayer.doMove();
        MoveStatus moveStatus = moveValidator.validate(move);

        if (moveStatus.isValid()) {
          board.applyMove(move);
          switchPlayerTurn();
          break;
        } else {
          cout << "Wrong move: " + moveStatus.getMessage() << endl;
        }
      }
    }
  }
private:
  bool gameEnded() {
    return false; // TODO
  }

  Player& getPlayerOnTurn() const {
    return isPlayer1Turn ? player1 : player2;
  }

  void switchPlayerTurn() {
    isPlayer1Turn = !isPlayer1Turn;
  }

  ChessBoard board;
  Player& player1;
  Player& player2;
  bool isPlayer1Turn;
};

int main() {
  string player1Name;
  string player2Name;

  cout << "Welcome to my chess ... " << endl;

  cout << "Player 1 name (White):";
  cin >> player1Name;

  cout << "Player 2 name (Black):";
  cin >> player2Name;

  ConsolePlayer player1(player1Name, FigureColor::WHITE());
  AIPlayer player2(player2Name, FigureColor::BLACK());

  Game game(player1, player2);
  game.startGame();
}













