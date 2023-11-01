#include "JoystickSceneDemo.h"
#include <math.h>

USING_NS_CC;

Scene *JoystickSceneDemo::createScene()
{
  return JoystickSceneDemo::create();
}

bool JoystickSceneDemo::init()
{
  if (!Scene::init())
  {
    return false;
  }
  auto dirs = Director::getInstance();
  auto visibleSize = dirs->getVisibleSize();
  Vec2 origin = dirs->getVisibleOrigin();

  this->joystick = Joystick::create(Vec2(200, 200));
  this->addChild(joystick);

  this->player = Sprite::create("HelloWorld.png");
  this->player->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
  this->addChild(this->player);

  this->scheduleUpdate();
//    joystick->getDirection();
//    joystick->getIntensity();
  
  return true;
}
void JoystickSceneDemo::update(float dt)
{
  if(this->joystick->getIsActive()){
    this->player->setRotation(this->joystick->getDirection());
    
    float angl = this->joystick->getDirection();
    float spf = Director::getInstance()->getSecondsPerFrame();
    float length = this->joystick->getIntensity()*0.05;
    
    float rad = CC_DEGREES_TO_RADIANS(0);
    if(angl<90)
      rad = CC_DEGREES_TO_RADIANS(angl-90);
    else if(angl<180)
      rad = CC_DEGREES_TO_RADIANS(angl+90);
    else if (angl<270)
      rad = CC_DEGREES_TO_RADIANS(angl-90);
    else if(angl<360)
      rad = CC_DEGREES_TO_RADIANS(angl+90);
    auto move = MoveBy::create(spf, Vec2(cos(rad)*length,sin(rad)*length));
    
    this->player->runAction(move);
  }
}
