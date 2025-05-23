#include "Piece.h"
#include <string>
#include <cctype>


#include <map>
using namespace std;

// Constructor implementation
Piece::Piece(Color color, string startPosition, PieceType type)
    : color(color), position(startPosition), type(type), isWhite(color == WHITE) {
    // Constructor body - initializes the piece with its color and starting position
}
// Implementation of the isMoveInBounds function checking to see if the move is within the bounds of the board
bool Piece::isMoveInBounds(const std::string& toPosition) {
    if (toPosition.length() != 2) return false;

    char file = std::toupper(toPosition[0]);  // Normalize to uppercase
    char rank = toPosition[1];

    return (file >= 'A' && file <= 'H') && (rank >= '1' && rank <= '8');
}

// Virtual destructor implementation
//Piece::~Piece() {}

//getter for piece color
bool Piece::isWhitePiece() const {
    return isWhite; //True if white, false if black
}

//getter for piece position
std::string Piece::getPosition() const {
    return position; // Returns cuurent board position of piece
}

//setter for piece position
void Piece::setPosition(const std::string& newPosition) {
    position = newPosition; // Sets new position of piece
}

//Overloaded operator for printing piece information
std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    static const std::map<PieceType, char> symbols = {
        {PAWN, 'P'},
        {ROOK, 'R'},
        {KNIGHT, 'N'},
        {BISHOP, 'B'},
        {QUEEN, 'Q'},
        {KING, 'K'}
    };
    char pieceSymbol = symbols.at(piece.type);
    if (!piece.isWhite) {
        pieceSymbol = std::tolower(pieceSymbol);
    }
    os << pieceSymbol;
    return os;
}





