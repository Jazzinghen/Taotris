/* 
 * File:   TTaotromino.cpp
 * Author: jazzinghen
 * 
 * Created on 15 April 2015, 16:13
 */

#include "Include/TTaotromino.h"
#include "Include/Taotromino.h"

USING_NS_CC;

TTaotromino::TTaotromino(int y) {
    
    /** Initialisation for the taoTromino structure
     *  I simply KNOW this is not the right way to do this because it's a C way
     *  but, fuck everything! I don't know how to do it in another way. Everything is
     *  fucked up on the Internet and my brain is refusing to work.
     */
     /** Initialisation for the taoTromino structure
     *  I simply KNOW this is not the right way to do this because it's a C way
     *  but, fuck everything! I don't know how to do it in another way. Everything is
     *  fucked up on the Internet and my brain is refusing to work.
     */
    
    /** First column is the RIGHTMOST!
     *  Yeah, I know, this is so weaboo...
     */
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> firstColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> secondColumn {
        { TaotrominoGrid::T, TaotrominoGrid::T, TaotrominoGrid::T, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> thirdColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    std::array<TaotrominoGrid::taotromino_t, (std::size_t) 4> fourthColumn {
        { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty }
    };
    
    
    // 0 is 0°, 1 is 90°, 2 is 180° and 3 is 270°
    taoDefinition[0] = { firstColumn, secondColumn, thirdColumn, fourthColumn };
    taoDefinition[2] = { secondColumn, firstColumn, thirdColumn, fourthColumn } ;
    
    firstColumn = { TaotrominoGrid::T, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    secondColumn = { TaotrominoGrid::T, TaotrominoGrid::T, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    thirdColumn = { TaotrominoGrid::T, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    fourthColumn = { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    
    taoDefinition[1] = { firstColumn, secondColumn, thirdColumn, fourthColumn };
    
    firstColumn = { TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    secondColumn = { TaotrominoGrid::T, TaotrominoGrid::T, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    thirdColumn = { TaotrominoGrid::Empty, TaotrominoGrid::T, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    fourthColumn = { TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty, TaotrominoGrid::Empty };
    
    taoDefinition[3] = { firstColumn, secondColumn, thirdColumn, fourthColumn };
    
    
    taoSize = 3;
    taoCentre[0] = 0;
    taoCentre[1] = 0;
    taoLocation[0] = 16;
    taoLocation[1] = y;
    
    
    std::cout << "Generating Sprites" << std::endl;
    
    auto tmpSquare = Sprite::createWithSpriteFrameName("daSquareMikuBig");
    tmpSquare->setPosition(0,-90);
    taoBlocks.push_back(tmpSquare);
    
    tmpSquare = Sprite::createWithSpriteFrameName("daSquareMikuBig");
    tmpSquare->setPosition(-90,0);
    taoBlocks.push_back(tmpSquare);
    
    tmpSquare = Sprite::createWithSpriteFrameName("daSquareMikuBig");
    tmpSquare->setPosition(-90,-90);
    taoBlocks.push_back(tmpSquare);
    
    tmpSquare = Sprite::createWithSpriteFrameName("daSquareMikuBig");
    tmpSquare->setPosition(-90,-180);
    taoBlocks.push_back(tmpSquare);
    
    std::cout << "Adding Sprites to the Taotromino" << std::endl;
    
    AddToNode();
};

TTaotromino::TTaotromino(const TTaotromino& orig) {
}

TTaotromino::~TTaotromino() {
}

TTaotromino * TTaotromino::create(int y)
{
    TTaotromino * ret = new (std::nothrow) TTaotromino(y);
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}