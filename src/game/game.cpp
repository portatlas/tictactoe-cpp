#include "game.hpp"

std::string Game::play(Board board,
                       Rules &rules,
                       Player *player1,
                       Player *player2,
                       Console &console) {

    if (rules.isOver(board)) {
        return rules.getResult(board);
    }

    if(rules.switchTurn(board) == X) {
        int move = player1 -> getMove(board);
        board.fillSlot(move, X);
    } else {
        int move = player2 -> getMove(board);
        board.fillSlot(move, O);
    }
    renderBoard(console, board);
    renderText(console, board, rules);

    return play(board, rules, player1, player2, console);
}

void Game::renderBoard(Console &console, Board board) {
    console.display(BoardFormatter::format(board));
}

void Game::renderText(Console &console, Board board, Rules rules) {
    console.display(rules.getResult(board));
}
