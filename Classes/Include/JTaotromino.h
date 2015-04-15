/* 
 * File:   JTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef JTAOTROMINO_H
#define	JTAOTROMINO_H

#include "Taotromino.h"


class JTaotromino : public Taotromino{
public:
    JTaotromino(int y);
    
    JTaotromino(const JTaotromino& orig);
    virtual ~JTaotromino();

private:

};

#endif	/* JTAOTROMINO_H */

