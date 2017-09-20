#include "computer_player.hpp"

ComputerPlayer::ComputerPlayer(Rules &rules) :
    _rules(rules)
{};

int ComputerPlayer::getMove(Board board) {
    int bestVal = -1000;
    int bestMove = -1;

    for (int slot : board.validSlots()) {
        board.fillSlot(slot, O);
        int moveVal = minimax(board, 0, false);
        board.fillSlot(slot, EMPTY);
        if (moveVal > bestVal) {
            bestMove = slot;
            bestVal = moveVal;
        }
    }
    return bestMove;
}

int ComputerPlayer::minimax(Board board, int depth, bool isMax) {
    if (_rules.getWinner(board) == O) { return 10; }
    if (_rules.getWinner(board) == X) { return -10; }
    if (_rules.isDraw(board)) { return 0; }

    if (isMax) {
        int best_score = -1000;
        for (int i = 1; i <= board.getSize(); i++) {
            if (board.getSlot(i) == EMPTY) {
                board.fillSlot(i, O);
                best_score = std::max(best_score, minimax(board, depth + 1, !isMax));
                board.fillSlot(i, EMPTY);
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (int i = 1; i <= board.getSize(); i++) {
            if (board.getSlot(i) == EMPTY) {
                board.fillSlot(i, X);
                best_score = std::min(best_score, minimax(board, depth + 1, !isMax));
                board.fillSlot(i, EMPTY);
            }
        }
        return best_score;
    }
}
