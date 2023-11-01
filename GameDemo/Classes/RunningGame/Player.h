#ifndef RunningGame_Player_h
#define RunningGame_Player_h

#include "cocos2d.h"

USING_NS_CC;

class Player : public Sprite
{
private:
  Action *_runAction;

public:
  int hp;
  static Player *create();

  virtual bool init();

  void run();
  // void idle();
  // void jump();
  // void walkLeft();
  // void walkRight();
};

#endif