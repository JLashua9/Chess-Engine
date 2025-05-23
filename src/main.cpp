//
// Created by Jami Lashua on 1/28/25.
//
#include <ostream>
#include "board.h"
using namespace std;

int main() {
    Board board;
    board.initializeBoard();
    while (!board.isGameOver()) {
        board.printBoard();
        string from, to;
        cout << "Enter move: ";
        cin >> from >> to;
        if (board.movePiece(from, to)) {
            cout << "Move successful\n";
        } else {
            cout << "Invalid move, try again\n";
        }
    }
    cout << "Game over\n";
    return 0;
}

