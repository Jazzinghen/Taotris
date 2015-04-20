#include <fstream>
#include <iostream>

#include "Include/HelloWorldScene.h"
#include "Include/GridManager.h"
#include "Include/Taotromino.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    taoManager = GridManager::create();
    
    // Using an empty node to maintain all of the game sprites
    auto spriteNode = Node::create();
    
    auto background = Sprite::createWithSpriteFrameName("background");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(0, 0);
    
    // Loading SquareBro from the SpriteSheet
    auto daSquareBro = Sprite::createWithSpriteFrameName("daSquareOtouto");
    daSquareBro->setPosition(0, 90);
    daSquareBro->setAnchorPoint(Vec2(0, 0));
    
    auto daSquareSis = Sprite::createWithSpriteFrameName("daSquareOnee");
    daSquareSis->setPosition(225, 225);
    daSquareSis->setScale(1,1);
    
    // Adding spriteNode
    this->addChild(spriteNode,-1);
    this->addChild(taoManager, -9);
    this->addChild(background, -10);
    
    // Adding Squares to the spriteNode
    spriteNode->addChild(daSquareBro,0);
    spriteNode->addChild(daSquareSis,0);
    
    // Needed to update the scene otherwise... It won't run it?
    this->scheduleUpdate();

    return true;
}

void HelloWorld::update(float delta){
    timeSinceStart += delta;

    if (timeSinceStart >= 2.0f){
        std::cout << "Now executing step!" << std::endl;
        taoManager->TaoStep();
        timeSinceStart = 0.0f;
    }
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
