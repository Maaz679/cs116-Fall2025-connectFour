//
// Created by Muhammad Maaz on 11/5/25.
//

#include "Chip.h"

Chip::Chip() {
    // initialize the chip with a space character
    // meaning empty cell on the game board
    this->symbol = ' ';
}

Chip::Chip(char symbol) {
    // initialize the chip with the given symbol
    // this allows creatinga chip that is already set
    // to 'X', 'O', or any other character
    this->symbol = symbol;
}

char Chip::getSymbol() const {
    // return the current symbol stored in this chip
    return this->symbol;
}

void Chip::setSymbol(char symbol) {
    // set the symbol of this chip to the given character
    this->symbol = symbol;
}

bool Chip::isEmpty() const {
    // return true if this chip has no symbol (empty space)
    // return false if this chip contains any other character
    return this->symbol == ' ';
}
