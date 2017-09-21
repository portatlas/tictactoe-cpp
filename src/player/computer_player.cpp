#include "computer_player.hpp"

ComputerPlayer::ComputerPlayer(std::string marker, Rules &rules) :
    _marker(marker),
    _rules(rules)
{};

int ComputerPlayer::getMove(Board board) {
    int bestVal = -1000;
    int bestMove = -1;

    for (int slot : board.validSlots()) {
        board.fillSlot(slot, _marker);
        int moveVal = minimax(board, 0, false);
        board.fillSlot(slot, EMPTY);
        if (moveVal > bestVal) {
            bestMove = slot;
            bestVal = moveVal;
        }
    }
    return bestMove;
}

int ComputerPlayer::minimax(Board board, int depth, bool is_max_player) {
    std::string opponent = _rules.getOpponent(_marker);
    if (_rules.getWinner(board) == _marker) { return 10; };
    if (_rules.getWinner(board) == opponent) { return -10; };
    if (_rules.isDraw(board)) { return 0; }

    if (is_max_player) {
        int best_score = -1000;
        for (int i = 1; i <= board.getSize(); i++) {
            if (board.getSlot(i) == EMPTY) {
                board.fillSlot(i, _marker);
                best_score = std::max(best_score, minimax(board, depth + 1, !is_max_player));
                board.fillSlot(i, EMPTY);
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (int i = 1; i <= board.getSize(); i++) {
            if (board.getSlot(i) == EMPTY) {
                board.fillSlot(i, opponent);
                best_score = std::min(best_score, minimax(board, depth + 1, !is_max_player));
                board.fillSlot(i, EMPTY);
            }
        }
        return best_score;
    }
}
