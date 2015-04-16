/* 
 * File:   TaotrominoGrid.h
 * Author: jazzinghen
 *
 * Created on 16 April 2015, 13:54
 */

#include <array>
#include "Taotromino.h"

#ifndef TAOTROMINOGRID_H
#define	TAOTROMINOGRID_H

class TaotrominoGrid {
public:
    TaotrominoGrid(std::array<Taotromino::taotromino_t, (std::size_t) 4> first,
                   std::array<Taotromino::taotromino_t, (std::size_t) 4> second,
                   std::array<Taotromino::taotromino_t, (std::size_t) 4> third,
                   std::array<Taotromino::taotromino_t, (std::size_t) 4> fourth);
    
    TaotrominoGrid(const TaotrominoGrid& orig);
    virtual ~TaotrominoGrid();
    
    std::array<Taotromino::taotromino_t, (std::size_t) 4> getColum(int x) {
        return gridDefinition[x];
    };
    
private:
    // gridDefinition are defined by columns, starting from the top (i.e. 0 is the first column to the right)
    std::array<std::array<Taotromino::taotromino_t, (std::size_t) 4>, (std::size_t) 4> gridDefinition;

};

#endif	/* TAOTROMINOGRID_H */

