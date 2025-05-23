//
// Created by Jami Lashua on 2/19/25.
//
#include "Rook.h"
using namespace std;

bool Rook::isMoveValid(const string& toPosition) const {
    //impementing rook-specific move logic
    //Rooks can move horizontally or vertically any number of squares
    if (position[0] == toPosition[0] || position[1] == toPosition[1]) {
        return true;
    }
    return false;
}
bool Rook::move(std::string& toPosition) {
    if (isMoveValid(toPosition)) {
        setPosition(toPosition);
        return true;
    }
    return false;
}