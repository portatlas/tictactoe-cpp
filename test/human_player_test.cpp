#include "../lib/catch.hpp"
#include "../src/human_player.hpp"

SCENARIO ("Human Player") {
    GIVEN("The rules and a console ui") {
        Console console;
        Rules rules;
        HumanPlayer humanplayer;

        WHEN("#getMove is passed an empty board and the user inputs 1") {
            Board board(9);
            THEN("return 1 as an int") {
                std::istringstream input("1");
                std::cin.rdbuf(input.rdbuf());
                REQUIRE(humanplayer.getMove(board, rules, console) == 1);
            }
        }

        WHEN("#getMove is passed an empty board and the user inputs 10") {
            Board board(9);
            std::istringstream input("10");
            std::cin.rdbuf(input.rdbuf());
            THEN("require the user to enter a valid input") {
                AND_WHEN("the user enters a valid input") {
                    std::istringstream new_input("1");
                    std::cin.rdbuf(new_input.rdbuf());
                    THEN("return 1 as an int") {
                        REQUIRE(humanplayer.getMove(board, rules, console) == 1);
                    }
                }
            }
        }

        WHEN("#getMove is passed an empty board and the user inputs A") {
            std::vector<std::string> marked_grid = {X,  O , X,
                                                    O, " ", O,
                                                    O,  X , O};
            Board board(marked_grid);
            std::istringstream input("1");
            std::cin.rdbuf(input.rdbuf());
            THEN("require the user to enter a valid input") {
                AND_WHEN("the user enters a valid input") {
                    std::istringstream new_input("5");
                    std::cin.rdbuf(new_input.rdbuf());
                    THEN("return 1 as an int") {
                        REQUIRE(humanplayer.getMove(board, rules, console) == 5);
                    }
                }
            }
        }
    }
}
