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

Taotromino::Taotromino(taotromino_t type) {
    
     std::cout << "Setting Type: " << type << std::endl;
    Taotromino::SetType(type);
    
     std::cout << "Generating Sprites" << std::endl;
    
    auto firstSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig.png");
    firstSquare->setPosition(0,0);
    auto secondSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig.png");
    secondSquare->setPosition(-90,0);
    auto thirdSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig.png");
    thirdSquare->setPosition(90,0);
    auto fourthSquare = Sprite::createWithSpriteFrameName("daSquareMidoriBig.png");
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

