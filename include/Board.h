#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <memory>
#include <string>
#include "Piece.h"

class Board {
public:
    Board();
    ~Board();


    Board(Board&& other) noexcept = default;
    Board& operator=(Board&& other) noexcept = default;


    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;

    void initializeBoard();
    bool isMoveValid(Piece* piece, const std::string& toPosition) const;
    bool movePiece(const std::string& fromPosition, const std::string& toPosition);
    void printBoard() const;
    bool isCheck(bool white) const;
    bool isCheckMate(bool white) const;
    bool isStalemate(bool white) const;
    bool isGameOver() const;
    Piece* getPieceAt(const std::string& position) const;
    Board clone() const;

private:
    std::map<std::string, std::unique_ptr<Piece>> board;
    bool isWhiteTurn;
};

#endif //BOARD_H