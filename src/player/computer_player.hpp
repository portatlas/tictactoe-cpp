#ifndef TICTACTOE_CPP_COMPUTER_PLAYER_H
#define TICTACTOE_CPP_COMPUTER_PLAYER_H

#include "player.hpp"

class ComputerPlayer : public Player {
    public:
        ComputerPlayer(std::string marker, Rules &rules);
        int getMove(Board board);
        int minimax(Board board, int depth, bool is_max_player);
    private:
        std::string _marker;
        Rules _rules;
};

#endif //TICTACTOE_CPP_COMPUTER_PLAYER_H
