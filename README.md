# 🚀 Space Shooter – Console Arcade Game

**Space Shooter** is a Windows console–based arcade game where the player controls a jet to shoot enemies descending from the top of the screen.  
Your objective is simple: **survive, score high, and avoid collisions!**

---

## 🎮 Features

- **Player Login & Registration**
  - Username and password verification  
  - 3 password attempts for existing users

- **High Score System**
  - Individual high scores per player  
  - Overall high score for all players  

- **Jet Controls**
  - **Left Arrow** → Move Left  
  - **Right Arrow** → Move Right  
  - **Spacebar** → Shoot bullets  
  - **Escape** → Exit Game  

- **Dynamic Gameplay**
  - Procedural enemy generation  
  - Enemy movement  
  - Two active bullets at a time  

- **Game Mechanics**
  - Collision detection (Jet ↔ Enemy, Bullet ↔ Enemy)  
  - Score tracking and life counter  
  - Sound effects for shooting & collisions  

- **File Handling**
  - Saves instructions in a text file  
  - Stores player accounts and high scores  

- **Console Graphics**
  - ASCII-based jet, bullets, and enemies  
  - Cursor movement (gotoxy) for smooth rendering  

---

## 🕹️ Controls

| Action          | Key        |
|-----------------|------------|
| Move Left       | Left Arrow |
| Move Right      | Right Arrow |
| Shoot Bullet    | Spacebar   |
| Exit Game       | Escape     |

---

## 📁 File Structure

| File Name                 | Description |
|---------------------------|-------------|
| **Main.cpp**              | Game loop, player login, menu, initialization |
| **functions.cpp / functions.h** | All game logic (drawing jet/enemies, movement, collision, scoring, file handling) |
| **Game.txt**              | Stores usernames & passwords |
| **Player_Scores.txt**     | Stores per-player high scores |
| **Overall_High_Score.txt**| Stores highest score globally |
| **Instructions.txt**      | Stores in-game instructions |

---

## 🛠️ Installation

1. **Clone or download** the repository:
   ```bash
   git clone <repo-url>
