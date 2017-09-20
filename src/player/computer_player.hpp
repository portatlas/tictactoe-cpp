#ifndef TICTACTOE_CPP_COMPUTER_PLAYER_H
#define TICTACTOE_CPP_COMPUTER_PLAYER_H

#include "player.hpp"

class ComputerPlayer : public Player {
    public:
        explicit ComputerPlayer(Rules &rules);
        virtual int getMove(Board board);
        int minimax(Board board, int depth, bool isMax);
    private:
        Rules _rules;
};

#endif //TICTACTOE_CPP_COMPUTER_PLAYER_H
