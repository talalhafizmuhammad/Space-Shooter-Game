# 🃏 Solitaire Game (C++ OOP)

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/3/35/Klondike-Patience-Game.svg" width="400" alt="Solitaire Game Preview">
</p>

<p align="center">
  <b>A fully object-oriented Solitaire game built in C++</b><br>
  Experience the classic card game implemented with modern C++ principles — classes, encapsulation, inheritance, and polymorphism.
</p>

---

## 🎯 Project Overview

This project is a **console-based Solitaire game** built using **Object-Oriented Programming (OOP)** concepts in **C++**.  
It demonstrates strong modular design and reusability while providing an interactive, logic-rich gaming experience.

---

## 🧩 Features

✅ **Object-Oriented Architecture** – Clean and modular design with classes for `Card`, `Deck`, `Pile`, `Game`, etc.  
✅ **Encapsulation & Abstraction** – Core game logic neatly hidden behind class interfaces.  
✅ **Dynamic Memory Handling** – Proper use of constructors, destructors, and pointers.  
✅ **Game Logic** – Realistic Solitaire moves, card flipping, and validation.  
✅ **Cross-Platform** – Runs smoothly on Windows, Linux, and macOS (console-based).  
✅ **Future Ready** – Can be easily extended with GUI using SFML or Qt.

---

## 🏗️ Class Structure

| Class | Description |
|-------|--------------|
| `Card` | Represents a playing card (suit, rank, visibility). |
| `Deck` | Manages shuffling and dealing of cards. |
| `Pile` | Handles a stack of cards in tableau or foundation. |
| `Game` | Main class that controls game state and rules. |
| `Player` | Manages player actions and score (optional). |
| `Utils` | Helper functions for rendering and input. |

---

## 💡 OOP Concepts Used

| Concept | Implementation Example |
|----------|------------------------|
| **Encapsulation** | Private card attributes with getters/setters. |
| **Abstraction** | High-level game operations like `moveCard()`, `flipCard()`. |
| **Inheritance** | Specialized piles (FoundationPile, TableauPile) derived from base class. |
| **Polymorphism** | Overridden behavior for move validation and card display. |
| **Composition** | `Game` contains multiple `Deck` and `Pile` objects. |

---

## ⚙️ How to Run

### 🖥️ Requirements
- C++ Compiler (GCC, Clang, or MSVC)
- Makefile or IDE (Code::Blocks / Visual Studio / Dev-C++)

### 🧱 Build & Run
```bash
g++ main.cpp Game.cpp Deck.cpp Card.cpp Pile.cpp -o solitaire
./solitaire
