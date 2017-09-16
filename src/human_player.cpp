#include "human_player.hpp"

int HumanPlayer::getMove(Board board, Rules rules, Console console){
    int move = convertStrToInt(console, console.retrieve());
    if(rules.isValidMove(board, move)) {
        return move;
    } else {
        console.display("Invalid move, please a slot on the board\n");
        move = getMove(board, rules, console);
    }
    return move;
};

int HumanPlayer::convertStrToInt(Console console, std::string input){
    int slot;
    try {
        slot = stoi(input);
    } catch (std::invalid_argument& e) {
        console.display("Input is not a number\n");
        slot = convertStrToInt(console, console.retrieve());
    }
    return slot;
};
