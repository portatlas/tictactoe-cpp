#include "human_player.hpp"


HumanPlayer::HumanPlayer(Rules &rules, Console &console) :
    _rules(rules),
    _console(console)
{};

int HumanPlayer::getMove(Board board) {
    int move = convertStrToInt(_console.retrieve());
    if(_rules.isValidMove(board, move)) {
        return move;
    } else {
        _console.display("Invalid move, please a slot on the board\n");
        move = getMove(board);
    }
    return move;
};

int HumanPlayer::convertStrToInt(std::string input) {
    int slot;
    try {
        slot = stoi(input);
    } catch (std::invalid_argument& e) {
        _console.display("Input is not a number\n");
        slot = convertStrToInt(_console.retrieve());
    }
    return slot;
};
