#ifndef __BUILT_IN_PARTICLE_DEMO_SCENE_H__
#define __BUILT_IN_PARTICLE_DEMO_SCENE_H__

#include "cocos2d.h"

class BuiltInParticleDemo : public cocos2d::Scene
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
  CREATE_FUNC(BuiltInParticleDemo);
};

#endif // __BUILT_IN_PARTICLE_DEMO_SCENE_H__