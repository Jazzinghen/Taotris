/* 
 * File:   gridManager.cpp
 * Author: jazzinghen
 * 
 * Created on 08 April 2015, 16:14
 */

#include "Include/GridManager.h"

USING_NS_CC;

GridManager::GridManager() {
    auto mainGrid = Sprite::createWithSpriteFrameName("mainGrid.png");
    mainGrid->setAnchorPoint(Vec2(0, 0));
    mainGrid->setPosition(90, 90);
    
    this->addChild(mainGrid);
}

GridManager::GridManager(const GridManager& orig) {
}

GridManager::~GridManager() {
}

