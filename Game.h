//
// Created by Muhammad Maaz on 11/5/25.
//

#ifndef CS116_FALL2025_CONNECTFOUR_GAME_H
#define CS116_FALL2025_CONNECTFOUR_GAME_H
#include "Board.h"


class Game {
private:
    Board board;
    char currentPlayer;
    bool vsAI;
    int aiChooseColumn();
public:
    Game();
    void play();
    void switchPlayer();
    char getSymbol() const;
    int askColumn() const;
    void announceWinner(char symbol) const;
};


#endif //CS116_FALL2025_CONNECTFOUR_GAME_H