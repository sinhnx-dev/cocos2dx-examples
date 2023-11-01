#ifndef __ANIMATE_DEMO_SCENE_H__
#define __ANIMATE_DEMO_SCENE_H__

#include "cocos2d.h"

class AnimateDemo : public cocos2d::Scene
{
public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(AnimateDemo);
};

#endif // __ANIMATE_DEMO_SCENE_H__