#ifndef TICTACTOE_CPP_BOARD_FORMATTER_H
#define TICTACTOE_CPP_BOARD_FORMATTER_H

#include "board.hpp"
#include "marker.hpp"

class BoardFormatter {
    public:
        static string format(Board board);
    private:
        static vector<string> indexEmptySlots(Board board);
};

#endif
