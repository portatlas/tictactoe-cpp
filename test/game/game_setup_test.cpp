#include "../../lib/catch.hpp"
#include "../../src/game/game_setup.hpp"

SCENARIO("GameSetup") {
    GameSetup gamesetup;
    Console console;
    Rules rules;

    GIVEN("A user wants to set a player as a computer") {
        WHEN("#setPlayer is called and user inputs c") {
            THEN("return a computer player") {
                std::cout.rdbuf(nullptr);
                std::istringstream new_input("c");
                std::cin.rdbuf(new_input.rdbuf());
                Player* actualPlayer1 = gamesetup.setPlayer(console, rules, X);
                Player* expectedPlayer = new ComputerPlayer(O, rules);
                REQUIRE(typeid(actualPlayer1).name() == typeid(expectedPlayer).name());
            }
        }
    }

    GIVEN("A user wants set a player as a human") {
        WHEN("#setPlayer is called and user inputs h") {
            THEN("returns a humany player") {
                std::cout.rdbuf(nullptr);
                std::istringstream new_input("h");
                std::cin.rdbuf(new_input.rdbuf());
                Player* actualPlayer2 = gamesetup.setPlayer(console, rules, O);
                Player* expectedPlayer = new HumanPlayer(rules, console);
                REQUIRE(typeid(actualPlayer2).name() == typeid(expectedPlayer).name());
            }
        }
    }

    GIVEN("A user wants to play a game") {
        WHEN("#willPlay is called and user inputs y") {
            THEN("return true") {
                std::cout.rdbuf(nullptr);
                std::istringstream new_input("y");
                std::cin.rdbuf(new_input.rdbuf());
                REQUIRE(gamesetup.willPlay(console) == true);
            }
        }
    }

    GIVEN("A user does not wants to play a game") {
        WHEN("#willPlay is called and user inputs n") {
            THEN("return false") {
                std::cout.rdbuf(nullptr);
                std::istringstream new_input("n");
                std::cin.rdbuf(new_input.rdbuf());
                REQUIRE(gamesetup.willPlay(console) == false);
            }
        }
    }
}