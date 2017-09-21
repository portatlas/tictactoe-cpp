#include <iostream>
#include "rules.hpp"

const std::vector <std::vector <int>> Rules::WINNING_SLOTS ({{1,2,3},
                                                             {4,5,6},
                                                             {7,8,9},
                                                             {1,4,7},
                                                             {2,5,8},
                                                             {3,6,9},
                                                             {1,5,9},
                                                             {3,5,7}});

bool Rules::isValidMove(Board board, int move) {
    std::vector<int> valid_slots = board.validSlots();
    return isMoveInValidSlots(move, valid_slots);
}

std::string Rules::getOpponent(std::string &marker) {
   return (marker == X) ? O : X;
};

std::string Rules::switchTurn(Board &board) {
    return(board.countMarker(X) > board.countMarker(O)) ? O : X;
}

std::string Rules::currentTurn(Board &board) {
    return(board.countMarker(X) > board.countMarker(O)) ? X : O;
}

bool Rules::hasWinner(Board &board) {
    std::string marker = currentTurn(board);
    for(auto& row:WINNING_SLOTS) {
        for(auto& slot:WINNING_SLOTS) {
            if (isMarkerInWinSlots(board, marker, slot)) {
                return true;
            }
        }
    }
    return false;
}

std::string Rules::getWinner(Board &board) {
    if (hasWinner(board)) {
        return currentTurn(board);
    }
    return "No winner";
};

bool Rules::isDraw(Board &board) {
    return board.validSlots().empty() && !hasWinner(board);
};

bool Rules::isOver(Board &board) {
    return isDraw(board) || hasWinner(board);
};

std::string Rules::getResult(Board &board) {
    std::string marker = currentTurn(board);
    if (hasWinner(board)) {
        return marker + " wins!\n";
    } else if (isDraw(board)) {
        return "Its a draw!\n";
    }
    return switchTurn(board) + "'s turn to move...\n\n";
};

bool Rules::isMoveInValidSlots(int move, std::vector<int> &valid_slots) {
    return std::find(valid_slots.begin(), valid_slots.end(), move) != valid_slots.end();
};

bool Rules::isMarkerInWinSlots(Board &board,
                               const std::string &marker,
                               const std::vector<int> &slot) {
    return board.getSlot(slot[0]) == marker &&
           board.getSlot(slot[1]) == marker &&
           board.getSlot(slot[2]) == marker;
};
