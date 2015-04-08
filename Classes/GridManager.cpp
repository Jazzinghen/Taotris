/* 
 * File:   gridManager.cpp
 * Author: jazzinghen
 * 
 * Created on 08 April 2015, 16:14
 */

#include "Include/GridManager.h"

USING_NS_CC;

GridManager::GridManager() {
    auto daSquareBro = Sprite::createWithSpriteFrameName("daSquareBro.png");
    daSquareBro->setPosition(350, 400);
    
    this->addChild(daSquareBro);
}

GridManager::GridManager(const GridManager& orig) {
}

GridManager::~GridManager() {
}

