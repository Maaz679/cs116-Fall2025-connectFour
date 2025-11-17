//
// Created by Muhammad Maaz on 11/5/25.
//

#include "Board.h"

#include <iostream>
#include <locale>
#include <ostream>

Board::Board() {
    // initialize every cell in the game board
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            // set each chip on the board to an empty space
            gameBoard[r][c].setSymbol(' ');
        }
    }

    // initialize the height array for each column
    //  height[c] keeps track of how many chips are stacked in column c
    for (int c = 0; c < COLS; c++) {
        height[c] = 0;  // no chips placed yet in any column
    }
}

bool Board::dropChip(int col, char symbol) {
    // convert user input (1-8) to zero-based index (0-7)
    col -= 1;

    // check if column index is outside valid range
    if (col < 0 || col >= COLS) {
        std::cerr << "Invalid column " << col << std::endl;
        return false;
    }
    // check if selected column is already full
    if (height[col] >= ROWS) {
        std::cerr << "Column "<< col << "is full" << std::endl;
        return false;
    }

    // calculate the row where the chip will land
    // ROWS - 1 = bottom row index
    // height[col] - how many chips already in this column
    int row = ROWS - 1 - height[col];

    // place the chip symbal in the calculated board position
    gameBoard[row][col].setSymbol(symbol);

    // increase the height of this column
    height[col]++;

    // operation successful
    return true;
}

void Board::displayBoard() const {
    // print a blank line before the board
    std::cout << "\n";

    // print each row of the board
    for (int r = 0; r < ROWS; r++) {
        std::cout << "|";   // left border
        for (int c = 0; c < COLS; c++) {
            // print the symbol at each cell, surrounded by vertical bars
            std::cout << gameBoard[r][c].getSymbol() << "|";
        }
        // move to next row
        std::cout << "\n";
    }

    // print the column numbers below the board
    std::cout << " ";   // leading space for alignment
    for (int c = 1; c < COLS; c++) {
        std::cout << c << " ";  // print column indices starting from 1
    }
    std::cout << "\n";  // end the line

}

bool Board::isFull() const {
    // loop through every column in the board
    for (int c = 0; c < COLS; c++) {

        // if any column has space left
        // the board is NOT full, so return false
        if (height[c] < ROWS) {
            return false;
        }
    }

    // if we checked every column and no space left
    // then the board is completely full, return true
    return true;
}

bool Board::checkWin(char symbol) const {
    // define 4 directions to check
    // each direction is represented as (row change, column change)
    int directions[4][2] = {
        {0, 1},   // move right horizontal
        {1, 0},   // move down vertical
        {1, 1},   // move down-right diagonal
        {-1, 1}   // move up-right diagonal
    };

    // loop through every row of the board
    for (int r = 0; r < ROWS; r++) {
        // loop through every column of the board
        for (int c = 0; c < COLS; c++) {

            // skip this position if the symbol does not match
            // the player we are checking
            if (gameBoard[r][c].getSymbol() != symbol) {
                continue;
            }

            // check all 4 directions from this starting cell
            for (int d = 0; d < 4; d++) {

                // get the direction offsets:
                // dr = row change
                // dc = column change
                int dr = directions[d][0];
                int dc = directions[d][1];
                // count how many matching pieces
                // start with 1 = current cell
                int count = 1;

                // forward direction
                int nr = r + dr;    // next row
                int nc = c + dc;    // next column

                // while inside the board AND symbol matches,
                // keep going forward
                while (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS &&
                       gameBoard[nr][nc].getSymbol() == symbol) {
                    count++;    // found another matching piece
                    // move to next cell in same direction
                    nr += dr;
                    nc += dc;
                       }

                // backward direction
                nr = r - dr;    // previous row
                nc = c - dc;    // previous column

                // while inside the board AND symbol matches,
                // keep going backward
                while (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS &&
                       gameBoard[nr][nc].getSymbol() == symbol) {
                    count++;    // found another matching piece
                    // move to next cell in same direction
                    nr -= dr;
                    nc -= dc;
                       }

                // if 4 or more identical symbols are connected,
                // this player wins
                if (count >= 4) {
                    return true;
                }
            }
        }
    }
    // no winning line found anywhere on the board
    return false;
}