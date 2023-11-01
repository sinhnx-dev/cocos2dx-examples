#ifndef __ACTIONS_DEMO_SCENE_H__
#define __ACTIONS_DEMO_SCENE_H__

#include "cocos2d.h"

class ActionsDemo : public cocos2d::Scene
{
public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // a selector callback
  void menuCloseCallback(cocos2d::Ref *pSender);

  // implement the "static create()" method manually
  CREATE_FUNC(ActionsDemo);
};

#endif // __ACTIONS_DEMO_SCENE_H__