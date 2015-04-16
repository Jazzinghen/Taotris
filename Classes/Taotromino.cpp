/* 
 * File:   Taotromino.cpp
 * Author: jazzinghen
 * 
 * Created on 13 April 2015, 18:29
 */
#include <fstream>
#include <iostream>
#include <array>

#include "Include/Taotromino.h"
#include "Include/TaotrominoGrid.h"

USING_NS_CC;



const TaotrominoGrid::taotromino_t Taotromino::squareDefinition[4][2][2] = {
    {
        {TaotrominoGrid::Square, TaotrominoGrid::Square},
        {TaotrominoGrid::Square, TaotrominoGrid::Square}               
    },
    {
        {TaotrominoGrid::Square, TaotrominoGrid::Square},
        {TaotrominoGrid::Square, TaotrominoGrid::Square}               
    },
    {
        {TaotrominoGrid::Square, TaotrominoGrid::Square},
        {TaotrominoGrid::Square, TaotrominoGrid::Square}               
    },
    {
        {TaotrominoGrid::Square, TaotrominoGrid::Square},
        {TaotrominoGrid::Square, TaotrominoGrid::Square}               
    }
};

const TaotrominoGrid::taotromino_t Taotromino::tDefinition[4][3][3]{
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::Empty},
        {TaotrominoGrid::T, TaotrominoGrid::T, TaotrominoGrid::T},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::T},
        {TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty},
        {TaotrominoGrid::T, TaotrominoGrid::T, TaotrominoGrid::T},
        {TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::Empty}
    },
     {
        {TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::Empty},
        {TaotrominoGrid::T, TaotrominoGrid::T, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::Empty}
    }
};

const TaotrominoGrid::taotromino_t Taotromino::jDefinition[4][3][3]{
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::J, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::J, TaotrominoGrid::Empty},
        {TaotrominoGrid::J, TaotrominoGrid::J, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::J, TaotrominoGrid::Empty, TaotrominoGrid::Empty},
        {TaotrominoGrid::J, TaotrominoGrid::J, TaotrominoGrid::J},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::J, TaotrominoGrid::J},
        {TaotrominoGrid::Empty, TaotrominoGrid::J, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::J, TaotrominoGrid::Empty}
    },
     {
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty},
        {TaotrominoGrid::J, TaotrominoGrid::J, TaotrominoGrid::J},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::J}
    }
};

const TaotrominoGrid::taotromino_t Taotromino::lDefinition[4][3][3]{
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::L, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::L, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::L, TaotrominoGrid::L}
    },
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty},
        {TaotrominoGrid::L, TaotrominoGrid::L, TaotrominoGrid::L},
        {TaotrominoGrid::L, TaotrominoGrid::Empty, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::L, TaotrominoGrid::L, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::L, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::L, TaotrominoGrid::Empty}
    },
     {
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::L},
        {TaotrominoGrid::L, TaotrominoGrid::L, TaotrominoGrid::L},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty}
    }
};

const TaotrominoGrid::taotromino_t Taotromino::sDefinition[4][3][3]{
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::S, TaotrominoGrid::S},
        {TaotrominoGrid::S, TaotrominoGrid::S, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::S, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::S, TaotrominoGrid::S},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::S}
    },
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::S, TaotrominoGrid::S},
        {TaotrominoGrid::S, TaotrominoGrid::S, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::S, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::S, TaotrominoGrid::S},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::S}
    }
};

const TaotrominoGrid::taotromino_t Taotromino::zDefinition[4][3][3]{
    {
        {TaotrominoGrid::Z, TaotrominoGrid::Z, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::Z, TaotrominoGrid::Z},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Z},
        {TaotrominoGrid::Empty, TaotrominoGrid::Z, TaotrominoGrid::Z},
        {TaotrominoGrid::Empty, TaotrominoGrid::Z, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::Z, TaotrominoGrid::Z, TaotrominoGrid::Empty},
        {TaotrominoGrid::Empty, TaotrominoGrid::Z, TaotrominoGrid::Z},
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty}
    },
    {
        {TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Z},
        {TaotrominoGrid::Empty, TaotrominoGrid::Z, TaotrominoGrid::Z},
        {TaotrominoGrid::Empty, TaotrominoGrid::Z, TaotrominoGrid::Empty}
    }
};

Taotromino::Taotromino() {
}

Taotromino::~Taotromino() {
}

void Taotromino::rotate(){
    rotation = (rotation + 1) % 4;
}
