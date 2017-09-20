#include "../../lib/catch.hpp"
#include "../../src/player/computer_player.hpp"

SCENARIO("ComputerPlayer") {
    Rules rules;
    ComputerPlayer computerplayer(rules);
    GIVEN("X wins the grid") {
        std::vector<std::string> x_win_grid = { X , " ", " ",
                                               " ",  X , " ",
                                               " ", " ",  X};
        Board board(x_win_grid);
        WHEN("#minimax is called") {
            THEN("return -10") {
                REQUIRE(computerplayer.minimax(board, 0, true) == -10);
            }
        }
    }

    GIVEN("O wins the grid") {
        std::vector<std::string> o_win_grid = { O , " ", " ",
                                               " ",  O , " ",
                                               " ", " ",  O};
        Board board(o_win_grid);
        WHEN("#minimax is called") {
            THEN("return 10") {
                REQUIRE(computerplayer.minimax(board, 0, true) == 10);
            }
        }
    }

    GIVEN("A draw") {
        std::vector<std::string> draw_grid = {X, O, X,
                                              O, X, O,
                                              O, X, O};
        Board board(draw_grid);
        WHEN("#minimax is called") {
            THEN("return 0") {
                REQUIRE(computerplayer.minimax(board, 0, true) == 0);
            }
        }
    }

    GIVEN("X is one move from win") {
        std::vector<std::string> x_to_win_grid = { X , " ", " ",
                                                   X ,  O ,  X ,
                                                  " ", " ",  O};
        Board board(x_to_win_grid);
        WHEN("#minimax is called") {
            THEN("return -10 for a win for X") {
                REQUIRE(computerplayer.minimax(board, 0, false) == -10);
            }
        }
    }

    GIVEN("O is one move from a win") {
        std::vector<std::string> o_to_win_grid = { X , " ",  X ,
                                                   O ,  O , " ",
                                                  " ",  X , " "};
        Board board(o_to_win_grid);
        WHEN("#minimax is called") {
            THEN("return 10 for a win for O") {
                REQUIRE(computerplayer.minimax(board, 0, true) == 10);
            }
        }
    }

    GIVEN("X is about to win") {
        std::vector<std::string> x_win_grid = { X , " ", " ",
                                                X ,  O ,  X ,
                                               " ", " ",  O};
        Board board(x_win_grid);
        WHEN("#getMove is called") {
            THEN("O makes a blocking move") {
                REQUIRE(computerplayer.getMove(board) == 7);
            }
        }
    }

    GIVEN("O is about to win") {
        std::vector<std::string> o_win_grid = { X , " ",  X ,
                                                O ,  O , " ",
                                               " ",  X , " "};
        Board board(o_win_grid);
        WHEN("#getMove is called") {
            THEN("O makes a winning move") {
                REQUIRE(computerplayer.getMove(board) == 6);
            }
        }
    }
}
