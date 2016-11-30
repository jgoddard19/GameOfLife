//
//  board.hpp
//  GameOfLife
//
//  Created by Jared Goddard on 11/7/16.
//  Copyright © 2016 Jared. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Board {
public:
    int boardSize;
    vector<int> boardValues;
    void buildBoard(Board& board);
    int getBoardSize(Board& board);
    void fillBoard(Board& board);
    void printBoard(Board& board);
    bool checkAlive(Board& board, int loc);
    int countAliveCells(Board& board);
    int countAliveNeighbors(Board& board, int loc);
};

// ideas:
/*
 pass alive cells to nextGen -
    put alive cells into array in game, then pass that to nextGen to make a new board
 pass board to nextGen -
    pass full board array into nextGen
 */

#endif /* board_hpp */
