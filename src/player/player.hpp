#ifndef TICTACTOE_CPP_PLAYER_H
#define TICTACTOE_CPP_PLAYER_H

#include "../rules.hpp"
#include "../board/board.hpp"

class Player {
    public:
        virtual int getMove(Board board)=0;
        virtual ~Player() {};
};

#endif //TICTACTOE_CPP_PLAYER_H
