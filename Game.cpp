//
// Created by Muhammad Maaz on 11/5/25.
//

#include "Game.h"
#include <iostream>
#include <vector>

// default constructor
Game::Game() : currentPlayer('X'), vsAI(false) {
    // board is automatically constructed
    // first player defaulted X
    // default playing human vs human
}

// main game loop
void Game::play() {
    // print welcome message
    std::cout << "Welcome to Connect Four!" << std::endl;

    // ask which mode to play
    std::cout << "Choose mode:" << std::endl;
    std::cout << "1) Human vs Human" << std::endl;
    std::cout << "2) Human vs AI" << std::endl;
    std::cout << "Enter 1 or 2: ";

    int gameMode;
    std::cin >> gameMode;
    vsAI = (gameMode == 2);

    if (vsAI) {
        std::cout << "Who goes first?" << std::endl;
        std::cout << "1) Human (X)" << std::endl;
        std::cout << "2) AI (O)" << std::endl;
        std::cout << "Enter 1 or 2: ";

        int firstPlayer;
        std::cin >> firstPlayer;

        if (firstPlayer == 2) {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    // loop until the board becomes full or someone wins
    while (!board.isFull()) {

        // display the current state of the board
        board.displayBoard();

        // symbol matches current player
        char symbol = getSymbol();   // X or O depending on current player

        // choose column to drop chip
        int col;

        // AI turn
        if (vsAI && currentPlayer == 'O') {
            col = aiChooseColumn();
            std::cout << "AI chooses column " << col << std::endl;
        }

        // Human turn
        else {
            col = askColumn();
        }


        // attempt to drop the chip
        // if dropChip returns false, the move was invalid
        if (!board.dropChip(col, symbol, false)) {
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

// AI player function
int Game::aiChooseColumn() {

    // try to win immediately
    for (int col = 1; col <= 8; col++) {
        if (board.isColumnFull(col)) {
            continue;
        }
        Board temp = board;
        if (temp.dropChip(col, 'O', true)) {
            if (temp.checkWin('O')) {
                return col;
            }
        }
    }

    // block opponent from winning
    for (int col = 1; col <= 8; col++) {
        if (board.isColumnFull(col)) {
            continue;
        }
        Board temp = board;
        if (temp.dropChip(col, 'X', true)) {
            if (temp.checkWin('X')) {
                return col;
            }
        }
    }

    // look 2 moves ahead
    for (int col = 1; col <= 8; col++) {
        if (board.isColumnFull(col)) {
            continue;
        }
        Board afterAIMove = board;

        if (!afterAIMove.dropChip(col, 'O', true))
            continue;

        bool badMove = false;

        for (int humanCol = 1; humanCol <= 8; humanCol++) {
            if (board.isColumnFull(humanCol)) {
                continue;
            }
            Board afterHumanMove = afterAIMove;

            if (afterHumanMove.dropChip(humanCol, 'X', true)) {
                if (afterHumanMove.checkWin('X')) {
                    badMove = true;
                    break;
                }
            }
        }
        if (!badMove) {
            return col;
        }
    }



    // if no winning move or able to block opponent, just play in the center
    int priority[8] = {4, 5, 3, 6, 2, 7, 1, 8} ;
    for (int column : priority) {
        if (board.isColumnFull(column)) {
            continue;
        }
        Board temp = board;
        if (temp.dropChip(column, 'O', true)) {
            return column;
        }
    }

    return 1;
}
