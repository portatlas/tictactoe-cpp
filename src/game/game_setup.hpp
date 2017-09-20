#ifndef TICTACTOE_CPP_GAME_SETUP_H
#define TICTACTOE_CPP_GAME_SETUP_H

#include "../console.hpp"
#include "../player/player.hpp"
#include "../player/computer_player.hpp"
#include "../player/human_player.hpp"

class GameSetup {
    public:
        static Player* getOpponent(Console &console, Rules &rules);
        static bool willPlay(Console &console);
};

#endif //TICTACTOE_CPP_GAME_SETUP_H
