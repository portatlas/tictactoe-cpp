#include "game_setup.hpp"

Player* GameSetup::getOpponent(Console &console, Rules &rules) {
    console.display("Select your opponent:\n  c for computer\n  h for human\n");
    std::string opponent = console.retrieve();
    Player* player2;
    if (opponent == "c") {
        player2 = new ComputerPlayer(rules);
    } else if (opponent == "h") {
        player2 = new HumanPlayer(rules, console);
    } else {
        console.display("Come again?\n");
        getOpponent(console, rules);
    }
    return player2;
}

bool GameSetup::willPlay(Console &console) {
    console.display("Would you like to play again? (y/n)\n");
    std::string play_again = console.retrieve();
    if (play_again == "y") {
        return true;
    }
    return false;
}
