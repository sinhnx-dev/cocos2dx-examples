#ifndef __JoystickSceneDemo_H__
#define __JoystickSceneDemo_H__

#include "cocos2d.h"
#include "Joystick.h"

class JoystickSceneDemo : public cocos2d::Scene
{
private:
  Joystick *joystick;
  cocos2d::Sprite *player;
  // scheduled Update
  void update(float dt);

public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(JoystickSceneDemo);
};

#endif // __JoystickSceneDemo_H__
