#ifndef TICTACTOE_CPP_GAME_H
#define TICTACTOE_CPP_GAME_H

#include "../console.hpp"
#include "../board/board.hpp"
#include "../player/human_player.hpp"
#include "../player/computer_player.hpp"

class Player;

class Game {
    public:
        std::string play(Board board,
                         Rules &rules,
                         Player *player1,
                         Player *player2,
                         Console &console);

    private:
        void renderBoard(Console &console,
                         Board board);
        void renderText(Console &console,
                        Board board,
                        Rules rules);
};

#endif //TICTACTOE_CPP_GAME_H
