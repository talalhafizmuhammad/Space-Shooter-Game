Space Shooter is a console-based arcade game.
 The player controls a jet to shoot downward enemies while avoiding collisions.
 

Features:

a.Player login and registration with password verification.

b.Track individual and overall high scores.

c.Arrow key movement for the jet:

d.Left Arrow: Move left

a..Right Arrow: Move right

b.Spacebar: Shoot bullets

c.Escape: Exit the game

d.Dynamic enemy generation and movement.

e.Collision detection between jet and enemies.

f.Score display and life counter.

g.Save game instructions in a separate text file.

h.Sound effects for shooting and collisions.

Controls:

a.Move Left - Left Arrow
b.Move Right - Right Arrow
c.Shoot Bullet - Spacebar
d.Exit Game	- Escape

Files:

a.Main.cpp: Contains the game loop, player login, menu, and initialization.

b.Functions.h OR functions.cpp: Game logic functions (drawing jet,drawing enemies, movement, collision detection, scoring, file handling for the user names and high scores).

c.Game.txt: Stores registered players and their passwords.

d.Player_Scores.txt: Stores player-specific high scores.

e.Overall_High_Score.txt: Stores the overall high score.

f.Instructions.txt: Saved instructions for the game.

Installation:

a.Clone or download the repository.

b.Open the project in a C++ IDE (e.g., Visual Studio) that supports Windows console applications.

c.Compile and run the project.

d.Ensure game.txt, Player_Scores.txt, and Overall_High_Score.txt are writable by the program.

How to Play:

a.Launch the game executable.

b.Enter your player name. If it’s a new player, set a password.

c.Log in with your password.

d.Choose from the menu:

a.Start Game: Begin playing.

b.Restart: Return to player login.

c.Instructions: View game instructions.

d.Quit: Exit the game.

e.Control your jet to shoot enemies and avoid collisions.

f.Track your score and try to beat individual and overall high scores.

Game Logic Highlights:

a.Player Authentication: Handles new user registration and existing user login with 3 password attempts.

b.Enemy Generation: Random enemy positions at the top of the screen.

c.Bullet Mechanics: Two bullets can be fired simultaneously; bullets move upwards and reset upon hitting enemies.

d.Collision Detection: Detects collisions between bullets and enemies, as well as jet and enemies.

e.Score Handling: Individual and overall high scores are saved and displayed dynamically.

f.Console Graphics: Uses ASCII graphics and console cursor manipulation (gotoxy) for game visuals.
