#include "functions.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;

Enemy e;
Bullets b;

char jet[5][5] = {
	{' ', '\\', '^', '/', ' '},
	{'<', ' ', '*', ' ', '>'},
	{'<', ' ', '*', ' ', '>'},
	{' ', '/', 'v', '\\', ' '},
	{' ', ' ', 'v', ' ', ' '}};

int jetPos = WIN_WIDTH / 2;

int score = 0;
int highScore = 0;
int overallHighScore = 0;
int lives = 3;

void setCursor(bool visible, unsigned long size)
{
	if (size == 0)
	{
		size = 20;
	}
	CONSOLE_CURSOR_INFO c;
	c.bVisible = visible;
	c.dwSize = size;
	SetConsoleCursorInfo(h, &c);
}

void gotoxy(int x, int y)
{
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(h, c);
}

void printSpaceShooterGame()
{
	const char *pattern[] = {
		"       ******    *****     ***      *****   *******   ",
		"       **        **  **   ** **    **       **        ",
		"       ******    *****   **   **   **       *******   ",
		"            **   **      *******   **       **        ",
		"       ******    **      **   **    *****   *******   ",
	};
	const char *pattern1[] = {
		"                      ******   **    **     *****     *****    ********    *******   *******   ",
		"                      **       **    **    **   **   **   **      **       **        **    **  ",
		"                      ******   ********    **   **   **   **      **       *******   *******   ",
		"                           **  **    **    **   **   **   **      **       **        **    **  ",
		"                      ******   **    **     *****     *****       **       *******   **     ** ",
	};
	for (int i = 0; i < 5; i++)
	{
		cout << pattern[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << pattern1[i] << endl;
	}
}

void drawBorder()
{
	for (int i = 0; i < SCREEN_WIDTH+2; i++)
	{
		gotoxy(i, SCREEN_HEIGHT);
		cout << "=";
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		gotoxy(0, i);
		cout << "|";
		gotoxy(SCREEN_WIDTH + 2, i);
		cout << "|";
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		gotoxy(WIN_WIDTH, i);
		cout << "|";
	}
}

void displayInstructions()
{
	system("cls");
	gotoxy(5, 3);
	cout << "INSTRUCTIONS";
	gotoxy(5, 4);
	cout << "------------";
	gotoxy(5, 6);
	cout << "Objective: Destroy enemies to increase score";
	gotoxy(5, 8);
	cout << "Controls:";
	gotoxy(5, 9);
	cout << "  <- Left Arrow Key  : Move left";
	gotoxy(5, 10);
	cout << "  -> Right Arrow Key : Move right";
	gotoxy(5, 11);
	cout << "  [Spacebar]         : Shoot bullets";
	gotoxy(5, 12);
	cout << "  [Escape]           : Exit game";
	gotoxy(5, 14);
	cout << "Game Rules:";
	gotoxy(5, 15);
	cout << "  - You have 3 lives";
	gotoxy(5, 16);
	cout << "  - Each enemy hit = +1 score";
	gotoxy(5, 17);
	cout << "  - Collision with enemy = -1 life";
	gotoxy(5, 20);
	cout << "Press any key to return to menu...";
	getch();
}

void controlDisplay()
{
	gotoxy(WIN_WIDTH + 2, 2);
	cout << "SPACE SHOOTER";
	gotoxy(WIN_WIDTH + 2, 4);
	cout << "CONTROLS";
	gotoxy(WIN_WIDTH + 2, 5);
	cout << "----------";
	gotoxy(WIN_WIDTH + 2, 7);
	cout << "<- Left";
	gotoxy(WIN_WIDTH + 2, 8);
	cout << "-> Right";
	gotoxy(WIN_WIDTH + 2, 9);
	cout << "Space Shoot";
	gotoxy(WIN_WIDTH + 2, 10);
	cout << "Esc Exit";

	gotoxy(25, 10);
	cout << "Press any key";
	getch();
	gotoxy(25, 10);
	cout << "             ";
}

void updateScore(int score)
{
	gotoxy(WIN_WIDTH + 2, 12);
	cout << "Score: " << score << "        ";
}

void updateLives(int lives)
{
	gotoxy(WIN_WIDTH + 2, 13);
	cout << "Lives: " << lives << "        ";
}

void displayHighestScore(int highScore)
{
	gotoxy(WIN_WIDTH + 2, 15);
	cout << "Your Best: " << highScore << "        ";
}

void displayOverallHighScore(int overallHighScore)
{
	gotoxy(WIN_WIDTH + 2, 16);
	cout << "Overall: " << overallHighScore << "        ";
}

void savePassword(const string &name, const string &password)
{
	ofstream outFile("game.txt", ios::app);

	if (outFile.is_open())
	{
		outFile << name << " " << password << endl;
		outFile.close();
	}
	else
	{
		cout << "error in opening the file." << endl;
	}
}

int readPlayers(Player *&players)
{
	ifstream inFile("game.txt");
	if (!inFile.is_open())
	{
		cout << "Error loading players." << endl;
		return 0;
	}

	int i = 0;
	string name, password;
	while (inFile >> name >> password)
	{
		players[i].name = name;
		players[i].password = password;
		i++;
	}
	inFile.close();
	return i;
}

bool verifyPassword(Player *players, int count, string username)
{
    int index = -1;
    for (int i = 0; i < count; i++)
    {
        if (players[i].name == username)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        system("cls");
        gotoxy(0,0); cout<<"===================================================================================================";
        gotoxy(0,1);
        printSpaceShooterGame();
        gotoxy(0,12);cout<<"===================================================================================================";
        gotoxy(5,15);
        cout << "User not found!";
        gotoxy(5,17);
        cout << "Press any key to continue...";
        getch();
        return false;
    }

    string pass;
    int attempts = 3;

    while (attempts > 0)
    {
        system("cls");
        gotoxy(0,0); cout<<"===================================================================================================";
        gotoxy(0,1);
        printSpaceShooterGame();
        gotoxy(0,12);cout<<"===================================================================================================";
        gotoxy(5,15);
        cout << "Enter Password (" << attempts << " attempts left): ";
        cin >> pass;

        if (pass == players[index].password)
        {
            system("cls");
            gotoxy(0,0); cout<<"===================================================================================================";
            gotoxy(0,1);
            printSpaceShooterGame();
            gotoxy(0,12);cout<<"===================================================================================================";
            gotoxy(5,15);
            cout << "Login successful!";
            gotoxy(5,17);
            cout << "Press any key to continue...";
            getch();
            return true;
        }

        attempts--;
        if (attempts > 0)
        {
            gotoxy(5,17);
            cout << "Incorrect password! Try again.";
            Sleep(1500);
        }
    }

    return false;
}

void saveInsToFile()
{
	fstream file;
	file.open("Instructions.txt", ios::out);
	if (file.is_open())
	{
		file << "Instructions" << endl;
		file << "-------------------" << endl;
		file << "-> Left Arrow Key for moving left" << endl;
		file << "-> Right Arrow Key for moving right" << endl;
		file << "-> Press spacebar to shoot enemies" << endl;
	}
	else
	{
		cout << "Error in opening the file" << endl;
	}
}

void gameover(int finalScore)
{
	system("cls");
	gotoxy(5, 5);
	cout << "================================";
	gotoxy(5, 6);
	cout << "|                              |";
	gotoxy(5, 7);
	cout << "|        GAME OVER             |";
	gotoxy(5, 8);
	cout << "|                              |";
	gotoxy(5, 9);
	cout << "================================";
	
	gotoxy(5, 12);
	cout << "Final Score: " << finalScore;
	
	gotoxy(5, 14);
	cout << "Your Best: " << highScore;
	
	gotoxy(5, 16);
	cout << "Overall Best: " << overallHighScore;
	
	if (finalScore == highScore && finalScore > 0)
	{
		gotoxy(5, 18);
		cout << "*** NEW PERSONAL RECORD! ***";
	}
	if (finalScore == overallHighScore && finalScore > 0)
	{
		gotoxy(5, 19);
		cout << "*** NEW OVERALL RECORD! ***";
	}
	
	gotoxy(5, 22);
	cout << "Press any key to return to menu...";
	getch();
}

void genEnemy(int ind)
{
	e.enemyX[ind] = 3 + rand() % (WIN_WIDTH - 10);
}

void drawEnemy(int ind)
{
	if (e.enemyFlag[ind] == true)
	{
		gotoxy(e.enemyX[ind], e.enemyY[ind]);
		cout << " <";
		gotoxy(e.enemyX[ind], e.enemyY[ind] + 1);
		cout << "<O>";
		gotoxy(e.enemyX[ind], e.enemyY[ind] + 2);
		cout << " >";
	}
}

void eraseEnemy(int ind)
{
	if (e.enemyFlag[ind] == true)
	{
		gotoxy(e.enemyX[ind], e.enemyY[ind]);
		cout << "    ";
		gotoxy(e.enemyX[ind], e.enemyY[ind] + 1);
		cout << "    ";
		gotoxy(e.enemyX[ind], e.enemyY[ind] + 2);
		cout << "    ";
	}
}

void resetEnemy(int ind)
{
	eraseEnemy(ind);
	e.enemyY[ind] = 1;
	genEnemy(ind);
}

void drawJet()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gotoxy(j + jetPos, i + SCREEN_HEIGHT - 5);
			cout << jet[i][j];
		}
	}
}

void eraseJet()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			gotoxy(j + jetPos, i + SCREEN_HEIGHT - 5);
			cout << " ";
		}
	}
}

void genBullet()
{
	b.bullets[b.bIndex][0] = SCREEN_HEIGHT - 5;
	b.bullets[b.bIndex][1] = jetPos;
	b.bullets[b.bIndex][2] = SCREEN_HEIGHT - 5;
	b.bullets[b.bIndex][3] = jetPos + 4;
	b.bIndex++;
	if (b.bIndex == 20)
		b.bIndex = 0;
	Beep(800, 50);
}

void drawBullets()
{
    for (int i = 0; i < 20; i++)
    {
        if (b.bullets[i][0] > 1) {
            gotoxy(b.bullets[i][1], b.bullets[i][0]);
            cout << ".";
        }
        if (b.bullets[i][2] > 1) {
            gotoxy(b.bullets[i][3], b.bullets[i][2]);
            cout << ".";
        }
    }
}

void moveBullet()
{
	for (int i = 0; i < 20; i++)
	{
		if (b.bullets[i][0] > 2)
			b.bullets[i][0]--;
		else
			b.bullets[i][0] = 0;

		if (b.bullets[i][2] > 2)
			b.bullets[i][2]--;
		else
			b.bullets[i][2] = 0;
	}
}

void eraseBullets()
{
    for (int i = 0; i < 20; i++)
    {
        if (b.bullets[i][0] >= 1)
        {
            gotoxy(b.bullets[i][1], b.bullets[i][0]);
            cout << " ";
        }
        if (b.bullets[i][2] >= 1)
        {
            gotoxy(b.bullets[i][3], b.bullets[i][2]);
            cout << " ";
        }
    }
}

void eraseBullet(int i)
{
	gotoxy(b.bullets[i][1], b.bullets[i][0]);
	cout << " ";
	gotoxy(b.bullets[i][3], b.bullets[i][2]);
	cout << " ";
}

int collision()
{
	if (e.enemyY[0] + 3 >= SCREEN_HEIGHT - 5)
	{
		if ((e.enemyX[0] + 3) - jetPos >= 0 && (e.enemyX[0] + 3) - jetPos < 8)
		{
			return 1;
		}
	}
	if (e.enemyY[1] + 3 >= SCREEN_HEIGHT - 5)
	{
		if ((e.enemyX[1] + 3) - jetPos >= 0 && (e.enemyX[1] + 3) - jetPos < 8)
		{
			return 1;
		}
	}
	return 0;
}

int bulletHit()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 4; j += 2)
		{
			if (b.bullets[i][j] != 0)
			{
				if (b.bullets[i][j] >= e.enemyY[0] && b.bullets[i][j] <= e.enemyY[0] + 2)
				{
					if (b.bullets[i][j + 1] >= e.enemyX[0] && b.bullets[i][j + 1] <= e.enemyX[0] + 3)
					{
						eraseBullet(i);
						b.bullets[i][j] = 0;
						resetEnemy(0);
						return 1;
					}
				}
				if (b.bullets[i][j] >= e.enemyY[1] && b.bullets[i][j] <= e.enemyY[1] + 2)
				{
					if (b.bullets[i][j + 1] >= e.enemyX[1] && b.bullets[i][j + 1] <= e.enemyX[1] + 3)
					{
						eraseBullet(i);
						resetEnemy(1);
						b.bullets[i][j] = 0;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int readPlayerHighScore(string playerName)
{
	fstream file;
	int playerScore = 0;
	string name, scoreStr;
	file.open("Player_Scores.txt", ios::in);
	if (file.is_open())
	{
		while (file >> name >> scoreStr)
		{
			if (name == playerName)
			{
				playerScore = stoi(scoreStr);
				break;
			}
		}
		file.close();
	}
	return playerScore;
}


int readOverallHighScore()
{
	fstream file;
	int overall = 0;
	string high, high1, high2;
	file.open("Overall_High_Score.txt", ios::in);
	if (file.is_open())
	{
		file >> high;
		file >> high1;
		file >> high2;
		file >> overall;
		file.close();
		overallHighScore = overall;
	}
	else
	{
		file.close();
		file.open("Overall_High_Score.txt", ios::out);
		if (file.is_open())
		{
			file << "Overall High Score: " << overall << endl;
			file.close();
		}
		overallHighScore = 0;
	}
	return overallHighScore;
}

void writeOverallHighScore(int score)
{
	int currentOverall = overallHighScore;
	if (score > currentOverall)
	{
		overallHighScore = score;
		fstream myfile;
		myfile.open("Overall_High_Score.txt", ios::out);
		if (myfile.is_open())
		{
			myfile << "Overall High Score: " << overallHighScore << endl;
			myfile.close();
		}
		displayOverallHighScore(overallHighScore);
	}
}

void writePlayerHighScore(string playerName, int score)
{
	fstream file;
	vector<string> lines;
	string name, scoreStr;
	bool found = false;
	int playerBest = 0;
	
	file.open("Player_Scores.txt", ios::in);
	if (file.is_open())
	{
		while (file >> name >> scoreStr)
		{
			if (name == playerName)
			{
				int oldScore = stoi(scoreStr);
				playerBest = oldScore;
				if (score > oldScore)
				{
					lines.push_back(name + " " + to_string(score));
					playerBest = score;
				}
				else
				{
					lines.push_back(name + " " + scoreStr);
				}
				found = true;
			}
			else
			{
				lines.push_back(name + " " + scoreStr);
			}
		}
		file.close();
	}
	
	if (!found)
	{
		playerBest = score;
		lines.push_back(playerName + " " + to_string(score));
	}
	
	file.open("Player_Scores.txt", ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < lines.size(); i++)
		{
			file << lines[i] << endl;
		}
		file.close();
	}
	
	writeOverallHighScore(score);
}

void play()
{
	jetPos = (WIN_WIDTH / 2) - 1;
	lives = 3;
	score = 0;

	for (int i = 0; i < 20; i++)
	{
		b.bullets[i][0] = b.bullets[i][1] = 0;
	}

	e.enemyFlag[0] = 1;
	e.enemyFlag[1] = 1;
	e.enemyY[0] = e.enemyY[1] = 1;

	genEnemy(0);
	genEnemy(1);
	updateLives(lives);
	updateScore(score);

	while (1)
	{
		if (kbhit())
		{
			char ch = getch();
			if (ch == 75)
			{
				if (jetPos > 2)
					jetPos -= 4;
			}
			if (ch == 77)
			{
				if (jetPos < WIN_WIDTH - 7)
					jetPos += 4;
			}
			if (ch == 32)
			{
				genBullet();
			}
			if (ch == 27)
			{
				return;
			}
		}

		drawJet();
		drawEnemy(0);
		drawEnemy(1);
		drawBullets();

		if (collision() == 1)
		{
			lives--;
			updateLives(lives);
			if (e.enemyY[0] + 3 >= SCREEN_HEIGHT - 5)
				resetEnemy(0);
			if (e.enemyY[1] + 3 >= SCREEN_HEIGHT - 5)
				resetEnemy(1);
			Beep(200, 200);
			Sleep(150);
			if (lives <= 0)
			{
				Beep(150, 300);
				Beep(100, 400);
				gameover(score);
				return;
			}
		}
		if (bulletHit() == 1)
		{
			score++;
			updateScore(score);
			if (score > highScore)
			{
				highScore = score;
				displayHighestScore(highScore);
			}
			Beep(1000, 30);
		}

		Sleep(80);

		eraseJet();
		eraseEnemy(0);
		eraseEnemy(1);
		eraseBullets();
		moveBullet();

		if (e.enemyFlag[0] == 1)
			e.enemyY[0] += 1;

		if (e.enemyFlag[1] == 1)
			e.enemyY[1] += 1;

		if (e.enemyY[0] > SCREEN_HEIGHT - 5)
		{
			resetEnemy(0);
		}
		if (e.enemyY[1] > SCREEN_HEIGHT - 5)
		{
			resetEnemy(1);
		}
	}
}
