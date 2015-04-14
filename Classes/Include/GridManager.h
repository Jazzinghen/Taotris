/* 
 * File:   gridManager.h
 * Author: jazzinghen
 *
 * Created on 08 April 2015, 16:14
 */

#ifndef GRIDMANAGER_H
#define	GRIDMANAGER_H

#include <string>
#include <array> 

#include "cocos2d.h"
#include "Taotromino.h"

class GridManager : public cocos2d::Node{
public:
    GridManager();
    GridManager(const GridManager& orig);
    virtual ~GridManager();
    
    void grawGrid (Node);
    void updateGrid ();
    
    std::string BlockName (Taotromino::taotromino_t blockType);
    
private:
    std::array<std::array<int,(std::size_t) 10>,(std::size_t) 16> frontGrid;
    std::array<std::array<int,(std::size_t) 10>,(std::size_t) 16> backGrid;
    
    Taotromino *currentTao;
};

#endif	/* GRIDMANAGER_H */

