Упражнение 11
===

+ public
~ protected
- private

Задачи
---
**Задача 1** Figure
Да се реализира йерархията от класове
      Figure
  /     |     \
Pawn  Queen  Knights

Figure - [abstract class]
  + move() - [virtual & abstract]
  ~ setName()
  + getName()
  + setColor(FigureColor color)
  + FigureColor getColor()
  - name: char* | string
  - color: FigureColor

Pawn - extends Figure
  При инициализация задава полето name на Figure на "Pawn"
  При извикване на move() извежда "Pawn moves"

Queen - extends Figure
  При инициализация задава полето name на Figure на "Queen"
  При извикване на move() извежда "Queen moves"

Knights - extends Figure
  При инициализация задава полето name на Figure на "Knights"
  При извикване на move() извежда "Knights moves"

FigureColor - изберете представяне и инициализация за класа
  + bool isWhite()
  + bool isBlack()

Reference
---
 * [Head First: OOD&A](http://www.headfirstlabs.com/books/hfooad/)
 * [Top-Down/Bottom-Up](https://en.wikipedia.org/wiki/Top-down_and_bottom-up_design)

