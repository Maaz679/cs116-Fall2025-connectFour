# Connect Four | C++

Terminal-based Connect Four built in C++ with object-oriented design and a basic AI opponent.

## Features

- Human vs Human and Human vs AI modes
- 8x8 board with gravity-based chip dropping
- AI strategy: win immediately, block opponent, look 2 moves ahead, then fall back to center-column priority
- Input validation and full win/draw detection

## Build

Requires CMake and a C++ compiler.

```bash
mkdir build && cd build
cmake ..
make
./cs116-Fall2025-connectFour
```

## How It Works

The project is split into three classes:

| Class | Responsibility |
|---|---|
| `Chip` | Represents a single cell on the board (empty, X, or O) |
| `Board` | Manages the 8x8 grid, chip dropping, win checking, and display |
| `Game` | Controls the game loop, player turns, and AI logic |

The AI uses a greedy look-ahead strategy rather than full minimax. It checks if it can win on the current move, then checks if the opponent can win and blocks, then simulates one human response to avoid handing the opponent a win, then defaults to center-column preference.

## Class: CS116 Data Structures and Algorithms, SJSU Fall 2025
