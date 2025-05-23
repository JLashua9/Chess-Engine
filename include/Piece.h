#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
using namespace std;

enum PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

enum Color {
    WHITE,
    BLACK
};

class Piece {
protected:
    Color color; // Color of the piece White or Black
    string position; // Current position of the piece on the board
    PieceType type; // Type of piece
    bool isWhite; // True if white, false if black

public:
    Piece(bool white, string pos) : color(white ? WHITE : BLACK), position(pos) {} // Constructor for pieces;

    Piece(Color color, string startPositon, PieceType type); // Constructor for pieces

    virtual bool move(string& toPosition) = 0;

    virtual bool isMoveValid(const string& toPosition) const  = 0;

    virtual ~Piece() = default;

    string getPosition() const;

    virtual PieceType getType() const = 0;

    void setPosition(const string &newPosition);

    bool isWhitePiece() const;

    bool isMoveInBounds(const string &toPosition);
    bool isWhiteColor() const { return isWhite; }

    friend ostream &operator<<(ostream &os, const Piece &piece);
};

#endif // PIECE_H
