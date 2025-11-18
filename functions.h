#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string>
#include <fstream>


using namespace std;

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

extern int score;
extern char jet[5][5];
extern int jetPos;
extern int highScore;
extern int overallHighScore;
extern int lives;

struct Player {
    string name;
    string password;
};

struct Enemy{
    int enemyX[2];
    int enemyY[2];
    int enemyFlag[2];
};

struct Bullets{
    int bullets[20][4];
    int bIndex =0;
};

bool verifyPassword(Player *players, int count, string username);

void gotoxy(int x,int y);
void savePassword(const string& name, const string& password);
void displayInstructions();
int readPlayers(Player*& players);
void printSpaceShooterGame();
void setCursor(bool visible, DWORD size);
void drawBorder();
void controlDisplay();
void updateScore(int score);
void updateLives(int lives);

void saveInsToFile();
void genEnemy(int ind);
void drawEnemy(int ind);
void resetEnemy(int ind);
void eraseEnemy(int ind);

void play();

void genBullet();
void drawJet();
void drawBullets();
void eraseJet();
void eraseBullets();
void moveBullet();

int collision();
void gameover(int finalScore);
int bulletHit();
void eraseBullet(int i);

int readPlayerHighScore(string playerName);
int readOverallHighScore();
void writePlayerHighScore(string playerName, int score);
void writeOverallHighScore(int score);
void displayHighestScore(int highScore);
void displayOverallHighScore(int overallHighScore);
