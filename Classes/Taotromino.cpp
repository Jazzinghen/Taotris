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

Taotromino::~Taotromino() {
}

void Taotromino::rotate(){
    rotation = (rotation + 1) % 4;
}
