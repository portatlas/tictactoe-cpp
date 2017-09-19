#include "../lib/catch.hpp"
#include "../src/console.hpp"

SCENARIO ("Console") {

    GIVEN("A message") {
        string message = "hi";
        WHEN("#display is called") {
            stringstream out;
            Console::display(out, message);
            THEN("the message is passed to an output stream") {
                REQUIRE("hi" == out.str());
            }
        }
    }

    GIVEN("A prompt") {
        WHEN("#retrieve is called") {
            THEN("return the input provided by the user") {
                istringstream iss("Y");
                REQUIRE("Y" == Console::retrieve(iss));
            }
        }
    }
}
