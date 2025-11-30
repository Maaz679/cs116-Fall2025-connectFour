//
// Created by Muhammad Maaz on 11/5/25.
//

#include "Game.h"
#include <iostream>

// default constructor
Game::Game() : currentPlayer('X') {
    // board is automatically constructed
    // first player defaulted X
}

// main game loop
void Game::play() {
    // print welcome message
    std::cout << "Welcome to Connect Four!" << std::endl;

    // loop until the board becomes full or someone wins
    while (!board.isFull()) {

        // display the current state of the board
        board.displayBoard();

        // symbol matches current player
        char symbol = getSymbol();   // X or O depending on current player

        // ask the current player for a column number between 1-8
        int col = askColumn();

        // attempt to drop the chip
        // if dropChip returns false, the move was invalid
        if (!board.dropChip(col, symbol)) {
            std::cout << "Invalid move. Try again." << std::endl;
            continue; // skip switching player and retry
        }

        // after placing a chip, check if the current player won
        if (board.checkWin(symbol)) {

            // display final board
            board.displayBoard();

            // announce which symbol won
            announceWinner(symbol);
            return;     // end the game
        }

        // switch to the other player for next turn
        switchPlayer();
    }

    // if loop ends because board is full, it's a draw
    board.displayBoard();
    std::cout << "The board is full. It's a draw!"<< std::endl;

}

// return symbol of current player
char Game::getSymbol() const {
    return currentPlayer;
}

// switch between players X and O
void Game::switchPlayer() {

    // if current player is X, switch to O
    if (currentPlayer == 'X') {
        currentPlayer = 'O';

        // otherwise switch from O to X
    } else {
        currentPlayer = 'X';
    }
}

// ask player for a column from 1 to 8
int Game::askColumn() const {

    // prompt for input
    std::cout << "Player " << getSymbol()
              << ", choose a column (1-8): ";

    int column;
    std::cin >> column;

    // validate column number
    while (column < 1 || column > 8) {
        std::cout << "Invalid column number. Enter a number 1-8: ";
        std::cin >> column;
    }

    return column;
}

// announce the winning symbol
void Game::announceWinner(char symbol) const {
    // show winner message
    std::cout << "Player " << symbol << " wins!" << std::endl;
}
