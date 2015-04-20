/* 
 * File:   TTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef TTAOTROMINO_H
#define	TTAOTROMINO_H

#include "Taotromino.h"


class TTaotromino : public Taotromino{
public:
    
    TTaotromino(const TTaotromino& orig);
    virtual ~TTaotromino();
    
    static TTaotromino * create(int y);
    
private:

    TTaotromino(int y);
};

#endif	/* TTAOTROMINO_H */

