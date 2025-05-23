//
// Created by Jami Lashua on 1/28/25.
//
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

#include <iostream>
#include <utility>

using namespace std;

// Constructor
Board::Board() {
    isWhiteTurn = true;
    initializeBoard();
}

// Destructor
Board::~Board() {}

// Initialize board with starting positions
void Board::initializeBoard() {
    board.clear();

    // Initialize pawns
    for (char file = 'A'; file <= 'H'; file++) {
        board[string(1, file) + "2"] = std::make_unique<Pawn>(true, string(1, file) + "2");
        board[string(1, file) + "7"] = std::make_unique<Pawn>(false, string(1, file) + "7");
    }

    // Initialize rooks
    board["A1"] = std::make_unique<Rook>(true, "A1");
    board["H1"] = std::make_unique<Rook>(true, "H1");
    board["A8"] = std::make_unique<Rook>(false, "A8");
    board["H8"] = std::make_unique<Rook>(false, "H8");

    // Initialize knights
    board["B1"] = std::make_unique<Knight>(true, "B1");
    board["G1"] = std::make_unique<Knight>(true, "G1");
    board["B8"] = std::make_unique<Knight>(false, "B8");
    board["G8"] = std::make_unique<Knight>(false, "G8");

    // Initialize bishops
    board["C1"] = std::make_unique<Bishop>(true, "C1");
    board["F1"] = std::make_unique<Bishop>(true, "F1");
    board["C8"] = std::make_unique<Bishop>(false, "C8");
    board["F8"] = std::make_unique<Bishop>(false, "F8");

    // Initialize queens
    board["D1"] = std::make_unique<Queen>(true, "D1");
    board["D8"] = std::make_unique<Queen>(false, "D8");

    // Initialize kings
    board["E1"] = std::make_unique<King>(true, "E1");
    board["E8"] = std::make_unique<King>(false, "E8");
}

bool Board::isMoveValid(Piece* piece, const std::string& toPosition) const {
    if (!piece) {
        cout << "DEBUG: Invalid move - no piece at position\n";
        return false;
    }

    if (!piece->isMoveValid(toPosition)) {
        cout << "DEBUG: Invalid move - piece can't move to " << toPosition << endl;
        return false;
    }

    if (toPosition[0] < 'A' || toPosition[0] > 'H' || toPosition[1] < '1' || toPosition[1] > '8') {
        cout << "DEBUG: Invalid move - outside board limits\n";
        return false;
    }

    Piece* destination = getPieceAt(toPosition);
    if (destination && destination->isWhiteColor() == piece->isWhiteColor()) {
        cout << "DEBUG: Invalid move - same color piece at " << toPosition << endl;
        return false;
    }

    // Check if move leads to check
    Board tempBoard = clone();
    tempBoard.movePiece(piece->getPosition(), toPosition);
    if (tempBoard.isCheck(piece->isWhiteColor())) {
        cout << "DEBUG: Invalid move - leads to check\n";
        return false;
    }

    cout << "DEBUG: Valid move from " << piece->getPosition() << " to " << toPosition << endl;
    return true;
}



bool Board::movePiece(const std::string& fromPosition, const std::string& toPosition) {
    Piece* piece = getPieceAt(fromPosition);
    if (!piece || piece->isWhiteColor() != isWhiteTurn) return false;
    if (!isMoveValid(piece, toPosition)) return false;
    board[toPosition] = std::move(board[fromPosition]);
    board.erase(fromPosition);
    piece->setPosition(toPosition);
    isWhiteTurn = !isWhiteTurn;
    cout << "DEBUG: Move successful, turn changed to " << (isWhiteTurn ? "White" : "Black") << endl;
    return true;
}

// Print the board
void Board::printBoard() const {
    for (char rank = '8'; rank >= '1'; rank--) {
        for (char file = 'A'; file <= 'H'; file++) {
            string pos = string(1, file) + rank;
            Piece* piece = getPieceAt(pos);
            if (piece) {
                cout << piece->getType() << " ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

bool Board::isCheck(bool white) const {
    string kingPosition;
    for (const auto& entry : board) {
        if (entry.second && entry.second->isWhiteColor() == white &&
            entry.second->getType() == PieceType::KING) {
            kingPosition = entry.first;
            break;
            }
    }
    if (kingPosition.empty()) return false; // King not found, avoid invalid access

    for (const auto& entry : board) {
        if (entry.second && entry.second->isWhiteColor() != white &&
            entry.second->isMoveValid(kingPosition)) {
            return true;
            }
    }
    return false;
}

bool Board::isCheckMate(bool white) const {
    if (!isCheck(white)) {
        return false;
    }
    for (const auto& entry : board) {
        if (entry.second->isWhiteColor() == white) {
            string fromPosition = entry.first;
            for (char file = 'A'; file <= 'H'; file++) {
                for (char rank = '1'; rank <= '8'; rank++) {
                    string toPosition = string(1, file) + rank;
                    if (isMoveValid(entry.second.get(), toPosition)) {
                        auto tempBoard = clone();
                        tempBoard.movePiece(fromPosition, toPosition);
                        if (!tempBoard.isCheck(white)) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Board::isStalemate(bool white) const {
    cout << "DEBUG: entering isStalemate\n";
    if (isCheck(white)) return false;
    cout << "DEBUG: entering if\n";
    for (const auto& entry : board) {

        if (entry.second->isWhiteColor() == white) {
            string fromPosition = entry.first;
            cout << "DEBUG: Checking moves for piece at " << fromPosition << endl;
            for (char file = 'A'; file <= 'H'; file++) {
                for (char rank = '1'; rank <= '8'; rank++) {
                    string toPosition = string(1, file) + rank;


                    Board tempBoard = clone();  // Simulate move on cloned board
                    if (tempBoard.movePiece(fromPosition, toPosition)) {
                        cout << "DEBUG: Valid move found: " << fromPosition << " -> " << toPosition << endl;
                        return false;
                    }
                }
            }
        }
    }
    cout << "DEBUG: No valid moves, stalemate\n";
    return true;
}

bool Board::isGameOver() const {
        bool checkMate = isCheckMate(isWhiteTurn);
        bool stalemate = isStalemate(isWhiteTurn);
        cout << "DEBUG: isCheckMate=" << checkMate << ", isStalemate=" << stalemate << endl;
        return checkMate || stalemate;
}

Piece* Board::getPieceAt(const string& position) const {
    auto it = board.find(position);
    if (it != board.end()) {
        return it->second.get();
    }
    return nullptr;
}


Board Board::clone() const {
    Board clonedBoard;
    clonedBoard.isWhiteTurn = isWhiteTurn;

    for (const auto& [pos, piece] : board) {
        if (piece) {
            switch (piece->getType()) {
                case PieceType::PAWN:
                    clonedBoard.board[pos] = std::make_unique<Pawn>(*dynamic_cast<Pawn*>(piece.get()));
                break;
                case PieceType::ROOK:
                    clonedBoard.board[pos] = std::make_unique<Rook>(*dynamic_cast<Rook*>(piece.get()));
                break;
                case PieceType::KNIGHT:
                    clonedBoard.board[pos] = std::make_unique<Knight>(*dynamic_cast<Knight*>(piece.get()));
                break;
                case PieceType::BISHOP:
                    clonedBoard.board[pos] = std::make_unique<Bishop>(*dynamic_cast<Bishop*>(piece.get()));
                break;
                case PieceType::QUEEN:
                    clonedBoard.board[pos] = std::make_unique<Queen>(*dynamic_cast<Queen*>(piece.get()));
                break;
                case PieceType::KING:
                    clonedBoard.board[pos] = std::make_unique<King>(*dynamic_cast<King*>(piece.get()));
                break;
            }
        }
    }
    return clonedBoard;
}

