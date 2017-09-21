#include "../../lib/catch.hpp"
#include "../../src/board/board_formatter.hpp"

SCENARIO ("BoardFormatter") {
    BoardFormatter boardFormatter;

    GIVEN("A board with a full grid") {
        std::vector<std::string> full_grid = {X, O, X,
                                              O, X, O,
                                              X, O, X};
        Board board(full_grid);
        WHEN("#format is called") {
            THEN("return the grid as a 3 x 3 matrix") {
                REQUIRE(boardFormatter.format(board) == "X O X\n"
                                                        "O X O\n"
                                                        "X O X\n");
            }
        }
    }

    GIVEN("A board with a grid of one empty slot") {
        std::vector<std::string> one_empty_slot_grid = {"\033[1;31m1\033[0m", O, X,
                                                                          O , X, O,
                                                                          X , O, X};
        Board board(one_empty_slot_grid);
        WHEN("#format is called") {
            THEN("return the grid as a 3 x 3 matrix and replace empty slots with the index in red") {
                REQUIRE(boardFormatter.format(board) == "\033[1;31m1\033[0m O X\n"
                                                                         "O X O\n"
                                                                         "X O X\n");
            }
        }
    }

    GIVEN("A a board with an empty grid") {
        std::vector<std::string> empty_grid = {" ", " ", " ",
                                               " ", " ", " ",
                                               " ", " ", " "};
        Board board(empty_grid);
        WHEN("#format is called") {
            THEN("return the grid as a 3 x 3 matrix and replace all empty slots with the index in red color") {
                std::string colored_board = "\033[1;31m1\033[0m \033[1;31m2\033[0m \033[1;31m3\033[0m\n"
                                            "\033[1;31m4\033[0m \033[1;31m5\033[0m \033[1;31m6\033[0m\n"
                                            "\033[1;31m7\033[0m \033[1;31m8\033[0m \033[1;31m9\033[0m\n";
                REQUIRE(boardFormatter.format(board) == colored_board);
            }
        }
    }
}
