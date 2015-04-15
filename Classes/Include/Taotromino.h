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

class Taotromino : public cocos2d::Node{    
public:    
    typedef enum {
        Empty, Square, Line, T, S, Z, J, L
    } taotromino_t;

    Taotromino();
    
    virtual ~Taotromino();
    
    void rotate();

    void SetType(taotromino_t type) {
        this->type = type;
    }

    taotromino_t GetType() const {
        return type;
    }
    
protected:
    taotromino_t type;
    // taoSize is needed to access the mathematical representation of the tetramino
    int taoSize;
    // taoCentre = [x, y] in pixels for rotation
    int taoCentre[2];
    // taoLocation = [x, y] in col, rows
    int taoLocation[2];
    int rotation = 0;
    std::array<std::array<std::array<Taotromino::taotromino_t, (std::size_t) 4>, (std::size_t) 4>, (std::size_t) 4> taoDefinition;

    static const Taotromino::taotromino_t lineDefinition[4][4][4];
    static const Taotromino::taotromino_t squareDefinition[4][2][2];
    static const Taotromino::taotromino_t tDefinition[4][3][3];
    static const Taotromino::taotromino_t lDefinition[4][3][3];
    static const Taotromino::taotromino_t jDefinition[4][3][3];
    static const Taotromino::taotromino_t sDefinition[4][3][3];
    static const Taotromino::taotromino_t zDefinition[4][3][3];
};

#endif	/* TAOTROMINO_H */

