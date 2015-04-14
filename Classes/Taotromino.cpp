/* 
 * File:   Taotromino.cpp
 * Author: jazzinghen
 * 
 * Created on 13 April 2015, 18:29
 */
#include <fstream>
#include <iostream>

#include "Include/Taotromino.h"

USING_NS_CC;

const Taotromino::taotromino_t lineDefinition[4][4][4] = {
    {
        {Taotromino::Line, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Line, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Line, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Line, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::Line, Taotromino::Line, Taotromino::Line, Taotromino::Line},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::Line, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Line, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Line, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Line, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    },
    {
        {Taotromino::Line, Taotromino::Line, Taotromino::Line, Taotromino::Line},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty},
        {Taotromino::Empty, Taotromino::Empty, Taotromino::Empty, Taotromino::Empty}
    }
};

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

Taotromino::Taotromino(taotromino_t type) {
    
     std::cout << "Setting Type: " << type << std::endl;
    Taotromino::SetType(type);
    
     std::cout << "Generating Sprites" << std::endl;
    
    auto firstSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig");
    firstSquare->setPosition(0,0);
    auto secondSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig");
    secondSquare->setPosition(-90,0);
    auto thirdSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig");
    thirdSquare->setPosition(90,0);
    auto fourthSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig");
    fourthSquare->setPosition(180,0);
    
     std::cout << "Adding Sprites to the Taotromino" << std::endl;
    
    this->addChild(firstSquare);
    this->addChild(secondSquare);
    this->addChild(thirdSquare);
    this->addChild(fourthSquare);
}



Taotromino::Taotromino(const Taotromino& orig) {
}

Taotromino::~Taotromino() {
}

