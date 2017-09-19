#include "../lib/catch.hpp"
#include "../src/marker.hpp"
#include "../src/rules.hpp"

SCENARIO("Rules: Validating Moves", "[rules-move]") {

    Board board(9);

    GIVEN("A valid move on an empty slot") {
        WHEN("#isValidMove is called") {
            THEN("return true") {
                REQUIRE(Rules::isValidMove(board, 1) == true);
            }
        }
    }

    GIVEN("An invalid move is made that is out of bounds") {
        WHEN("#isValidMove is called") {
            THEN("return false") {
                REQUIRE(Rules::isValidMove(board, -11)== false );
                REQUIRE(Rules::isValidMove(board, 0)== false );
                REQUIRE(Rules::isValidMove(board, 11)== false );
            }
        }
    }

    GIVEN("An invalid move is made that is not a number") {
        WHEN("#isValidMove is called") {
            THEN("return false") {
                REQUIRE(Rules::isValidMove(board, 'A') == false);
            }
        }
    }

    GIVEN("An invalid move is made on an occupied spot") {
        WHEN("#isValidMove is called") {
            THEN("return false") {
                std::vector<std::string> x_on_1_board = { X , " ", " ",
                                                         " ", " ", " ",
                                                         " ", " ", " "};
                Board played_board(x_on_1_board);
                REQUIRE(Rules::isValidMove(played_board, 1) == false);
            }
        }
    }
}

SCENARIO("Rules: Validating Turn", "[rules-turn]") {

    GIVEN("An empty board grid") {
        Board board(9);
        WHEN("#switchTurn is called") {
            THEN("return X") {
                REQUIRE(Rules::switchTurn(board) == X);
            }
        }
    }

    GIVEN("A board grid with X on the first slot") {
        std::vector<std::string> x_on_1_board = { X , " ", " ",
                                                 " ", " ", " ",
                                                 " ", " ", " "};
        Board played_board(x_on_1_board);
        WHEN("#switchTurn is called") {
            REQUIRE(Rules::switchTurn(played_board) == O);
        }
        WHEN("#currentTurn is called") {
            REQUIRE(Rules::currentTurn(played_board) == X);
        }
    }

    GIVEN("A board grid with X,O,X on 1,2,3 respective") {
        std::vector<std::string> new_board = { X ,  O ,  X ,
                                              " ", " ", " ",
                                              " ", " ", " "};
        Board played_board(new_board);
        WHEN("#switchTurn is called") {
            REQUIRE(Rules::switchTurn(played_board) == O);
        }
        WHEN("#currentTurn is called") {
            REQUIRE(Rules::currentTurn(played_board) == X);
        }
    }
}

SCENARIO ("Rules: Validating Game Results", "[rules-result]") {
    GIVEN("A 3X3 board") {
        WHEN("WINNING_SLOTS") {
            THEN("represents a vector of vectors of all indices of winning") {
                std::vector< std::vector<int>> EXPECTED_WINNING_SLOTS = {{1,2,3},
                                                                         {4,5,6},
                                                                         {7,8,9},
                                                                         {1,4,7},
                                                                         {2,5,8},
                                                                         {3,6,9},
                                                                         {1,5,9},
                                                                         {3,5,7}};
                REQUIRE(Rules::WINNING_SLOTS == EXPECTED_WINNING_SLOTS);
            }
        }
    }

    GIVEN("An empty board") {
        Board board(9);
        WHEN("hasWinner is called") {
            THEN("return false") {
                REQUIRE(Rules::hasWinner(board) == false);
            }
        }
    }

    GIVEN("A board with a winner on the first row") {
        std::vector<std::string> x_win_grid = { X ,  X ,  X ,
                                               " ", " ", " ",
                                               " ", " ", " "};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(Rules::hasWinner(x_win_board) == true);
            }
        }
    }

    GIVEN("A board with a winner on the second row") {
        std::vector<std::string> x_win_grid = {" ", " ", " ",
                                                X ,  X ,  X ,
                                               " ", " ", " "};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(Rules::hasWinner(x_win_board) == true);
            }
        }
    }

    GIVEN("A board with a winner on the third row") {
        std::vector<std::string> x_win_grid = {" ", " ", " ",
                                               " ", " ", " ",
                                                X ,  X ,  X };
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(Rules::hasWinner(x_win_board) == true);
            }
        }
    }

    GIVEN("A board with a winner on the first column") {
        std::vector<std::string> x_win_grid = {X, " ", " ",
                                               X, " ", " ",
                                               X, " ", " "};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(Rules::hasWinner(x_win_board) == true);
            }
        }
    }

    GIVEN("A board with a winner on the second column") {
        std::vector<std::string> x_win_grid = {" ", X, " ",
                                               " ", X, " ",
                                               " ", X, " "};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(Rules::hasWinner(x_win_board) == true);
            }
        }
    }

    GIVEN("A board with a winner on the third column") {
        std::vector<std::string> x_win_grid = {" ", " ", X,
                                               " ", " ", X,
                                               " ", " ", X};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(Rules::hasWinner(x_win_board) == true);
            }
        }
    }

    GIVEN("A board with a winner on the top right to bottom left diagonal") {
        std::vector<std::string> x_win_grid = { X , " ", " ",
                                               " ",  X , " ",
                                               " ", " ",  X};
        Board x_win_board(x_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(Rules::hasWinner(x_win_board) == true);
            }
        }

        WHEN("getWinner is called") {
            THEN("return X") {
                REQUIRE(Rules::getResult(x_win_board) == "X wins!\n");
            }
        }
    }

    GIVEN("A board with a winner on the top right to bottom left diagonal") {
        std::vector<std::string> o_win_grid = { O , " ", " ",
                                               " ",  O , " ",
                                               " ", " ",  O};
        Board o_win_board(o_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(Rules::hasWinner(o_win_board) == true);
            }
        }

        WHEN("getResult is called") {
            THEN("return O") {
                REQUIRE(Rules::getResult(o_win_board) == "O wins!\n");
            }
        }
    }

    GIVEN("A board with one move a way from a win") {
        std::vector<std::string> x_close_to_win_grid = { X,  " ",  X ,
                                                       " ", " ", " ",
                                                       " ", " ", " "};
        Board no_winner_board(x_close_to_win_grid);
        WHEN("hasWinner is called") {
            THEN("return true") {
                REQUIRE(Rules::hasWinner(no_winner_board) ==  false);
            }
        }

        WHEN("getResult is called") {
            THEN("return O") {
                REQUIRE(Rules::getResult(no_winner_board) == "O's turn to move...\n\n");
            }
        }
    }

    GIVEN("A board with a draw") {
        std::vector<std::string> draw_grid = { X, O, X ,
                                               O, X, O,
                                               O, X, O};
        Board draw_board(draw_grid);
        WHEN("isDraw is called") {
            THEN("return true") {
                REQUIRE(Rules::isDraw(draw_board) == true);
            }
        }

        WHEN("isOver is called") {
            THEN("return true") {
                REQUIRE(Rules::isOver(draw_board) == true);
            }
        }

        WHEN("getResult is called") {
            THEN("return ") {
                REQUIRE(Rules::getResult(draw_board) == "Its a draw!\n");
            }
        }
    }

    GIVEN("A board with an empty slot on the grid") {
        std::vector<std::string> ongoing_grid = {X,  O , X,
                                                 O, " ", O,
                                                 O,  X , O};
        Board active_board(ongoing_grid);
        WHEN("isDraw is called") {
            THEN("return false") {
                REQUIRE(Rules::isDraw(active_board) == false);
            }
        }

        WHEN("isOver is called") {
            THEN("return false") {
                REQUIRE(Rules::isOver(active_board) == false);
            }
        }
    }

    GIVEN("A board with a winner") {
        std::vector<std::string> x_win_grid = { X, O, X,
                                                X, O, O,
                                                X, X, O};
        Board x_win_board(x_win_grid);
        WHEN("isDraw is called") {
            THEN("return false") {
                REQUIRE(Rules::isDraw(x_win_board) == false);
            }
        }

        WHEN("isOver is called") {
            THEN("return true") {
                REQUIRE(Rules::isOver(x_win_board) == true);
            }
        }
    }
};
