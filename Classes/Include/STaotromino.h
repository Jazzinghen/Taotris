/* 
 * File:   STaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef STAOTROMINO_H
#define	STAOTROMINO_H

#include "Taotromino.h"


class STaotromino : public Taotromino{
public:
    STaotromino(int y);
    
    STaotromino(const STaotromino& orig);
    virtual ~STaotromino();

private:

};

#endif	/* STAOTROMINO_H */

