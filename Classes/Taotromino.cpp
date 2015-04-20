/* 
 * File:   Taotromino.cpp
 * Author: jazzinghen
 * 
 * Created on 13 April 2015, 18:29
 */
#include <fstream>
#include <iostream>
#include <array>

#include "Include/Taotromino.h"
#include "Include/TaotrominoGrid.h"

USING_NS_CC;

Taotromino::Taotromino() {
}

Taotromino * Taotromino::create()
{
    Taotromino * ret = new (std::nothrow) Taotromino();
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

Taotromino::~Taotromino() {
}

void Taotromino::Rotate(){
    rotation = (rotation + 1) % 4;
}

void Taotromino::AddToNode() {
    for (auto block : taoBlocks){
        this->addChild(block);
    }
}
