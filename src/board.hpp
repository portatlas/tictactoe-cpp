#ifndef TICTACTOE_CPP_BOARD_H
#define TICTACTOE_CPP_BOARD_H

#include <vector>

using namespace std;

class Board {
    public:
        explicit Board(unsigned int size);
        explicit Board(vector<string> grid);

        unsigned int getSize();
        vector<string> getGrid();
        string getSlot(int position);
        bool isSlotEmpty(int position);
        Board fillSlot(int position, string &marker);
        long countMarker(string marker);
        bool isGridFull();
        vector<int> validSlots();
    private:
        unsigned int _size;
        vector<string> _grid;
};

#endif
