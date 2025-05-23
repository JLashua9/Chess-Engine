cmake_minimum_required(VERSION 3.10)  # Specify the minimum version of CMake required

# Set the project name and version
project(Chess VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Automatically add all source files from the src directory
file(GLOB SOURCES "src/*.cpp")

# Add executable that will be built from the provided source files
add_executable(ChessGame
        src/main.cpp
        src/Piece.cpp
        src/Board.cpp
        src/Chess.cpp
        include/Piece.h
        include/Enums.h
        include/Chess.h
        include/Board.h
        src/Pawn.cpp
        include/Pawn.h
        include/Rook.h
        include/Knight.h
        include/Bishop.h
        include/Queen.h
        include/King.h
        include/King.h
        src/Rook.cpp
        src/Knight.cpp
        src/Queen.cpp
        src/King.cpp
        src/Bishop.cpp
)