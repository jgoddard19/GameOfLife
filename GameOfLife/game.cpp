//
//  main.cpp
//  GameOfLife
//
//  Created by Jared Goddard on 11/3/16.
//  Copyright © 2016 Jared. All rights reserved.
//

#include "catch.hpp"
#include "game.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

Board Game :: nextGen(Board& board) {
    Board nextGenBoard = board;
    int aliveNeighbors = 0;
    vector<int> flagged;
    //**** bug checking print statement
    //printf("Generating nextGenBoard, size: %d\n", nextGenBoard.boardSize);
    
    //loop through board and flag cells that should live/die for the next generation
    for(int i=0; i<nextGenBoard.boardSize; i++) {
        if(nextGenBoard.checkAlive(nextGenBoard, i)) {
            //cell is alive
            aliveNeighbors = nextGenBoard.countAliveNeighbors(nextGenBoard, i);
            if(aliveNeighbors < 2) {
                //cell should die
                //printf("cell %d flagged\n", i);
                flagged.push_back(i);
            }
            else if(aliveNeighbors == 2 || aliveNeighbors == 3) {
                //cell should live
            }
            else if(aliveNeighbors > 3) {
                //cell should die
                //printf("cell %d flagged\n", i);
                flagged.push_back(i);
            }
        } else {
            //cell is dead
            //printf("cell %d flagged\n", i);
            flagged.push_back(i);
        }
    }
    
    //kill/birth cells for new generation
    for(int i=0; i<flagged.size(); i++) {
        if(board.boardValues[flagged[i]] == 0) {
            nextGenBoard.boardValues[flagged[i]] = 1;
        }
        else if(board.boardValues[flagged[i]] == 1) {
            nextGenBoard.boardValues[flagged[i]] = 0;
        }
    }
    
    return nextGenBoard;
}

int Game :: getGenCount() {
    int genCount;
    cout << "Input how many generations to advance: ";
    cin >> genCount;
    return genCount;
}

Board Game :: runGens(Board& board, int genCount) {
    Board nextGenBoard;
    cout << "------------\n";
    cout << "Starting board:\n";
    board.printBoard(board);
    for(int i=0; i<genCount; i++) {
        nextGenBoard = nextGen(board);
        if(nextGenBoard.countAliveCells(nextGenBoard) == 0) {
            cout << "All cells died\n";
            i = genCount-1;
        }
        board = nextGenBoard;
        cout << "------------\n";
        if(i == genCount-1) {
            cout << "Final board:\n";
        }
        board.printBoard(nextGenBoard);
    }
    cout << "------------\n";
    return nextGenBoard;
}











