#ifndef __AUDIO_ENGINE_DEMO_SCENE_H__
#define __AUDIO_ENGINE_DEMO_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "AudioEngine.h"

class AudioEngineDemo : public cocos2d::Scene
{

public:
  static cocos2d::Scene *createScene();
  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(AudioEngineDemo);
};

#endif // __PHYSIC_ENGINE_DEMO_SCENE_H__