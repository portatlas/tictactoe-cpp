#include "rules.hpp"

const vector <vector <int>> Rules::WINNING_SLOTS ({{1,2,3},
                                                   {4,5,6},
                                                   {7,8,9},
                                                   {1,4,7},
                                                   {2,5,8},
                                                   {3,6,9},
                                                   {1,5,9},
                                                   {3,5,7}});

bool Rules::isValidMove(Board board, int move) {
    vector<int> valid_slots = board.validSlots();
    return isMoveInValidSlots(move, valid_slots);
}

string Rules::switchTurn(Board board) {
    return(board.countMarker(X) > board.countMarker(O)) ? O : X;
}

bool Rules::hasWinner(Board board, string marker){
    for(auto& row:WINNING_SLOTS) {
        for(auto& slot:WINNING_SLOTS) {
            if (isMarkerInWinSlots(board, marker, slot)) {
                return true;
            }
        }
    }
    return false;
}

bool Rules::isDraw(Board board, string &marker){
    return board.validSlots().empty() && !hasWinner(board, marker);
};

bool Rules::isOver(Board board, string marker){
    return isDraw(board,marker) || hasWinner(board, marker);
};

string Rules::getResult(Board board, string marker){
    if (hasWinner(board, marker)) {
        return marker;
    } else if (isDraw(board, marker)) {
        return "Its a draw!";
    }
    return "Keep playing!";
};

bool Rules::isMoveInValidSlots(int move, vector<int> &valid_slots) {
    return find(valid_slots.begin(), valid_slots.end(), move) != valid_slots.end();
};

bool Rules::isMarkerInWinSlots(Board &board,
                               const string &marker,
                               const vector<int> &slot){
    return board.getSlot(slot[0]) == marker &&
           board.getSlot(slot[1]) == marker &&
           board.getSlot(slot[2]) == marker;
};
