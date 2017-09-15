#include "../lib/catch.hpp"
#include "../src/marker.hpp"
#include "../src/rules.hpp"

SCENARIO("Rules: Validating Moves", "[rules-move]") {

    Board board(9);

    GIVEN("A valid move on an empty slot") {
        WHEN("#isValidMove is called") {
            THEN("return true") {
                REQUIRE(true == Rules::isValidMove(board, 1));
            }
        }
    }

    GIVEN("An invalid move is made that is out of bounds") {
        WHEN("#isValidMove is called") {
            THEN("return false") {
                REQUIRE(false == Rules::isValidMove(board, -11));
                REQUIRE(false == Rules::isValidMove(board, 0));
                REQUIRE(false == Rules::isValidMove(board, 11));
            }
        }
    }

    GIVEN("An invalid move is made that is not a number") {
        WHEN("#isValidMove is called") {
            THEN("return false") {
                REQUIRE(false == Rules::isValidMove(board, 'A'));
            }
        }
    }

    GIVEN("An invalid move is made on an occupied spot") {
        WHEN("#isValidMove is called") {
            THEN("return false") {
                vector<string> x_on_1_board = { X , " ", " ",
                                               " ", " ", " ",
                                               " ", " ", " "};
                Board played_board(x_on_1_board);
                REQUIRE(false == Rules::isValidMove(played_board, 1));
            }
        }
    }
}

SCENARIO("Rules: Validating Turn", "[rules-turn]") {

    GIVEN("An empty board grid") {
        Board board(9);
        WHEN("#switchTurn is called") {
            THEN("return X") {
                REQUIRE(X == Rules::switchTurn(board));
            }
        }
    }

    GIVEN("A board grid with X on the first slot") {
        vector<string> x_on_1_board = { X , " ", " ",
                                       " ", " ", " ",
                                       " ", " ", " "};
        Board played_board(x_on_1_board);
        WHEN("#switchTurn is called") {
            REQUIRE(O == Rules::switchTurn(played_board));
        }
    }

    GIVEN("A board grid with X,O,X on 1,2,3 respective") {
        vector<string> new_board = { X ,  O ,  X ,
                                    " ", " ", " ",
                                    " ", " ", " "};
        Board played_board(new_board);
        WHEN("#switchTurn is called") {
            REQUIRE(O == Rules::switchTurn(played_board));
        }
    }
}

SCENARIO ("Rules: Validating Game Results", "[rules-result]") {
    GIVEN("A 3X3 board") {
        WHEN("WINNING_SLOTS") {
            THEN("represents a vector of vectors of all indices of winning") {
                vector< vector<int>> WINNING_SLOTS = {{1,2,3},
                                                      {4,5,6},
                                                      {7,8,9},
                                                      {1,4,7},
                                                      {2,5,8},
                                                      {3,6,9},
                                                      {1,5,9},
                                                      {3,5,7}};
                REQUIRE(WINNING_SLOTS == WINNING_SLOTS);
            }
        }
    }

    GIVEN("An empty board") {
        Board board(9);
        WHEN("hasWinner is called") {
            THEN("return false") {
                REQUIRE(false == Rules::hasWinner(board, X));
            }
        }
    }

    GIVEN("A board with a winner on the first row") {
        vector<string> x_win_grid = { X,   X,   X,
                                     " ", " ", " ",
                                     " ", " ", " "};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(true == Rules::hasWinner(x_win_board, X));
            }
        }
    }

    GIVEN("A board with a winner on the second row") {
        vector<string> x_win_grid = {" ", " ", " ",
                                      X,   X,   X,
                                     " ", " ", " "};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(true == Rules::hasWinner(x_win_board, X));
            }
        }
    }

    GIVEN("A board with a winner on the third row") {
        vector<string> x_win_grid = {" ", " ", " ",
                                     " ", " ", " ",
                                      X,   X,   X};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(true == Rules::hasWinner(x_win_board, X));
            }
        }
    }

    GIVEN("A board with a winner on the first column") {
        vector<string> x_win_grid = {X, " ", " ",
                                     X, " ", " ",
                                     X, " ", " "};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(true == Rules::hasWinner(x_win_board, X));
            }
        }
    }

    GIVEN("A board with a winner on the second column") {
        vector<string> x_win_grid = {" ", X, " ",
                                     " ", X, " ",
                                     " ", X, " "};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(true == Rules::hasWinner(x_win_board, X));
            }
        }
    }

    GIVEN("A board with a winner on the third column") {
        vector<string> x_win_grid = {" ", " ", X,
                                     " ", " ", X,
                                     " ", " ", X};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(true == Rules::hasWinner(x_win_board, X));
            }
        }
    }

    GIVEN("A board with a winner on the top right to bottom left diagonal") {
        vector<string> x_win_grid = { X , " ", " ",
                                     " ",  X , " ",
                                     " ", " ",  X};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(true == Rules::hasWinner(x_win_board, X));
            }
        }

        WHEN("getWinner is called") {
            THEN("return X") {
                REQUIRE(X == Rules::getResult(x_win_board, X));
            }
        }
    }

    GIVEN("A board with a winner on the top right to bottom left diagonal") {
        vector<string> o_win_grid = { O , " ", " ",
                                      " ",  O , " ",
                                      " ", " ",  O};
        Board o_win_board(o_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(true == Rules::hasWinner(o_win_board, O));
            }
        }

        WHEN("getResult is called") {
            THEN("return O") {
                REQUIRE(O == Rules::getResult(o_win_board, O));
            }
        }
    }

    GIVEN("A board with one move a way from a win") {
        vector<string> x_close_to_win_grid = { X,  " ",  X ,
                                              " ", " ", " ",
                                              " ", " ", " "};
        Board no_winner_board(x_close_to_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(false == Rules::hasWinner(no_winner_board, X));
            }
        }

        WHEN("getResult is called") {
            THEN("return O") {
                REQUIRE("Keep playing!" == Rules::getResult(no_winner_board, X));
            }
        }
    }

    GIVEN("A board with a draw") {
        vector<string> draw_grid = { X, O, X ,
                                     O, X, O,
                                     O, X, O};
        Board draw_board(draw_grid);
        WHEN("isDraw is called") {
            THEN("return true") {
                REQUIRE(true == Rules::isDraw(draw_board, X));
            }
        }

        WHEN("isOver is called") {
            THEN("return true") {
                REQUIRE(true == Rules::isOver(draw_board, O));
            }
        }

        WHEN("getResult is called") {
            THEN("return ") {
                REQUIRE("Its a draw!" == Rules::getResult(draw_board, X));
            }
        }
    }

    GIVEN("A board with an empty slot on the grid") {
        vector<string> ongoing_grid = {X,  O , X,
                                       O, " ", O,
                                       O,  X , O};
        Board active_board(ongoing_grid);
        WHEN("isDraw is called") {
            THEN("return false") {
                REQUIRE(false == Rules::isDraw(active_board, X));
            }
        }

        WHEN("isOver is called") {
            THEN("return false") {
                REQUIRE(false == Rules::isOver(active_board, X));
            }
        }
    }

    GIVEN("A board with a winner") {
        vector<string> o_win_grid = { O, X, X,
                                      X, O, O,
                                      X, X, O};
        Board o_win_board(o_win_grid);
        WHEN("isDraw is called") {
            THEN("return false") {
                REQUIRE(false == Rules::isDraw(o_win_board, O));
            }
        }

        WHEN("isOver is called") {
            THEN("return true") {
                REQUIRE(true == Rules::isOver(o_win_board, O));
            }
        }
    }
};
