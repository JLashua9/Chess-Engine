//
// Created by Jami Lashua on 2/19/25.
//
#include "Piece.h"
#include "Knight.h"
using namespace std;

bool Knight::isMoveValid(const string& toPosition) const {
    //Implement knight move logic
    //knights can move in L shape: two squares in one direction and one square perpendicular
    int fileDiff = abs(position[0] - toPosition[0]);
    int rankDiff = abs(position[1] - toPosition[1]);
    if ((fileDiff == 2 && rankDiff == 1) || (fileDiff == 1 && rankDiff == 2)) {
        return true;
    }
    return false;
}
bool Knight::move(std::string& toPosition) {
    if (isMoveValid(toPosition)) {
        setPosition(toPosition);
        return true;
    }
    return false;
}