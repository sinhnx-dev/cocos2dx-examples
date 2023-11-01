#ifndef __EFFEKSEER_DEMO_SCENE_H__
#define __EFFEKSEER_DEMO_SCENE_H__

// #if COCOS2D_VERSION >= 0x00040000
// #include "EffekseerForCocos2d-x.h"
// #else
// #include "Effekseer/Effekseer.h"
// #endif

#include "cocos2d.h"

class EffekseerDemo : public cocos2d::Scene
{
private:
  // efk::EffectManager *manager = nullptr;
  int count = 0;

public:
  static cocos2d::Scene *createScene();

  virtual bool init();
  // virtual void update(float delta) override;
  // virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags) override;
  // implement the "static create()" method manually
  CREATE_FUNC(EffekseerDemo);
};

#endif // __EFFEKSEER_DEMO_SCENE_H__