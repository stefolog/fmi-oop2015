#include <iostream>
using namespace std;

class Team {
public:
  Team(string name) {
    this->name = name;
  }

  bool operator==(Team& other) {
    return this->name == other.name;
  }

  string getName() const {
    return this->name;
  }
private:
  string name;
};

class TeamSport {
public:
  TeamSport(Team team1, Team team2) : team1(team1), team2(team2) {
    this->team1Score = 0;
    this->team2Score = 0;
  }

  void printScore() const {
    cout << team1.getName() << " : " << team2.getName() << endl;
    cout << team1Score << " : " << team2Score << endl;
  }
protected:
  void scorePoints(Team scoringTeam, int points) {
    if (scoringTeam == team1) {
      team1Score += points;
    } else if (scoringTeam == team2) {
      team2Score += points;
    }
  }
private:
  Team team1;
  Team team2;
  int team1Score;
  int team2Score;
};

class TimedSport {
public:
  TimedSport(int overallTime) {
    this->overallTime = overallTime;
  }

  void tick() {
    if (overallTime > 0) {
      overallTime--;
    }
  }

  bool gameEnded() const {
    return overallTime == 0;
  }
private:
  int overallTime;
};

class Football : public TeamSport, public TimedSport {
public:
  Football(Team team1, Team team2) : TeamSport(team1, team2), TimedSport(90) {
  }

  void score(Team team) {
    scorePoints(team, 1);
  }
};

class Basketball : public TeamSport, public TimedSport {
public:
  Basketball(Team team1, Team team2) : TeamSport(team1, team2), TimedSport(60) {
  }

  void score(Team team, int points) {
    scorePoints(team, points);
  }
};

template <typename T>
T random(T a, T b) {
  return rand() % 2 ? a : b;
}

bool hasScore() {
  return (rand() % 100) < 5;
}

void sampleGames() {
  Team cTeam("cherry team");
  Team sTeam("strawberry team");

  Football football(cTeam, sTeam);
  while (true) {
    football.tick();
    if (hasScore()) {
      football.score(random(cTeam, sTeam));
    }

    if (football.gameEnded()) {
      football.printScore();
      break;
    }
  }

  Basketball basketball(cTeam, sTeam);
  basketball.score(cTeam, 2);
  basketball.score(cTeam, 2);
  basketball.score(cTeam, 1);
  basketball.score(sTeam, 3);
  basketball.printScore();
}








template <typename T>
class RefCount {
public:
  RefCount() {
    count++;
  }

  ~RefCount() {
    count--;
  }

  static int getCount() {
    return count;
  }
private:
  static int count;
};

template <typename T>
int RefCount<T>::count = 0;

template <typename T>
class A1 {};

template <typename T>
class A2 {};

template <typename T, typename T2>
class B : A1<T2> {};

template <typename T, typename X>
class C : B<T, X>, A2<T> {};

class Gosho : public RefCount<Gosho> {
public:
  Gosho(T data) {
    this->data = data;
  }
  T data;
};

class Pesho : public RefCount<Pesho> {

};

int main() {
  Gosho<int> g1(20);
  cout << g1.data << endl;

  Gosho<double> g2(20.5), g3(42.13);
  cout << g2.data << endl;
  cout << g3.data << endl;

  Pesho p1, p2;

  cout << RefCount<Gosho<int> >::getCount() << endl;
  cout << RefCount<Gosho<double> >::getCount() << endl;
  cout << RefCount<Pesho>::getCount() << endl;

  return 0;
}
