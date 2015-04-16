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
#include "Include/TaotrominoGrid.h"
#include "Include/LineTaotromino.h"
#include "Include/SquareTaotromino.h"
#include "Include/TTaotromino.h"
#include "Include/JTaotromino.h"
#include "Include/LTaotromino.h"
#include "Include/STaotromino.h"
#include "Include/ZTaotromino.h"

USING_NS_CC;

GridManager::GridManager() {
    auto mainGrid = Sprite::createWithSpriteFrameName("mainGrid");
    mainGrid->setAnchorPoint(Vec2(0, 0));
    mainGrid->setPosition(90, 90);
    
    this->addChild(mainGrid);
    
     std::cout << "Creating Taotromino" << std::endl;
    currentTao = new LineTaotromino(5);
     std::cout << "Setting Location" << std::endl;
    currentTao->setPosition((90 + 90*16) - 45, (90 + 90*5) - 45);
    
    auto fuffa1 = new LTaotromino(4);
    fuffa1->setPosition((90 + 90*4) - 45, (90 + 90*7) - 45);
    
    auto fuffa2 = new ZTaotromino(4);
    fuffa2->setPosition((90 + 90*10) - 45, (90 + 90*10) - 45);
    
     std::cout << "Adding Taotromino to scene" << std::endl;
    this->addChild(currentTao, 2);
    this->addChild(fuffa1, 2);
    this->addChild(fuffa2, 2);
     std::cout << "End" << std::endl;
    
}

GridManager::GridManager(const GridManager& orig) {
}

GridManager::~GridManager() {
}

std::string GridManager::BlockName(TaotrominoGrid::taotromino_t blockType){
    
    switch (blockType){
        case TaotrominoGrid::Line:
            return "daSquareMidoriBig";
            break;
        case TaotrominoGrid::Square:
            return "daSquareMomoBig";
            break;
        case TaotrominoGrid::T:
            return "daSquareMikuBig";
            break;
        case TaotrominoGrid::J:
            return "daSquareAkaBig";
            break;
        case TaotrominoGrid::L:
            return "daSquareShiroBig";
            break;
        case TaotrominoGrid::S:
            return "daSquareOnii";
            break;
        case TaotrominoGrid::Z:
            return "daSquareOnee";
            break;
        default:
            return NULL;
            break;
    }
}