#include "../marker.hpp"
#include "board.hpp"

Board::Board(unsigned int size) :
    _size(size),
    _grid(std::vector<std::string>(_size, EMPTY))
{}

Board::Board(std::vector<std::string> grid) {
    _size = (int)grid.size();
    _grid = grid;
}

unsigned int Board::getSize() {
    return _size;
};

std::vector<std::string> Board::getGrid() {
    return _grid;
};

std::string Board::getSlot(int position) {
    return _grid[position - 1];
};

bool Board::isSlotEmpty(int position) {
    return getSlot(position) == EMPTY;
};

Board Board::fillSlot(int position, std::string &marker) {
    _grid[position - 1] = marker;
    Board new_board(_grid);
    return new_board;
};

long Board::countMarker(std::string &marker) {
    long marker_count = count_if(_grid.begin(),
                                 _grid.end(),
                                 [marker](std::string slot) {
                                     return slot == marker;
                                 });
    return marker_count;
}

bool Board::isGridFull() {
    return countMarker(X) + countMarker(O) == _size;
}

std::vector<int> Board::validSlots() {
    std::vector<int> valid_slots;
    for(int i = 1; i <= _size; i++) {
        if(isSlotEmpty(i)) {
            valid_slots.push_back(i);
        }
    }
    return valid_slots;
}
