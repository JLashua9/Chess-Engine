//
// Created by Jami Lashua on 2/19/25.
//

#ifndef ROOK_H
#define ROOK_H
#include <string>
#include "Piece.h"

class Rook : public Piece {
public:
    // Constructor
    Rook(bool isWhite, const std::string& position) : Piece(isWhite, position) {}
    bool isMoveValid(const std::string& toPosition) const override;
    bool move(std::string& toPosition) override;
    PieceType getType() const override { return PieceType::ROOK; }
};

#endif //ROOK_H
