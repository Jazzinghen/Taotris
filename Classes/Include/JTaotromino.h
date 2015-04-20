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
    
    JTaotromino(const JTaotromino& orig);
    virtual ~JTaotromino();

    static JTaotromino * create(int y);
    
private:
    
    JTaotromino(int y);

};

#endif	/* JTAOTROMINO_H */

