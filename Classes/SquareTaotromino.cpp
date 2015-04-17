/* 
 * File:   SquareTaotromino.cpp
 * Author: jazzinghen
 * 
 * Created on 15 April 2015, 16:13
 */

#include "Include/SquareTaotromino.h"
#include "Include/Taotromino.h"
#include "Include/TaotrominoGrid.h"

USING_NS_CC;

SquareTaotromino::SquareTaotromino(int y) {
    
     /** Initialisation for the taoTromino structure
     *  I simply KNOW this is not the right way to do this because it's a C way
     *  but, fuck everything! I don't know how to do it in another way. Everything is
     *  fucked up on the Internet and my brain is refusing to work.
     */
    
    /** First column is the RIGHTMOST!
     *  Yeah, I know, this is so weaboo...
     */
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> firstColumn {
        { TaotrominoGrid::Square, TaotrominoGrid::Square, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> secondColumn {
        { TaotrominoGrid::Square, TaotrominoGrid::Square, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> thirdColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> fourthColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    
    // 0 is 0°, 1 is 90°, 2 is 180° and 3 is 270°
    taoDefinition[0] = { firstColumn, secondColumn, thirdColumn, fourthColumn };
    taoDefinition[1] = taoDefinition[0];
    taoDefinition[2] = taoDefinition[0];
    taoDefinition[3] = taoDefinition[0];
    
    
    taoSize = 2;
    taoCentre[0] = 0;
    taoCentre[1] = 0;
    taoLocation[0] = 16;
    taoLocation[1] = y;
    
    
    std::cout << "Generating Sprites" << std::endl;
    
    auto tmpSquare = Sprite::createWithSpriteFrameName("daSquareMomoBig");
    tmpSquare->setPosition(0,0);
    taoBlocks.push_back(tmpSquare);
    
    tmpSquare = Sprite::createWithSpriteFrameName("daSquareMomoBig");
    tmpSquare->setPosition(-90,0);
    taoBlocks.push_back(tmpSquare);
    
    tmpSquare = Sprite::createWithSpriteFrameName("daSquareMomoBig");
    tmpSquare->setPosition(0,-90);
    taoBlocks.push_back(tmpSquare);
    
    tmpSquare = Sprite::createWithSpriteFrameName("daSquareMomoBig");
    tmpSquare->setPosition(-90,-90);
    taoBlocks.push_back(tmpSquare);
    
    std::cout << "Adding Sprites to the Taotromino" << std::endl;
    
    AddToNode();
};

SquareTaotromino::SquareTaotromino(const SquareTaotromino& orig) {
}

SquareTaotromino::~SquareTaotromino() {
}