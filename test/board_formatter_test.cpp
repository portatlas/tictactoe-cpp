#include "catch.hpp"
#include "../src/board_formatter.hpp"

SCENARIO ("BoardFormatter") {
    BoardFormatter boardFormatter;

    GIVEN("A board with a full grid") {
        vector<string> full_grid = {X, O, X, O, X, O, X, O, X};
        Board board(full_grid);
        WHEN("#format is called") {
            THEN("return the grid as a 3 x 3 matrix") {
                REQUIRE("X O X\n"
                        "O X O\n"
                        "X O X\n" == boardFormatter.format(board));
            }
        }
    }

    GIVEN("A board with a grid of one empty slot") {
        vector<string> one_empty_slot_grid = {" ", O, X, O, X, O, X, O, X};
        Board board(one_empty_slot_grid);
        WHEN("#format is called") {
            THEN("return the grid as a 3 x 3 matrix and replace empty slots with the index") {
                REQUIRE("1 O X\n"
                        "O X O\n"
                        "X O X\n" == boardFormatter.format(board));
            }
        }
    }

    GIVEN("A a board with an empty grid") {
        vector<string> empty_grid = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
        Board board(empty_grid);
        WHEN("#format is called") {
            THEN("return the grid as a 3 x 3 matrix and replace all empty slots with the index") {
                REQUIRE("1 2 3\n"
                        "4 5 6\n"
                        "7 8 9\n" == boardFormatter.format(board));
            }
        }
    }
}