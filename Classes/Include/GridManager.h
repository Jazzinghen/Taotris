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
#include <random>

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
    
    /** Structure to manage random numbers generation
     * 
     *  I have to admit, shamefully, that I have copied the code from a Stack Overflow answer and
     *  I still have to understand why they are doing this, why this is better than other types
     *  of approach and how does "static" work in front of methods inside structures inside class
     *  definitions. I would have done differently but I suppo... WAIT A MOMENT!
     *
     *
     *  typedef struct
     *  {
     *  unsigned random = random_value();
     *  static unsigned random_value() {
     *         static std::random_device engine;
     *         static std::uniform_int_distribution<unsigned> distribution{0, 6};
     *         return distribution(engine);
     *      }
     *  } randomDevice_t;
     *
     * randomDevice_t blockGenerator;
     */
    
    void GenerateNewTao ();
};

#endif	/* GRIDMANAGER_H */

