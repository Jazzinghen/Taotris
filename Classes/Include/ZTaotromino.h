/* 
 * File:   ZTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef LINETAOTROMINO_H
#define	LINETAOTROMINO_H

#include "Taotromino.h"


class ZTaotromino : public Taotromino{
public:
    ZTaotromino(int y);
    
    ZTaotromino(const ZTaotromino& orig);
    virtual ~ZTaotromino();

private:

};

#endif	/* LINETAOTROMINO_H */

