#include "../lib/catch.hpp"
#include "../src/console.hpp"

SCENARIO ("Console") {
    Console console;
    GIVEN("A message") {
        std::string message = "hi";
        WHEN("#display is called") {
            THEN("the message is passed to the console") {
                std::ostringstream out;
                std::streambuf *sbuf = std::cout.rdbuf();
                std::cout.rdbuf(out.rdbuf());
                console.display("hello");
                std::cout.rdbuf(sbuf);
                REQUIRE(out.str() == "hello");
            }
        }
    }

    GIVEN("A prompt") {
        WHEN("#retrieve is called") {
            THEN("return the input provided by the user") {
                std::streambuf* orig = std::cin.rdbuf();
                std::istringstream input("Y");
                std::cin.rdbuf(input.rdbuf());
                REQUIRE(console.retrieve() == "Y");
                std::cin.rdbuf(orig);
            }
        }
    }
}
