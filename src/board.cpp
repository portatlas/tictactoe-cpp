#include "marker.hpp"
#include "board.hpp"

string X = "X";
string O = "O";

Board::Board(int size) {
    _size = size;
    _grid = vector<string>(size, " ");
}

Board::Board(vector<string> grid) {
    _size = grid.size();
    _grid = grid;
}

int Board::getSize() {
    return _size;
};

vector<string> Board::getGrid() {
    return _grid;
};

string Board::getSlot(int position) {
    return _grid[position - 1];
};

bool Board::isSlotEmpty(int position) {
    return (getSlot(position) == " ") ? true : false;
};

Board Board::fillSlot(int position) {
    string marker = whoseTurn();
    _grid[position - 1] = marker;
    Board new_board(_grid);
    return new_board;
};

long Board::countMarker(string marker){
    long marker_count = count_if(_grid.begin(),
                                 _grid.end(),
                                 [marker](string slot){
                                     return slot == marker;
                                 });
    return marker_count;
}

string Board::whoseTurn(){
    return (countMarker(X) > countMarker(O)) ? O : X;
};

bool Board::isGridFull(){
    return (countMarker(X) + countMarker(O) == _size) ? true : false;
}

vector<int> Board::validSlots(){
    vector<int> valid_slots;
    for(int i = 1; i <= _size; i++) {
        if(isSlotEmpty(i)){
            valid_slots.push_back(i);
        }
    }
    return valid_slots;
}