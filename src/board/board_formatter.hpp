#ifndef TICTACTOE_CPP_BOARD_FORMATTER_H
#define TICTACTOE_CPP_BOARD_FORMATTER_H

#include "board.hpp"
#include "../marker.hpp"

class BoardFormatter {
    public:
        static std::string format(Board board);
    private:
        static std::vector<std::string> indexEmptySlots(Board board);
};

#endif //TICTACTOE_CPP_BOARD_FORMATTER_H
