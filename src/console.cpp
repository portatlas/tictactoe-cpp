#include "console.hpp"

void Console::display(std::string message) {
    std::cout << message;
};

std::string Console::retrieve() {
    std::string input = " ";
    std::cin >> input;
    return input;
};
