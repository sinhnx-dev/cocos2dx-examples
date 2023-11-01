#ifndef __FIRST_SCENE_H__
#define __FIRST_SCENE_H__

#include "cocos2d.h"

class FirstScene : public cocos2d::Scene
{
public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(FirstScene);
};

#endif // __FIRST_SCENE_H__