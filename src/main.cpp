#include "game/game.hpp"
#include "game/game_setup.hpp"

int main() {
    Console console;
    Rules rules;
    Player* player1;
    Player* player2;
    Board board(9);
    Game game;
    bool play = true;
    
    console.display("\033[1;4;34mWelcome to TicTacToe!\033[0m\n");
    player1 = GameSetup::setPlayer(console, rules, X);
    player2 = GameSetup::setPlayer(console, rules, O);
    console.display("Enter a number to place a marker on the board\n");
    while(play) {
        console.display(BoardFormatter::format(board));
        game.play(board, rules, player1, player2, console);

        play = GameSetup::willPlay(console);
    }
    return 0;
}
