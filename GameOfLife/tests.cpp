//
//  tests1.cpp
//  GameOfLife
//
//  Created by Jared Goddard on 11/3/16.
//  Copyright © 2016 Jared. All rights reserved.
//

#include "catch.hpp"
#include "game.hpp"
#include "board.hpp"

#include <math.h>

Game game;
Board board;
Board nextGenBoard;

TEST_CASE( "board is valid", "[board]" ) {
    REQUIRE_NOTHROW(board.buildBoard(board));
}

TEST_CASE( "board populates", "[board]" ) {
    // check that fillBoard doesn't throw any exceptions
    REQUIRE_NOTHROW(board.fillBoard(board));
}

TEST_CASE( "board size is valid", "[board]" ) {
    int boardSize = board.getBoardSize(board);
    REQUIRE(boardSize == board.boardSize);
    // check that board has a size greater than 0, so no 0 and no negatives
    REQUIRE(boardSize > 0);
    // check that the board is square
    REQUIRE(sqrt(boardSize)*sqrt(boardSize) == boardSize);
}

/*TEST_CASE( "board prints", "[board]" ) {
    // check that printBoard doesn't throw any exceptions
    REQUIRE_NOTHROW(board.printBoard(board));
}*/

TEST_CASE( "make sure there are alive cells", "[board]" ) {
    REQUIRE_NOTHROW(board.countAliveCells(board));
}

TEST_CASE( "count neighbors runs", "[board]" ) {
    int boardSize = board.boardSize;
    int sq = sqrt(boardSize);
    //upper left corner
    REQUIRE_NOTHROW(board.countAliveNeighbors(board, 0));
    //lower left corner
    REQUIRE_NOTHROW(board.countAliveNeighbors(board, boardSize-sq));
    //upper right corner
    REQUIRE_NOTHROW(board.countAliveNeighbors(board, 0+sq-1));
    //lower right corner
    REQUIRE_NOTHROW(board.countAliveNeighbors(board, boardSize-1));
    if(boardSize > 4) {
        //left edge
        REQUIRE_NOTHROW(board.countAliveNeighbors(board, 0+sq));
        //right edge
        REQUIRE_NOTHROW(board.countAliveNeighbors(board, 0+sq+sq-1));
        //middle
        REQUIRE_NOTHROW(board.countAliveNeighbors(board, boardSize/2));
    }
}

TEST_CASE( "next generations", "[game]" ) {
    int genCount = game.getGenCount();
    Board nextGenBoard = game.runGens(board, genCount);
    REQUIRE(board.getBoardSize(nextGenBoard) == board.getBoardSize(board));
    
}

TEST_CASE( "test board", "[board]" ) {
    Game testGame;
    Board testBoard;
    testBoard.boardSize = 9;
    int boardSize = testBoard.boardSize;
    int sq = sqrt(boardSize);
    testBoard.boardValues = {1, 1, 0, 1, 1, 1, 0, 0, 0};
    //testBoard.printBoard(testBoard);
    REQUIRE(testBoard.countAliveCells(testBoard) == 5);
    REQUIRE(testBoard.countAliveNeighbors(testBoard, 0) == 3);
    REQUIRE(testBoard.countAliveNeighbors(testBoard, boardSize-sq) == 2);
    REQUIRE(testBoard.countAliveNeighbors(testBoard, 0+sq-1) == 3);
    REQUIRE(testBoard.countAliveNeighbors(testBoard, boardSize-1) == 2);
    if(boardSize > 4) {
        REQUIRE(testBoard.countAliveNeighbors(testBoard, 0+sq) == 3);
        REQUIRE(testBoard.countAliveNeighbors(testBoard, 0+sq+sq-1) == 2);
        REQUIRE(testBoard.countAliveNeighbors(testBoard, boardSize/2) == 4);
    }
}
