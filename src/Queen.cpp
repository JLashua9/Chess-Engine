//
// Created by Jami Lashua on 2/19/25.
//
#include "Queen.h"

bool Queen::isMoveValid(const string& toPosition) const {
    //implement Queen-specific move logic
    //Queen can move horizontally, vertically, or diagonally any number of squares
    int fileDiff = abs(position[0] - toPosition[0]);
    int rankDiff = abs(position[1] - toPosition[1]);
    if (position[0] == toPosition[0] || position[1] == toPosition[1] || fileDiff == rankDiff) {
        return true;
    }
    return false;
}
bool Queen::move(std::string& toPosition) {
    if (isMoveValid(toPosition)) {
        setPosition(toPosition);
        return true;
    }
    return false;
}