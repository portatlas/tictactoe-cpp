#ifndef TICTACTOE_CPP_BOARD_H
#define TICTACTOE_CPP_BOARD_H

#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Board {
    public:
        explicit Board(int size);
        explicit Board(vector<string> grid);

        int getSize();
        vector<string> getGrid();
        string getSlot(int position);
        bool isSlotEmpty(int position);
        Board fillSlot(int position);
        long countMarker(string marker);
        string whoseTurn();
        bool isGridFull();
        vector<int> validSlots();
    private:
        int _size;
        vector<string> _grid;
};

#endif
