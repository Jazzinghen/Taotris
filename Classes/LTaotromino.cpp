/* 
 * File:   LTaotromino.cpp
 * Author: jazzinghen
 * 
 * Created on 15 April 2015, 16:13
 */

#include "Include/LTaotromino.h"
#include "Include/Taotromino.h"

USING_NS_CC;

LTaotromino::LTaotromino(int y) {
    
    /** Initialisation for the taoTromino structure
     *  I simply KNOW this is not the right way to do this because it's a C way
     *  but, fuck everything! I don't know how to do it in another way. Everything is
     *  fucked up on the Internet and my brain is refusing to work.
     */
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> firstColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::L, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> secondColumn {
        { TaotrominoGrid::L, TaotrominoGrid::L, TaotrominoGrid::L, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> thirdColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> fourthColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    
    // 0 is 0°, 1 is 90°, 2 is 180° and 3 is 270°
    // I am doing all this stuff in order to write as less as possible ;3;
    
    taoDefinition[0] = { firstColumn, secondColumn, thirdColumn, fourthColumn };
    
    firstColumn = { TaotrominoGrid::L, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    
    taoDefinition[2] = { secondColumn, firstColumn, thirdColumn, fourthColumn };
    
    firstColumn = { TaotrominoGrid::L, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    secondColumn = { TaotrominoGrid::L, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    thirdColumn = { TaotrominoGrid::L, TaotrominoGrid::L, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    fourthColumn = { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    
    taoDefinition[1] = { firstColumn, secondColumn, thirdColumn, fourthColumn };

    firstColumn = { TaotrominoGrid::L, TaotrominoGrid::L, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    secondColumn = { TaotrominoGrid::Empty, TaotrominoGrid::L, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    thirdColumn = { TaotrominoGrid::Empty, TaotrominoGrid::L, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    fourthColumn = { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    
    taoDefinition[3] = { firstColumn, secondColumn, thirdColumn, fourthColumn };
    
    taoSize = 3;
    taoCentre[0] = 0;
    taoCentre[1] = 0;
    taoLocation[0] = 16;
    taoLocation[1] = y;
    
    
    std::cout << "Generating Sprites" << std::endl;
    
    auto firstSquare = Sprite::createWithSpriteFrameName("daSquareShiroBig");
    firstSquare->setPosition(0,-180);
    auto secondSquare = Sprite::createWithSpriteFrameName("daSquareShiroBig");
    secondSquare->setPosition(-90,0);
    auto thirdSquare = Sprite::createWithSpriteFrameName("daSquareShiroBig");
    thirdSquare->setPosition(-90,-90);
    auto fourthSquare = Sprite::createWithSpriteFrameName("daSquareShiroBig");
    fourthSquare->setPosition(-90,-180);
    
    std::cout << "Adding Sprites to the Taotromino" << std::endl;
    
    this->addChild(firstSquare);
    this->addChild(secondSquare);
    this->addChild(thirdSquare);
    this->addChild(fourthSquare);
};

LTaotromino::LTaotromino(const LTaotromino& orig) {
}

LTaotromino::~LTaotromino() {
}