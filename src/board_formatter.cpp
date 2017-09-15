#include "board_formatter.hpp"

string BoardFormatter::format(Board board) {
    vector<string> grid = indexEmptySlots(board);
    string pretty_grid;
    for (int i = 0; i < board.getSize(); i += 3) {
        pretty_grid += grid[i] + " " + grid[i + 1] + " " + grid[i + 2] + "\n";
    }
    return pretty_grid;
};

vector<string> BoardFormatter::indexEmptySlots(Board board) {
    vector<string> indexed_grid;
    for (int i = 1; i <= board.getSize(); i++) {
        indexed_grid.push_back((board.isSlotEmpty(i)) ? to_string(i) : board.getSlot(i));
    }
    return indexed_grid;
};
