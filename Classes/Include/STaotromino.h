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
    
    STaotromino(const STaotromino& orig);
    virtual ~STaotromino();
    
    static STaotromino * create(int y);


private:
    
    STaotromino(int y);

};

#endif	/* STAOTROMINO_H */

