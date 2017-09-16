#ifndef TICTACTOE_CPP_GAME_H
#define TICTACTOE_CPP_GAME_H

#include "console.hpp"
#include "board.hpp"
#include "human_player.hpp"

class Game {
    public:
        std::string play(Board board,
                         Rules rules,
                         HumanPlayer player1,
                         HumanPlayer player2,
                         Console console);
    private:
        void renderBoard(Console console,
                         Board board);
        void renderText(Console console,
                        Board board,
                        Rules rules);
};

#endif //TICTACTOE_CPP_GAME_H
