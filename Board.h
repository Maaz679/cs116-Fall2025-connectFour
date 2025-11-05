//
// Created by Muhammad Maaz on 11/5/25.
//

#ifndef CS116_FALL2025_CONNECTFOUR_BOARD_H
#define CS116_FALL2025_CONNECTFOUR_BOARD_H
#include "Chip.h"


class Board {
private:
    static const int ROWS = 8;
    static const int COLS = 8;
    Chip gameBoard[ROWS][COLS];
    int height[ROWS];
public:
    Board();
    bool dropChip(int col, char symbol);
    void displayBoard() const;
    bool isFull() const;
    bool checkWin(char symbol) const;
};


#endif //CS116_FALL2025_CONNECTFOUR_BOARD_H