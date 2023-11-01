#ifndef __LABEL_DEMO_SCENE_H__
#define __LABEL_DEMO_SCENE_H__

#include "cocos2d.h"

class LabelDemo : public cocos2d::Scene
{
public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(LabelDemo);
};

#endif // __LABEL_DEMO_SCENE_H__