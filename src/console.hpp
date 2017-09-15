#ifndef TICTACTOE_CPP_CONSOLE_H
#define TICTACTOE_CPP_CONSOLE_H

#include <iostream>

using namespace std;

class Console {
    public:
        static void display(ostream& output, string message);
        static string retrieve(istream& is);
};

#endif
