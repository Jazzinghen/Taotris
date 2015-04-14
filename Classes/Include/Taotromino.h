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

class Taotromino : public cocos2d::Node{
public:    
    typedef enum {
        Empty, Square, Line, T, S, Z, J, L
    } taotromino_t;

    Taotromino(taotromino_t type);
    Taotromino(const Taotromino& orig);
    virtual ~Taotromino();

    void SetType(taotromino_t type) {
        this->type = type;
    }

    taotromino_t GetType() const {
        return type;
    }
    
    void TaoStep () {
        taoLocation[0]++;
    };
    
private:
    taotromino_t type;
    // taoSize is needed to access the mathematical representation of the tetramino
    int taoSize;
    // taoCentre = [x, y] in pixels for rotation
    int taoCentre[2];
    // taoLocation = [x, y] in col, rows
    int taoLocation[2];
    int rotation = 0;

    static const Taotromino::taotromino_t lineDefinition[4][4][4];
    static const Taotromino::taotromino_t squareDefinition[4][2][2];
    static const Taotromino::taotromino_t tDefinition[4][3][3];
    static const Taotromino::taotromino_t lDefinition[4][3][3];
    static const Taotromino::taotromino_t jDefinition[4][3][3];
    static const Taotromino::taotromino_t sDefinition[4][3][3];
    static const Taotromino::taotromino_t zDefinition[4][3][3];
};

#endif	/* TAOTROMINO_H */

