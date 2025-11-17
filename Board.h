//
// Created by Muhammad Maaz on 11/5/25.
//

#ifndef CS116_FALL2025_CONNECTFOUR_BOARD_H
#define CS116_FALL2025_CONNECTFOUR_BOARD_H
#include "Chip.h"

/**
 * @class Board
 * @note simulation of a connect four board
 * @brief the board will be initialized with 8 rows and 8 columns
 *          filled with chips initialized with ' '.
 *          When a chip is "dropped" in a specific column, the closest
 *          unflipped chip at the highest row in that column will change
 *          from ' ', to either 'X' or 'O'.
 */
class Board {
private:
    static const int ROWS = 8;
    static const int COLS = 8;
    Chip gameBoard[ROWS][COLS];
    int height[COLS];
public:
    /**
     * @note default constructor
     * @brief initializes board with empty chips
     */
    Board();

    /**
     *
     * @param col 1 - 8
     * @param symbol 'X' or 'O'
     * @return true if the column is valid and has space
     */
    bool dropChip(int col, char symbol);

    /**
     * @note displays the board and the states of each chip
     */
    void displayBoard() const;

    /**
     *
     * @return true if all chips have been flipped
     */
    bool isFull() const;

    /**
     *
     * @param symbol
     * @return
     */
    bool checkWin(char symbol) const;
};


#endif //CS116_FALL2025_CONNECTFOUR_BOARD_H