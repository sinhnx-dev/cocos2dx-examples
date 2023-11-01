#ifndef __PHYSIC_ENGINE_DEMO_SCENE_H__
#define __PHYSIC_ENGINE_DEMO_SCENE_H__

#include "cocos2d.h"

class PhysicEngineDemo : public cocos2d::Scene
{

public:
  static cocos2d::Scene *createScene();

  virtual bool init();
  bool onContactBegin(cocos2d::PhysicsContact &contact);

  // implement the "static create()" method manually
  CREATE_FUNC(PhysicEngineDemo);
};

#endif // __PHYSIC_ENGINE_DEMO_SCENE_H__