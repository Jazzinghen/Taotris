/* 
 * File:   ZTaotromino.cpp
 * Author: jazzinghen
 * 
 * Created on 15 April 2015, 16:13
 */

#include "Include/ZTaotromino.h"
#include "Include/Taotromino.h"

USING_NS_CC;

ZTaotromino::ZTaotromino(int y) {
    
    /** Initialisation for the taoTromino structure
     *  I simply KNOW this is not the right way to do this because it's a C way
     *  but, fuck everything! I don't know how to do it in another way. Everything is
     *  fucked up on the Internet and my brain is refusing to work.
     */
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> firstColumn {
        { TaotrominoGrid::Z, TaotrominoGrid::Z, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> secondColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Z, TaotrominoGrid::Z, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> thirdColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> fourthColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    
    // 0 is 0°, 1 is 90°, 2 is 180° and 3 is 270°
    taoDefinition[0] = { firstColumn, secondColumn, thirdColumn, fourthColumn };
    taoDefinition[2] = taoDefinition[0];
    
    firstColumn = { TaotrominoGrid::Empty, TaotrominoGrid::Z, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    secondColumn = { TaotrominoGrid::Z, TaotrominoGrid::Z, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    thirdColumn = { TaotrominoGrid::Z, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    fourthColumn = { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    
    taoDefinition[1] = { firstColumn, secondColumn, thirdColumn, fourthColumn };    
    taoDefinition[3] = taoDefinition[1];
    
    taoSize = 3;
    taoCentre[0] = 0;
    taoCentre[1] = 0;
    taoLocation[0] = 16;
    taoLocation[1] = y;
    
    
    std::cout << "Generating Sprites" << std::endl;
    
    std::cout << "Generating First" << std::endl;
    auto firstSquare = Sprite::createWithSpriteFrameName("daSquareOnee");
    std::cout << "Setting First Rotation" << std::endl;
    firstSquare->setPosition(0,0);
    std::cout << "Generating Second" << std::endl;
    auto secondSquare = Sprite::createWithSpriteFrameName("daSquareOnee");
    secondSquare->setPosition(0,-90);
    std::cout << "Generating Third" << std::endl;
    auto thirdSquare = Sprite::createWithSpriteFrameName("daSquareOnee");
    thirdSquare->setPosition(-90,-90);
    std::cout << "Generating Fourth" << std::endl;
    auto fourthSquare = Sprite::createWithSpriteFrameName("daSquareOnee");
    fourthSquare->setPosition(-90,-180);
    
    std::cout << "Adding Sprites to the Taotromino" << std::endl;
    
    this->addChild(firstSquare);
    this->addChild(secondSquare);
    this->addChild(thirdSquare);
    this->addChild(fourthSquare);
};

ZTaotromino::ZTaotromino(const ZTaotromino& orig) {
}

ZTaotromino::~ZTaotromino() {
}