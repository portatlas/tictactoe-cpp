#include "../../lib/catch.hpp"
#include "../../src/game/game_setup.hpp"

SCENARIO("GameSetup") {
    GameSetup gamesetup;
    Console console;
    Rules rules;

    GIVEN("A user wants to play a computer") {
        WHEN("#getOpponent is called and user inputs c") {
            THEN("return true") {
                std::cout.rdbuf(nullptr);
                std::istringstream new_input("c");
                std::cin.rdbuf(new_input.rdbuf());
                Player* actualPlayer = gamesetup.getOpponent(console, rules);
                Player* expectedPlayer = new ComputerPlayer(rules);
                REQUIRE(typeid(actualPlayer).name() == typeid(expectedPlayer).name());
            }
        }
    }

    GIVEN("A user wants to play a human") {
        WHEN("#getOpponent is called and user inputs h") {
            THEN("return true") {
                std::cout.rdbuf(nullptr);
                std::istringstream new_input("h");
                std::cin.rdbuf(new_input.rdbuf());
                Player* actualPlayer = gamesetup.getOpponent(console, rules);
                Player* expectedPlayer = new HumanPlayer(rules, console);
                REQUIRE(typeid(actualPlayer).name() == typeid(expectedPlayer).name());
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
            THEN("return true") {
                std::cout.rdbuf(nullptr);
                std::istringstream new_input("n");
                std::cin.rdbuf(new_input.rdbuf());
                REQUIRE(gamesetup.willPlay(console) == false);
            }
        }
    }
}