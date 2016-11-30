//
//  board.cpp
//  GameOfLife
//
//  Created by Jared Goddard on 11/7/16.
//  Copyright © 2016 Jared. All rights reserved.
//

#include "board.hpp"

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void Board :: buildBoard(Board& board) {
    cout << "input board size: ";
    cin >> board.boardSize;
    //printf("Building board with size: %d, and %d rows\n", board.boardSize, int(sqrt(board.boardSize)));
    //for(vector<int>::iterator i = board.boardValues.begin(); i != board.boardValues.end(); ++i) {
}

int Board :: getBoardSize(Board& board) {
    //cout << "boardValues.size() at getBoardSize: " << board.boardValues.size() << " board.boardSize: " << board.boardSize << " ***\n";
    return int(board.boardValues.size());
}

void Board :: fillBoard(Board& board) {
    cout << "Filling board\n";
    for(int i=0; i<board.boardSize; i++) {
        int randNum = rand() % 2;
        board.boardValues.push_back(randNum);
        if(i > board.boardSize) {
            throw "Infinite loop";
        }
    }
}

void Board :: printBoard(Board& board) {
    int boardSize = board.getBoardSize(board);
    for(int i=0; i<boardSize; i++) {
        cout << board.boardValues[i] << " ";
        if(int(i+1) % int(sqrt(boardSize)) == 0) {
            cout << "\n";
        }
    }
    if(sqrt(boardSize)*sqrt(boardSize) != boardSize) {
        throw "Invalid board size";
    }
}

int Board :: countAliveCells(Board& board) {
    int aliveCellCount = 0;
    for(int i=0; i<board.boardSize; i++) {
        if(board.boardValues[i] == 1) {
            aliveCellCount+=1;
        }
    }
    if(aliveCellCount <= 0) {
        throw "Error. Board is Dead, mismatch.";
    }
    printf("Total alive cells on board: %d\n", aliveCellCount);
    return aliveCellCount;
}

bool Board :: checkAlive(Board& board, int loc) {
    //board.boardValues[loc] == 1 ? : return true : return false;
    if(board.boardValues[loc] == 1) {
        return true;
    } else {
        return false;
    }
}

int Board :: countAliveNeighbors(Board& board, int loc) {
    int aliveNeighborCount = 0;
    int sq = int(sqrt(board.boardSize));
    //printf("Counting alive cells for location: %d\n", loc);
    /*
     1 1 1
     0 1 0
     0 0 1
     try
     loc-sq-1 loc-sq loc-sq+1
     loc-1    loc    loc+1
     loc+sq-1 loc+sq loc+sq+1
     catch
     */
    /*for(int i=-1; i<2; i++) {
        //if(board.boardValues[loc-sq+i] == NULL) {
            
        //}
        if(board.boardValues[loc-sq+i] == 1 && loc-sq+i != loc+1 && loc-sq+i != loc-1 && loc-sq+i != loc) {
            aliveNeighborCount+=1;
            printf("Alive neighbor location1: %d, i: %d\n", (loc-sq+i), i);
        }
        if(board.boardValues[loc+sq+i] == 1 && loc+sq+i != loc+1 && loc+sq+i != loc-1 && loc+sq+i != loc && loc+sq+i != loc-sq+i) {
            aliveNeighborCount+=1;
            printf("Alive neighbor location4: %d, i: %d\n", (loc+sq+i), i);
        }
     }
    
     if(board.boardValues[loc+1] == 1) {
     aliveNeighborCount+=1;
     printf("Alive neighbor location2: %d\n", (loc+1));
     }
     if(board.boardValues[loc-1] == 1) {
     aliveNeighborCount+=1;
     printf("Alive neighbor location3: %d\n", (loc-1));
     }*/
    
    // ***************
    // TODO: make this better
    // ***************
    // left
    if(loc == 0) {
        //loc is upper left corner
        if(board.checkAlive(board, loc+1) == 1) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc+sq) == 1) {
            aliveNeighborCount++;
        }
    }
    else if(loc == board.boardSize-sq) {
        //loc is lower left corner
        if(board.checkAlive(board, loc-sq)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc+1)) {
            aliveNeighborCount++;
        }
    }
    else if(loc%sq == 0 && loc != 0 && loc != board.boardSize-sq-1) {
        //loc is a left edge
        if(board.checkAlive(board, loc-sq)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc-sq+1)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc+1)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc+sq)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc+sq+1)) {
            aliveNeighborCount++;
        }
    }
    // right
    else if(loc+1-sq == 0) {
        //loc is upper right corner
        if(board.checkAlive(board, loc-1)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc+sq)) {
            aliveNeighborCount++;
        }
    }
    else if(loc == board.boardSize-1) {
        //loc is lower right corner
        if(board.checkAlive(board, loc-sq)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc-1)) {
            aliveNeighborCount++;
        }
        
    }
    else if((loc+1)%sq == 0) {
        //loc is a right edge
        if(board.checkAlive(board, loc-sq)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc-sq-1)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc-1)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc+sq)) {
            aliveNeighborCount++;
        }
        if(board.checkAlive(board, loc+sq-1)) {
            aliveNeighborCount++;
        }
    } else {
        //loc isn't on an edge
        for(int i=-1; i<2; i++) {
            //if(board.boardValues[loc-sq+i] == NULL) {
            
            //}
            if(board.boardValues[loc-sq+i] == 1 /*&& loc-sq+i != loc+1 && loc-sq+i != loc-1 && loc-sq+i != loc*/) {
                aliveNeighborCount+=1;
                //printf("Alive neighbor location1: %d, i: %d\n", (loc-sq+i), i);
            }
            if(board.boardValues[loc+sq+i] == 1 /*&& loc+sq+i != loc+1 && loc+sq+i != loc-1 && loc+sq+i != loc && loc+sq+i != loc-sq+i*/) {
                aliveNeighborCount+=1;
                //printf("Alive neighbor location4: %d, i: %d\n", (loc+sq+i), i);
            }
            if(board.checkAlive(board, loc-1)) {
                aliveNeighborCount++;
            }
            if(board.checkAlive(board, loc+1)) {
                aliveNeighborCount++;
            }
        }
    }
    
    /*if(board.boardValues[loc] == 1) {
        aliveNeighborCount++;
    }*/
    printf("Alive neighbors for cell %d: %d\n", loc, aliveNeighborCount);
    return aliveNeighborCount;
}













