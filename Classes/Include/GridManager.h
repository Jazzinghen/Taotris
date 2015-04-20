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
#include "TaotrominoGrid.h"

class GridManager : public cocos2d::Node{
public:
    GridManager(const GridManager& orig);
    virtual ~GridManager();
    
    void TrawGrid (Node);
    void UpdateGrid ();
    
    std::string BlockName (TaotrominoGrid::taotromino_t blockType);
    
    static GridManager * create();
    
    void TaoStep ();
    
private:
    std::array<std::array<TaotrominoGrid::taotromino_t,(std::size_t) 10>,(std::size_t) 16> frontGrid;
    std::array<std::array<TaotrominoGrid::taotromino_t,(std::size_t) 10>,(std::size_t) 16> backGrid;
    
    Taotromino *currentTao;
    
    GridManager();
};

#endif	/* GRIDMANAGER_H */

