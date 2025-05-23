//
// Created by Jami Lashua on 2/19/25.
//

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece {
public:
    Knight(bool isWhite, const string& position) : Piece(isWhite, position) {}
    bool isMoveValid(const std::string& toPosition) const override; // No inline definition
    bool move(std::string& toPosition) override;
    PieceType getType() const override { return PieceType::KNIGHT; }
};

#endif //KNIGHT_H
