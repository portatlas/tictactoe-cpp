#ifndef TICTACTOE_CPP_RULES_H
#define TICTACTOE_CPP_RULES_H

#include "marker.hpp"
#include "board.hpp"

class Rules {
    public:
        static const vector <vector <int>> WINNING_SLOTS;

        static bool isValidMove(Board board, int move);
        static string switchTurn(Board board);
        static bool hasWinner(Board board, string marker);
        static bool isDraw(Board board, string &marker);
        static bool isOver(Board board, string marker);
        static string getResult(Board board, string marker);

    private:
        static bool isMoveInValidSlots(int move,
                                vector<int> &valid_slots);
        static bool isMarkerInWinSlots(Board &board,
                                const string &marker,
                                const vector<int> &slot);
};

#endif
