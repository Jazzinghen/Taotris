/* 
 * File:   LTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef LINETAOTROMINO_H
#define	LINETAOTROMINO_H

#include "Taotromino.h"


class LTaotromino : public Taotromino{
public:
    LTaotromino(int y);
    
    LTaotromino(const LTaotromino& orig);
    virtual ~LTaotromino();

private:

};

#endif	/* LINETAOTROMINO_H */

