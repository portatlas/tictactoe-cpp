#include "board_formatter.hpp"

std::string BoardFormatter::format(Board board) {
    std::vector<std::string> grid = indexEmptySlots(board);
    std::string pretty_grid;
    for (int i = 0; i < board.getSize(); i += 3) {
        pretty_grid += grid[i] + " " + grid[i + 1] + " " + grid[i + 2] + "\n";
    }
    return pretty_grid;
};

std::vector<std::string> BoardFormatter::indexEmptySlots(Board board) {
    std::vector<std::string> indexed_grid;
    for (int i = 1; i <= board.getSize(); i++) {
        std::string empty_slot = "\033[1;31m" + std::to_string(i) + "\033[0m";
        indexed_grid.push_back((board.isSlotEmpty(i)) ? empty_slot : board.getSlot(i));
    }
    return indexed_grid;
};
