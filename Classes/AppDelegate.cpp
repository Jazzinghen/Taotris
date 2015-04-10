#include <iostream>

#include "Include/AppDelegate.h"
#include "Include/HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("Taotris");
        //glview->setDesignResolutionSize(1920, 1080, (ResolutionPolicy) 3 );
        director->setOpenGLView(glview);
        /* * This function is needed in order to create a design space.
         *   The main idea of having a Design Space is to draw everything using
         *   a single resolution (E.g. using always the same coordinates, and then
         *   transform these coordinates in the screen space.
         * 
         *   In this way you do a double passage: first you scale graphical
         *   resources to the design space, then you scale from design space
         *   to screen space. Obviously sprites are not converted two times, it's
         *   just a computation. But in this way you don't have to do computations
         *   for scaling resources or game elements.
         * 
         *   Put it AFTER the initialisation of the OpenGL view. I'm dumb.
         */
        glview->setFrameSize(1280, 720);
        glview->setDesignResolutionSize(1920, 1080, ResolutionPolicy::SHOW_ALL);
    }
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

        
    auto screenSize = director->getOpenGLView()->getFrameSize();
    
    std::cout << "getVisibleSize " << screenSize.height;
    
    // loads the spritesheet into the manager
    auto squareCache = SpriteFrameCache::getInstance();
    
    if (screenSize.height >= 540) {
        squareCache->addSpriteFramesWithFile("res/SpriteSheets/HDR/TaotrisRes.plist");
    } else if (screenSize.height >= 270) {
        squareCache->addSpriteFramesWithFile("res/SpriteSheets/HD/TaotrisRes.plist");
    } else {
        squareCache->addSpriteFramesWithFile("res/SpriteSheets/SD/TaotrisRes.plist");
    }
    
    
    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
