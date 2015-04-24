/* 
 * File:   gridManager.cpp
 * Author: jazzinghen
 * 
 * Created on 08 April 2015, 16:14
 */

#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <random>

#include "Include/GridManager.h"
#include "Include/Taotromino.h"
#include "Include/TaotrominoGrid.h"
#include "Include/LineTaotromino.h"
#include "Include/SquareTaotromino.h"
#include "Include/TTaotromino.h"
#include "Include/JTaotromino.h"
#include "Include/LTaotromino.h"
#include "Include/STaotromino.h"
#include "Include/ZTaotromino.h"

USING_NS_CC;

GridManager * GridManager::create()
{
    GridManager * ret = new (std::nothrow) GridManager();
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

GridManager::GridManager() {
    
//    std::cout << "Front Grid (pre init)" << std::endl;
//    
//    for (std::array<TaotrominoGrid::taotromino_t, (std::size_t) 10> taoColumn : GridManager::frontGrid){
//        for (TaotrominoGrid::taotromino_t taoCell : taoColumn){
//            std::cout << taoCell << " ";
//        }
//        std::cout << ";" << std::endl;
//    }
   
    for (auto&& taoColumn : GridManager::frontGrid){
        for (auto&& taoCell : taoColumn){
            taoCell = TaotrominoGrid::Empty;
        }
    }
    
//    std::cout << "Front Grid (post init)" << std::endl;
//    for (std::array<TaotrominoGrid::taotromino_t, (std::size_t) 10> taoColumn : GridManager::frontGrid){
//        for (TaotrominoGrid::taotromino_t taoCell : taoColumn){
//            std::cout << taoCell << " ";
//        }
//        std::cout << ";" << std::endl;
//    }
    
    for (auto&& taoColumn : GridManager::backGrid){
        for (auto&& taoCell : taoColumn){
            taoCell = TaotrominoGrid::Empty;
        }
    }
    
    auto mainGrid = Sprite::createWithSpriteFrameName("mainGrid");
    mainGrid->setAnchorPoint(Vec2(0, 0));
    mainGrid->setPosition(90, 90);
    
    this->addChild(mainGrid);
    
    GenerateNewTao();
}

GridManager::GridManager(const GridManager& orig) {
}

GridManager::~GridManager() {
}

void GridManager::GenerateNewTao(){
    
    /** This makes more sense to me. I have a static variable which is the same
     *  variable, shared in all the instances of the class, without having to
     *  create a new random_device every time and a new uniform_int_distribution.
     *  It is not important that there will be just one instance of the GridManager,
     *  but at least this is the way I feel this should be done.
     * 
     *  I will leave the other, suggested, implementation in the header. I know
     *  this litters the code, but I might get some insight from it.
     */
    
    static std::random_device engine;
    static std::uniform_int_distribution<unsigned> distribution{0, 6};
    
    unsigned type = distribution(engine);
    
    std::cout << "Creating Taotromino " << type << std::endl;
    
    switch (type){
        case 0:
            currentTao = LineTaotromino::create(5);
            break;
        
        case 1:
            currentTao = SquareTaotromino::create(5);
            break;
            
        case 2:
            currentTao = TTaotromino::create(5);
            break;
        
        case 3:
            currentTao = STaotromino::create(5);
            break;
            
        case 4:
            currentTao = ZTaotromino::create(5);
            break;
        
        case 5:
            currentTao = JTaotromino::create(5);
            break;
            
        case 6:
            currentTao = LTaotromino::create(5);
            break;    
            
        default:
            std::cout << "We _REALLY_ should not be here!" << std::endl;
            break;
    }
    
    
     std::cout << "Setting Location" << std::endl;
    currentTao->setPosition((90 + 90*16) - 45, (90 + 90*5) - 45);
    
//    auto fuffa1 = new ZTaotromino(4);
//    fuffa1->setPosition((90 + 90*4) - 45, (90 + 90*7) - 45);
//    
//    auto fuffa2 = new LineTaotromino(4);
//    fuffa2->setPosition((90 + 90*10) - 45, (90 + 90*10) - 45);
    
     std::cout << "Adding Taotromino to scene" << std::endl;
    this->addChild(currentTao, 2);
    //this->addChild(fuffa1, 2);
    //this->addChild(fuffa2, 2);
     std::cout << "End" << std::endl;
}

std::string GridManager::BlockName(TaotrominoGrid::taotromino_t blockType){
    
    switch (blockType){
        case TaotrominoGrid::Line:
            return "daSquareMidoriBig";
            break;
        case TaotrominoGrid::Square:
            return "daSquareMomoBig";
            break;
        case TaotrominoGrid::T:
            return "daSquareMikuBig";
            break;
        case TaotrominoGrid::J:
            return "daSquareAkaBig";
            break;
        case TaotrominoGrid::L:
            return "daSquareShiroBig";
            break;
        case TaotrominoGrid::S:
            return "daSquareOnii";
            break;
        case TaotrominoGrid::Z:
            return "daSquareOnee";
            break;
        default:
            return NULL;
            break;
    }
}

void GridManager::TaoStep() {
    auto taoMove = MoveBy::create(0.5f, Vec2(-90, 0));
    auto taoSeq = Sequence::create(taoMove, nullptr);
    currentTao->runAction(taoSeq);
}