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

USING_NS_CC;



const Taotromino::taotromino_t Taotromino::squareDefinition[4][2][2] = {
    {
        {Taotromino::Square, Taotromino::Square},
        {Taotromino::Square, Taotromino::Square}               
    },
    {
        {Taotromino::Square, Taotromino::Square},
        {Taotromino::Square, Taotromino::Square}               
    },
    {
        {Taotromino::Square, Taotromino::Square},
        {Taotromino::Square, Taotromino::Square}               
    },
    {
        {Taotromino::Square, Taotromino::Square},
        {Taotromino::Square, Taotromino::Square}               
    }
};

const Taotromino::taotromino_t Taotromino::tDefinition[4][3][3]{
    {
        {Taotromino::Empty, Taotromino::T, Taotromino::Empty},
        {Taotromino::T, Taotromino::T, Taotromino::T},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::Empty, Taotromino::T, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::T, Taotromino::T},
        {Taotromino::Empty, Taotromino::T, Taotromino::Empty}
    },
    {
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::T, Taotromino::T, Taotromino::T},
        {Taotromino::Empty, Taotromino::T, Taotromino::Empty}
    },
     {
        {Taotromino::Empty, Taotromino::T, Taotromino::Empty},
        {Taotromino::T, Taotromino::T, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::T, Taotromino::Empty}
    }
};

const Taotromino::taotromino_t Taotromino::jDefinition[4][3][3]{
    {
        {Taotromino::Empty, Taotromino::J, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::J, Taotromino::Empty},
        {Taotromino::J, Taotromino::J, Taotromino::Empty}
    },
    {
        {Taotromino::J, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::J, Taotromino::J, Taotromino::J},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::Empty, Taotromino::J, Taotromino::J},
        {Taotromino::Empty, Taotromino::J, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::J, Taotromino::Empty}
    },
     {
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::J, Taotromino::J, Taotromino::J},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::J}
    }
};

const Taotromino::taotromino_t Taotromino::lDefinition[4][3][3]{
    {
        {Taotromino::Empty, Taotromino::L, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::L, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::L, Taotromino::L}
    },
    {
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::L, Taotromino::L, Taotromino::L},
        {Taotromino::L, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::L, Taotromino::L, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::L, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::L, Taotromino::Empty}
    },
     {
        {Taotromino::Empty, Taotromino::Empty, Taotromino::L},
        {Taotromino::L, Taotromino::L, Taotromino::L},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    }
};

const Taotromino::taotromino_t Taotromino::sDefinition[4][3][3]{
    {
        {Taotromino::Empty, Taotromino::S, Taotromino::S},
        {Taotromino::S, Taotromino::S, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::Empty, Taotromino::S, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::S, Taotromino::S},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::S}
    },
    {
        {Taotromino::Empty, Taotromino::S, Taotromino::S},
        {Taotromino::S, Taotromino::S, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::Empty, Taotromino::S, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::S, Taotromino::S},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::S}
    }
};

const Taotromino::taotromino_t Taotromino::zDefinition[4][3][3]{
    {
        {Taotromino::Z, Taotromino::Z, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::Z, Taotromino::Z},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Z},
        {Taotromino::Empty, Taotromino::Z, Taotromino::Z},
        {Taotromino::Empty, Taotromino::Z, Taotromino::Empty}
    },
    {
        {Taotromino::Z, Taotromino::Z, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::Z, Taotromino::Z},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Z},
        {Taotromino::Empty, Taotromino::Z, Taotromino::Z},
        {Taotromino::Empty, Taotromino::Z, Taotromino::Empty}
    }
};

Taotromino::Taotromino() {
}

Taotromino::~Taotromino() {
}

void Taotromino::rotate(){
    rotation = (rotation + 1) % 4;
}
