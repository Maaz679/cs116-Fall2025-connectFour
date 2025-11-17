//
// Created by Muhammad Maaz on 11/5/25.
//

#ifndef CS116_FALL2025_CONNECTFOUR_CHIP_H
#define CS116_FALL2025_CONNECTFOUR_CHIP_H

/**
 * @class Chip
 * @note simulation of a chip
 * @brief chips will either be ' ', 'X', or 'O'.
 */
class Chip {
private:
    char symbol;
public:
    /**
     * @note default constructor
     * initializes with ' '
     */
    Chip();

    /**
     * @note parameterized constructor
     * @param symbol 'X' or 'O'
     */
    Chip(char symbol);

    /**
     *
     * @return symbol of chip
     */
    char getSymbol() const;

    /**
     * @note sets the symbol of the chip
     * @param symbol
     */
    void setSymbol(char symbol);

    /**
     *
     * @return true if chip is not flipped
     */
    bool isEmpty() const;
};


#endif //CS116_FALL2025_CONNECTFOUR_CHIP_H