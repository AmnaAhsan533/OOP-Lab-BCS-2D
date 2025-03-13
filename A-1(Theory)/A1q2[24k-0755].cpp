#include <iostream>
#include <string>
using namespace std;

class Ball {
    int x, y;
public:
    Ball(int startX = 0, int startY = 0) : x(startX), y(startY) {}
    int getX() { return x; }
    int getY() { return y; }
    void move(int dx, int dy) { x += dx; y += dy; }
};
class Goal {
public:
    static const int goalX = 3;
    static const int goalY = 3;
    bool isGoalReached(int ballX, int ballY) { return (ballX == goalX && ballY == goalY); }
};
class Robot {
    string name;
    int hits;
public:
    Robot(string n) : name(n), hits(0) {}
    void hitBall(Ball &ball, const string &direction) {
        if (direction == "up") ball.move(0, 1);
        else if (direction == "down") ball.move(0, -1);
        else if (direction == "left") ball.move(-1, 0);
        else if (direction == "right") ball.move(1, 0);
        else cout << "Invalid move! Use up, down, left, or right.\n";
        hits++;
    }
    int getHits() { return hits; }
    string getName() { return name; }
};
class Team {
    string teamName;
    Robot *player;
public:
    Team(string name, string robotName): teamName(name){ player = new Robot(robotName); }
    ~Team() { delete player; }
    Robot* getPlayer() { return player; }
    string getTeamName() { return teamName; }
};
class Game {
    Team *teamOne, *teamTwo;
    Ball ball;
    Goal goal;
public:
    Game(string team1, string robot1, string team2, string robot2) {
        teamOne = new Team(team1, robot1);
        teamTwo = new Team(team2, robot2);
    }
    ~Game() {
        delete teamOne;
        delete teamTwo;
    }
    void play(Team *team) {
        Robot *robot = team->getPlayer();
        cout<<"\n"<<team->getTeamName()<<"'s Robot "<<robot->getName()<<" starts moving the ball.\n";        
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            cout << "Ball Position: (" << ball.getX() << ", " << ball.getY() << ")\n";
            cout << "Enter move (up/down/left/right): ";
            string move;
            cin >> move;
            robot->hitBall(ball, move);
        }
        cout << "Goal reached in " << robot->getHits() << " hits!\n";
    }
    void startGame() {
        cout << "Game Start!\n";
        play(teamOne);
        ball = Ball(); 
        play(teamTwo);
        declareWinner();
    }
    void declareWinner() {
        int hits1 = teamOne->getPlayer()->getHits();
        int hits2 = teamTwo->getPlayer()->getHits();
        cout << "\nFinal Results:\n";
        cout << teamOne->getTeamName() << " Hits: " << hits1 << "\n";
        cout << teamTwo->getTeamName() << " Hits: " << hits2 << "\n";
        if (hits1 < hits2)
            cout << teamOne->getTeamName() << " wins!\n";
        else if (hits2 < hits1)
            cout << teamTwo->getTeamName() << " wins!\n";
        else
            cout << "It's a tie!\n";
    }
};
int main() {
    cout << "\nName: Amna Ahsan\nID: 24K-0755\n\n";
    Game footballGame("Team A", "RoboA", "Team B", "RoboB");
    footballGame.startGame();
    return 0;
}
