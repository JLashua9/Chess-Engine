//
// Created by Jami Lashua on 2/19/25.
//

#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece {
public:
    King(bool isWhite, const std::string& position) : Piece(isWhite, position) {}
    bool isMoveValid(const std::string& toPosition) const override;
    bool move(std::string& toPosition) override;
    PieceType getType() const override { return KING; };
};
#endif //KING_H
