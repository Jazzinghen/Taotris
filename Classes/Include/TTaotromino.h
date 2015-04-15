/* 
 * File:   TTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef LINETAOTROMINO_H
#define	LINETAOTROMINO_H

#include "Taotromino.h"


class TTaotromino : public Taotromino{
public:
    TTaotromino(int y);
    
    TTaotromino(const TTaotromino& orig);
    virtual ~TTaotromino();

private:

};

#endif	/* LINETAOTROMINO_H */

