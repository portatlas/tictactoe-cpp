#include "console.hpp"

void Console::display(ostream& output, string message) {
    output << message;
};

string Console::retrieve(istream& is) {
    string input = " ";
    is >> input;
    return input;
};
