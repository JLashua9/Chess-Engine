//
// Created by Jami Lashua on 2/20/25.
//
#include "Bishop.h"

bool Bishop::isMoveValid(const string& toPosition) const {
    // Implement Bishop-specific move validation logic
    // Bishop moves diagonally any number of squares
    int fileDiff = abs(position[0] - toPosition[0]);
    int rankDiff = abs(position[1] - toPosition[1]);
    if (fileDiff == rankDiff) {
        return true;
    }
    return false;
}
bool Bishop::move(std::string& toPosition) {
    if (isMoveValid(toPosition)) {
        setPosition(toPosition);
        return true;
    }
    return false;
}
