//
// Created by Jami Lashua on 2/19/25.
//

#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen : public Piece {
public:
    Queen(bool isWhite, const string& position) : Piece(isWhite, position) {}
    bool isMoveValid(const std::string& toPosition) const override;
    bool move(std::string& toPosition) override;
    PieceType getType() const override { return PieceType::QUEEN; }
};
#endif //QUEEN_H
