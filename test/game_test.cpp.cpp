#include "../lib/catch.hpp"
#include "../src/game.hpp"

SCENARIO("Game") {
    Game game;
    Console console;
    Rules rules;
    HumanPlayer player1;
    HumanPlayer player2;

    GIVEN("A board with X as a winner") {
        std::vector<std::string> x_win_grid = {  X ,  X ,  X ,
                                                " ", " ", " ",
                                                " ", " ", " "};
        Board x_wins_board(x_win_grid);
        WHEN("#play is called") {
            THEN("return X wins!") {
                REQUIRE(game.play(x_wins_board, rules, player1, player2, console) == "X wins!\n");
            }
        }
    }

    GIVEN("A board with a draw") {
        std::vector<std::string> draw_grid = { X, O, X,
                                               O, X, O,
                                               O, X, O};
        Board draw_board(draw_grid);
        WHEN("#play is called") {
            THEN("return X wins!") {
                REQUIRE(game.play(draw_board, rules, player1, player2, console) == "Its a draw!\n");
            }
        }
    }

    GIVEN("A board with empty slots") {
        std::vector<std::string> active_grid = { X , " ",  X ,
                                                 O , " ", " ",
                                                 O , " ", " "};
        Board active_board(active_grid);
        WHEN("#play is called") {
            AND_WHEN("player1 enters 2") {
                std::stringstream buffer;
                std::streambuf *sbuf = std::cout.rdbuf();
                std::cout.rdbuf(buffer.rdbuf());
                std::istringstream input("2");
                std::cin.rdbuf(input.rdbuf());
                THEN("return X wins!") {
                    REQUIRE(game.play(active_board, rules, player1, player2, console) == "X wins!\n");
                    REQUIRE(buffer.str() == "X X X\n"
                                            "O 5 6\n"
                                            "O 8 9\n"
                                            "X wins!\n");
                }
                std::cout.rdbuf(sbuf);
            }
        }
    }
}
