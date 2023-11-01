#ifndef __EVENT_DISPATCH_DEMO_SCENE_H__
#define __EVENT_DISPATCH_DEMO_SCENE_H__

#include "cocos2d.h"

class EventDispatchDemo : public cocos2d::Scene
{

public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  void onMouseDown(cocos2d::Event *event);
  void onMouseUp(cocos2d::Event *event);
  void onMouseMove(cocos2d::Event *event);
  void onMouseScroll(cocos2d::Event *event);

  // implement the "static create()" method manually
  CREATE_FUNC(EventDispatchDemo);
};

#endif // __EVENT_DISPATCH_DEMO_SCENE_H__