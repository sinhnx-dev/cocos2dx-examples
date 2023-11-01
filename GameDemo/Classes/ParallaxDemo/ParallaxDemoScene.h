#ifndef __PARALLAX_DEMO_SCENE_H__
#define __PARALLAX_DEMO_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

class ParallaxDemo : public cocos2d::Scene
{
private:
  cocos2d::Sprite *_bg1;
  cocos2d::Sprite *_bg2;

public:
  static cocos2d::Scene *createScene();
  virtual bool init();
  virtual void update(float delta);

  // implement the "static create()" method manually
  CREATE_FUNC(ParallaxDemo);
};

#endif // __PHYSIC_ENGINE_DEMO_SCENE_H__