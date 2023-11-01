#ifndef __BUTTON_DEMO_SCENE_H__
#define __BUTTON_DEMO_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

class WidgetUiDemo : public cocos2d::Scene
{
public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(WidgetUiDemo);
};

#endif // __BUTTON_DEMO_SCENE_H__