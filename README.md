🚀 Space Shooter – Console Arcade Game

A fast-paced console-based arcade shooter where the player controls a jet to destroy incoming enemies while avoiding collisions.
The game includes player authentication, score tracking, ASCII graphics, and sound effects.

🎮 Features
🔐 Player System

User login & registration

Password verification with 3 attempts

Individual player profiles

Saves personal high scores

🏆 Score System

Track individual and overall high scores

Automatically updates and saves high scores to files

✈️ Gameplay

Smooth arrow-key movement

Spacebar shooting with dual-bullet mechanics

Dynamic enemy spawn and movement

Collision detection (bullets vs enemies / jet vs enemies)

Lives counter and score display

ASCII-based console graphics

Sound effects for shooting and collisions

⌨️ Controls
Action	Key
Move Left	⬅️ Left Arrow
Move Right	➡️ Right Arrow
Shoot Bullet	Spacebar
Exit Game	Escape (Esc)
📂 Project Files Structure
File	Description
main.cpp	Main game loop, player login, menu handling, initialization
functions.h / functions.cpp	Game logic (drawing jet/enemies, movement, collisions, file I/O, scoring)
Game.txt	Registered users & passwords
Player_Scores.txt	Player-specific high scores
Overall_High_Score.txt	Stores overall highest score
Instructions.txt	Game instructions saved from the menu
🛠️ Installation

Clone or download the repository:

git clone https://github.com/your-username/your-repo.git


Open project in a C++ IDE that supports Windows Console Applications
(Visual Studio, CodeBlocks, Dev-C++, etc.)

Compile and run the game.

Ensure the following files are writable:

Game.txt

Player_Scores.txt

Overall_High_Score.txt

🎯 How to Play

Launch the game executable.

Enter your username.

New user → register with a password

Existing user → login (3 password attempts allowed)

Choose from the main menu:

Start Game – begin playing

Restart – logout and return to login screen

Instructions – view control guide

Quit – exit the game

Control your jet, shoot enemies, avoid collisions.

Try to beat your personal and overall high scores.

🧠 Game Logic Overview
🔑 Player Authentication

New users register with a password

Existing users are authenticated with limited attempts

Data stored securely in text files

👾 Enemy Mechanics

Enemies spawn randomly at the top of the screen

Move downward each frame

Reset on collision or on reaching the bottom

🔫 Bullet System

Two bullets can exist simultaneously

Move upward each frame

Reset after impact or leaving screen

💥 Collision Detection

Bullet ↔ Enemy collision

Jet ↔ Enemy collision (reduces lives)

📊 Scoring

Scores updated in real-time

File handling for:

Player high scores

Overall highest score

🖥️ Console Graphics

ASCII character sprites (jet, enemies, bullets)

Cursor control using Windows console API

Simple sound effects for shooting & crashes
