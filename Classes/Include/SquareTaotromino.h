/* 
 * File:   SquareTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef SQUARETAOTROMINO_H
#define	SQUARETAOTROMINO_H

#include "Taotromino.h"


class SquareTaotromino : public Taotromino{
public:
    SquareTaotromino(int y);
    
    SquareTaotromino(const SquareTaotromino& orig);
    virtual ~SquareTaotromino();

private:

};

#endif	/* SQUARETAOTROMINO_H */

