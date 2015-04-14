/* 
 * File:   gridManager.cpp
 * Author: jazzinghen
 * 
 * Created on 08 April 2015, 16:14
 */

#include <fstream>
#include <iostream>
#include <string>

#include "Include/GridManager.h"
#include "Include/Taotromino.h"

USING_NS_CC;

GridManager::GridManager() {
    auto mainGrid = Sprite::createWithSpriteFrameName("mainGrid");
    mainGrid->setAnchorPoint(Vec2(0, 0));
    mainGrid->setPosition(90, 90);
    
    this->addChild(mainGrid);
    
     std::cout << "Creating Taotromino" << std::endl;
    currentTao = new Taotromino(Taotromino::Line);
     std::cout << "Setting Location" << std::endl;
    currentTao->setPosition((90 + 90*16) - 45, (90 + 90*5) - 45);
    currentTao->setRotation(90.0);
    
     std::cout << "Adding Taotromino to scene" << std::endl;
    this->addChild(currentTao, 2);
     std::cout << "End" << std::endl;
    
}

GridManager::GridManager(const GridManager& orig) {
}

GridManager::~GridManager() {
}

std::string GridManager::BlockName(Taotromino::taotromino_t blockType){
    
    switch (blockType){
        case Taotromino::Line:
            return "daSquareMidoriBig";
            break;
        case Taotromino::Square:
            return "daSquareMomoBig";
            break;
        default:
            return NULL;
            break;
    }
}