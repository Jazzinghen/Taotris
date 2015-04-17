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
    typedef enum {
        Empty, Square, Line, T, S, Z, J, L
    } taotromino_t;
    
    TaotrominoGrid(std::array<taotromino_t, (std::size_t) 4> first,
                   std::array<taotromino_t, (std::size_t) 4> second,
                   std::array<taotromino_t, (std::size_t) 4> third,
                   std::array<taotromino_t, (std::size_t) 4> fourth);
    
    TaotrominoGrid();
    
    TaotrominoGrid(const TaotrominoGrid& orig) {
        for (int i = 0; i < 4; i++) {
            this->gridDefinition[i] = orig.gridDefinition[i];
        }
    };
    virtual ~TaotrominoGrid();
    
    std::array<taotromino_t, (std::size_t) 4> getColum(int x) {
        return gridDefinition[x];
    };
    
private:
    // gridDefinition are defined by columns, starting from the top (i.e. 0 is the first column to the right)
    std::array<std::array<taotromino_t, (std::size_t) 4>, (std::size_t) 4> gridDefinition;

};

#endif	/* TAOTROMINOGRID_H */

