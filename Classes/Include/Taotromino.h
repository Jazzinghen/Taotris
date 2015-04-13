/* 
 * File:   Taotromino.h
 * Author: jazzinghen
 *
 * Created on 13 April 2015, 18:29
 */

#ifndef TAOTROMINO_H
#define	TAOTROMINO_H

#include "cocos2d.h"

typedef enum {
    Square, Line, T, S, Z, J, L
} taotromino_t;

class Taotromino : public cocos2d::Sprite{
public:
    Taotromino(taotromino_t type);
    Taotromino(const Taotromino& orig);
    virtual ~Taotromino();
private:

};

#endif	/* TAOTROMINO_H */

