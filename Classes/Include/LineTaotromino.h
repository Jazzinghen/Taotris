/* 
 * File:   LineTaotromino.h
 * Author: jazzinghen
 *
 * Created on 15 April 2015, 16:13
 */

#ifndef LINETAOTROMINO_H
#define	LINETAOTROMINO_H

#include "Taotromino.h"


class LineTaotromino : public Taotromino{
public:
    LineTaotromino(int y);
    
    LineTaotromino(const LineTaotromino& orig);
    virtual ~LineTaotromino();

private:

};

#endif	/* LINETAOTROMINO_H */

