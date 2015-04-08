/* 
 * File:   gridManager.h
 * Author: jazzinghen
 *
 * Created on 08 April 2015, 16:14
 */

#ifndef GRIDMANAGER_H
#define	GRIDMANAGER_H

#include "cocos2d.h"

class GridManager : public cocos2d::Node{
public:
    GridManager();
    GridManager(const GridManager& orig);
    virtual ~GridManager();
    
    void grawGrid (Node);
    void updateGrid ();
private:
    std::array<std::array<int,(std::size_t) 10>,(std::size_t) 16> frontGrid;
    std::array<std::array<int,(std::size_t) 10>,(std::size_t) 16> backGrid;
};

#endif	/* GRIDMANAGER_H */

