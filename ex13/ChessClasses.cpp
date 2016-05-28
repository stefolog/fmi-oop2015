class FigureColor {
public:
  bool isWhite() const {
    return this->white;
  }

  bool isBlack() const {
    return !isWhite();
  }

  static FigureColor WHITE() {
    return FigureColor(true);
  }

  static FigureColor BLACK() {
    return FigureColor(false);
  }
private:
  bool white;

  FigureColor(bool white) {
    this->white = white;
  }
};

class Figure {

};

struct Position {
  int row;
  int col;
};

struct Move {
  Position from;
  Position to;
  Figure fig;
};

class Player {
public:
  Move doMove() {
    // console
    return Move();
  }
protected:
  string name;
  FigureColor color;
};

class ConsolePlayer: Player {
public:
  Move doMove() {
    Position from;
    Position to;
    char figureChar;

    cout << "Enter move\n"
    cout << "From: "
    cin >> from.row >> from.col;
    cout << "To: "
    cin >> to.row >> to.col;
    cout << "Figure: "
    cin >> figureChar;

    return Move(from, to, Figure.fromChar(figureChar));
  }
};






class ChessBoard {

};
