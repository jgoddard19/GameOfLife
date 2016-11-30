//
//  game.h
//  GameOfLife
//
//  Created by Jared Goddard on 11/3/16.
//  Copyright © 2016 Jared. All rights reserved.
//

#ifndef game_h
#define game_h

#include "board.hpp"

class Game {
public:
    Board nextGen(Board& board);
    int getGenCount();
    Board runGens(Board& board, int genCount);
};


#endif /* game_h */
