//
// Created by Jami Lashua on 1/30/25.
//
#include "Pawn.h"
#include "Piece.h"
using namespace std;

//constructor for pawn
Pawn::Pawn(bool white, string pos) : Piece(white, pos) {
    type = PAWN;
}
//Implementing move function for pawn
bool Pawn::move(string& toPosition) {
    int fileDiff = toPosition[0] - position[0]; //difference in file
    int rankDiff = toPosition[1] - position[1]; //difference in rank

    if (isWhite) {
        if ((rankDiff == 1 && fileDiff == 0) || (rankDiff == 1 && abs(fileDiff) == 1)) {
            return true;
        }
    } else {
        if ((rankDiff == -1 && fileDiff == 0) || (rankDiff == -2 && fileDiff == 0 && position[1] == '7')) {
            return true; //if move is valid
        }
    }
    if (abs(fileDiff) == 1 && rankDiff == (isWhite ? 1 : -1)) {
        return true; //valid capture
    }
    return false; //invalid move
}
//Getter for type of piece

//Implementing isMoveValid function for pawn
bool Pawn::isMoveValid(const std::string& toPosition) const {
    int fileDiff = toPosition[0] - position[0];
    int rankDiff = toPosition[1] - position[1];

    // Allow white pawns to move up (rank +1) and black pawns to move down (rank -1)
    if (isWhite) {
        if ((rankDiff == 1 && fileDiff == 0) ||
            (rankDiff == 2 && fileDiff == 0 && position[1] == '2')) { // White starts at rank 2
            return true;
            }
    } else {
        if ((rankDiff == -1 && fileDiff == 0) ||
            (rankDiff == -2 && fileDiff == 0 && position[1] == '7')) { // Black starts at rank 7
            return true;
            }
    }
    return false;
}
