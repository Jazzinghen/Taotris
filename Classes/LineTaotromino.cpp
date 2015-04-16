/* 
 * File:   LineTaotromino.cpp
 * Author: jazzinghen
 * 
 * Created on 15 April 2015, 16:13
 */

#include "Include/LineTaotromino.h"
#include "Include/Taotromino.h"

USING_NS_CC;

LineTaotromino::LineTaotromino(int y) {
    
    /** Initialisation for the taoTromino structure
     *  I simply KNOW this is not the right way to do this because it's a C way
     *  but, fuck everything! I don't know how to do it in another way. Everything is
     *  fucked up on the Internet and my brain is refusing to work.
     */
    
    // 0° rotation
    taoDefinition[0][0][0] = Taotromino::Line;
    taoDefinition[0][0][1] = Taotromino::Empty;
    taoDefinition[0][0][2] = Taotromino::Empty;
    taoDefinition[0][0][3] = Taotromino::Empty;
    
    taoDefinition[0][1][0] = Taotromino::Line;
    taoDefinition[0][1][1] = Taotromino::Empty;
    taoDefinition[0][1][2] = Taotromino::Empty;
    taoDefinition[0][1][3] = Taotromino::Empty;
    
    taoDefinition[0][2][0] = Taotromino::Line;
    taoDefinition[0][2][1] = Taotromino::Empty;
    taoDefinition[0][2][2] = Taotromino::Empty;
    taoDefinition[0][2][3] = Taotromino::Empty;
    
    taoDefinition[0][3][0] = Taotromino::Line;
    taoDefinition[0][3][1] = Taotromino::Empty;
    taoDefinition[0][3][2] = Taotromino::Empty;
    taoDefinition[0][3][3] = Taotromino::Empty;
    
    // 90° rotation
    taoDefinition[1][0][0] = Taotromino::Line;
    taoDefinition[1][0][1] = Taotromino::Line;
    taoDefinition[1][0][2] = Taotromino::Line;
    taoDefinition[1][0][3] = Taotromino::Line;
    
    taoDefinition[1][1][0] = Taotromino::Empty;
    taoDefinition[1][1][1] = Taotromino::Empty;
    taoDefinition[1][1][2] = Taotromino::Empty;
    taoDefinition[1][1][3] = Taotromino::Empty;
    
    taoDefinition[1][2][0] = Taotromino::Empty;
    taoDefinition[1][2][1] = Taotromino::Empty;
    taoDefinition[1][2][2] = Taotromino::Empty;
    taoDefinition[1][2][3] = Taotromino::Empty;
    
    taoDefinition[1][3][0] = Taotromino::Empty;
    taoDefinition[1][3][1] = Taotromino::Empty;
    taoDefinition[1][3][2] = Taotromino::Empty;
    taoDefinition[1][3][3] = Taotromino::Empty;
    
    // 180° rotation
    taoDefinition[2][0][0] = Taotromino::Line;
    taoDefinition[2][0][1] = Taotromino::Empty;
    taoDefinition[2][0][2] = Taotromino::Empty;
    taoDefinition[2][0][3] = Taotromino::Empty;
    
    taoDefinition[2][1][0] = Taotromino::Line;
    taoDefinition[2][1][1] = Taotromino::Empty;
    taoDefinition[2][1][2] = Taotromino::Empty;
    taoDefinition[2][1][3] = Taotromino::Empty;
    
    taoDefinition[2][2][0] = Taotromino::Line;
    taoDefinition[2][2][1] = Taotromino::Empty;
    taoDefinition[2][2][2] = Taotromino::Empty;
    taoDefinition[2][2][3] = Taotromino::Empty;
    
    taoDefinition[2][3][0] = Taotromino::Line;
    taoDefinition[2][3][1] = Taotromino::Empty;
    taoDefinition[2][3][2] = Taotromino::Empty;
    taoDefinition[2][3][3] = Taotromino::Empty;
    
    // 270° rotation
    taoDefinition[1][0][0] = Taotromino::Line;
    taoDefinition[1][0][1] = Taotromino::Line;
    taoDefinition[1][0][2] = Taotromino::Line;
    taoDefinition[1][0][3] = Taotromino::Line;
    
    taoDefinition[1][1][0] = Taotromino::Empty;
    taoDefinition[1][1][1] = Taotromino::Empty;
    taoDefinition[1][1][2] = Taotromino::Empty;
    taoDefinition[1][1][3] = Taotromino::Empty;
    
    taoDefinition[1][2][0] = Taotromino::Empty;
    taoDefinition[1][2][1] = Taotromino::Empty;
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
    
    auto firstSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig");
    firstSquare->setPosition(0,0);
    auto secondSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig");
    secondSquare->setPosition(90,0);
    auto thirdSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig");
    thirdSquare->setPosition(180,0);
    auto fourthSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig");
    fourthSquare->setPosition(270,0);
    
    std::cout << "Adding Sprites to the Taotromino" << std::endl;
    
    this->addChild(firstSquare);
    this->addChild(secondSquare);
    this->addChild(thirdSquare);
    this->addChild(fourthSquare);
};

LineTaotromino::LineTaotromino(const LineTaotromino& orig) {
}

LineTaotromino::~LineTaotromino() {
}