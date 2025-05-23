# Chess Game (CS 2300 Module 2 OEP)

## Author

Jami Lashua

## Summary

This is a simple Chess game in C++. Two players take turns entering their moves (like `A2 A4`) in the console. The code checks if each move is valid (e.g., within the board limits, not capturing your own piece, etc.) and continues until a checkmate or stalemate. Main features include:

- A `Piece` base class with derived classes (`Pawn`, `Knight`, `Bishop`, `Rook`, `Queen`, `King`).
- A `Board` class that stores piece objects in a map, handles turn-taking, checks for game-ending conditions.
- A minimal console interface were players enter moves each turn.

## Module 2 Concepts Used

1. **Inheritance (Is-A Relationship)**
    - Each chess piece class inherits from the `Piece` class. They override `isMoveValid()` and `move()` to enforcing movement rules.
2. **Composition (Has-A Relationship)**
    - The `Board` class holds all the pieces in a single `std::map`, organizing them by position.

## Known Bugs / Limitations

- Special moves like **castling** and **en passant** are not implemented.
- The function `isStalemate()` always returns true.
- Input validation is basic; users need to ensure they type valid moves.

## Future Work

- Fully implement castling, en passant, and pawn promotion.
- Improve input validation to handle incorrect entries more gracefully.
- Implement a simple AI for single-player mode
- Fix the stalemate detection logic.

## Grade Justification

- **Main Program (30/40)**: It has an interactive loop, uses inheritance for different pieces, checks moves, and ends the game at checkmate or stalemate. Input validation is present but minimal.
- **Inheritance Relationship (20/20)**: The `Piece` base class and derived classes are used effectively.
- **Style & Documentation (0 pts deducted)**: Code is fairly organized and commented.

**Est. Total**: 5*0 pts*

