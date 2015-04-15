/* 
 * File:   SquareTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef LINETAOTROMINO_H
#define	LINETAOTROMINO_H

#include "Taotromino.h"


class SquareTaotromino : public Taotromino{
public:
    SquareTaotromino(int y);
    
    SquareTaotromino(const SquareTaotromino& orig);
    virtual ~SquareTaotromino();

private:

};

#endif	/* LINETAOTROMINO_H */

