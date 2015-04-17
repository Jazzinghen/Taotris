/* 
 * File:   TaotrominoGrid.cpp
 * Author: jazzinghen
 * 
 * Created on 16 April 2015, 13:54
 */

#include <array>

#include "Include/TaotrominoGrid.h"
#include "Include/Taotromino.h"

TaotrominoGrid::TaotrominoGrid(std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> first,
                               std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> second,
                               std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> third,
                               std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> fourth) {
    
    gridDefinition[0] = first;
    gridDefinition[1] = second;
    gridDefinition[2] = third;
    gridDefinition[3] = fourth;

}

TaotrominoGrid::TaotrominoGrid(){
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> empty {
        TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty,
    };
    
    gridDefinition[0] = empty;
    gridDefinition[0] = empty;
    gridDefinition[0] = empty;
    gridDefinition[0] = empty;
};

TaotrominoGrid::~TaotrominoGrid() {
}