#ifndef TICTACTOE_CPP_HUMAN_PLAYER_H
#define TICTACTOE_CPP_HUMAN_PLAYER_H

#include "player.hpp"
#include "../console.hpp"

class HumanPlayer : public Player {
    public:
        HumanPlayer(Rules &rules, Console &console);
        int getMove(Board board);
    private:
        Rules _rules;
        Console _console;
        int convertStrToInt(std::string input);
};

#endif //TICTACTOE_CPP_HUMAN_PLAYER_H
