/* 
 * File:   LTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef LTAOTROMINO_H
#define	LTAOTROMINO_H

#include "Taotromino.h"


class LTaotromino : public Taotromino{
public:
    
    LTaotromino(const LTaotromino& orig);
    virtual ~LTaotromino();

    static LTaotromino * create(int y);
    
private:
    
    LTaotromino(int y);

};

#endif	/* LTAOTROMINO_H */

