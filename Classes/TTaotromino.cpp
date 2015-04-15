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
    
    // 0° rotation
    taoDefinition[0][0][0] = Taotromino::Empty;
    taoDefinition[0][0][1] = Taotromino::T;
    taoDefinition[0][0][2] = Taotromino::Empty;
    taoDefinition[0][0][3] = Taotromino::Empty;
    
    taoDefinition[0][1][0] = Taotromino::T;
    taoDefinition[0][1][1] = Taotromino::T;
    taoDefinition[0][1][2] = Taotromino::T;
    taoDefinition[0][1][3] = Taotromino::Empty;
    
    taoDefinition[0][2][0] = Taotromino::Empty;
    taoDefinition[0][2][1] = Taotromino::Empty;
    taoDefinition[0][2][2] = Taotromino::Empty;
    taoDefinition[0][2][3] = Taotromino::Empty;
    
    taoDefinition[0][3][0] = Taotromino::Empty;
    taoDefinition[0][3][1] = Taotromino::Empty;
    taoDefinition[0][3][2] = Taotromino::Empty;
    taoDefinition[0][3][3] = Taotromino::Empty;
    
    // 90° rotation
    taoDefinition[1][0][0] = Taotromino::T;
    taoDefinition[1][0][1] = Taotromino::Empty;
    taoDefinition[1][0][2] = Taotromino::Empty;
    taoDefinition[1][0][3] = Taotromino::Empty;
    
    taoDefinition[1][1][0] = Taotromino::T;
    taoDefinition[1][1][1] = Taotromino::T;
    taoDefinition[1][1][2] = Taotromino::Empty;
    taoDefinition[1][1][3] = Taotromino::Empty;
    
    taoDefinition[1][2][0] = Taotromino::T;
    taoDefinition[1][2][1] = Taotromino::Empty;
    taoDefinition[1][2][2] = Taotromino::Empty;
    taoDefinition[1][2][3] = Taotromino::Empty;
    
    taoDefinition[1][3][0] = Taotromino::Empty;
    taoDefinition[1][3][1] = Taotromino::Empty;
    taoDefinition[1][3][2] = Taotromino::Empty;
    taoDefinition[1][3][3] = Taotromino::Empty;
    
    // 180° rotation
    taoDefinition[2][0][0] = Taotromino::T;
    taoDefinition[2][0][1] = Taotromino::T;
    taoDefinition[2][0][2] = Taotromino::T;
    taoDefinition[2][0][3] = Taotromino::Empty;
    
    taoDefinition[2][1][0] = Taotromino::Empty;
    taoDefinition[2][1][1] = Taotromino::T;
    taoDefinition[2][1][2] = Taotromino::Empty;
    taoDefinition[2][1][3] = Taotromino::Empty;
    
    taoDefinition[2][2][0] = Taotromino::Empty;
    taoDefinition[2][2][1] = Taotromino::Empty;
    taoDefinition[2][2][2] = Taotromino::Empty;
    taoDefinition[2][2][3] = Taotromino::Empty;
    
    taoDefinition[2][3][0] = Taotromino::Empty;
    taoDefinition[2][3][1] = Taotromino::Empty;
    taoDefinition[2][3][2] = Taotromino::Empty;
    taoDefinition[2][3][3] = Taotromino::Empty;
    
    // 270° rotation
    taoDefinition[1][0][0] = Taotromino::Empty;
    taoDefinition[1][0][1] = Taotromino::T;
    taoDefinition[1][0][2] = Taotromino::Empty;
    taoDefinition[1][0][3] = Taotromino::Empty;
    
    taoDefinition[1][1][0] = Taotromino::T;
    taoDefinition[1][1][1] = Taotromino::T;
    taoDefinition[1][1][2] = Taotromino::Empty;
    taoDefinition[1][1][3] = Taotromino::Empty;
    
    taoDefinition[1][2][0] = Taotromino::Empty;
    taoDefinition[1][2][1] = Taotromino::T;
    taoDefinition[1][2][2] = Taotromino::Empty;
    taoDefinition[1][2][3] = Taotromino::Empty;
    
    taoDefinition[1][3][0] = Taotromino::Empty;
    taoDefinition[1][3][1] = Taotromino::Empty;
    taoDefinition[1][3][2] = Taotromino::Empty;
    taoDefinition[1][3][3] = Taotromino::Empty;
    
    
    taoSize = 4;
    taoCentre[0] = 0;
    taoCentre[1] = 0;
    taoLocation[0] = 16;
    taoLocation[1] = y;
    
    
    std::cout << "Generating Sprites" << std::endl;
    
    auto firstSquare = Sprite::createWithSpriteFrameName("daSquareMikuBig");
    firstSquare->setPosition(90,0);
    auto secondSquare = Sprite::createWithSpriteFrameName("daSquareMikuBig");
    secondSquare->setPosition(0,-90);
    auto thirdSquare = Sprite::createWithSpriteFrameName("daSquareMikuBig");
    thirdSquare->setPosition(90,-90);
    auto fourthSquare = Sprite::createWithSpriteFrameName("daSquareMikuBig");
    fourthSquare->setPosition(180,-90);
    
    std::cout << "Adding Sprites to the Taotromino" << std::endl;
    
    this->addChild(firstSquare);
    this->addChild(secondSquare);
    this->addChild(thirdSquare);
    this->addChild(fourthSquare);
};

TTaotromino::TTaotromino(const TTaotromino& orig) {
}

TTaotromino::~TTaotromino() {
}