#include "Include/HelloWorldScene.h"

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
    
    // Using an empty node to maintain all of the game sprites
    auto spriteNode = Node::create();
    
    // Loading SquareBro from the SpriteSheet
    auto daSquareBro = Sprite::createWithSpriteFrameName("daSquareBro.png");
    daSquareBro->setPosition(100, 200);
    
    auto daSquareSis = Sprite::createWithSpriteFrameName("daSquareSis.png");
    daSquareSis->setPosition(400, 200);
    daSquareSis->setScale(0.5,0.5);
    
    // Adding spriteNode
    this->addChild(spriteNode,-1);
    
    // Adding Squares to the spriteNode
    spriteNode->addChild(daSquareBro,0);
    spriteNode->addChild(daSquareSis,0);
    
    return true;
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
