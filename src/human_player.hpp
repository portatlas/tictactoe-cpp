#ifndef TICTACTOE_CPP_HUMAN_PLAYER_H
#define TICTACTOE_CPP_HUMAN_PLAYER_H

#include "console.hpp"
#include "rules.hpp"
#include "board.hpp"

class HumanPlayer {
    public:
        int getMove(Board board, Rules rules, Console console);
    private:
        int convertStrToInt(Console console, std::string input);
};

#endif //TICTACTOE_CPP_HUMAN_PLAYER_H
