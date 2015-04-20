/* 
 * File:   ZTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef ZTAOTROMINO_H
#define	ZTAOTROMINO_H

#include "Taotromino.h"


class ZTaotromino : public Taotromino{
public:

    
    ZTaotromino(const ZTaotromino& orig);
    virtual ~ZTaotromino();
    
    static ZTaotromino * create(int y);
    
private:
    
    ZTaotromino(int y);
};

#endif	/* ZTAOTROMINO_H */

