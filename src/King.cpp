//
// Created by Jami Lashua on 2/19/25.
//
#include "King.h"
using namespace std;

bool King::isMoveValid(const string& toPosition)const {
    //implement king move logic
    //king can move any direction, 1 square
    int fileDiff = abs(position[0] - toPosition[0]);
    int rankDiff = abs(position[1] - toPosition[1]);
    if (fileDiff <= 1 && rankDiff <= 1) {
        return true;
    }
    return false;
}

bool King::move(std::string& toPosition) {
    if (isMoveValid(toPosition)) {
        setPosition(toPosition);
        return true;
    }
    return false;
}