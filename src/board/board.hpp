#ifndef TICTACTOE_CPP_BOARD_H
#define TICTACTOE_CPP_BOARD_H

#include <vector>

class Board {
    public:
        explicit Board(unsigned int size);
        explicit Board(std::vector<std::string> grid);
        unsigned int getSize();
        std::string getSlot(int position);
        bool isSlotEmpty(int position);
        Board fillSlot(int position, std::string &marker);
        long countMarker(std::string &marker);
        bool isGridFull();
        std::vector<int> validSlots();
    private:
        unsigned int _size;
        std::vector<std::string> _grid;
};

#endif //TICTACTOE_CPP_BOARD_H
