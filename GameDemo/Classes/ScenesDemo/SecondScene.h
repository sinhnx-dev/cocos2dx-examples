#ifndef __SECOND_SCENE_H__
#define __SECOND_SCENE_H__

#include "cocos2d.h"

class SecondScene : public cocos2d::Scene
{
public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(SecondScene);
};

#endif // __SECOND_SCENE_H__