#ifndef TICTACTOE_CPP_RULES_H
#define TICTACTOE_CPP_RULES_H

#include "marker.hpp"
#include "board/board.hpp"

class Rules {
    public:
        static const std::vector <std::vector <int>> WINNING_SLOTS;

        static bool isValidMove(Board board, int move);
        static std::string getOpponent(std::string &marker);
        static std::string currentTurn(Board &board);
        static std::string switchTurn(Board &board);
        static bool hasWinner(Board &board);
        static std::string getWinner(Board &board);
        static bool isDraw(Board &board);
        static bool isOver(Board &board);
        static std::string getResult(Board &board);

    private:
        static bool isMoveInValidSlots(int move,
                                std::vector<int> &valid_slots);
        static bool isMarkerInWinSlots(Board &board,
                                       const std::string &marker,
                                       const std::vector<int> &slot);
};

#endif //TICTACTOE_CPP_RULES_H
