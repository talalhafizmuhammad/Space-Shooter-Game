#include "functions.h"

int main() {

Start:

    setCursor(0,0);
    srand((unsigned)time(NULL));

    const int MAX_PLAYERS = 50;
    Player* players = new Player[MAX_PLAYERS];
    int playerCount = readPlayers(players);

    string playername, password;

    system("cls");
    gotoxy(0,0); cout<<"===================================================================================================";
    gotoxy(0,1);
    printSpaceShooterGame();
    gotoxy(0,12);cout<<"===================================================================================================";
    gotoxy(5,15);
    cout << "Enter Player Name: ";
    getline(cin, playername);

    bool player_exist = false;

    for (int i = 0; i < playerCount; i++) {
        if (players[i].name == playername) {
            player_exist = true;
            system("cls");
            gotoxy(0,0); cout<<"===================================================================================================";
            gotoxy(0,1);
            printSpaceShooterGame();
            gotoxy(0,12);cout<<"===================================================================================================";
            gotoxy(5,15);
            cout << "Player already exists!";
            gotoxy(5,17);
            cout << "Press any key to continue...";
            getch();
        }
    }

    if (!player_exist) {
        system("cls");
        gotoxy(0,0); cout<<"===================================================================================================";
        gotoxy(0,1);
        printSpaceShooterGame();
        gotoxy(0,12);cout<<"===================================================================================================";
        gotoxy(5,15);
        cout << "Set Password: ";
        getline(cin, password);

        players[playerCount].name = playername;
        players[playerCount].password = password;

        savePassword(playername, password);
        playerCount++;

        system("cls");
    }

    if (!verifyPassword(players, playerCount, playername))
    {
        system("cls");
        gotoxy(0,0); cout<<"===================================================================================================";
        gotoxy(0,1);
        printSpaceShooterGame();
        gotoxy(0,12);cout<<"===================================================================================================";
        gotoxy(5,15);
        cout << "Too many failed password attempts.";
        gotoxy(5,17);
        cout << "Do you want to re-enter player name? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();

        delete[] players;

        if (choice == 'y' || choice == 'Y') {
            goto Start;
        }
        return 0;
    }

    while (1) {
        system("cls");
        gotoxy(0,0); cout<<"===================================================================================================";
        gotoxy(0,1);
        printSpaceShooterGame();
        gotoxy(0,12);cout<<"===================================================================================================";
        
        gotoxy(5, 15);
        cout << "1. Start Game";
        gotoxy(5, 16);
        cout << "2. Restart";
        gotoxy(5, 17);
        cout << "3. Instructions";
        gotoxy(5, 18);
        cout << "4. Quit";
        gotoxy(5, 20);
        cout << "Select Option: ";

        char op = getche();

        if (op == '1') {
            system("cls");
            drawBorder();
            score = 0;
            updateScore(score);

            highScore = readPlayerHighScore(playername);
            overallHighScore = readOverallHighScore();
            displayHighestScore(highScore);
            displayOverallHighScore(overallHighScore);
            controlDisplay();
            saveInsToFile();
            play();
            
            writePlayerHighScore(playername, score);
        }
        else if (op == '2') {
            goto Start;
        }
        else if (op == '3') {
            displayInstructions();
        }
        else if (op == '4') {
            break;
        }
    }

    delete[] players;
    return 0;
}
