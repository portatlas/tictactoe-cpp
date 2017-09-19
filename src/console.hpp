#ifndef TICTACTOE_CPP_CONSOLE_H
#define TICTACTOE_CPP_CONSOLE_H

#include "board_formatter.hpp"

#include <string>
#include <iostream>

class Console {
    public:
        void display(std::string message);
        std::string retrieve();
};

#endif //TICTACTOE_CPP_CONSOLE_H
