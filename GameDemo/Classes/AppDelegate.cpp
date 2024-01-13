/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "Actions/ActionsDemoScene.h"
#include "Actions/AnimateDemoScene.h"
#include "ScenesDemo/FirstScene.h"
#include "UIComponents/LabelDemoScene.h"
#include "UIComponents/MenuDemoScene.h"
#include "UIComponents/WidgetUiDemoScene.h"
#include "TileMaps/TileMapDemoScene.h"
#include "ParticleSystem/BuiltInParticleDemo.h"
#include "ParticleSystem/EffekseerDemo/EffekseerDemoScene.h"
#include "SpaceGame/SpaceGameScene.h"
#include "RunningGame/RunningGame.h"
#include "EventDispatch/EventDispatchDemoScene.h"
#include "PhysicEngine/PhysicEngineDemoScene.h"
#include "AudioEngine/AudioEngineDemoScene.h"
#include "ParallaxDemo/ParallaxDemoScene.h"
#include "WorkingWithData/playerUser.h"
#include "WorkingWithData/LeaderBoardWithSqlite.h"
#include "WorkingWithData/ParseJsonDemo.h"
#include "WorkingWithData/ParseXmlDemo.h"
#include "Joystick/JoystickSceneDemo.h"
using namespace std;
// #define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; // flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto dirs = Director::getInstance();
    auto glview = dirs->getOpenGLView();
    if (!glview)
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("Game Demo", cocos2d::Rect(0, 0, mediumResolutionSize.width, mediumResolutionSize.height));
#else
        glview = GLViewImpl::create("Game Demo");
#endif
        dirs->setOpenGLView(glview);
    }
    // turn on display FPS
    dirs->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    dirs->setAnimationInterval(1.0f / 30);

    auto scene = PhysicEngineDemo::createScene();
    // run
    dirs->runWithScene(scene);

    // Size visibleSize = dirs->getVisibleSize();
    // auto myScene = Scene::create();

    // auto sfc = SpriteFrameCache::getInstance();
    // sfc->addSpriteFramesWithFile("anim/running.plist");
    // auto ac = AnimationCache::getInstance();
    // ac->addAnimationsWithFile("anim/run-animation.plist");
    // auto sprite = Sprite::create("anim/run_01.png");
    // sprite->setPosition(100, 100);
    // myScene->addChild(sprite);
    // sprite->runAction(ac);

    // auto cache = AnimationCache::getInstance();
    // cache->addAnimationsWithFile("anim/sprite-sheet anim.plist");
    // auto animation = cache->getAnimation("CapGuyWalk");
    // auto animate = Animate::create(animation);
    // auto sprite = Sprite::createWithSpriteFrameName("CapGuyWalk0001");
    // sprite->setPosition(100, 100);
    // myScene->addChild(sprite);
    // sprite->runAction(animate);

    // auto label1 = Label::createWithTTF("Create Scene Demo", "fonts/Marker Felt.ttf", 36);
    // label1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

    // myScene->addChild(label1);

    // auto sprite1 = Sprite::create("HelloWorld.png");
    // sprite1->setPosition(Vec2(visibleSize.width / 2, 150));
    // // myScene->addChild(sprite1);

    // auto sprite2 = Sprite::create("HelloWorld.png");
    // sprite2->setPosition(Vec2(visibleSize.width / 2, 150));
    // sprite2->setAnchorPoint(Vec2(0, 0));
    // sprite2->setRotation(45);
    // sprite2->setScale(0.5);
    // // myScene->addChild(sprite2);

    // auto mySprite = Sprite::create("HelloWorld.png");
    // mySprite->setPosition(Vec2(visibleSize.width / 2, 150));
    // mySprite->setAnchorPoint(Vec2(0, 0));
    // myScene->addChild(mySprite);

    //    // Move a sprite 50 pixels to the right & 10 pixels to the top over 2 seconds
    //    auto moveBy = MoveBy::create(2, Vec2(0, 0));
    //    mySprite->runAction(moveBy);
    //
    //    // Move a sprite to a specific location over 2 seconds.
    //    auto moveTo = MoveTo::create(2, Vec2(0, 0));
    //    mySprite->runAction(moveTo);

    // // move to point 50,10 over 2 seconds
    // auto moveTo1 = MoveTo::create(2, Vec2(50, 10));
    // // move from current position by 100,10 over 2 seconds
    // auto moveBy1 = MoveBy::create(2, Vec2(100, 10));
    // // move to point 150,10 over 2 seconds
    // auto moveTo2 = MoveTo::create(2, Vec2(150, 10));
    // // create a delay
    // auto delay = DelayTime::create(1);
    // //    mySprite->runAction(Sequence::create(moveTo1, delay, moveBy1, delay->clone(), moveTo2, nullptr));
    // mySprite->runAction(Spawn::create(moveTo1, moveBy1, moveTo2, nullptr));

    // run
    // dirs->runWithScene(myScene);

    // a simple string
    log("This would be outputted to the console");
    // a string and a variable
    string s = "My variable";
    log("string is %s", s.c_str());
    // a double and a variable
    double dd = 42;
    log("double is %f", dd);
    // an integer and a variable
    int i = 6;
    log("integer is %d", i);
    // a bool and a variable
    bool b = true;
    log("bool is %s", b ? "true" : "false");
    // if (b == true)
    //     log("bool is true");
    // else
    //     log("bool is false");

    std::string lbdb = "LeaderBoard.db";
    LeaderBoardWithSqlite *leaderBoard = new LeaderBoardWithSqlite(lbdb);
    // log(leaderBoard->createDb(lbdb));

    std::string userName = "user2";
    if(!leaderBoard->insertLeaderBoard(userName, 10)){
        log("can't insert to LeadersBoard\n");
    }
    // playerUser u;
    // u.userName = userName;
    // u.score = 20;
    // leaderBoard->insertLeaderBoard(u);

    std::vector<playerUser> users = leaderBoard->loadLeaderBoard(5);
    for (playerUser u : users)
    {
        log("%s - %d", u.userName.c_str(), u.score);
    }

    ParseJsonDemo *json = new ParseJsonDemo("data/LeadersBoard.json");
    playerUser us;
    us.userName = "sinhnx";
    us.score = 50;
    json->insertLeaderBoard(us);
    std::vector<playerUser> jsonUsers = json->loadLeaderBoard(5);
    for (playerUser u : jsonUsers)
    {
        log("%s - %d", u.userName.c_str(), u.score);
    }

    ParseXmlDemo *xml = new ParseXmlDemo("data/LeadersBoard.xml");
    // if(xml->saveToFile(jsonUsers)){
    //     log("save to file completed!");
    // }else{
    //     log("can't save to file");
    // }
    if(xml->insertLeaderBoard(us)){
        log("insert completed!");
    }else{
        log("can't insert user");
    }
    std::vector<playerUser> xmlUsers = xml->loadLeaderBoard(5);
    for (playerUser u : xmlUsers)
    {
        log("%s - %d", u.userName.c_str(), u.score);
    }

    // initialize director
    //    auto director = Director::getInstance();
    //    auto glview = director->getOpenGLView();
    //    if (!glview)
    //    {
    // #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    //        glview = GLViewImpl::createWithRect("FirstGame", cocos2d::Rect(0, 0, mediumResolutionSize.width, mediumResolutionSize.height));
    // #else
    //        glview = GLViewImpl::create("FirstGame");
    // #endif
    //        director->setOpenGLView(glview);
    //    }
    //
    //    // turn on display FPS
    //    director->setDisplayStats(true);
    //
    //    // set FPS. the default value is 1.0/60 if you don't call this
    //    director->setAnimationInterval(1.0f / 60);
    //
    //    // Set the design resolution
    //    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    //    auto frameSize = glview->getFrameSize();
    //    // if the frame's height is larger than the height of medium size.
    //    if (frameSize.height > mediumResolutionSize.height)
    //    {
    //        director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
    //    }
    //    // if the frame's height is larger than the height of small size.
    //    else if (frameSize.height > smallResolutionSize.height)
    //    {
    //        director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
    //    }
    //    // if the frame's height is smaller than the height of medium size.
    //    else
    //    {
    //        director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
    //    }
    //
    //    register_all_packages();
    //
    //    // create a scene. it's an autorelease object
    //    auto scene = HelloWorld::createScene();
    //
    //    // run
    //    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#endif
}
