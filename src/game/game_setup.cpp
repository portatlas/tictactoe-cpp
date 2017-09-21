#include "game_setup.hpp"

Player* GameSetup::setPlayer(Console &console, Rules &rules, std::string marker) {
    console.display("Select " + marker + " player:\n   c for computer\n   h for human\n");
    std::string selectedPlayer = console.retrieve();
    Player* player;
    if (selectedPlayer == "c") {
        player = new ComputerPlayer(marker, rules);
    } else if (selectedPlayer == "h") {
        player = new HumanPlayer(rules, console);
    } else {
        console.display("Come again?\n");
        setPlayer(console, rules, marker);
    }
    return player;
}

bool GameSetup::willPlay(Console &console) {
    console.display("Would you like to play again? (y/n)\n");
    std::string play_again = console.retrieve();
    if (play_again == "y") {
        return true;
    }
    return false;
}
