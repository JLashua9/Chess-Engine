//
// Created by Jami Lashua on 1/30/25.
//
#include "Piece.h"
#ifndef PAWN_H
#define PAWN_H
using namespace std;
//class pawn inherits from class Piece
class Pawn : public Piece {
public:
    Pawn(bool white,string pos);
    bool isMoveValid(const std::string& toPosition) const override; // No inline definition
    bool move(std::string& toPosition) override;
    PieceType getType() const override { return PieceType::PAWN; }
private:
};



#endif //PAWN_H
