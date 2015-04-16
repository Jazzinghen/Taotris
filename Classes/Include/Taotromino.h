/* 
 * File:   Taotromino.h
 * 
 * Author: jazzinghen
 *
 * Created on 13 April 2015, 18:29
 */

#ifndef TAOTROMINO_H
#define	TAOTROMINO_H

#include "cocos2d.h"
#include <iostream>
#include <fstream>
#include <array>

#include "TaotrominoGrid.h"

class Taotromino : public cocos2d::Node{    
public:
    Taotromino();
    
    virtual ~Taotromino();
    
    void rotate();

    void SetType(TaotrominoGrid::taotromino_t type) {
        this->type = type;
    }

    TaotrominoGrid::taotromino_t GetType() const {
        return type;
    }
    
protected:
    TaotrominoGrid::taotromino_t type;
    // taoSize is needed to access the mathematical representation of the tetramino
    int taoSize;
    // taoCentre = [x, y] in pixels for rotation
    int taoCentre[2];
    // taoLocation = [x, y] in col, rows
    int taoLocation[2];
    int rotation = 0;
    std::array<TaotrominoGrid, (std::size_t) 4> taoDefinition;

    static const TaotrominoGrid::taotromino_t lineDefinition[4][4][4];
    static const TaotrominoGrid::taotromino_t squareDefinition[4][2][2];
    static const TaotrominoGrid::taotromino_t tDefinition[4][3][3];
    static const TaotrominoGrid::taotromino_t lDefinition[4][3][3];
    static const TaotrominoGrid::taotromino_t jDefinition[4][3][3];
    static const TaotrominoGrid::taotromino_t sDefinition[4][3][3];
    static const TaotrominoGrid::taotromino_t zDefinition[4][3][3];
};

#endif	/* TAOTROMINO_H */

