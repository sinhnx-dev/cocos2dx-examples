#ifndef __MENU_DEMO_SCENE_H__
#define __MENU_DEMO_SCENE_H__

#include "cocos2d.h"

class MenuDemo : public cocos2d::Scene
{
public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(MenuDemo);

  // a selector callback
  void menuCloseCallback(cocos2d::Ref *pSender);
};

#endif // __MENU_DEMO_SCENE_H__