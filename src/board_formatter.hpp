#ifndef TICTACTOE_CPP_BOARD_FORMATTER_H
#define TICTACTOE_CPP_BOARD_FORMATTER_H

#include "board.hpp"
#include "marker.hpp"

#include <string>

using namespace std;

class BoardFormatter {
    public:
        string format(Board board);
    private:
        vector<string> indexEmptySlots(Board board);
};

#endif
