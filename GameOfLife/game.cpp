//
//  main.cpp
//  GameOfLife
//
//  Created by Jared Goddard on 11/3/16.
//  Copyright © 2016 Jared. All rights reserved.
//

#include "catch.hpp"
#include "game.hpp"
using namespace std;

unsigned int Game :: Factorial( unsigned int number ) {
    return number > 1 ? Factorial(number-1)*number : 1;
}

Board Game :: nextGen(Board& board) {
    Board nextGenBoard = board;
    int aliveNeighbors = 0;
    //printf("Generating nextGenBoard, size: %d\n", nextGenBoard.boardSize);
    for(int i=0; i<nextGenBoard.boardSize; i++) {
        if(nextGenBoard.boardValues[i] == 1) {
            aliveNeighbors = nextGenBoard.countAliveNeighbors(nextGenBoard, i);
        }
    }
    return nextGenBoard;
}
