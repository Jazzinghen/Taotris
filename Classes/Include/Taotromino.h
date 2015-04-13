/* 
 * File:   Taotromino.h
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
        Square, Line, T, S, Z, J, L
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
    
private:
    taotromino_t type;
    //Vec2 location;
    int rotation = 0;
};

#endif	/* TAOTROMINO_H */

