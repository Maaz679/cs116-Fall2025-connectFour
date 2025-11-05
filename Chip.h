//
// Created by Muhammad Maaz on 11/5/25.
//

#ifndef CS116_FALL2025_CONNECTFOUR_CHIP_H
#define CS116_FALL2025_CONNECTFOUR_CHIP_H


class Chip {
private:
    char symbol;

public:
    Chip(char symbol);
    char getSymbol() const;
    void setSymbol(char symbol);
    bool isEmpty() const;
};


#endif //CS116_FALL2025_CONNECTFOUR_CHIP_H