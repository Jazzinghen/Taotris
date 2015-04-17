/* 
 * File:   JTaotromino.cpp
 * Author: jazzinghen
 * 
 * Created on 15 April 2015, 16:13
 */

#include "Include/JTaotromino.h"
#include "Include/Taotromino.h"

USING_NS_CC;

JTaotromino::JTaotromino(int y) {
    
    /** Initialisation for the taoTromino structure
     *  I simply KNOW this is not the right way to do this because it's a C way
     *  but, fuck everything! I don't know how to do it in another way. Everything is
     *  fucked up on the Internet and my brain is refusing to work.
     */
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> firstColumn {
        { TaotrominoGrid::J, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> secondColumn {
        { TaotrominoGrid::J, TaotrominoGrid::J, TaotrominoGrid::J, TaotrominoGrid::Empty }
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
    
    firstColumn = { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::J, TaotrominoGrid::Empty };
    
    taoDefinition[2] = { secondColumn, firstColumn, thirdColumn, fourthColumn };
    
    firstColumn = { TaotrominoGrid::J, TaotrominoGrid::J, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    secondColumn = { TaotrominoGrid::J, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    thirdColumn = { TaotrominoGrid::J, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    fourthColumn = { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    
    taoDefinition[1] = { firstColumn, secondColumn, thirdColumn, fourthColumn };

    firstColumn = { TaotrominoGrid::Empty, TaotrominoGrid::J, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    secondColumn = { TaotrominoGrid::Empty, TaotrominoGrid::J, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    thirdColumn = { TaotrominoGrid::J, TaotrominoGrid::J, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    fourthColumn = { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    
    taoDefinition[3] = { firstColumn, secondColumn, thirdColumn, fourthColumn };
    
    taoSize = 3;
    taoCentre[0] = 0;
    taoCentre[1] = 0;
    taoLocation[0] = 16;
    taoLocation[1] = y;
    
    
    std::cout << "Generating Sprites" << std::endl;
    
    auto tmpSquare = Sprite::createWithSpriteFrameName("daSquareAkaBig");
    tmpSquare->setPosition(0,0);
    taoBlocks.push_back(tmpSquare);
    
    tmpSquare = Sprite::createWithSpriteFrameName("daSquareAkaBig");
    tmpSquare->setPosition(-90,0);
    taoBlocks.push_back(tmpSquare);
    
    tmpSquare = Sprite::createWithSpriteFrameName("daSquareAkaBig");
    tmpSquare->setPosition(-90,-90);
    taoBlocks.push_back(tmpSquare);
    
    tmpSquare = Sprite::createWithSpriteFrameName("daSquareAkaBig");
    tmpSquare->setPosition(-90,-180);
    taoBlocks.push_back(tmpSquare);
    
    std::cout << "Adding Sprites to the Taotromino" << std::endl;
    
    AddToNode();
};

JTaotromino::JTaotromino(const JTaotromino& orig) {
}

JTaotromino::~JTaotromino() {
}