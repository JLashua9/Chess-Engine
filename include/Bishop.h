//
// Created by Jami Lashua on 2/19/25.
//

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(bool isWhite, const string& position) : Piece(isWhite, position) {}
    bool isMoveValid(const std::string& toPosition) const override;
    bool move(std::string& toPosition) override;
    PieceType getType() const override { return PieceType::BISHOP; }
};
#endif //BISHOP_H
