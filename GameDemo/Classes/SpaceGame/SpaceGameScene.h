#ifndef __SPACE_GAME_SCENE_H__
#define __SPACE_GAME_SCENE_H__

#include "cocos2d.h"
#include "ParallaxNodeExtras.h"
#include "InfiniteParallaxNode.h"

class SpaceGameScene : public cocos2d::Scene
{
private:
  cocos2d::SpriteBatchNode *_batchNode;
  cocos2d::Sprite *_ship;
  // cocos2d::ParallaxNode *_backgroundNode;
  // ParallaxNodeExtras *_backgroundNode;
  InfiniteParallaxNode *_backgroundNode;
  cocos2d::Sprite *_spacedust1;
  cocos2d::Sprite *_spacedust2;
  cocos2d::Sprite *_planetsunrise;
  cocos2d::Sprite *_galaxy;
  cocos2d::Sprite *_spacialanomaly;
  cocos2d::Sprite *_spacialanomaly2;

  // scheduled Update
  void update(float dt);

public:
  static cocos2d::Scene *createScene();

  virtual bool init();
  // virtual void update(float delta) override;
  // virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags) override;
  // implement the "static create()" method manually
  CREATE_FUNC(SpaceGameScene);
};

#endif // __SPACE_GAME_SCENE_H__